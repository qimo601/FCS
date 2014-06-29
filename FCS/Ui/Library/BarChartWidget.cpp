#include "BarChartWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
#include "Ui/Library/BarChart.h"
#include "BarStruct.h"
BarChartWidget::BarChartWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//细胞绘图控件初始化
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(0);
	vLayoutCellPlotFrame->setContentsMargins(0, 0, 0, 0);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_barChart = new BarChart(ui.cellPlotFrame);
	d_barChart->setObjectName(QStringLiteral("d_barChart"));

	vLayoutCellPlotFrame->addWidget(d_barChart);



	////设置背景线是否显示
	//connect(ui.gridCheckBox, SIGNAL(clicked(bool)), d_barChart, SLOT(setGridEnable(bool)));
	////设置放大/缩小按钮可选择
	//ui.zoomerBtn->setCheckable(true);
	////设置放大缩小功能是否启用
	//connect(ui.zoomerBtn, SIGNAL(toggled(bool)), d_barChart, SLOT(enableZoomMode(bool)));
	////设置平移按钮可选择
	//ui.pannerBtn->setCheckable(true);
	////设置平移按钮功能是否启用
	//connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_barChart, SLOT(enablePannerMode(bool)));

	m_timerId = 0;//初始化

	initBarData();//初始化直方图数据
	staticsThread.setDataWidget(this);
	staticsThread.start();
	//绑定统计信号
	connect(&staticsThread, SIGNAL(staticsFinished()), this, SLOT(updateSamples()));
}

BarChartWidget::~BarChartWidget()
{

}

double BarChartWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}

void BarChartWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	/*if (event->timerId() == m_timerId)
	{
	updateSamples(0);
	}*/
}

void BarChartWidget::startAcqTimer()
{
	//开启定时器
	//m_timerId = startTimer(10);
}
void BarChartWidget::stopAcqTimer()
{
	//关闭定时器
	//killTimer(m_timerId);
}

void BarChartWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}

/**
* @brief 更新数据
*/
void BarChartWidget::updateSamples()
{
	//QPolygonF samples;

	////bllDataCenter.getCellData(false);
	////QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	////QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);
	////d_barChart->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());

	//bllDataCenter.getCellDataVector(origialDataList, logDataList, barStructList);//更新最新的数据给当前plot
	
	/*QVector<double>* vectorX;
	QVector<double>* vectorY;*/
	//if (logEnable)//决定显示log否
	//{

	//	vectorX = logDataList->at(3)->at(1);
	//	vectorY = logDataList->at(3)->at(0);

	//}
	//else
	//{
	//	vectorX = origialDataList->at(3)->at(1);
	//	vectorY = origialDataList->at(3)->at(0);
	//}

	dataMutex.lock();

	QVector<double> barChartDataVector;

	QVector<BarStruct>* vector = barStructList->at(3)->at(0);
	for (int i = 0; i < vector->size(); i++)
		barChartDataVector.append(vector->at(i).m_value);

	d_barChart->setSamples(barChartDataVector);
	dataMutex.unlock();
	//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
	d_barChart->replot();

}

/**
* @brief 初始化Bar列标题、颜色，模拟数据
*/
void BarChartWidget::initBarData()
{

	//初始化该绘图的数据结构
	origialDataList = new QList < QList < QVector<double>* >*  >();//符合条件的原始数据
	logDataList = new QList < QList < QVector<double>* >*  >();//符合条件的log值
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
			//初始化直方图数据结构
			QVector<BarStruct>* vector2= new QVector<BarStruct>();
			double internal = 10.00 / 100;
			for (int i = 0; i < 100; i++)
			{
				BarStruct barStruct1(i*internal, QString("[%1,%2)").arg(i*internal).arg((i + 1)*internal), 0, QColor("DodgerBlue"), QPoint(i*internal, (i + 1)*internal));
				vector2->append(barStruct1);//QList不是new的，append只是拷贝，所以必须在最后append
			}
			list2->append(vector2);

		}
		barStructList->append(list2);//QList不是new的，append只是拷贝，所以必须在最后append

	}

	logEnable = false; //默认不显示log

	d_barChart->setBarChartData(barStructList);
	d_barChart->replot();

}