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
	//X轴通道值选择
	connect(ui.passageXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setPassage(int)));
	//Y轴通道值选择
	connect(ui.passageYCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setPassage(int)));
	//Y轴数据单元类型选择
	connect(ui.dataUnitXCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataUnit(int)));
	//Y轴数据单元类型选择
	connect(ui.dataUnitYCombox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataUnit(int)));
	//最大化窗口
	connect(ui.maximizedBtn, SIGNAL(clicked()), this, SLOT(maximizedPlotWidget()));
	//还原窗口
	connect(ui.normalBtn, SIGNAL(clicked()), this, SLOT(normalPlotWidget()));
	//直方图统计
	connect(ui.barChatStaticsCheckBox, SIGNAL(clicked(bool)), this, SLOT(setBarStatisticsMode(bool)));
	//散点图统计
	connect(ui.scatterCheckBox, SIGNAL(clicked(bool)), this, SLOT(setScatterMode(bool)));
	
	m_timerId = 0;//初始化
	//m_timerId = startTimer(10);//测试开始即实时显示

	this->setFocusPolicy(Qt::ClickFocus);
	parent = 0;

	//设置统计线程
	staticsThread.setDataWidget(this);
	staticsThread.start();
	//绑定统计线程更新数据
	connect(&staticsThread, SIGNAL(staticsFinished()), this, SLOT(updateSamples()));


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
			QVector<BarStruct>* vector2 = new QVector<BarStruct>();
			double internal = 10.00 / 100;
			for (int i = 0; i < 100; i++)
			{
				QPointF p(i*internal, (i + 1)*internal);
				BarStruct barStruct1(i*internal, QString("[%1,%2)").arg(i*internal).arg((i + 1)*internal), 0, QColor("DodgerBlue"), QPointF(i*internal, (i + 1)*internal));
				vector2->append(barStruct1);
			}
			list2->append(vector2);//QList不是new的，append只是拷贝，所以必须在最后append

		}
		barStructList->append(list2);//QList不是new的，append只是拷贝，所以必须在最后append

	}

	logEnable = false; //默认不显示log
	//初始化界面一些数据
	initUi();
	//初始化bar条件数据
	initBarData();
}

/**
* @brief 初始化界面一些数据
*/
void PlotWidget::initUi()
{
	//初始化通道和数据单元值
	for (int i = 0; i < 8; i++)
	{
		ui.passageXCombox->addItem(QString("通道%1").arg(i + 1), i);
		ui.passageYCombox->addItem(QString("通道%1").arg(i + 1), i);
	}
	ui.dataUnitYCombox->addItem("HH", 0);
	ui.dataUnitYCombox->addItem("AA", 1);
	ui.dataUnitYCombox->addItem("WW", 2);
	ui.dataUnitXCombox->addItem("HH", 0);
	ui.dataUnitXCombox->addItem("AA", 1);
	ui.dataUnitXCombox->addItem("WW", 2);

	ui.passageXCombox->setCurrentIndex(2);//默认通道3
	ui.passageYCombox->setCurrentIndex(2);
	ui.dataUnitXCombox->setCurrentIndex(0);//默认HH数据单元
	ui.dataUnitYCombox->setCurrentIndex(0);

}
/**
* @brief 初始化Bar列标题、颜色，模拟数据
*/
void PlotWidget::initBarData()
{

	//double internal = 10.00 / 100;
	////初始化直方图数据结构
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
/**
* @brief 设置通道
*/
void PlotWidget::setPassage(int index)
{
	updateSamples();
}
/**
* @brief 设置数据单元类型
*/
void PlotWidget::setDataUnit(int index)
{
	updateSamples();
}
/**
* @brief 最大化当前plot窗口
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
* @brief 还原窗口
*/
void PlotWidget::normalPlotWidget()
{
	ui.maximizedBtn->setEnabled(true);
	ui.normalBtn->setEnabled(false);
	this->setParent(m_parent);
	emit normalPlot();//还原窗口信号
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
	updateSamples();
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

/**
* @brief 设置直方图统计显示模式
*/
void PlotWidget::setBarStatisticsMode(bool mode)
{
	if (mode)
	{
		//设置统计曲线样式
		d_plot->enableStaticsMode();

		//手动更新一次数据
		updateStaticsSamples();
		//直方图没有x轴
		ui.passageXCombox->setEnabled(false);
		ui.dataUnitXCombox->setEnabled(false);
	}
}
/**
* @brief 设置散点图显示模式
*/
void PlotWidget::setScatterMode(bool mode)
{
	if (mode)
	{
		//设置散点图样式
		d_plot->enableScatterMode();
		setAxisScale();//自动设置坐标，判断是否需要log显示
		//手动更新一次数据
		updateSamples();

		//散点图有x轴
		ui.passageXCombox->setEnabled(true);
		ui.dataUnitXCombox->setEnabled(true);
	}
}
//更新数据
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
* @brief 更新散点图统计数据
*/
void PlotWidget::updateScatterSamples()
{
	QPolygonF samples;

	//bllDataCenter.getCellData(false);//读取细胞数据，不清空缓存
	//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);

	//bllDataCenter.getCellDataVector(origialDataList,logDataList);//更新最新的数据给当前plot
	QVector<double>* vectorX;
	QVector<double>* vectorY;

	if (logEnable)//决定显示log否
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
* @brief 更新直方图统计数据
*/
void PlotWidget::updateStaticsSamples()
{
	if (ui.barChatStaticsCheckBox->isChecked())
	{
		dataMutex.lock();
		QVector<double> barChartDataVector;
		QVector<double> xIndexVector;

		//选择通道和数据单元类型
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