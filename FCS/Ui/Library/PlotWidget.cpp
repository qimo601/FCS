#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
#include "BarStruct.h"

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
	//ֱ��ͼͳ��
	connect(ui.barChatStaticsCheckBox, SIGNAL(clicked(bool)), this, SLOT(setBarStatisticsMode(bool)));
	//ɢ��ͼͳ��
	connect(ui.scatterCheckBox, SIGNAL(clicked(bool)), this, SLOT(setScatterMode(bool)));
	
	m_timerId = 0;//��ʼ��
	//m_timerId = startTimer(10);//���Կ�ʼ��ʵʱ��ʾ

	this->setFocusPolicy(Qt::ClickFocus);
	parent = 0;

	//����ͳ���߳�
	staticsThread.setDataWidget(this);
	staticsThread.start();
	//��ͳ���̸߳�������
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
	//��ʼ���û�ͼ�����ݽṹ
	origialDataList = new QList < QList < QVector<double>* >*  >();//����������ԭʼ����
	logDataList = new QList < QList < QVector<double>* >*  >();//����������logֵ
	barStructList = new QList < QList < QVector<BarStruct>* >*  >();
	for (int i = 0; i < 8; i++)
	{
		QList < QVector<double>* >* list = new QList < QVector<double>* >();
		origialDataList->append(list);
		QList < QVector<double>* >* list1 = new QList < QVector<double>* >();
		logDataList->append(list1);

		QList<QVector<BarStruct>*>* list2 = new QList<QVector<BarStruct>*>();
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = new QVector<double>();
			list->append(vector);
			QVector<double>* vector1 = new QVector<double>();
			list1->append(vector1);
			//��ʼ��ֱ��ͼ���ݽṹ
			QVector<BarStruct>* vector2 = new QVector<BarStruct>();
			double internal = 10.00 / 100;
			for (int i = 0; i < 100; i++)
			{
				QPointF p(i*internal, (i + 1)*internal);
				BarStruct barStruct1(i*internal, QString("[%1,%2)").arg(i*internal).arg((i + 1)*internal), 0, QColor("DodgerBlue"), QPointF(i*internal, (i + 1)*internal));
				vector2->append(barStruct1);
			}
			list2->append(vector2);//QList����new�ģ�appendֻ�ǿ��������Ա��������append

		}
		barStructList->append(list2);//QList����new�ģ�appendֻ�ǿ��������Ա��������append

	}

	logEnable = false; //Ĭ�ϲ���ʾlog
	//��ʼ������һЩ����
	initUi();
	//��ʼ��bar��������
	initBarData();
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

/**
* @brief ����ֱ��ͼͳ����ʾģʽ
*/
void PlotWidget::setBarStatisticsMode(bool mode)
{
	if (mode)
	{
		//����ͳ��������ʽ
		d_plot->enableStaticsMode();

		//�ֶ�����һ������
		updateStaticsSamples();
		//ֱ��ͼû��x��
		ui.passageXCombox->setEnabled(false);
		ui.dataUnitXCombox->setEnabled(false);
	}
}
/**
* @brief ����ɢ��ͼ��ʾģʽ
*/
void PlotWidget::setScatterMode(bool mode)
{
	if (mode)
	{
		//����ɢ��ͼ��ʽ
		d_plot->enableScatterMode();
		setAxisScale();//�Զ��������꣬�ж��Ƿ���Ҫlog��ʾ
		//�ֶ�����һ������
		updateSamples();

		//ɢ��ͼ��x��
		ui.passageXCombox->setEnabled(true);
		ui.dataUnitXCombox->setEnabled(true);
	}
}
//��������
void PlotWidget::updateSamples()
{


	if (ui.scatterCheckBox->isChecked())
	{
		updateScatterSamples();
	}
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
	QPolygonF samples;

	//bllDataCenter.getCellData(false);//��ȡϸ�����ݣ�����ջ���
	//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);

	//bllDataCenter.getCellDataVector(origialDataList,logDataList);//�������µ����ݸ���ǰplot
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
/**
* @brief ����ֱ��ͼͳ������
*/
void PlotWidget::updateStaticsSamples()
{
	if (ui.barChatStaticsCheckBox->isChecked())
	{
		dataMutex.lock();
		QVector<double> barChartDataVector;
		QVector<double> xIndexVector;

		//ѡ��ͨ�������ݵ�Ԫ����
		QVector<BarStruct>* vecotrData = barStructList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());
		for (int i = 0; i < vecotrData->size(); i++)
		{
			barChartDataVector.append(vecotrData->at(i).m_value);
			xIndexVector.append(vecotrData->at(i).m_index);
		}
		d_plot->setSamples(xIndexVector, barChartDataVector);
		dataMutex.unlock();
		//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
		d_plot->replot();
	}
}