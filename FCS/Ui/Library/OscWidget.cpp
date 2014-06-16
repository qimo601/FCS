#include "OscWidget.h"
#include <qwt_scale_draw.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>
#include <qwt_legend_label.h>
#include <qwt_plot_intervalcurve.h>
#include <qwt_symbol.h>
#include <QTime>
#include <QBitmap>
#include "USB/USBThread.h"
#include "Include/OscDataCenter.h"
OscWidget::OscWidget(QWidget *parent)
: QWidget(parent), m_interval_x(0.0, 1028), m_interval_y(30000, 45000), m_markPos(514,37500)
//m_interval_x���ô���1024������۲�߽�ֵ
{
	ui.setupUi(this);
	//��ʼ��
	init();
}


OscWidget::~OscWidget()
{
	if (d_origin!=0)
		delete d_origin;//ɾ��ʮ���м���
	if (grid != 0)
		delete grid;//ɾ����������
	if (canvas != 0)
		delete canvas;//ɾ������
	if (legend != 0)
		delete legend;//ɾ������
	//ɾ����������
	while (m_curveList.size() != 0)
	{
		delete m_curveList.takeFirst();
	}
	//�رն�ʱ��
	if (m_timerId != 0)
		killTimer(m_timerId);
}

//ʱ��̶ȱ�
class TimeScaleDraw : public QwtScaleDraw
{
public:
	TimeScaleDraw(const QTime &base) :
		baseTime(base)
	{
	}
	virtual QwtText label(double v) const
	{
		//�Զ��巵�صı�ǩ����
		/*QTime upTime = baseTime.addSecs(static_cast<int>(v));
		return upTime.toString();*/

		return QString::number(v);
	}
private:
	QTime baseTime;
};

/**
* @brief ��ʼ��
*/
void OscWidget::init()
{
	initPlot();//��ʼ��plot
	initWheelBox();//��ʼ������
	initAnimation();//��ʼ�����Դ��ڼ��䶯��
	this->setMouseTracking(true);
	m_timerId = 0;//��ʼ��

	readOscThread = new ReadOscThread();//ʾ�������ݶ�ȡ�߳�
	connect(readOscThread, SIGNAL(oscReadySignal()), this, SLOT(updateOscPlot()));
	
}
/**
* @brief ��ʼ�����Դ��ڼ��䶯��
*/
void OscWidget::initAnimation()
{	//���Դ���
	propertyWidget = new PropertyWidget(this);
	propertyWidget->setVisible(false);
	//���Դ�����ʾ�Ķ���
	showPropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry", this);

	//���Դ�����ʧ�Ķ���
	closePropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry", this);
	//
	connect(this, SIGNAL(propertyClicked()), this, SLOT(on_propertyBtn_clicked()));

	connect(closePropertyAnimation, SIGNAL(finished()), this, SLOT(setVisiblePropertyWidget()));
}
/**
* @brief ��ʼ��Plot
*/
void OscWidget::initPlot()
{
	//���û���
	canvas = new QwtPlotCanvas();//����
	QPalette pal = palette();

#if QT_VERSION >= 0x040400
	QLinearGradient gradient;
	gradient.setCoordinateMode(QGradient::StretchToDeviceMode);
	gradient.setColorAt(0.0, QColor(0, 49, 110));
	gradient.setColorAt(1.0, QColor(0, 87, 174));

	pal.setBrush(QPalette::Window, QBrush(gradient));
#else
	pal.setBrush(QPalette::Window, QBrush(color));
#endif

	// QPalette::WindowText is used for the curve color
	pal.setColor(QPalette::WindowText, Qt::green);

	canvas->setPalette(pal);
	canvas->setBorderRadius(10);//�������ܱ߿�ǰ뾶
	ui.oscPlot->setCanvas(canvas);//���û�ͼ�Ļ���


	ui.oscPlot->plotLayout()->setAlignCanvasToScales(true);//���ö��뻭���������ᡢ�̶�
	
	legend = new QwtLegend();//��������
	legend->setDefaultItemMode(QwtLegendData::Checkable);//����������QCheckBox����
	ui.oscPlot->insertLegend(legend, QwtPlot::RightLegend);//����λ�ã����Էֱ�����������
	//��ʼ������
	for (int i = 1; i < 9; i++)
	{
		QPolygonF points;
		for (int j = 0; j < 20; j++)
		{
			points << QPointF(qrand()%1000, qrand()%500) ;
		}
		// add curves
		oscCurve = new QwtPlotCurve(QString("ͨ��%1").arg(i));
		oscCurve->setRenderHint(QwtPlotItem::RenderAntialiased);//�����
		//������ɫ
		QColor c(qrand() % 255, qrand() % 255, qrand() % 255);
		oscCurve->setPen(c,1);
		//oscCurve->setBrush(c);//���ɫ

		/*oscCurve->setPen(c, 1);
		QColor bg(Qt::blue);
		bg.setAlpha(150);
		oscCurve->setBrush(QBrush(bg));
		oscCurve->setStyle(QwtPlotCurve::Lines);*/

		oscCurve->setZ(oscCurve->z() - i*10);//����z�������Ⱥ�˳���ĸ��������ϡ�


		// ��������
		oscCurve->setSamples(points);
		//�����߸���plot
		oscCurve->attach(ui.oscPlot);

		//����Ĭ����ʾ����
		if (i == 3)
			showCurve(oscCurve, true);//Ĭ����ʾ�ĸ�����
		else
			showCurve(oscCurve, false);//����ʾ��ʾ�ĸ�����

		m_curveList.append(oscCurve);//�����߽�������
		
	}
	connect(legend, SIGNAL(checked(const QVariant &, bool, int)),
		SLOT(legendChecked(const QVariant &, bool)));//����������ʾ��ע�⴫�ݵĲ�������
	//����X������
	ui.oscPlot->setAxisTitle(QwtPlot::xBottom, " ʱ��[us]");//���������-x��
	
	QTime t(1, 0, 0);
	ui.oscPlot->setAxisScaleDraw(QwtPlot::xBottom,new TimeScaleDraw(t));//����x��Ŀ̶Ȼ滭
	ui.oscPlot->setAxisLabelRotation(QwtPlot::xBottom, -50.0);//��ǩ��ת50��
	ui.oscPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
	ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());//����x������̶ȴ�С
	/*
	In situations, when there is a label at the most right position of the
	scale, additional space is needed to display the overlapping part
	of the label would be taken by reducing the width of scale and canvas.
	To avoid this "jumping canvas" effect, we add a permanent margin.
	We don't need to do the same for the left border, because there
	is enough space for the overlapping label below the left scale.
	*/

	QwtScaleWidget *scaleWidget = ui.oscPlot->axisWidget(QwtPlot::xBottom);//x��̶ȿؼ�
	const int fmh = QFontMetrics(scaleWidget->font()).height();
	scaleWidget->setMinBorderDist(0, fmh / 2);//���ÿ̶ȵı߽���Сֵ����ֹ��Ϊ��ǩ�仯����������


	//Y������
	ui.oscPlot->setAxisTitle(QwtPlot::yLeft, "ͨ��ֵ [��]");//Y�����ñ���
	ui.oscPlot->setAxisScale(QwtPlot::yLeft, m_interval_y.minValue(), m_interval_y.maxValue());//Y��̶�


	//����

	grid = new QwtPlotGrid();
	grid->setPen(Qt::gray, 0.0, Qt::DotLine);
	grid->enableX(true);
	grid->enableXMin(true);
	grid->enableY(true);
	grid->enableYMin(true);
	grid->attach(ui.oscPlot);

	//���һ���м�ʮ�ֱ��
	d_origin = new QwtPlotMarker();
	d_origin->setLineStyle(QwtPlotMarker::Cross);
	d_origin->setValue(m_markPos.x(), m_markPos.y());
	d_origin->setLinePen(Qt::gray, 0.0, Qt::DashLine);
	d_origin->attach(ui.oscPlot);
// 
// 	//���
// 	QwtPlotMarker* d_marker = new QwtPlotMarker();
// 	//���ֵ
// 	d_marker->setValue(0, 20);
// 	QwtText text("alert");
// 	text.setFont(QFont("Helvetica", 10));
// 	//text.setFont(QFont("Helvetica", 10, QFont::Bold));
// 	text.setColor(QColor(200, 15, 370));
// 	//���ñ���ߵı�ǩ
// 	d_marker->setLabel(text);
// 	d_marker->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
// 	//����ߵ��߷�� ˮƽ�ߣ���ֱ�ߣ�ʮ����
// 	d_marker->setLineStyle(QwtPlotMarker::HLine);
// 	d_marker->setLinePen(QPen(Qt::red, 0, Qt::DashDotLine));
// 	//����ߵı�־��
// 	d_marker->setSymbol(new QwtSymbol(QwtSymbol::Diamond,
// 		QColor(Qt::yellow), QColor(Qt::red), QSize(7, 7)));
// 	d_marker->attach(ui.oscPlot);


	//ˢ��plot
	ui.oscPlot->replot();


	//��ʼ����ʱ�����Զ����»���
	//m_timer = new QTimer(this);
	//connect(m_timer, SIGNAL(timeout()), this, SLOT(updateOscPlot()));

}
/**
* @brief ��ʼ��WheelBox
*/
void OscWidget::initWheelBox()
{
	ui.xScalewheelBox->setProperty("X�����", 0, 100000, 40);
	ui.yScalewheelBox->setProperty("Y�����", 0, 100000, 400);
	ui.xMarkwheelBox->setProperty("X���м���", 0, 100000, 40);
	ui.yMarkwheelBox->setProperty("Y���м�����", 0, 100000,400);

	ui.xScalewheelBox->setValue(m_interval_x.width());
	ui.yScalewheelBox->setValue(m_interval_y.width());
	ui.xMarkwheelBox->setValue(m_markPos.x());
	ui.yMarkwheelBox->setValue(m_markPos.y());
	connect(ui.xScalewheelBox, SIGNAL(valueChanged(double)), this, SLOT(setXAxisScale(double)));
	connect(ui.yScalewheelBox, SIGNAL(valueChanged(double)), this, SLOT(setYAxisScale(double)));
	connect(ui.xMarkwheelBox, SIGNAL(valueChanged(double)), this, SLOT(setXMark(double)));
	connect(ui.yMarkwheelBox, SIGNAL(valueChanged(double)), this, SLOT(setYMark(double)));
}
/**
* @brief ���»�ͼ����
*/
void OscWidget::updateOscPlot()
{
	QVector<double> oscXData;
	QVector<double> oscYData;
	bllDataCenter.getOscData(oscXData, oscYData);
	//OscDataCenter::setLock();
	for (int i = 0; i < Global::oscYData.count(); i++)

	{
		oscCurve = m_curveList[i];
		/*if (Global::oscYData.at(i).size() != 0 && Global::oscXData.size() != 0)
		{*/
			//QVector<double> oxcX = Global::oscXData;
			//QVector<double> oxcY = Global::oscYData[i];
			oscCurve->setSamples(Global::oscXData, Global::oscYData[i]);
			ui.oscPlot->replot();
		//}
	}
	//OscDataCenter::setUnlock();
	
}
/**
* @brief ��ʼʾ�����ɼ�
*/
void OscWidget::on_startOscAcqBtn_clicked()
{
	emit startOscAcq();
	//ֹͣ�ɼ�����
	VoCmd voCmd;
	voCmd.setCmd(8);
	voCmd.setLength(0);
	bllControl.sendCmd(voCmd);


	m_timerId = startTimer(10);//��ʱ����ȡ
	//readOscThread->start();//ʾ�����̶߳�ȡ
	//readOscThread->setGoOn(true);//�������ѭ��
	ui.startOscAcqBtn->setEnabled(false);
	ui.stopOscAcqBtn->setEnabled(true);
}

/**
* @brief ֹͣʾ�����ɼ�
*/
void OscWidget::on_stopOscAcqBtn_clicked()
{
	//ֹͣ�ɼ�����
	VoCmd voCmd;
	voCmd.setCmd(9);
	voCmd.setLength(0);
	bllControl.sendCmd(voCmd);
	//�رն�ʱ��
	killTimer(m_timerId);
	//readOscThread->setGoOn(false);//ֹͣ���ѭ�����߳̽�������׶�
	ui.startOscAcqBtn->setEnabled(true);
	ui.stopOscAcqBtn->setEnabled(false);
}
void OscWidget::timerEvent(QTimerEvent *event)
{
	//ÿ��10ms����һ��
	if (event->timerId() == m_timerId)
	{
		updateOscPlot();

		

		//const double elapsed = m_clock.elapsed() / 1000.0;
		////3������
		//if (elapsed > 3)
		//{
		//	Global::oscXData.clear();
		//	for (int i = 0; i < Global::oscYData.count(); i++)
		//		Global::oscYData[i].clear();

		//	m_clock.restart();
		//}

			

// 		const double elapsed = d_clock.elapsed() / 1000.0;
// 		if (elapsed > d_interval.maxValue())
// 			incrementInterval();

		return;
	}

	QWidget::timerEvent(event);
}
/**
* @brief ������������ۺ���
*/
void OscWidget::legendChecked(const QVariant &itemInfo, bool on)
{
	//ʶ����ѡ��
	QwtPlotItem *plotItem = ui.oscPlot->infoToItem(itemInfo);
	//���ѡ�У�����ʾ������
	if (plotItem)
		showCurve(plotItem, on);
}
/**
* @brief ����һ���ĸ�������ʾ
*/
void OscWidget::showCurve(QwtPlotItem *item, bool on)
{
	item->setVisible(on);
	//��ȡ�û�ͼ������
	QwtLegend *lgd = qobject_cast<QwtLegend *>( ui.oscPlot->legend());
	//��ȡ�����������
	QList<QWidget *> legendWidgets =
		lgd->legendWidgets( ui.oscPlot->itemToInfo(item));

	if (legendWidgets.size() == 1)
	{
		//��ȡ�����������ı�ǩֵ
		QwtLegendLabel *legendLabel =
			qobject_cast<QwtLegendLabel *>(legendWidgets[0]);
		//�����ǩ��ֵ������ʾ
		if (legendLabel)
			legendLabel->setChecked(on);
	}

	ui.oscPlot->replot();
}
/**
* @brief ����X������-��Χ
*/
void OscWidget::setXAxisScale(double interval)
{
	//�ж��Ƿ���Ч
	if (interval > 0.0 && interval != m_interval_x.width())
	{
		double xChange = (interval - m_interval_x.width()) / 2;
		m_interval_x.setMaxValue(m_interval_x.maxValue() + xChange);//�������ü��
		m_interval_x.setMinValue(m_interval_x.minValue() - xChange);//�������ü��
		//��������x�����귶Χ
		ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());
		//����һ��mark�Ƿ�仯����ʵ�����
		ui.xMarkwheelBox->setValue(m_markPos.x());
		ui.oscPlot->replot();
	}
}
/**
* @brief ����Y������-��Χ
*/
void OscWidget::setYAxisScale(double interval)
{
	//�ж��Ƿ���Ч
	if (interval > 0.0 && interval != m_interval_y.width())
	{
		double yChange = (interval - m_interval_y.width())/2;
		m_interval_y.setMaxValue(m_interval_y.maxValue() + yChange);//�������ü��
		m_interval_y.setMinValue(m_interval_y.minValue() - yChange);//�������ü��
		//��������y�����귶Χ
		ui.oscPlot->setAxisScale(QwtPlot::yLeft,  m_interval_y.minValue(),  m_interval_y.maxValue());
		//����һ��mark�Ƿ�仯����ʵ�����
		ui.yMarkwheelBox->setValue(m_markPos.y());
		ui.oscPlot->replot();
	}
}
/**
* @brief ����X���м���
*/
void OscWidget::setXMark(double mark_x)
{
	//�ж��Ƿ���Ч
	if (mark_x > 0.0 && mark_x != m_markPos.x())
	{
		double xchange = mark_x - m_markPos.x();
		//����ʮ���м�������
		m_markPos.setX(mark_x);
		//����ʮ���м��߾���λ��
		d_origin->setValue(m_markPos);
		//���¼��ֵ
		m_interval_x.setInterval(m_interval_x.minValue() + xchange, m_interval_x.maxValue() + xchange);
		//��������x�����귶Χ
		ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());
		//����һ��mark
		ui.xMarkwheelBox->setValue(m_markPos.x());
		ui.oscPlot->replot();
	}
}
/**
* @brief ����Y���м���
*/
void OscWidget::setYMark(double mark_y)
{
	//�ж��Ƿ���Ч
	if (mark_y > 0.0 && mark_y != m_markPos.y())
	{
		double ychange = mark_y - m_markPos.y();
		//����ʮ���м�������
		m_markPos.setY(mark_y);
		//����ʮ���м��߾���λ��
		d_origin->setValue(m_markPos);
		//���¼��ֵ
		m_interval_y.setInterval(m_interval_y.minValue() + ychange, m_interval_y.maxValue() + ychange);
		//��������y�����귶Χ
		ui.oscPlot->setAxisScale(QwtPlot::yLeft, m_interval_y.minValue(), m_interval_y.maxValue());
		//����һ��mark
		ui.yMarkwheelBox->setValue(m_markPos.y());
		ui.oscPlot->replot();
	}
}
/**
* @brief ���ð�ť�������Դ���
*/
void OscWidget::on_propertyBtn_clicked()
{
	if (!propertyWidget->isVisible())
	{
		showPropertyWidget();
	}
	else
	{
		closePropertyWidget();

	}

}
/**
* @brief ��껬���¼�
*/
void OscWidget::mouseMoveEvent(QMouseEvent* event)
{
	/*int x = mapToGlobal(event->pos()).x();
	int y = mapToGlobal(event->pos()).y();
	int propertyX = mapToGlobal(ui.propertyBtn->pos()).x();
	int propertyY = mapToGlobal(ui.propertyBtn->pos()).y();
	int propertWidth = ui.propertyBtn->width();
	int propertHeight = ui.propertyBtn->height();

	if (x > propertyX && x <propertyX + propertWidth && y>propertyY && y < propertyY + propertHeight)
	{
	this->setCursor(Qt::OpenHandCursor);
	emit propertyClicked();
	}
	else{
	this->setCursor(Qt::ArrowCursor);
	}*/

}
/**
* @brief ��ʾ���Դ���
*/
void OscWidget::showPropertyWidget()
{
	propertyWidget->setVisible(true);

	int width = propertyWidget->width();
	int height = propertyWidget->height();

	showPropertyAnimation->setDuration(100);
	QPoint pos = ui.toolFrame->mapTo(this, ui.propertyBtn->pos());
	showPropertyAnimation->setStartValue(QRect(pos.x(), pos.y(), 0, 300));//��ʼλ��
	showPropertyAnimation->setEndValue(QRect(pos.x() - 530, pos.y(), 530, 300));//����λ��

	showPropertyAnimation->start();

}
/**
* @brief �ر����Դ���
*/
void OscWidget::closePropertyWidget()
{
	int width = propertyWidget->width();
	int height = propertyWidget->height();
	closePropertyAnimation->setDuration(100);
	QPoint pos = ui.toolFrame->mapTo(this, ui.propertyBtn->pos());
	closePropertyAnimation->setStartValue(QRect(pos.x() - width, pos.y(), 530, 300));//��ʼλ��
	closePropertyAnimation->setEndValue(QRect(pos.x(), pos.y(), 0, 300));//����λ��
	closePropertyAnimation->start();
	//propertyWidget->setVisible(false);
}
/**
* @brief �������Դ��ڲ��ɼ�
*/
void OscWidget::setVisiblePropertyWidget()
{
	propertyWidget->setVisible(false);
	update();
}

/**
* @brief ����ʾ��������
*/
void OscWidget::on_saveCheckBox_clicked()
{
	if (ui.saveCheckBox->isChecked())
	{
		USBThread::fileName = QString("file_%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd--HH-mm-ss"));
		USBThread::projectFile = fopen(USBThread::fileName.toLocal8Bit().data(), "ab+");
		USBThread::saveTag = true;
	}
	else
	{
		USBThread::saveTag = false;
		//�ر��ļ�
		if (fclose(USBThread::projectFile) != 0)
			qDebug() << "��on_saveCheckBox_clicked���ر��ļ�ʧ�ܣ��ļ�����" << USBThread::fileName;
	}
}