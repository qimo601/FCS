#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
PlotWidget::PlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//细胞绘图控件初始化
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(0);
	vLayoutCellPlotFrame->setContentsMargins(0, 0, 0, 0);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_plot = new Plot(ui.cellPlotFrame);
	d_plot->setObjectName(QStringLiteral("d_plot"));

	vLayoutCellPlotFrame->addWidget(d_plot);



	//设置背景线是否显示
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), d_plot, SLOT(setGridEnable(bool)));
	//设置是否显示log值
	connect(ui.logCheckBox, SIGNAL(clicked(bool)), this, SLOT(setLogEnable(bool)));
	//设置放大/缩小按钮可选择
	ui.zoomerBtn->setCheckable(true);
	//设置放大缩小功能是否启用
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enableZoomMode(bool)));
	//设置平移按钮可选择
	ui.pannerBtn->setCheckable(true);
	//设置平移按钮功能是否启用
	connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enablePannerMode(bool)));

	m_timerId = 0;//初始化
	//m_timerId = startTimer(10);//测试开始即实时显示

	this->setFocusPolicy(Qt::ClickFocus);

	init();//初始化

}

PlotWidget::~PlotWidget()
{

}
/**
* @brief 初始化
*/
void PlotWidget::init()
{
	//初始化该绘图的数据结构
	origialDataList = new QList < QList < QVector<double>* >*  >();//符合条件的原始数据
	logDataList = new QList < QList < QVector<double>* >*  >();//符合条件的log值
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

	logEnable = false; //默认不显示log
}
double PlotWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}

/**
* @brief 转换成log(10)x
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
//* @brief 经过条件筛选
//*/
//void PlotWidget::translateWithCondition()
//{
//
//}
void PlotWidget::updateSamples()
{
	QPolygonF samples;

	//bllDataCenter.getCellData(false);//读取细胞数据，不清空缓存
	//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);
    
	bllDataCenter.getCellDataVector(origialDataList,logDataList);//更新最新的数据给当前plot
	QVector<double>* vectorX = logDataList->at(3)->at(1);
	QVector<double>* vectorY = logDataList->at(3)->at(0);
	if (logEnable)//决定显示log否
	{
		
		vectorX = logDataList->at(3)->at(1);
		vectorY = logDataList->at(3)->at(0);

	}
	else
	{
		vectorX = origialDataList->at(3)->at(1);
		vectorY = origialDataList->at(3)->at(0);
	}
	d_plot->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());
	//qDebug() << "PlotWidget," << this->objectName() << " " << origialDataList->at(3)->at(0)->size();
	d_plot->replot();
}
void PlotWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	if (event->timerId() == m_timerId)
	{
		updateSamples();
	}
}

void PlotWidget::startAcqTimer()
{
	//开启定时器
	m_timerId = startTimer(10);
}
void PlotWidget::stopAcqTimer()
{
	//关闭定时器
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
* @brief 启动log数据显示
*/
void PlotWidget::setLogEnable(bool enable)
{
	logEnable = enable;
	setAxisScale();

}
/**
* @brief 重新设置刻度
*/
void PlotWidget::setAxisScale()
{
	if (logEnable)

	{
		d_plot->setAxisScale(QwtPlot::xBottom, 0, 10);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
		d_plot->setAxisScale(QwtPlot::yLeft, 0, 10);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
	}
	else
	{
		d_plot->setAxisScale(QwtPlot::xBottom, 4000000, 6000000);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
		d_plot->setAxisScale(QwtPlot::yLeft, 4000000, 6000000);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
	}

	d_plot->replot();
}