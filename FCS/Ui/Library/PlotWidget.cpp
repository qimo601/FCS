#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
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
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), d_plot, SLOT(setGridEnable(bool)));
	//�����Ƿ���ʾlogֵ
	connect(ui.logCheckBox, SIGNAL(clicked(bool)), this, SLOT(setLogEnable(bool)));
	//���÷Ŵ�/��С��ť��ѡ��
	ui.zoomerBtn->setCheckable(true);
	//���÷Ŵ���С�����Ƿ�����
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enableZoomMode(bool)));
	//����ƽ�ư�ť��ѡ��
	ui.pannerBtn->setCheckable(true);
	//����ƽ�ư�ť�����Ƿ�����
	connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enablePannerMode(bool)));
	//ͨ��ֵѡ��
	connect(ui.passageXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setPassage(int)));
	//���ݵ�Ԫ����ѡ��
	connect(ui.dataUnitXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataUnit(int)));
	//��󻯴���
	connect(ui.maximizedBtn, SIGNAL(clicked()), this, SLOT(maximizedPlotWidget()));
	//��ԭ����
	connect(ui.normalBtn, SIGNAL(clicked()), this, SLOT(normalPlotWidget()));
	
	m_timerId = 0;//��ʼ��
	//m_timerId = startTimer(10);//���Կ�ʼ��ʵʱ��ʾ

	this->setFocusPolicy(Qt::ClickFocus);
	parent = 0;
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
	//��ʼ���û�ͼ�����ݽṹ
	origialDataList = new QList < QList < QVector<double>* >*  >();//����������ԭʼ����
	logDataList = new QList < QList < QVector<double>* >*  >();//����������logֵ
	for (int i = 0; i < 8; i++)
	{
		QList < QVector<double>* >* list = new QList < QVector<double>* >();
		origialDataList->append(list);
		QList < QVector<double>* >* list1 = new QList < QVector<double>* >();
		logDataList->append(list1);
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = new QVector<double>();
			list->append(vector);
			QVector<double>* vector1 = new QVector<double>();
			list1->append(vector1);
		}
	}

	logEnable = false; //Ĭ�ϲ���ʾlog
	//��ʼ������һЩ����
	initUi();
}

/**
* @brief ��ʼ������һЩ����
*/
void PlotWidget::initUi()
{
	//��ʼ��ͨ�������ݵ�Ԫֵ
	for (int i = 0; i < 8; i++)
	{
		ui.passageXCombox->addItem(QString("ͨ��%1").arg(i + 1), i);
		ui.passageYCombox->addItem(QString("ͨ��%1").arg(i + 1), i);
	}
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
	updateSamples();
}
/**
* @brief �������ݵ�Ԫ����
*/
void PlotWidget::setDataUnit(int index)
{
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
void PlotWidget::updateSamples()
{
	QPolygonF samples;

	//bllDataCenter.getCellData(false);//��ȡϸ�����ݣ�����ջ���
	//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);
    
	bllDataCenter.getCellDataVector(origialDataList,logDataList);//�������µ����ݸ���ǰplot
	QVector<double>* vectorX;
	QVector<double>* vectorY;
	
	if (logEnable)//������ʾlog��
	{
		
		vectorX = logDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		vectorY = logDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

	}
	else
	{
		vectorX = origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		vectorY = origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());
	}
	d_plot->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());
	//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
	d_plot->replot();
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
* @brief �������ÿ̶�
*/
void PlotWidget::setAxisScale()
{
	if (logEnable)

	{
		d_plot->setAxisScale(QwtPlot::xBottom, 0, 10);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisScale(QwtPlot::yLeft, 0, 10);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
	}
	else
	{
		d_plot->setAxisScale(QwtPlot::xBottom, 4000000, 6000000);//����x������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
		d_plot->setAxisScale(QwtPlot::yLeft, 4000000, 6000000);//����y������̶ȴ�С,���ֵ����Сֵ���Լ���С�̶�
	}

	d_plot->replot();
}