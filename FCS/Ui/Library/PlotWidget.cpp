#include "PlotWidget.h"

#include <qmath.h>
#include <QTime>
#include <QPainter>
#include "BarStruct.h"
#include <qwt_scale_engine.h>
#include <qwt_scale_draw.h>
#include "Ui/Library/ViewWidget.h"
//����logֵ���Ʊ�ǩ
class LogScaleDraw : public QwtScaleDraw
{
public:
	LogScaleDraw()
	{
		setTickLength(QwtScaleDiv::MinorTick, 1);
		setTickLength(QwtScaleDiv::MediumTick, 2);
		setTickLength(QwtScaleDiv::MajorTick, 4);

		enableComponent(QwtScaleDraw::Backbone, true);
		//setLabelRotation(-20.0);

		setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	}
	~LogScaleDraw()
	{
	}
	//�̶ȱ�ǩֵ
	virtual QwtText label(double value) const
	{
		double lblValue = qPow(10, value);//qLn(value) / qLn(10);
		QwtText lbl = QString::number(lblValue);

		return lbl;
	}

};
PlotWidget::PlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ϸ����ͼ�ؼ���ʼ��
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(0);
	vLayoutCellPlotFrame->setContentsMargins(0, 0, 0, 0);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_plot = new Plot(ui.cellPlotFrame);
	d_plot->setObjectName(QStringLiteral("d_plot"));

	vLayoutCellPlotFrame->addWidget(d_plot);



	//���ñ������Ƿ���ʾ
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), this, SLOT(setGridEnable(bool)));
	//�����Ƿ���ʾlogֵ
	connect(ui.logCheckBox, SIGNAL(clicked(bool)), this, SLOT(setLogEnable(bool)));
	//���÷Ŵ�/��С��ť��ѡ��
	ui.zoomerBtn->setCheckable(true);
	//���÷Ŵ���С�����Ƿ�����
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), this, SLOT(enableZoomMode(bool)));
	//����ƽ�ư�ť��ѡ��
	ui.pannerBtn->setCheckable(true);
	//����ƽ�ư�ť�����Ƿ�����
	connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enablePannerMode(bool)));
	//X��ͨ��ֵѡ��
	connect(ui.passageXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setPassage(int)));
	//Y��ͨ��ֵѡ��
	connect(ui.passageYCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setPassage(int)));

	//Y�����ݵ�Ԫ����ѡ��
	connect(ui.dataUnitXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataUnit(int)));
	//Y�����ݵ�Ԫ����ѡ��
	connect(ui.dataUnitYCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataUnit(int)));
	//��󻯴���
	connect(ui.maximizedBtn, SIGNAL(clicked()), this, SLOT(maximizedPlotWidget()));
	//��ԭ����
	connect(ui.normalBtn, SIGNAL(clicked()), this, SLOT(normalPlotWidget()));
	//ʮ��������
	connect(ui.crossBtn, SIGNAL(toggled(bool)), this, SLOT(enableCrossBtnMode(bool)));
	//���������ʾ��ֵ
	connect(ui.viewTrueValueBtn_2, SIGNAL(toggled(bool)), this, SLOT(enableViewTrueValueMode2(bool)));
	//��������
	connect(ui.rectBtn, SIGNAL(toggled(bool)), this, SLOT(enableRectBtn(bool)));
	//ƽ��������
	connect(ui.parallelLineBtn, SIGNAL(toggled(bool)), this, SLOT(enableParallelLineBtn(bool)));
	//��Բ����
	connect(ui.ellipseBtn, SIGNAL(toggled(bool)), this, SLOT(enableEllipseBtn(bool)));
	//���������
	connect(ui.polygonBtn, SIGNAL(toggled(bool)), this, SLOT(enablePolygonBtn(bool)));
	

	//����-����ѡ��
	connect(ui.testUpBtn, SIGNAL(toggled(bool)), this, SLOT(testUpBtnMode(bool)));
	//���ٲ���ѡ��
	connect(ui.testDownBtn, SIGNAL(toggled(bool)), this, SLOT(testDownBtnMode(bool)));
	
	//ֱ��ͼͳ��
	connect(ui.barChatStaticsCheckBox, SIGNAL(clicked(bool)), this, SLOT(setBarStatisticsMode(bool)));
	//ɢ��ͼͳ��
	connect(ui.scatterCheckBox, SIGNAL(clicked(bool)), this, SLOT(setScatterMode(bool)));


	//************��ʱ���Ų���*******************//
	////��ͼ-ʮ��������-����ֵ
	//connect(d_plot, SIGNAL(selectedCrossPicker(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
	////��ͼ-��������-����ֵ
	//connect(d_plot, SIGNAL(selectedRectPicker(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));
	////��ͼ-ƽ��������-����ֵ
	//connect(d_plot, SIGNAL(selectedParallelLinePicker(QList<QPointF>)), this, SLOT(selectedParallelLinePickerSlot(QList<QPointF>)));

	
	m_timerId = 0;//��ʼ��
	d_rectPicker = 0;
	d_parallelLinePicker_1 = 0;
	d_parallelLinePicker_2 = 0;
	d_crossPicker_1 = 0;
	d_crossPicker_2 = 0;
	d_polygonPicker = 0;
	d_ellipsePicker = 0;




	//m_timerId = startTimer(10);//���Կ�ʼ��ʵʱ��ʾ

	this->setFocusPolicy(Qt::ClickFocus);
	parent = 0;

	//����ͳ���߳�
	staticsThread.setDataWidget(this);
	staticsThread.start();
	//��ͳ���̸߳������ݣ��������ݿ�����plot������ɢ��ͼ��ֱ��ͼ�ȣ�
	connect(&staticsThread, SIGNAL(staticsFinished()), this, SLOT(updateSamples()));

	init();//��ʼ��

}

PlotWidget::~PlotWidget()
{

}





/**
* @brief ��ʼ��
*/
void PlotWidget::init()
{
	condition = 1024;//ֱ��ͼ����������Ŀ
	dataMutex.lock();
	//��ʼ���û�ͼ�����ݽṹ
	origialDataList = new QList < QList < QVector<double>* >*  >();//����������ԭʼ����
	logDataList = new QList < QList < QVector<double>* >*  >();//����������logֵ
	barStructList = new QList < QList < QVector<BarStruct>* >*  >();
	//8��ͨ��
	for (int i = 0; i < 8; i++)
	{
		QList < QVector<double>* >* list = new QList < QVector<double>* >();
		origialDataList->append(list);
		QList < QVector<double>* >* list1 = new QList < QVector<double>* >();
		logDataList->append(list1);

		QList<QVector<BarStruct>*>* list2 = new QList<QVector<BarStruct>*>();
		//�������
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = new QVector<double>();
			list->append(vector);
			QVector<double>* vector1 = new QVector<double>();
			list1->append(vector1);
			//��ʼ��ֱ��ͼ���ݽṹ
			QVector<BarStruct>* vector2 = new QVector<BarStruct>();
			//double internal = 10000000000.00 / condition;
			double internal = 10.00/ condition;
			for (int k = 0; k < condition; k++)
			{
				QPointF p(qPow(10,k*internal), qPow(10,(k + 1)*internal));
				BarStruct barStruct1(p.x(), QString("[%1,%2)").arg(p.x()).arg(p.y()), 0, QColor("DodgerBlue"), p);
				vector2->append(barStruct1);
			}
			list2->append(vector2);//QList����new�ģ�appendֻ�ǿ��������Ա��������append

		}
		barStructList->append(list2);//QList����new�ģ�appendֻ�ǿ��������Ա��������append

	}
	dataMutex.unlock();
	logEnable = false; //Ĭ�ϲ���ʾlog
	//��ʼ������һЩ����
	initUi();
	//��ʼ��bar��������
	initBarData();
	//��ʼ������
	setAxisScale();
	//�ֶ�����һ������
	updateSamples();
}

/**
* @brief ��ʼ������һЩ����
*/
void PlotWidget::initUi()
{
	//��ʼ��ͨ�������ݵ�Ԫֵ
	//�ɺ���������
	/*for (int i = 0; i < 8; i++)
	{
		ui.passageXCombox->addItem(QString("ͨ��%1").arg(i + 1), i);
		ui.passageYCombox->addItem(QString("ͨ��%1").arg(i + 1), i);
	}*/
	//��ʼ��passageXCombox��ͨ��Ĭ����ֵ
	ui.passageXCombox->addItem("FSC", (int)0);
	ui.passageXCombox->addItem("SSC", (int)1);
	ui.passageXCombox->addItem("FL1", (int)2);
	ui.passageXCombox->addItem("FL2", (int)3);
	ui.passageXCombox->addItem("FL3", (int)4);
	ui.passageXCombox->addItem("FL4", (int)5);
	ui.passageXCombox->addItem("FL5", (int)6);
	ui.passageXCombox->addItem("FL6", (int)7);

	//��ʼ��passageYCombox��ͨ��Ĭ����ֵ
	ui.passageYCombox->addItem("FSC", (int)0);
	ui.passageYCombox->addItem("SSC", (int)1);
	ui.passageYCombox->addItem("FL1", (int)2);
	ui.passageYCombox->addItem("FL2", (int)3);
	ui.passageYCombox->addItem("FL3", (int)4);
	ui.passageYCombox->addItem("FL4", (int)5);
	ui.passageYCombox->addItem("FL5", (int)6);
	ui.passageYCombox->addItem("FL6", (int)7);


	ui.dataUnitYCombox->addItem("HH", 0);
	ui.dataUnitYCombox->addItem("AA", 1);
	ui.dataUnitYCombox->addItem("WW", 2);
	ui.dataUnitXCombox->addItem("HH", 0);
	ui.dataUnitXCombox->addItem("AA", 1);
	ui.dataUnitXCombox->addItem("WW", 2);

	ui.passageXCombox->setCurrentIndex(2);//Ĭ��ͨ��3
	ui.passageYCombox->setCurrentIndex(2);
	ui.dataUnitXCombox->setCurrentIndex(0);//Ĭ��HH���ݵ�Ԫ
	ui.dataUnitYCombox->setCurrentIndex(0);


	//���ؽ��治�õİ�ť
	ui.zoomerBtn->setVisible(false);
	ui.viewTrueValueBtn_2->setVisible(false);
	//ui.parallelLineBtn_2->setVisible(false);
	ui.testUpBtn->setVisible(false);
	ui.testDownBtn->setVisible(false);


	//Ĭ������
	ui.rectBtn->setEnabled(true);//����������ʾ
	ui.parallelLineBtn->setEnabled(false);//ƽ����������
}
/**
* @brief ��ʼ��Bar�б��⡢��ɫ��ģ������
*/
void PlotWidget::initBarData()
{

	//double internal = 10.00 / 100;
	////��ʼ��ֱ��ͼ���ݽṹ
	//for (int i = 0; i < 100; i++)
	//{
	//	BarStruct barStruct1(i*internal, QString("[%1,%2)").arg(i*internal).arg((i + 1)*internal), 0, QColor("DodgerBlue"), QPoint(i*internal, (i + 1)*internal));
	//	barStructList.append(barStruct1);
	//}

}
double PlotWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}

/**
* @brief ת����log(10)x
*/
//void PlotWidget::translateToLog()
//{
//	QList< QVector<double>* >* passageData = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		passageData = new QList < QVector<double>* >();
//		for (int j = 0; j < 3; j++)
//		{
//
//			QVector<double>* vector = new QVector<double>();
//			passageData->append(vector);
//		}
//		cellFullData->append(passageData);
//	}
//	origialDataList->append();
//	logDataList->append();
//}
///**
//* @brief ��������ɸѡ
//*/
//void PlotWidget::translateWithCondition()
//{
//
//}
/**
* @brief ����ͨ��
*/
void PlotWidget::setPassage(int index)
{
	//���ֱ��ͼģʽѡ����ͳ��һ�¸�ͨ��
	if (ui.barChatStaticsCheckBox->isChecked())
		statisticsHistogram(ui.passageYCombox->currentData().toInt(), ui.dataUnitYCombox->currentData().toInt());
	updateSamples();
}
/**
* @brief �������ݵ�Ԫ����
*/
void PlotWidget::setDataUnit(int index)
{
	//���ֱ��ͼģʽѡ����ͳ��һ�¸�ͨ��
	if (ui.barChatStaticsCheckBox->isChecked())
		statisticsHistogram(ui.passageYCombox->currentData().toInt(), ui.dataUnitYCombox->currentData().toInt());
	updateSamples();
}
/**
* @brief ��󻯵�ǰplot����
*/
void PlotWidget::maximizedPlotWidget()
{
	m_parent = this->parentWidget();
	this->setParent(0);
	this->showMaximized();
	ui.maximizedBtn->setEnabled(false);
	ui.normalBtn->setEnabled(true);
}
/**
* @brief ��ԭ����
*/
void PlotWidget::normalPlotWidget()
{
	ui.maximizedBtn->setEnabled(true);
	ui.normalBtn->setEnabled(false);
	this->setParent(m_parent);
	emit normalPlot();//��ԭ�����ź�
}

void PlotWidget::timerEvent(QTimerEvent *event)
{
	//ÿ��10ms����һ��
	if (event->timerId() == m_timerId)
	{
		updateSamples();
	}
}

void PlotWidget::startAcqTimer()
{
	//������ʱ��
	m_timerId = startTimer(10);
}
void PlotWidget::stopAcqTimer()
{
	//�رն�ʱ��
	killTimer(m_timerId);
}



void PlotWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}
/**
* @brief ����log������ʾ
*/
void PlotWidget::setLogEnable(bool enable)
{
	logEnable = enable;
	setAxisScale();
	updateSamples();
}
/**
* @brief ��������������
*/
void PlotWidget::setGridEnable(bool enable)
{
	//�����ֱ��ͼģʽ����Ҫ����ˢɫ�ʡ����򱳾�ˢΪ��
	bool barMode = ui.barChatStaticsCheckBox->isChecked();
	d_plot->setGridEnable(enable, barMode);
}
/**
* @brief �������ÿ̶�
*/
void PlotWidget::setAxisScale()
{
	//ɢ��ͼģʽ
	if (ui.scatterCheckBox->isChecked())
	{
		d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());
		d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
		d_plot->setAxisScale(QwtPlot::xBottom, 0, 1e8);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisScale(QwtPlot::yLeft, 0, 1e8);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLinearScaleEngine);
		d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
		if (ui.logCheckBox->isChecked())
		{

			d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());//ÿ�θı�����ֵ���������»��ƿ̶ȱ�ǩ�Ϳ̶���ʽ
			d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
			
			d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
			d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine);
			//d_plot->setAxisScale(QwtPlot::xBottom, 0, 6);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
			//d_plot->setAxisScale(QwtPlot::yLeft, 0, 6);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
			d_plot->setAxisScale(QwtPlot::xBottom, 1, 1e8);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
			d_plot->setAxisScale(QwtPlot::yLeft, 1, 1e8);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
			/*d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
			d_plot->setAxisAutoScale(QwtPlot::yLeft, true);*/
		}

	}
	//ֱ��ͼͳ��ģʽ
	else if (ui.barChatStaticsCheckBox->isChecked())
	{
		d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());
		d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
		d_plot->setAxisScale(QwtPlot::xBottom, 0, 1e6);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisAutoScale(QwtPlot::yLeft);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLinearScaleEngine);
		d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
		d_plot->setAxisMaxMajor(QwtPlot::xBottom, 5);//
		d_plot->setAxisMaxMinor(QwtPlot::xBottom, 5);
		if (ui.logCheckBox->isChecked())
		{
			
			d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
			d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
			d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());//ÿ�θı�����ֵ���������»��ƿ̶ȱ�ǩ�Ϳ̶���ʽ
			d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
			d_plot->setAxisMaxMajor(QwtPlot::xBottom, 10);//��̶����10��
			d_plot->setAxisMaxMinor(QwtPlot::xBottom, 5);//С�̶����5��
			//d_plot->setAxisScale(QwtPlot::yLeft, 0, 10000);
			d_plot->setAxisScale(QwtPlot::xBottom, 1,1e6);
			d_plot->setAxisAutoScale(QwtPlot::yLeft, true);
			//d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
			//d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
		}
	}

}

/**
* @brief ����ֱ��ͼͳ����ʾģʽ
*/
void PlotWidget::setBarStatisticsMode(bool mode)
{
	//����ֱ��ͼģʽ
	if (mode)
	{
		//���ǳ�ʼ��ʱ��modeΪtrue����������һ�µ�ǰ����
		ui.barChatStaticsCheckBox->setChecked(true);
		//d_plot->setTitle("ֱ��ͼ");



		//���ֱ��ͼģʽѡ����ͳ��һ�¸�ͨ��
		statisticsHistogram(ui.passageYCombox->currentData().toInt(), ui.dataUnitYCombox->currentData().toInt());
		//����ͳ��������ʽ
		d_plot->enableStaticsMode();
		setAxisScale();
		//�ֶ�����һ������
		updateStaticsSamples();
		//ֱ��ͼû��x��
		ui.passageXCombox->setEnabled(false);
		ui.dataUnitXCombox->setEnabled(false);

		ui.parallelLineBtn->setEnabled(true);//��ʾƽ������
		ui.rectBtn->setEnabled(false);//���ؾ�������
	}
}
/**
* @brief ����ɢ��ͼ��ʾģʽ
*/
void PlotWidget::setScatterMode(bool mode)
{
	if (mode)
	{
		//���ǳ�ʼ��ʱ��modeΪtrue����������һ�µ�ǰ����
		ui.scatterCheckBox->setChecked(true);
		//d_plot->setTitle("ɢ��ͼ");

		//����ɢ��ͼ��ʽ
		d_plot->enableScatterMode();
		setAxisScale();//�Զ��������꣬�ж��Ƿ���Ҫlog��ʾ
		//�ֶ�����һ������
		updateSamples();

		//ɢ��ͼ��x��
		ui.passageXCombox->setEnabled(true);
		ui.dataUnitXCombox->setEnabled(true);


		ui.parallelLineBtn->setEnabled(false);//����ƽ������
		ui.rectBtn->setEnabled(true);//��ʾ��������
	}
}
/**
* @brief ���÷Ŵ���С��ť
*/
void PlotWidget::enableZoomMode(bool mode)
{

	d_plot->enableZoomMode(mode);
}
/**
* @brief ����ʮ��������
*/
void PlotWidget::enableCrossBtnMode(bool mode)
{

	////����������
	//if (mode)
	//{
	//	//ʮ����
	//	d_crossPicker = new CrossPicker(d_plot->canvas);
	//	//ʮ��������-����ֵ
	//	connect(d_crossPicker, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
	//	d_crossPicker->setEnabled(mode);
	//	d_crossPicker->setTrackerMode(QwtPicker::ActiveOnly);
	//}
	////ֹͣ������
	//else
	//{

	//	//d_rectPicker->setEnabled(false);
	//	//d_rectPicker->reset();//״̬�����reset the state machine and terminate ( end(false) ) the selection
	//	//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
	//	//d_rectPicker->remove();
	//	//d_rectPicker->end(false);
	//	d_crossPicker->setTrackerMode(QwtPicker::AlwaysOff);
	//}




	//����������
	if (mode)
	{
		//ƽ��������
		d_crossPicker_1 = new CrossPicker(d_plot->canvas);
		connect(d_crossPicker_1, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
		//ƽ��������
		d_crossPicker_2 = new CrossPicker(d_plot->canvas);
		d_crossPicker_2->setRubberBandPen(QPen(Qt::blue));
		connect(d_crossPicker_2, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));

		d_crossPicker_1->setEnabled(true);
		d_crossPicker_2->setEnabled(false);
		d_crossPicker_1->setTrackerMode(QwtPicker::ActiveOnly);
		d_crossPicker_2->setTrackerMode(QwtPicker::AlwaysOff);

	}
	//ֹͣ������
	else
	{
		//d_parallelLinePicker_1->setEnabled(false);
		//d_parallelLinePicker_2->setEnabled(false);
		//d_parallelLinePicker_1->reset();
		//d_parallelLinePicker_2->reset();
		d_crossPicker_1->setTrackerMode(QwtPicker::AlwaysOff);
		d_crossPicker_2->setTrackerMode(QwtPicker::AlwaysOff);
	}
}
/**
* @brief ��ʾ���ָ��ĵ����ֵ
*/
void PlotWidget::enableViewTrueValueMode2(bool mode)
{

	d_plot->enableViewTrueValue2(mode);
}

///**
//* @brief ���������¼�
//*/
//void PlotWidget::on_rectBtn_toggled(bool mode)
//{
//
//	enableRectBtn(mode);
//}


/**
* @brief ���þ�������
*/
void PlotWidget::enableEllipseBtn(bool mode)
{
	//����������
	if (mode)
	{
		//��Բ��
		d_ellipsePicker = new EllipsePicker(d_plot->canvas);
		//��������-����ֵ
		connect(d_ellipsePicker, SIGNAL(selected(QRectF)), this, SLOT(selectedEllipsePickerSlot(QRectF)));
		d_ellipsePicker->setEnabled(mode);
		d_ellipsePicker->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//ֹͣ������
	else
	{

		//d_rectPicker->setEnabled(false);
		//d_rectPicker->reset();//״̬�����reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_ellipsePicker->setTrackerMode(QwtPicker::AlwaysOff);
	}
}

/**
* @brief ���ö��������
*/
void PlotWidget::enablePolygonBtn(bool mode)
{
	//����������
	if (mode)
	{
		//�����
		d_polygonPicker = new PolygonPicker(d_plot->canvas);
		//��������-����ֵ
		connect(d_polygonPicker, SIGNAL(selected(QVector<QPointF>)), this, SLOT(selectedPolygonPickerSlot(QVector<QPointF>)));
		d_polygonPicker->setEnabled(mode);
		d_polygonPicker->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//ֹͣ������
	else
	{

		//d_rectPicker->setEnabled(false);
		//d_rectPicker->reset();//״̬�����reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_polygonPicker->setTrackerMode(QwtPicker::AlwaysOff);
	}
}

/**
* @brief ���þ�������
*/
void PlotWidget::enableRectBtn(bool mode)
{
	//����������
	if (mode)
	{
		//����
		d_rectPicker = new RectPicker(d_plot->canvas);
		//��������-����ֵ
		connect(d_rectPicker, SIGNAL(selected(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));
		d_rectPicker->setEnabled(mode);
		d_rectPicker->setTrackerMode(QwtPicker::ActiveOnly);

	}
	//ֹͣ������
	else
	{

		//d_rectPicker->setEnabled(false);
		//d_rectPicker->reset();//״̬�����reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_rectPicker->setTrackerMode(QwtPicker::AlwaysOff);
	}
	//��ʱ������
	//d_plot->enableRectPicker(mode);
}
/**
* @brief ����ƽ��������
*/
void PlotWidget::enableParallelLineBtn(bool mode)
{
	//����������
	if (mode)
	{
		//ƽ��������
		d_parallelLinePicker_1 = new ParallelLinePicker(d_plot->canvas);
		connect(d_parallelLinePicker_1, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));
		//ƽ��������
		d_parallelLinePicker_2 = new ParallelLinePicker(d_plot->canvas);
		d_parallelLinePicker_2->setRubberBandPen(QPen(Qt::blue));
		connect(d_parallelLinePicker_2, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));

		d_parallelLinePicker_1->setEnabled(true);
		d_parallelLinePicker_2->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::ActiveOnly);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);

	}
	//ֹͣ������
	else
	{
		//d_parallelLinePicker_1->setEnabled(false);
		//d_parallelLinePicker_2->setEnabled(false);
		//d_parallelLinePicker_1->reset();
		//d_parallelLinePicker_2->reset();
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);
	}
	//��ʱ����
	//d_plot->enableParallelLinePicker(mode);
}

/**
* @brief ����ֵ-����
*/
void PlotWidget::testUpBtnMode(bool mode)
{

	d_plot->setUpBtnMode(mode);

}
/**
* @brief ����ֵ-����
*/
void PlotWidget::testDownBtnMode(bool mode)
{

	d_plot->setDownBtnMode(mode);

}



//��������
void PlotWidget::updateSamples()
{

	//ɢ��ͼģʽ
	if (ui.scatterCheckBox->isChecked())
	{
		updateScatterSamples();
	}
	//ֱ��ͼͳ��ģʽ
	else if (ui.barChatStaticsCheckBox->isChecked())
	{
		updateStaticsSamples();
	}


}

/**
* @brief ����ɢ��ͼͳ������
*/
void PlotWidget::updateScatterSamples()
{
	//ɢ��ͼģʽ
	if (ui.scatterCheckBox->isChecked())
	{

		QPolygonF samples;

		//bllDataCenter.getCellData(false);//��ȡϸ�����ݣ�����ջ���
		//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
		//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);

		//bllDataCenter.getCellDataVector(origialDataList,logDataList);//�������µ����ݸ���ǰplot
		QVector<double>* vectorX;
		QVector<double>* vectorY;
		//��Ϊ��log�����ᣬ������������ֻ����ԭ���ݼ��ɣ������ж�Log�ˡ�
		int m = ui.passageXCombox->currentData().toInt();
		int n = ui.dataUnitXCombox->currentData().toInt();
		vectorX = origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		vectorY = origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

		//if (ui.logCheckBox->isChecked())//������ʾlog��
		//{

		//	vectorX = logDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		//	vectorY = logDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

		//}
		//else
		//{
		//	vectorX = origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		//	vectorY = origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());
		//}
		d_plot->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());
		//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
		d_plot->replot();
	}
}
/**
* @brief ����ֱ��ͼͳ������
*/
void PlotWidget::updateStaticsSamples()
{
	if (ui.barChatStaticsCheckBox->isChecked())
	{
		dataMutex.lock();
		QVector<double> barChartDataVector;
		QVector<double> xIndexVectorLog;//logֵx������
		QVector<double> xIndexVectorOri;//ԭֵx������

		//ѡ��ͨ�������ݵ�Ԫ����
		QVector<BarStruct>* vecotrData = barStructList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());
		for (int i = 0; i < vecotrData->size(); i++)
		{
			barChartDataVector.append(vecotrData->at(i).m_value);
			//barChartDataVector.append(0);//�ø���ֵΪ0��͹������
			//xIndexVectorLog.append(vecotrData->at(i).m_index);
			xIndexVectorOri.append(vecotrData->at(i).m_index);
			//xIndexVectorOri.append(qPow(10,vecotrData->at(i).m_index));//���logֵ����ָ���õ�ԭ��

			//xIndexVector.append(vecotrData->at(i).m_index+10/256/2);//�ø���ֵ������Ϊ�м�����0.05
		}
		//ȫ������Դ����
		//��Ϊ��log�����ᣬ������������ֻ����ԭ���ݼ��ɣ������ж�Log�ˡ�
		d_plot->setSamples(xIndexVectorOri, barChartDataVector);
		//���ѡ��logģʽ
		/*if (ui.logCheckBox->isChecked())
		{
		d_plot->setSamples(xIndexVectorOri, barChartDataVector);
		}
		else
		{
			d_plot->setSamples(xIndexVectorOri, barChartDataVector);
		}*/
		
		dataMutex.unlock();
		//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
		d_plot->replot(); 
	}
}

/**
* @brief ���²�������
*/
void PlotWidget::updateParamsStatics()
{

}
/**
* @brief ���²���-ϸ������
*/
double PlotWidget::computerEvents()
{
	double events = origialDataList->at(0)->at(0)->size();
	return events;
}
/**
* @brief ���²���-%Parent:��ǰ���ŵ�ϸ����Ŀ��ռ����İٷֱ�
*/
double PlotWidget::computerPercentageParent()
{
	return 0;

}
/**
* @brief ���²���-%Total:��ǰ���ŵ�ϸ����Ŀ��ռԴ����ϸ�������İٷֱ�
*/
double PlotWidget::computerPercentageTotal()
{
	return 0;

}
/**
* @brief ���²���-ƽ��ֵ��x1+x2+x3+...+xn��/n
*/
void PlotWidget::computerAverageValue(QList<QList<double>>& averageList, QList<QList<double>>& midList, QList<QList<double>>& cvList)
{
	int passage = 0;
	int dataUnit = 0;
	double averageValue =0;

	//һ��24��ƽ��ֵ
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			averageValue = 0;//��ʼ����0
			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				averageValue += origialDataList->at(i)->at(j)->at(k);
			}
			//���Ϊ��
			if (origialDataList->at(i)->at(j)->size() != 0)
				averageValue = averageValue / origialDataList->at(i)->at(j)->size();
			else
				averageValue = 0;
			list.append(averageValue);
		}
		
		averageList.append(list);
	}


	double midValue = 0;//�м�ֵ
	//һ��24���м�ֵ
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			QList<double> valueList;//�����Vector���������append�ٶȡ������Ͳ���Ҫ���Ͽ��ٿռ�
			QVector<double> valueVector;
			//memcpy(&valueVector, origialDataList->at(i)->at(j), origialDataList->at(i)->at(j)->size());
			midValue = 0;//��ʼ����0
			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				valueVector.append(origialDataList->at(i)->at(j)->at(k));
			}

			qSort(valueVector.begin(), valueVector.end());
			if (valueVector.size()>0)
			{
				//�����ż����
				if (valueVector.size() % 2 == 0)
				{
					midValue = (valueVector.at(valueVector.size() / 2) + valueVector.at(valueVector.size() / 2 -1))/2;
				}
				//�����������
				else
				{
					midValue = valueVector.at(valueVector.size() / 2 );
				}

			}
				
			else
				midValue = 0;
			list.append(midValue);
		}

		midList.append(list);
	}

	double stdEv = 0;//��׼����
	double cvValue = 0;//CVֵ
	double sum = 0;

	/*
	CV=��/|��|������ ��=�̡�(xi-u)^2/(n-1)��u=(��xi)/n
	���Դ���
	*/
	/*QList<double> testList;
	testList.append(2);
	testList.append(5);
	testList.append(6);
	testList.append(1022);
	testList.append(80);
	testList.append(30);
	testList.append(26);
	testList.append(27);
	double uTest = 0;
	double bTest = 0;
	double cvTest = 0;
	for (int i = 0; i < testList.size(); i++)
	{
		uTest += testList.at(i);
	}
	uTest = uTest / testList.size();
	for (int i = 0; i < testList.size(); i++)
	{
		bTest = bTest + (testList.at(i) - uTest)*(testList.at(i) - uTest);
	}
	bTest = bTest / (testList.size() - 1);
	bTest = qSqrt(bTest);
	cvTest = bTest / qAbs(uTest);*/

	//һ��24��CVֵ
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			double average = averageList.at(i).at(j);
			sum = 0;//��ʼ����0
			stdEv = 0;//��ʼ����0
			cvValue = 0;//��ʼ����0

			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				double diff = qAbs(origialDataList->at(i)->at(j)->at(k) - average);
				sum = sum+ diff*diff;//�ۼ�����ƽ����
			}
			//���Ϊ��
			if (origialDataList->at(i)->at(j)->size() != 0)
			{
				sum = sum / (origialDataList->at(i)->at(j)->size() - 1);//
				stdEv = qSqrt(sum);//��׼����
				cvValue = stdEv / averageList.at(i).at(j);
				
			}
			else
			{
				cvValue = 0;
			}
				list.append(cvValue);
		}

		cvList.append(list);

	}





}
/**
* @brief ���²���-�м�ֵ��������м��ֵ��
*/
double PlotWidget::computerMidValue()
{
	return 0;

}
/**
* @brief ���²���-����ϵ�� CV(Coefficient of Variance):��׼�����ֵ�ı���
*CV=��/|��|������ ��=�̡�(xi-u)^2/(n-1)��u=(��xi)/n
*/
double PlotWidget::computerCvValue()
{
	
	return 0;

}



/**
* @brief ���plot������
*
*/
void PlotWidget::clearPlotSamples()
{
	dataMutex.lock();

	//��ʼ���û�ͼ�����ݽṹ
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			origialDataList->at(i)->at(j)->clear();
			logDataList->at(i)->at(j)->clear();
			for (int k = 0; k < condition; k++)
			{
				BarStruct barstruct = barStructList->at(i)->at(j)->at(k);
				barstruct.m_value = 0;

				barStructList->at(i)->at(j)->replace(k, barstruct);
			}

		}

	}
	dataMutex.unlock();
	updateSamples();
}

/**
* @brief ѡ���ʮ������
*
*/
void PlotWidget::selectedCrossPickerSlot(QPointF pointf)
{
	//�Ƿ��д��ڵĵ�
	for (int i = 0; i < crossPickerList.size(); i++)
	{
		if (pointf == crossPickerList.at(i))
		{
			return;
		}
		else
		{
			crossPickerList.append(pointf);
			break;
		}
	}
	//�޵�
	if (crossPickerList.size() == 0)
	{
		crossPickerList.append(pointf);
	}
	//�Ѿ���һ����
	if (crossPickerList.size() == 1)
	{
		//d_parallelLinePicker_1->setEnabled(false);
		d_crossPicker_1->setTrackerMode(QwtPicker::AlwaysOff);

		d_crossPicker_2->setEnabled(true);
		d_crossPicker_2->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//�Ѿ���2����
	if (crossPickerList.size() >= 2)
	{

		//emit selectedParallelLinePicker(parallelLineList);
		//�޸Ĵ�
		selectedCrossPickerSlot(crossPickerList);
	}

	
}
/**
* @brief ѡ���ʮ������
*
*/
void PlotWidget::selectedCrossPickerSlot(QList<QPointF> crossPickerList)
{
	//�������Ŵ���
	computeCrossPickerSlot(crossPickerList);
}
/**
* @brief ��������
*
*/
void PlotWidget::selectedRectPickerSlot(QRectF rectf1)
{
	QRectF rectf = rectf1;
	//�������Ŵ���
	computeRectPickerSlot(rectf);
	
}

/**
* @brief ƽ��������,�ж��Ƿ���������
*
*/
void PlotWidget::selectedParallelLinePickerSlot(QPointF pointf)
{
	//�Ƿ��д��ڵĵ�
	for (int i = 0; i < parallelLineList.size(); i++)
	{
		if (pointf == parallelLineList.at(i))
		{
			return;
		}
		else
		{
			parallelLineList.append(pointf);
			break;
		}
	}
	//�޵�
	if (parallelLineList.size() == 0)
	{
		parallelLineList.append(pointf);
	}
	//�Ѿ���һ����
	if (parallelLineList.size() == 1)
	{
		//d_parallelLinePicker_1->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);

		d_parallelLinePicker_2->setEnabled(true);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//�Ѿ���2����
	if (parallelLineList.size() >= 2)
	{
		
		//emit selectedParallelLinePicker(parallelLineList);
		//�޸Ĵ�
		selectedParallelLinePickerSlot(parallelLineList);
	}

}
/**
* @brief ƽ��������
*
*/
void PlotWidget::selectedParallelLinePickerSlot(QList<QPointF> pointFList)
{

	computeParallelLinePickerSlot(pointFList);
}

/**
* @brief ��Բ����
*
*/
void PlotWidget::selectedEllipsePickerSlot(QRectF rectf1)
{
	QRectF rectf = rectf1;
	//�������Ŵ���
	computeEllipsePickerSlot(rectf);

}

/**
* @brief ���������
*
*/
void PlotWidget::selectedPolygonPickerSlot(QVector<QPointF> vector1)
{
	QVector<QPointF> vector = vector1;
	//�������Ŵ���
	computePolygonPickerSlot(vector);

}


/**
* @brief ��ȡ����ؼ���״̬
*/
QMap<QString, int>  PlotWidget::getStatusControl()
{
	QMap<QString, int> map;
	int passageYCombox = ui.passageYCombox->currentData().toInt();
	int dataUnitYCombox = ui.dataUnitYCombox->currentData().toInt();
	int passageXCombox = ui.passageXCombox->currentData().toInt();
	int dataUnitXCombox = ui.dataUnitXCombox->currentData().toInt();
	int gridCheckBox = ui.gridCheckBox->isChecked();
	int logCheckBox = ui.logCheckBox->isChecked();
	int scatterCheckBox = ui.scatterCheckBox->isChecked();
	int barChatStaticsCheckBox = ui.barChatStaticsCheckBox->isChecked();
	map.insert("passageYCombox", passageYCombox);
	map.insert("dataUnitYCombox", dataUnitYCombox);
	map.insert("passageXCombox", passageXCombox);
	map.insert("dataUnitXCombox", dataUnitXCombox);
	map.insert("gridCheckBox", gridCheckBox);
	map.insert("logCheckBox", logCheckBox);
	map.insert("scatterCheckBox", scatterCheckBox);
	map.insert("barChatStaticsCheckBox", barChatStaticsCheckBox);
	return map;
}
/**
* @brief ���ý���ؼ���״̬
*/
void PlotWidget::setStatusControl(QMap<QString,int> map)
{
	//����Yͨ��
	int index = ui.passageYCombox->findData(map.value("passageYCombox"));
	ui.passageYCombox->setCurrentIndex(index);
	setPassage(ui.passageYCombox->currentData().toInt());//������ʾ��ǰͨ������

	//����Yͨ�����ݵ�Ԫ
	index = ui.dataUnitYCombox->findData(map.value("dataUnitYCombox"));
	ui.dataUnitYCombox->setCurrentIndex(index);
	setDataUnit(ui.dataUnitYCombox->currentData().toInt());//������ʾ��ǰͨ����ǰ��������



	//����Xͨ��
	index = ui.passageXCombox->findData(map.value("passageXCombox"));
	ui.passageXCombox->setCurrentIndex(index);
	setPassage(ui.passageYCombox->currentData().toInt());//������ʾ��ǰͨ������

	//����Xͨ�����ݵ�Ԫ
	index = ui.dataUnitXCombox->findData(map.value("dataUnitXCombox"));
	ui.dataUnitXCombox->setCurrentIndex(index);
	setDataUnit(ui.dataUnitYCombox->currentData().toInt());//������ʾ��ǰͨ����ǰ��������

	//���ñ���������
	ui.gridCheckBox->setChecked(map.value("gridCheckBox"));
	setGridEnable(map.value("gridCheckBox"));

	//����log״̬
	ui.logCheckBox->setChecked(map.value("logCheckBox"));
	setLogEnable(map.value("logCheckBox"));
	//����ɢ��ͼ״̬
	ui.scatterCheckBox->setChecked(map.value("scatterCheckBox"));
	setScatterMode(map.value("scatterCheckBox"));
	//����ֱ��ͼ״̬
	ui.barChatStaticsCheckBox->setChecked(map.value("barChatStaticsCheckBox"));
	setBarStatisticsMode(map.value("barChatStaticsCheckBox"));

}
/**
* @brief �������
*/
void PlotWidget::addGate(GateStorage::GateType type)
{
	GateStorage* gateStorage = new GateStorage();
	gateStorage->setParentWidget((QObject*)this);//��ǰ������
	gateStorage->setPlotWidget(d_plotWidgetGate);//���������ɵĴ���
	gateStorage->setGatePointer(d_rectPicker);//��ǰ����ָ��
	gateStorage->setGateName(QString("P%1").arg(ViewWidget::m_plotWidgetList.size() + 1));//��������
	QString title;
	PlotWidget* plotwidget = (PlotWidget*)gateStorage->getParentWidget();
	if (gateStorage->getParentWidget() != 0)
		title = QString("%1-%2").arg(plotwidget->getTitle()).arg(gateStorage->getGateName());
	//�������Ŵ��ڵĻ�������
	d_plotWidgetGate->setTitle(title);
	gateStorage->setGateType(type);//��������
	m_gateStorageList.append(gateStorage);//�������

	emit addGateSignal((QWidget*)d_plotWidgetGate);
}


/**
* @brief ɾ��ָ������
*/
void PlotWidget::deleteGate(GateStorage* gateStorage)
{
	for (int i = 0; i < m_gateStorageList.size(); i++)
	{
		GateStorage* gate = m_gateStorageList.at(i);
		//�ҵ�����
		if (gate == gateStorage)
		{
			//��������
			GateStorage::GateType m_gateType = gate->getGateType();
			//��������
			if (m_gateType == GateStorage::RECT)
			{
				RectPicker* rectPicker = (RectPicker*)gate->getGatePointer();
				rectPicker->setEnabled(false);
				delete rectPicker;
			}
			//ƽ��������
			else if (m_gateType == GateStorage::PARALLEL)
			{
				ParallelLinePicker* parallLinePicker = (ParallelLinePicker*)gate->getGatePointer();
				parallLinePicker->setEnabled(false);
				delete parallLinePicker;
			}
			//��������ɾ��������
			m_gateStorageList.removeAt(i);
		}
	}
	
}
/**
* @brief ���ݾ���ɸѡ
*
*/
void PlotWidget::computeRectPickerSlot(QRectF rectf)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
	QPointF topLeft = rectf.topLeft();
	QPointF bottomRight = rectf.bottomRight();

	double top = rectf.top();
	double left = rectf.left();
	double right = rectf.right();
	double bottom = rectf.bottom();
	d_plotWidgetGate = new PlotWidget();//��plot����

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//X���Y��Ӧ����ͬһ��ͨ���Ĳ�������
	for (int i = 0; i < vectorY->size(); i++)
	{
		if (rectf.contains(vectorX->at(i), vectorY->at(i)))
		{
			indexVector.append(i);
		}
		////���Y�����ھ�����
		//if (vectorY->at(i) >= topLeft.y() && vectorY->at(i) <= bottomRight.y())
		//{
		//	//�Ƚ�X����
		//	for (int j = 0; j < vectorX->size(); j++)
		//	{
		//		//���X�����ھ�����
		//		if (vectorX->at(j) <= bottomRight.x() && vectorX->at(j) >= topLeft.x())
		//			indexVector.append(j);
		//	}
		//}

	}
	//�����������´���
	copyData(indexVector);
	//���ݿؼ�״̬����
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//�������������
	addGate(GateStorage::RECT);
	//�����������
	//enableRectBtn(false);
	//�ü�
	ui.rectBtn->setChecked(false);//���Զ����òۺ���enableRectBtn(false);
}

/**
* @brief ����ʮ����ɸѡ
*
*/
void PlotWidget::computeCrossPickerSlot(QList<QPointF> pointFList)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);


	QPointF pointF1 = pointFList.at(0);
	QPointF pointF2 = pointFList.at(1);
	const QRectF rectf = QRectF(pointF1, pointF2).normalized();

	double top = rectf.top();
	double left = rectf.left();
	double right = rectf.right();
	double bottom = rectf.bottom();
	d_plotWidgetGate = new PlotWidget();//��plot����

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//X���Y��Ӧ����ͬһ��ͨ���Ĳ�������
	for (int i = 0; i < vectorY->size(); i++)
	{
		if (rectf.contains(vectorX->at(i), vectorY->at(i)))
		{
			indexVector.append(i);
		}
	}
	//�����������´���
	copyData(indexVector);
	//���ݿؼ�״̬����
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//�������������
	addGate(GateStorage::CROSS);
	//�����������
	//enableRectBtn(false);

	//�ü�
	ui.crossBtn->setChecked(false);//���Զ����òۺ���enableCrossBtn(false);
}
//void PlotWidget::computeCrossPickerSlot(QPointF pointF)
//{
//	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
//	double x = pointF.x();
//	double y = pointF.y();//��ǰ���ĵ������
//
//	
//
//	int passageY = ui.passageYCombox->currentData().toInt();
//	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
//	int passageX = ui.passageXCombox->currentData().toInt();
//	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();
//
//	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
//	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);
//
//	QList<QVector<int>> indexVectorList;
//	QVector<int> indexVector1;//�ĸ�����
//	QVector<int> indexVector2;
//	QVector<int> indexVector3;
//	QVector<int> indexVector4;
//	//�ж���������
//	for (int i = 0; i < vectorY->size(); i++)
//	{
//		if (vectorX->at(i) < x)
//		{
//			if (vectorY->at(i) < y)
//			{
//				indexVector2.append(i);//�ڶ�����
//			}
//			else if (vectorY->at(i) >= y)
//			{
//				indexVector1.append(i);//��һ����
//			}
//		}
//		else if (vectorX->at(i) >= x)
//		{
//			if (vectorY->at(i) < y)
//			{
//				indexVector3.append(i);//��������
//			}
//			else if (vectorY->at(i) >= y)
//			{
//				indexVector4.append(i);//��������
//			}
//		}
//
//	}
//	indexVectorList.append(indexVector1);
//	indexVectorList.append(indexVector2);
//	indexVectorList.append(indexVector3);
//	indexVectorList.append(indexVector4);
//
//	for (int i = 0; i < 4; i++)
//	{
//		d_plotWidgetGate = new PlotWidget();//��plot����
//		//�����������´���
//		copyData(indexVectorList.at(i));
//		//���ݿؼ�״̬����
//		d_plotWidgetGate->setStatusControl(getStatusControl());
//
//		d_plotWidgetGate->show();
//		d_plotWidgetGate->updateSamples();
//
//		//�������������
//		addGate(GateStorage::CROSS);
//	}
//
//	
//	//�ü�
//	ui.crossBtn->setChecked(false);//���Զ����òۺ���enableCrossBtn(false);
//}
/**
* @brief ���ݶ����ɸѡ
*
*/
void PlotWidget::computePolygonPickerSlot(QVector<QPointF> vector)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
	
	d_plotWidgetGate = new PlotWidget();//��plot����

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;


	int polySides = vector.size();//�ܹ�����
	float* polyX = new float[polySides];
	float* polyY = new float[polySides];
	//�����㸳ֵ
	for (int i = 0; i < polySides; i++)
	{
		polyX[i] = vector.at(i).x();
		polyY[i] = vector.at(i).y();
	}

	//X���Y��Ӧ����ͬһ��ͨ���Ĳ�������
	for (int i = 0; i < vectorY->size(); i++)
	{
		QPointF pointF(vectorX->at(i), vectorY->at(i));
		if (pointInPolygon(pointF,polyX, polyY, polySides))
			indexVector.append(i);
	}



	//�����������´���
	copyData(indexVector);
	//���ݿؼ�״̬����
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//�������������
	addGate(GateStorage::POLYGON);
	//�����������
	//enableRectBtn(false);
	//�ü�
	ui.polygonBtn->setChecked(false);//���Զ����òۺ���enablePolygonBtn(false);

	delete[] polyX;//�ͷ�
	delete[] polyY;
}

/**
* @brief �жϵ��Ƿ��ڶ�����ڲ�
* @param QPointF ��ǰ��
* @param float* polyX ����ζ���X����
* @param float* polyY ����ζ���Y����
* @param int polySides ����ζ�����
*/
bool PlotWidget::pointInPolygon(QPointF pointF, float* polyX, float* polyY,int polySides)
{
	// Globals which should be set before calling this function:  
	//  
	// int    polySides  =  how many cornersthe polygon has  
	// float  polyX[]    =  horizontal coordinates of corners  
	// float  polyY[]    =  vertical coordinates of corners  
	// float  x,y       =  point to be tested  
	//  
	// (Globals are used in this example for purposes of speed.  Change as  
	// desired.)  
	//  
	//  Thefunction will return YES if the point x,y is inside the polygon, or  
	//  NOif it is not.  If the point is exactly on the edge of the polygon,  
	// then the function may return YES or NO.  
	//  
	// Note that division by zero is avoided because the division is protected  
	//  bythe "if" clause which surrounds it.
	double x = pointF.x();
	double y = pointF.y();

	int   i, j = polySides - 1;
	bool  oddNodes = false;

	for (i = 0; i < polySides; i++) {
		if ((polyY[i] < y && polyY[j] >= y
			|| polyY[j] < y && polyY[i] >= y)
			&& (polyX[i] <= x || polyX[j] <= x)) {
			oddNodes ^= (polyX[i] + (y - polyY[i]) / (polyY[j] - polyY[i])*(polyX[j] - polyX[i]) < x);
		}
		j = i;
	}

	return oddNodes;
}
/**
* @brief �����������¿ؼ�
*/
void PlotWidget::copyData(QVector<int> indexVector)
{
	//��������
	for (int t = 0; t < indexVector.size(); t++)
	{
		//8��ͨ��
		for (int i = 0; i < origialDataList->size(); i++)
		{
			QList < QVector<double>* > * list1 = d_plotWidgetGate->origialDataList->at(i);//ԭʼ����
			QList < QVector<double>* > * list2 = d_plotWidgetGate->logDataList->at(i);//log����
			QList < QVector<BarStruct>* >* list3 = d_plotWidgetGate->barStructList->at(i);//��������
			//3�����
			for (int j = 0; j < 3; j++)
			{
				QVector<double>* vector1 = list1->at(j);//ԭʼ����
				QVector<double>* vector2 = list2->at(j);//log����
				QVector<BarStruct>* vector3 = list3->at(j);//��������
				vector1->append(origialDataList->at(i)->at(j)->at(indexVector.at(t)));//����ԭʼ����
				vector2->append(logDataList->at(i)->at(j)->at(indexVector.at(t)));//����log����
				//vector3->append(barStructList->at(i)->at(j)->at(indexVector.at(t)));//����Ҫ������ÿ�ε�����������µ�������
			}
		}

	}
}
/**
* @brief ����ƽ����ɸѡ
*
*/
void PlotWidget::computeParallelLinePickerSlot(QList<QPointF> pointFList)
{
	QPointF pointF1 = pointFList.at(0);
	QPointF pointF2 = pointFList.at(1);
	d_plotWidgetGate = new PlotWidget();//��plot����

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//Y�ᵱǰͨ���͵�ǰ�Ĳ���
	for (int i = 0; i < vectorY->size(); i++)
	{
		if (vectorY->at(i) >= pointF1.x() && vectorY->at(i) <= pointF2.x())
		{
			indexVector.append(i);
		}
		
	}

	//�����������´���
	copyData(indexVector);
	//���ݿؼ�״̬����
	d_plotWidgetGate->setStatusControl(getStatusControl());
	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//�������������
	addGate(GateStorage::PARALLEL);
	//ƽ�����������
	//enableParallelLineBtn(false);
	ui.parallelLineBtn->setChecked(false);//���Զ����òۺ���enableParallelLineBtn(false);
}


/**
* @brief ������Բɸѡ
*
* ������Բ�� ��Բ���̣�x-p��^2/(a*a)+(y-q)^2/(b*b)=1 ԭ���� ֻ��Ҫ���� �жϣ�x-p��^2/(a*a)+(y-q)^2/(b*b����1�ͺ���

* ���������˳����ܲ�ˬ �����жϣ�x-p��^2*(b*b)+(y-q)^2*(a*a����a*a*b*b
*/
void PlotWidget::computeEllipsePickerSlot(QRectF rectf)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
	

	d_plotWidgetGate = new PlotWidget();//��plot����

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();


	
	QPointF topLeft = rectf.topLeft();
	QPointF topRight = rectf.topRight();
	QPointF bottomLeft = rectf.bottomLeft();
	QPointF bottomRight = rectf.bottomRight();

	double top = rectf.top();
	double left = rectf.left();
	double right = rectf.right();
	double bottom = rectf.bottom();

	

	/*top = qPow(10, top);
	left = qPow(10, left);
	right = qPow(10, right);
	bottom = qPow(10, bottom);*/

	
	QVector<double>* vectorY;
	QVector<double>* vectorX;
	//�����logģʽ
	if (ui.logCheckBox->isChecked())
	{
		//ȡlogֵ
		vectorY = logDataList->at(passageY)->at(dataUnitY);
		vectorX = logDataList->at(passageX)->at(dataUnitX);
		//ȡ��Բlog����
		top = qLn(top) / qLn(10);
		left = qLn(left) / qLn(10);
		right = qLn(right) / qLn(10);
		bottom = qLn(bottom) / qLn(10);

	}
	else if (ui.scatterCheckBox->isChecked())
	{
		//ȡԭֵ
		vectorY = origialDataList->at(passageY)->at(dataUnitY);
		vectorX = origialDataList->at(passageX)->at(dataUnitX);
	}
	//������Բ����
	double a = qFabs(right - left) / 2;
	double b = qFabs(top - bottom) / 2;
	double p = (right + left) / 2;//����x����
	double q = (top + bottom) / 2;//����y����
	qDebug() << QString("����(%1,%2)������a:%3,�߶�b:%4").arg(p).arg(q).arg(a).arg(b);

	QVector<int> indexVector;
	//ɸѡ����
	//X���Y��Ӧ����ͬһ����ű�ǩ�Ĳ�������
	for (int i = 0; i < vectorY->size(); i++)
	{

		//�Ƚ�X����
		QPointF pointF(vectorX->at(i), vectorY->at(i));
		//���(x,y)�����ھ�����
		/*if(((pointF.x() - p)*(pointF.x() - p)*(b*b) + (pointF.y() - q)*(pointF.y() - q)*(a*a)) <= a*a*b*b)
			indexVector.append(i);*/
		if (((pointF.x() - p)*(pointF.x() - p)/(a*a) + (pointF.y() - q)*(pointF.y() - q)/(b*b)) <= 1)
			indexVector.append(i);

		/*if (pointF.y()>top && pointF.y()<bottom)
			indexVector.append(i);*/

	}


	//�����������´���
	copyData(indexVector);
	//���ݿؼ�״̬����
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//�������������
	addGate(GateStorage::ELLIPSE);
	//�����������
	//enableRectBtn(false);
	//�ü�
	ui.ellipseBtn->setChecked(false);//���Զ����òۺ���enableRectBtn(false);
}
/**
* @brief �����ļ�
* @param QString:�ļ�����
*/
void PlotWidget::saveExpFileSlot(QString fileName,QString fileType)
{
	if (fileType == "usb")
		saveUSBFile(fileName);
	else if (fileType == "fcm")
		saveFcmFile(fileName);
	else if (fileType == "fcs")
		saveFCSFile(fileName);
}
/**
* @brief ����USB��ʽ�ļ�
* @param QString �ļ����ƣ�QString:�ļ�����
*/
void PlotWidget::saveUSBFile(QString fileName)
{
	
}
/**
* @brief ����FCM/MatLab��ʽ�ļ�
* @param QString �ļ����ƣ�QString:�ļ�����
*/
void PlotWidget::saveFcmFile(QString fileName)
{
	FILE *stream;
	int err;
	int numwritten;

	QByteArray pathByteArray = fileName.toLocal8Bit();
	if ((stream = fopen(pathByteArray.data(), "wb")) != NULL)
	{
		int m = origialDataList->at(0)->at(0)->size();
		int n = origialDataList->at(0)->size();
		int t = origialDataList->size();
		//n��ϸ��
		for (int i = 0; i < origialDataList->at(0)->at(0)->size(); i++)
		{
			//8��ͨ��
			for (int j = 0; j < origialDataList->size(); j++)
			{
				//3�����
				double valueHH = origialDataList->at(j)->at(0)->at(i);
				double valueAA = origialDataList->at(j)->at(1)->at(i);
				double valueWW = origialDataList->at(j)->at(2)->at(i);



				valueAA = valueAA + 32768 * valueWW;
				valueHH = valueHH + 32768 * 8;

				qint32 valueAAInt = valueAA;
				qint32 valueHHInt = valueHH;
				qint32 valueWWInt = valueWW;


				//numwritten = fwrite(&valueAAInt, sizeof(qint32), 1, stream);//����˳��
				numwritten = fwrite(&valueHHInt, sizeof(qint32), 1, stream);//��ȷ˳��HH\AA\WW
				numwritten = fwrite(&valueAAInt, sizeof(qint32), 1, stream);
				numwritten = fwrite(&valueWWInt, sizeof(qint32), 1, stream);


			}

			qDebug() << "��PlotWidget�� �����ļ��ɹ�:" << fileName;
		}

		//�ر��ļ�
		if (stream)
		{
			if (fclose(stream))
			{
				qDebug() << "��PlotWidget���ļ��ر�ʧ��:" << fileName;
			}
		}
	}
}
/**
* @brief ����FCS��׼��ʽ�ļ�
* @param QString �ļ����ƣ�QString:�ļ�����
*/
void PlotWidget::saveFCSFile(QString fileName)
{

}
/**
* @brief һ����ͳ��ֱ��ͼ
* @param passageͨ��
* @param dataUnit���ݵ�Ԫ
*/ 
void PlotWidget::statisticsHistogram(int passage,int dataUnit)
{

	dataMutex.lock();
	int i = passage;//��i��ͨ��
	int j = dataUnit;//��j�����
	QVector<double>* originalList = origialDataList->at(i)->at(j);//ԭʼ����
	QVector<BarStruct>* barList = barStructList->at(i)->at(j);//��������
		//��Դ����ɸѡһ��
	for (int m = 0; m < originalList->size(); m++)
	{

		double value = originalList->at(m);//ԭֵ���㷶Χ1024�鲻��ϸ
		int start = 0;
		int end = barList->size()-1;
		int mid = start+ (end - start) / 2;
		while (mid > 0)//���ֲ���
		{
			BarStruct barStruct = barList->at(mid);
			if (value >= barStruct.m_point.x())
			{
				if (value < barStruct.m_point.y())
				{
					barStruct.m_value++;
					barList->replace(mid, barStruct);
					break;
				}
				else
				{
					start = mid;
				}
			}
			else if(value < barStruct.m_point.x())
			{
				end = mid;
			}
			mid = start + (end - start) / 2;
				
		}
			
	}
	dataMutex.unlock();

}

/**
* @brief ��ոô�����������-�ָ�������
*/
void PlotWidget::unistall()
{

	if (d_rectPicker != 0)
	{
		delete d_rectPicker;
		d_rectPicker = 0;
	}
	if (d_parallelLinePicker_1 != 0)
	{
		delete d_parallelLinePicker_1;
		d_parallelLinePicker_1 = 0;
	}
	if (d_parallelLinePicker_2 != 0)
	{
		delete d_parallelLinePicker_2;
		d_parallelLinePicker_2 = 0;
	}
	parallelLineList.clear();
	if (d_ellipsePicker != 0)
	{
		delete d_ellipsePicker;
		d_ellipsePicker = 0;
	}
	if (d_crossPicker_1 != 0)
	{
		delete d_crossPicker_1;
		d_crossPicker_1 = 0;
	}
	if (d_crossPicker_2 != 0)
	{
		delete d_crossPicker_2;
		d_crossPicker_2 = 0;
	}
	crossPickerList.clear();
	if (d_polygonPicker != 0)
	{
		delete d_polygonPicker;
		d_polygonPicker = 0;
	}
	//������Ŵ��ڹ�ϵ
	m_gateStorageList.clear();
	//��ջ������ݣ����»�ͼ
	clearPlotSamples();


	//reportTree->updateReport();//���±������
}
/**
* @brief ���û�������
*/
void PlotWidget::setTitle(QString title)
{
	d_plot->setTitle(title);
}
/**
* @brief ���û�������
*/
QString PlotWidget::getTitle()
{
	return d_plot->title().text();
}
