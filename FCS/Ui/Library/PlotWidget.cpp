#include "PlotWidget.h"

#include <qmath.h>
#include <QTime>
#include <QPainter>
#include "BarStruct.h"
#include <qwt_scale_engine.h>
#include <qwt_scale_draw.h>
#include "Ui/Library/ViewWidget.h"
//按照log值绘制标签
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
	//刻度标签值
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
	//细胞绘图控件初始化
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(0);
	vLayoutCellPlotFrame->setContentsMargins(0, 0, 0, 0);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_plot = new Plot(ui.cellPlotFrame);
	d_plot->setObjectName(QStringLiteral("d_plot"));

	vLayoutCellPlotFrame->addWidget(d_plot);



	//设置背景线是否显示
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), this, SLOT(setGridEnable(bool)));
	//设置是否显示log值
	connect(ui.logCheckBox, SIGNAL(clicked(bool)), this, SLOT(setLogEnable(bool)));
	//设置放大/缩小按钮可选择
	ui.zoomerBtn->setCheckable(true);
	//设置放大缩小功能是否启用
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), this, SLOT(enableZoomMode(bool)));
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
	//十字线设门
	connect(ui.crossBtn, SIGNAL(toggled(bool)), this, SLOT(enableCrossBtnMode(bool)));
	//跟踪鼠标显示真值
	connect(ui.viewTrueValueBtn_2, SIGNAL(toggled(bool)), this, SLOT(enableViewTrueValueMode2(bool)));
	//矩形设门
	connect(ui.rectBtn, SIGNAL(toggled(bool)), this, SLOT(enableRectBtn(bool)));
	//平行线设门
	connect(ui.parallelLineBtn, SIGNAL(toggled(bool)), this, SLOT(enableParallelLineBtn(bool)));
	//椭圆设门
	connect(ui.ellipseBtn, SIGNAL(toggled(bool)), this, SLOT(enableEllipseBtn(bool)));
	//多边形设门
	connect(ui.polygonBtn, SIGNAL(toggled(bool)), this, SLOT(enablePolygonBtn(bool)));

	
	//直方图统计
	connect(ui.barChatStaticsCheckBox, SIGNAL(clicked(bool)), this, SLOT(setBarStatisticsMode(bool)));
	//散点图统计
	connect(ui.scatterCheckBox, SIGNAL(clicked(bool)), this, SLOT(setScatterMode(bool)));

	//密度图显示
	connect(ui.spectrogramCheckBox, SIGNAL(clicked(bool)), this, SLOT(setSpectrogramMode(bool)));
	//等高线显示
	connect(ui.contourCheckBox, SIGNAL(clicked(bool)), this, SLOT(setContourMode(bool)));

	//************临时设门测试*******************//
	////绘图-十字线设门-返回值
	//connect(d_plot, SIGNAL(selectedCrossPicker(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
	////绘图-矩形设门-返回值
	//connect(d_plot, SIGNAL(selectedRectPicker(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));
	////绘图-平行线设门-返回值
	//connect(d_plot, SIGNAL(selectedParallelLinePicker(QList<QPointF>)), this, SLOT(selectedParallelLinePickerSlot(QList<QPointF>)));

	
	m_timerId = 0;//初始化
	d_rectPicker = 0;
	d_parallelLinePicker_1 = 0;
	d_parallelLinePicker_2 = 0;
	d_crossPicker_1 = 0;
	d_crossPicker_2 = 0;
	d_polygonPicker = 0;
	d_ellipsePicker = 0;




	//m_timerId = startTimer(10);//测试开始即实时显示

	this->setFocusPolicy(Qt::ClickFocus);
	parent = 0;

	//设置统计线程
	staticsThread.setDataWidget(this);
	staticsThread.start();
	//绑定统计线程更新数据（有新数据拷贝至plot，更新散点图、直方图等）
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
	mouse_press = false;//初始化值为false，防止点击设门就会移动
	condition = 1024;//直方图条件划分数目
	dataMutex.lock();
	//初始化该绘图的数据结构
	origialDataList = new QList < QList < QVector<double>* >*  >();//符合条件的原始数据
	logDataList = new QList < QList < QVector<double>* >*  >();//符合条件的log值
	barStructList = new QList < QList < QVector<BarStruct>* >*  >();
	//8个通道
	for (int i = 0; i < 8; i++)
	{
		QList < QVector<double>* >* list = new QList < QVector<double>* >();
		origialDataList->append(list);
		QList < QVector<double>* >* list1 = new QList < QVector<double>* >();
		logDataList->append(list1);

		QList<QVector<BarStruct>*>* list2 = new QList<QVector<BarStruct>*>();
		//三组参数
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = new QVector<double>();
			list->append(vector);
			QVector<double>* vector1 = new QVector<double>();
			list1->append(vector1);
			//初始化直方图数据结构
			QVector<BarStruct>* vector2 = new QVector<BarStruct>();
			//double internal = 10000000000.00 / condition;
			double internal = 10.00/ condition;
			for (int k = 0; k < condition; k++)
			{
				QPointF p(qPow(10,k*internal), qPow(10,(k + 1)*internal));
				BarStruct barStruct1(p.x(), QString("[%1,%2)").arg(p.x()).arg(p.y()), 0, QColor("DodgerBlue"), p);
				vector2->append(barStruct1);
			}
			list2->append(vector2);//QList不是new的，append只是拷贝，所以必须在最后append

		}
		barStructList->append(list2);//QList不是new的，append只是拷贝，所以必须在最后append

	}
	dataMutex.unlock();
	logEnable = false; //默认不显示log
	//初始化界面一些数据
	initUi();

	//手动更新一次数据
	updateSamples();
	//初始化属性窗口动画、配置界面参数
	initAnimation();

	//初始化坐标
	setAxisScale();
}

/**
* @brief 初始化界面一些数据
*/
void PlotWidget::initUi()
{
	//初始化通道和数据单元值
	//旧函数，不用
	/*for (int i = 0; i < 8; i++)
	{
		ui.passageXCombox->addItem(QString("通道%1").arg(i + 1), i);
		ui.passageYCombox->addItem(QString("通道%1").arg(i + 1), i);
	}*/
	//初始化passageXCombox的通道默认数值
	ui.passageXCombox->addItem("FSC", (int)0);
	ui.passageXCombox->addItem("SSC", (int)1);
	ui.passageXCombox->addItem("FL1", (int)2);
	ui.passageXCombox->addItem("FL2", (int)3);
	ui.passageXCombox->addItem("FL3", (int)4);
	ui.passageXCombox->addItem("FL4", (int)5);
	ui.passageXCombox->addItem("FL5", (int)6);
	ui.passageXCombox->addItem("FL6", (int)7);

	//初始化passageYCombox的通道默认数值
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

	ui.passageXCombox->setCurrentIndex(1);//默认通道0
	ui.passageYCombox->setCurrentIndex(0);
	ui.dataUnitXCombox->setCurrentIndex(0);//默认HH数据单元
	ui.dataUnitYCombox->setCurrentIndex(0);


	//隐藏界面不用的按钮
	ui.zoomerBtn->setVisible(false);
	ui.viewTrueValueBtn_2->setVisible(false);
	//ui.parallelLineBtn_2->setVisible(false);



	//默认设门
	ui.rectBtn->setEnabled(true);//矩形设门显示
	ui.parallelLineBtn->setEnabled(false);//平行设门隐藏
}
/**
* @brief 初始化参数数据
*/
void PlotWidget::initPlotConfigData()
{

	//直方图线条粗细颜色
	m_barChatColor = "#325481";
	m_barChatWide = 2;
	m_barChartDefault = 0;
	//x轴坐标
	m_xLeftBarchart = 0;
	m_xRightBarchart = 1e6;
	m_xAutoBarchart =0;

	//y轴坐标
	m_yDownBarchart = 0;
	m_yTopBarchart = 1e6;
	m_yAutoBarchart = 0;

	//散点图线条粗细颜色
	m_scatterColor ="DarkBlue";
	m_scatterWide =2;
	m_scatterDefault = 0;
	//x轴坐标
	m_xLeftScatter = 0;
	m_xRightScatter =1e6;
	m_xAutoScatter = 0;

	//y轴坐标
	m_yDownScatter = 0;
	m_yTopScatter = 1e6;
	m_yAutoScatter =0;


	//画布颜色
	m_plotColor="#FFFFFF";
	m_defaultCheck=0;
	

	//初始散点图背景参数
	QMap<QString, QVariant> scatterValueMap;
	//读取散点图配置
	plotConfig->initScatterPlotSettings(scatterValueMap);
	//更新散点图配置
	setScatterPlotConfig(scatterValueMap);

	//初始直方图背景参数
	QMap<QString, QVariant> barChartValueMap;
	//更新画布曲线颜色
	plotConfig->initBarChartPlotSettings(barChartValueMap);
	//更新直方图配置
	setBarChartPlotConfig(barChartValueMap);

	//初始画布背景参数
	QMap<QString, QVariant> plotValueMap;
	plotConfig->initPlotSettings(plotValueMap);
	//画布颜色
	m_plotColor = plotValueMap.value("plotColorBtn").toString();
	m_defaultCheck = plotValueMap.value("defaultCheckBox").toInt();
	//更新配置
	setPlotConfig(plotValueMap);
	


	//整体坐标更新
	setAxisScale();
	//刷新一遍
	d_plot->replot();

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
	//如果直方图模式选择，先统计一下该通道
	if (ui.barChatStaticsCheckBox->isChecked())
		statisticsHistogram(ui.passageXCombox->currentData().toInt(), ui.dataUnitXCombox->currentData().toInt());
	updateSamples();
}
/**
* @brief 设置数据单元类型
*/
void PlotWidget::setDataUnit(int index)
{
	//如果直方图模式选择，先统计一下该通道
	if (ui.barChatStaticsCheckBox->isChecked())
		statisticsHistogram(ui.passageXCombox->currentData().toInt(), ui.dataUnitXCombox->currentData().toInt());
	updateSamples();
}
/**
* @brief 最大化当前plot窗口
*/
void PlotWidget::maximizedPlotWidget()
{
	//设置最大策略
	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
	this->setSizePolicy(sizePolicy);
	this->setMinimumSize(QSize(0, 0));
	this->setMaximumSize(QSize(16777215, 16777215));
	this->setFocusPolicy(Qt::StrongFocus);
	this->setAcceptDrops(true);

	m_parent = this->parentWidget();
	this->setParent(0);
	this->showMaximized();
	ui.maximizedBtn->setEnabled(true);
	ui.normalBtn->setEnabled(true);

}
/**
* @brief 还原窗口
*/
void PlotWidget::normalPlotWidget()
{
	if (m_parent != 0)
	{
		//设置还原后窗口伸展策略
		QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
		this->setSizePolicy(sizePolicy);
		this->setMinimumSize(QSize(502, 446));
		this->setMaximumSize(QSize(502, 446));
		this->setFocusPolicy(Qt::StrongFocus);
		this->setAcceptDrops(false);


		ui.maximizedBtn->setEnabled(true);
		ui.normalBtn->setEnabled(true);
	
		this->setParent(m_parent);
		emit normalPlot();//还原窗口信号
	}

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
* @brief 启动背景方格线
*/
void PlotWidget::setGridEnable(bool enable)
{
	//如果是直方图模式，需要背景刷色彩。否则背景刷为空
	bool barMode = ui.barChatStaticsCheckBox->isChecked();
	d_plot->setGridEnable(enable, barMode);
}


/**
* @brief 重新设置画布参数
*/
void PlotWidget::setPlotConfig(QMap<QString, QVariant> valueMap)
{
	m_plotColor = valueMap.value("plotColorBtn").toString();
	m_defaultCheck = valueMap.value("defaultCheckBox").toInt();
	d_plot->setCanvasBackgroundColor(m_plotColor);

	//整体坐标更新
	setAxisScale();
	d_plot->replot();
}
/**
* @brief 重新设置画布参数
*/
void PlotWidget::setScatterPlotConfig(QMap<QString, QVariant> scatterValueMap)
{
	//散点图线条粗细颜色
	m_scatterColor = scatterValueMap.value("scatterColorBtn").toString();
	m_scatterWide = scatterValueMap.value("scatterWideSpinBox").toInt();
	m_scatterDefault = scatterValueMap.value("scatterDefaultCheckBox").toInt();
	//x轴坐标
	m_xLeftScatter = scatterValueMap.value("xLeftSpinBox").toInt();
	m_xRightScatter = scatterValueMap.value("xRightSpinBox").toInt();
	m_xAutoScatter = scatterValueMap.value("xAutoCheckBox").toInt();

	//y轴坐标
	m_yDownScatter = scatterValueMap.value("yDownSpinBox").toInt();
	m_yTopScatter = scatterValueMap.value("yTopSpinBox").toInt();
	m_yAutoScatter = scatterValueMap.value("yAutoCheckBox").toInt();
	//整体坐标更新
	setAxisScale();
	//更新曲线颜色
	d_plot->setScatterCurve(m_scatterColor, m_scatterWide, "");
	d_plot->replot();

}
/**
* @brief 重新设置画布参数
*/
void PlotWidget::setBarChartPlotConfig(QMap<QString, QVariant> barChartValueMap)
{
	//直方图线条粗细颜色
	m_barChatColor = barChartValueMap.value("barChatColorBtn").toString();
	m_barChatWide = barChartValueMap.value("barChatWideSpinBox").toInt();
	m_barChartDefault = barChartValueMap.value("barChartDefaultCheckBox").toInt();
	//x轴坐标
	m_xLeftBarchart = barChartValueMap.value("xLeftSpinBox_2").toInt();
	m_xRightBarchart = barChartValueMap.value("xRightSpinBox_2").toInt();
	m_xAutoBarchart = barChartValueMap.value("xAutoCheckBox_2").toInt();

	//y轴坐标
	m_yDownBarchart = barChartValueMap.value("yDownSpinBox_2").toInt();
	m_yTopBarchart = barChartValueMap.value("yTopSpinBox_2").toInt();
	m_yAutoBarchart = barChartValueMap.value("yAutoCheckBox_2").toInt();

	//整体坐标更新
	setAxisScale();
	//更新曲线颜色
	d_plot->setBarChartCurve(m_barChatColor, m_barChatWide, "");
	d_plot->replot();
}
/**
* @brief 重新设置刻度
*/
void PlotWidget::setAxisScale()
{
	//散点图模式
	if (ui.scatterCheckBox->isChecked())
	{
		d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());//每次改变坐标值，都会重新绘制刻度标签和刻度样式
		d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
		//若m_xAutoScatter不需要自动
		if (!m_xAutoScatter)
		{
			d_plot->setAxisScale(QwtPlot::xBottom, m_xLeftScatter, m_xRightScatter);//设置x轴坐标刻度大小,最大值1e6和最小值，以及最小刻度
		}
		else
		{
			d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
		}
		//若m_yAutoScatter不需要自动
		if (!m_yAutoScatter)
		{
			d_plot->setAxisScale(QwtPlot::yLeft, m_yDownScatter, m_yTopScatter);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
		}
		else
		{
			d_plot->setAxisAutoScale(QwtPlot::yLeft, true);
		}
		//线性模式
		d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLinearScaleEngine);
		d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
		
		//log模式
		if (ui.logCheckBox->isChecked())
		{

			//d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());//每次改变坐标值，都会重新绘制刻度标签和刻度样式
			//d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
			//更换绘图引擎为log模式
			d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
			d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine);
			//d_plot->setAxisScale(QwtPlot::xBottom, 0, 1e6);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
			//d_plot->setAxisScale(QwtPlot::yLeft, 0, 1e6);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
			//若m_xAutoScatter不需要自动
			if (!m_xAutoScatter)
			{
				if (m_xLeftScatter <= 0)
					d_plot->setAxisScale(QwtPlot::xBottom, 1, m_xRightScatter);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
				else
					d_plot->setAxisScale(QwtPlot::xBottom, m_xLeftScatter, m_xRightScatter);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度

			}
			else
			{
				d_plot->setAxisAutoScale(QwtPlot::xBottom,true);
			}
			if (!m_yAutoScatter)
			{
				if (m_yDownScatter<=0)
					d_plot->setAxisScale(QwtPlot::yLeft, 1, m_yTopScatter);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
				else
					d_plot->setAxisScale(QwtPlot::yLeft, m_yDownScatter, m_yTopScatter);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
			}
			else
			{
				d_plot->setAxisAutoScale(QwtPlot::yLeft, true);
			}
				/*d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
			d_plot->setAxisAutoScale(QwtPlot::yLeft, true);*/
		}
		d_plot->setAxisLabelRotation(QwtPlot::xBottom, -50.0);//标签旋转50度 


	}
	//直方图统计模式
	else if (ui.barChatStaticsCheckBox->isChecked())
	{
		d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());
		d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
		//若m_xAutoBarchart不需要自动
		if (!m_xAutoBarchart)
		{
			d_plot->setAxisScale(QwtPlot::xBottom, m_xLeftBarchart, m_xRightBarchart);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
		}
		else
		{
			d_plot->setAxisAutoScale(QwtPlot::xBottom);//设置x轴
		}
		//若m_xAutoBarchart不需要自动
		if (!m_yAutoBarchart)
		{
			d_plot->setAxisScale(QwtPlot::yLeft, m_yDownBarchart, m_yTopBarchart);
		}
		else
		{
			d_plot->setAxisAutoScale(QwtPlot::yLeft);//设置y轴坐标刻度大小,最大值和最小值，以及最小刻度
		}

		d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLinearScaleEngine);
		d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
		d_plot->setAxisMaxMajor(QwtPlot::xBottom, 5);//
		d_plot->setAxisMaxMinor(QwtPlot::xBottom, 5);
		if (ui.logCheckBox->isChecked())
		{
			
			d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
			d_plot->setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine);
			d_plot->setAxisScaleDraw(QwtPlot::xBottom, new QwtScaleDraw());//每次改变坐标值，都会重新绘制刻度标签和刻度样式
			d_plot->setAxisScaleDraw(QwtPlot::yLeft, new QwtScaleDraw());
			d_plot->setAxisMaxMajor(QwtPlot::xBottom, 10);//大刻度最多10个
			d_plot->setAxisMaxMinor(QwtPlot::xBottom, 5);//小刻度最多5个
			//d_plot->setAxisScale(QwtPlot::yLeft, 0, 10000);
			if (!m_xAutoBarchart)
			{
				if (m_xLeftBarchart <= 0)
					d_plot->setAxisScale(QwtPlot::xBottom, 1, m_xRightBarchart);//设置x轴坐标刻度大小,最大值和最小值，以及最小刻度
				else
					d_plot->setAxisScale(QwtPlot::xBottom, m_xLeftBarchart, m_xRightBarchart);
			}
			else
			{
				d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
			}
			if (!m_yAutoBarchart)
			{
				//防止log值<=0
				if (m_yDownBarchart <= 0)
					d_plot->setAxisScale(QwtPlot::yLeft, 1, m_yTopBarchart);
				else
					d_plot->setAxisScale(QwtPlot::xBottom, m_yDownBarchart, m_yTopBarchart);
			}
			else
			{
				d_plot->setAxisAutoScale(QwtPlot::yLeft, true);
			}
			//d_plot->setAxisAutoScale(QwtPlot::xBottom, true);
			//d_plot->setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);
		}
		d_plot->setAxisLabelRotation(QwtPlot::xBottom, -50.0);//标签旋转50度 
	}

}

/**
* @brief 设置直方图统计显示模式
*/
void PlotWidget::setBarStatisticsMode(bool mode)
{
	//若是直方图模式
	if (mode)
	{
		//若是初始化时，mode为true，可以配置一下当前界面
		ui.barChatStaticsCheckBox->setChecked(true);
		//d_plot->setTitle("直方图");



		//如果直方图模式选择，先统计一下该通道
		statisticsHistogram(ui.passageXCombox->currentData().toInt(), ui.dataUnitXCombox->currentData().toInt());
		//设置统计曲线样式
		d_plot->enableStaticsMode();
		setAxisScale();
		//手动更新一次数据
		updateStaticsSamples();
		//直方图没有x轴
		ui.passageYCombox->setEnabled(false);
		ui.dataUnitYCombox->setEnabled(false);

		ui.parallelLineBtn->setEnabled(true);//显示平行设门
		ui.rectBtn->setEnabled(false);//隐藏矩形设门
		ui.ellipseBtn->setEnabled(false);//显示椭圆设门
		ui.polygonBtn->setEnabled(false);//显示多边形设门
		ui.crossBtn->setEnabled(false);//显示十字设门



		//直方图模式，只能显示如下设门
		if (d_rectPicker!=0)
			d_rectPicker->setEnabled(false);
		if (d_polygonPicker != 0)
			d_polygonPicker->setEnabled(false);
		if (d_crossPicker_1 != 0)
			d_crossPicker_1->setEnabled(false);
		if (d_crossPicker_2 != 0)
			d_crossPicker_2->setEnabled(false);
		if (d_ellipsePicker != 0)
			d_ellipsePicker->setEnabled(false);
		if (d_parallelLinePicker_1 != 0)
			d_parallelLinePicker_1->setEnabled(true);
		if (d_parallelLinePicker_2 != 0)
			d_parallelLinePicker_2->setEnabled(true);
	}
}
/**
* @brief 设置散点图显示模式
*/
void PlotWidget::setScatterMode(bool mode)
{
	if (mode)
	{
		//若是初始化时，mode为true，可以配置一下当前界面
		ui.scatterCheckBox->setChecked(true);
		//d_plot->setTitle("散点图");

		//设置散点图样式
		d_plot->enableScatterMode();
		setAxisScale();//自动设置坐标，判断是否需要log显示
		//手动更新一次数据
		updateSamples();

		//散点图有y轴
		ui.passageYCombox->setEnabled(true);
		ui.dataUnitYCombox->setEnabled(true);


		ui.parallelLineBtn->setEnabled(false);//隐藏平行设门
		ui.rectBtn->setEnabled(true);//显示矩形设门
		ui.ellipseBtn->setEnabled(true);//显示椭圆设门
		ui.polygonBtn->setEnabled(true);//显示多边形设门
		ui.crossBtn->setEnabled(true);//显示十字设门

		//散点图模式，只能显示如下设门
		if (d_rectPicker != 0)
			d_rectPicker->setEnabled(true);
		if (d_polygonPicker != 0)
			d_polygonPicker->setEnabled(true);
		if (d_crossPicker_1 != 0)
			d_crossPicker_1->setEnabled(true);
		if (d_crossPicker_2 != 0)
			d_crossPicker_2->setEnabled(true);
		if (d_ellipsePicker != 0)
			d_ellipsePicker->setEnabled(true);
		if (d_parallelLinePicker_1 != 0)
			d_parallelLinePicker_1->setEnabled(false);
		if (d_parallelLinePicker_2 != 0)
			d_parallelLinePicker_2->setEnabled(false);
	}
}
/**
* @brief 启用放大缩小按钮
*/
void PlotWidget::enableZoomMode(bool mode)
{

	d_plot->enableZoomMode(mode);
	
}
/**
* @brief 启用十字线设门
*/
void PlotWidget::enableCrossBtnMode(bool mode)
{

	////启用新设门
	//if (mode)
	//{
	//	//十字线
	//	d_crossPicker = new CrossPicker(d_plot->canvas);
	//	//十字线设门-返回值
	//	connect(d_crossPicker, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
	//	d_crossPicker->setEnabled(mode);
	//	d_crossPicker->setTrackerMode(QwtPicker::ActiveOnly);
	//}
	////停止旧设门
	//else
	//{

	//	//d_rectPicker->setEnabled(false);
	//	//d_rectPicker->reset();//状态机清空reset the state machine and terminate ( end(false) ) the selection
	//	//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
	//	//d_rectPicker->remove();
	//	//d_rectPicker->end(false);
	//	d_crossPicker->setTrackerMode(QwtPicker::AlwaysOff);
	//}




	//启用新设门
	if (mode)
	{
		//平行线设门
		d_crossPicker_1 = new CrossPicker(d_plot->canvas);
		connect(d_crossPicker_1, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
		//平行线设门
		d_crossPicker_2 = new CrossPicker(d_plot->canvas);
		d_crossPicker_2->setRubberBandPen(QPen(Qt::blue));
		connect(d_crossPicker_2, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));

		d_crossPicker_1->setEnabled(true);
		d_crossPicker_2->setEnabled(false);
		d_crossPicker_1->setTrackerMode(QwtPicker::ActiveOnly);
		d_crossPicker_2->setTrackerMode(QwtPicker::AlwaysOff);

	}
	//停止旧设门
	else
	{
		//d_parallelLinePicker_1->setEnabled(false);
		//d_parallelLinePicker_2->setEnabled(false);
		//d_parallelLinePicker_1->reset();
		//d_parallelLinePicker_2->reset();
		//停止使用，消失
		d_crossPicker_1->setEnabled(false);
		d_crossPicker_2->setEnabled(false);
		d_crossPicker_1->setTrackerMode(QwtPicker::AlwaysOff);
		d_crossPicker_2->setTrackerMode(QwtPicker::AlwaysOff);
		//删除置0
		delete d_crossPicker_1;
		d_crossPicker_1 = 0;
		delete d_crossPicker_2;
		d_crossPicker_2 = 0;

		//置假
		ui.crossBtn->setChecked(false);
	}
}
/**
* @brief 显示鼠标指向的点的真值
*/
void PlotWidget::enableViewTrueValueMode2(bool mode)
{

	d_plot->enableViewTrueValue2(mode);
}

///**
//* @brief 矩形设门事件
//*/
//void PlotWidget::on_rectBtn_toggled(bool mode)
//{
//
//	enableRectBtn(mode);
//}


/**
* @brief 启用矩形设门
*/
void PlotWidget::enableEllipseBtn(bool mode)
{
	//启用新设门
	if (mode)
	{
		//椭圆形
		d_ellipsePicker = new EllipsePicker(d_plot->canvas);
		//矩形设门-返回值
		connect(d_ellipsePicker, SIGNAL(selected(QRectF)), this, SLOT(selectedEllipsePickerSlot(QRectF)));
		d_ellipsePicker->setEnabled(mode);
		d_ellipsePicker->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//停止旧设门
	else
	{
		//停止使用,消失
		d_ellipsePicker->setEnabled(false);
		//d_rectPicker->reset();//状态机清空reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_ellipsePicker->setTrackerMode(QwtPicker::AlwaysOff);
		//删除置0
		delete d_ellipsePicker;
		d_ellipsePicker = 0;
		//置假
		ui.ellipseBtn->setChecked(false);
	}
}

/**
* @brief 启用多边形设门
*/
void PlotWidget::enablePolygonBtn(bool mode)
{
	//启用新设门
	if (mode)
	{
		//多边形
		d_polygonPicker = new PolygonPicker(d_plot->canvas);
		//矩形设门-返回值
		connect(d_polygonPicker, SIGNAL(selected(QVector<QPointF>)), this, SLOT(selectedPolygonPickerSlot(QVector<QPointF>)));
		d_polygonPicker->setEnabled(mode);
		d_polygonPicker->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//停止旧设门
	else
	{
		//停止使用，消失
		d_polygonPicker->setEnabled(false);
		//d_rectPicker->reset();//状态机清空reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_polygonPicker->setTrackerMode(QwtPicker::AlwaysOff);
		//删除，置0
		delete d_polygonPicker;
		d_polygonPicker = 0;
		//置假
		ui.polygonBtn->setChecked(false);
	}
}

/**
* @brief 启用矩形设门
*/
void PlotWidget::enableRectBtn(bool mode)
{
	qDebug("enableRectBtn");
	//启用新设门
	if (mode)
	{
		//矩形
		d_rectPicker = new RectPicker(d_plot->canvas);
		//矩形设门-返回值
		connect(d_rectPicker, SIGNAL(selected(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));
		d_rectPicker->setEnabled(mode);
		d_rectPicker->setTrackerMode(QwtPicker::ActiveOnly);

	}
	//停止旧设门
	else
	{
		//停止使用，消失
		d_rectPicker->setEnabled(false);
		//d_rectPicker->reset();//状态机清空reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(false);
		d_rectPicker->setTrackerMode(QwtPicker::AlwaysOff);
		//删除，置0
		delete d_rectPicker;
		d_rectPicker = 0;
		//置假
		ui.rectBtn->setChecked(false);
	}
	//暂时不用了
	//d_plot->enableRectPicker(mode);
}
/**
* @brief 启用平行线设门
*/
void PlotWidget::enableParallelLineBtn(bool mode)
{
	//启用新设门
	if (mode)
	{
		//清空坐标
		parallelLineList.clear();
		//平行线设门
		d_parallelLinePicker_1 = new ParallelLinePicker(d_plot->canvas);
		connect(d_parallelLinePicker_1, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));
		//平行线设门
		d_parallelLinePicker_2 = new ParallelLinePicker(d_plot->canvas);
		d_parallelLinePicker_2->setRubberBandPen(QPen(Qt::blue));
		connect(d_parallelLinePicker_2, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));

		d_parallelLinePicker_1->setEnabled(true);
		d_parallelLinePicker_2->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::ActiveOnly);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);

	}
	//停止旧设门
	else
	{
		//停止使用
		d_parallelLinePicker_1->setEnabled(false);
		d_parallelLinePicker_2->setEnabled(false);
		//d_parallelLinePicker_1->reset();
		//d_parallelLinePicker_2->reset();
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);

		//删除 置0
		delete d_parallelLinePicker_1;
		d_parallelLinePicker_1 = 0;
		delete d_parallelLinePicker_2;
		d_parallelLinePicker_2 = 0;
		parallelLineList.clear();//清空一次，才能保证两次同时用
		//置假
		ui.parallelLineBtn->setChecked(false);
	}
	//暂时不用
	//d_plot->enableParallelLinePicker(mode);
}




//更新数据
void PlotWidget::updateSamples()
{

	//散点图模式
	if (ui.scatterCheckBox->isChecked())
	{
		updateScatterSamples();
	}
	//直方图统计模式
	else if (ui.barChatStaticsCheckBox->isChecked())
	{
		updateStaticsSamples();
	}

	setCellEvents(origialDataList->at(0)->at(0)->size());//设置细胞个数

}

/**
* @brief 更新散点图统计数据
*/
void PlotWidget::updateScatterSamples()
{
	//散点图模式
	if (ui.scatterCheckBox->isChecked())
	{

		QPolygonF samples;

		//bllDataCenter.getCellData(false);//读取细胞数据，不清空缓存
		//QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
		//QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);

		//bllDataCenter.getCellDataVector(origialDataList,logDataList);//更新最新的数据给当前plot
		QVector<double>* vectorX;
		QVector<double>* vectorY;
		//因为用log坐标轴，所以所有数据只需用原数据即可，不用判断Log了。
		int m = ui.passageXCombox->currentData().toInt();
		int n = ui.dataUnitXCombox->currentData().toInt();
		vectorX = origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		vectorY = origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

		//if (ui.logCheckBox->isChecked())//决定显示log否
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
		//更新设门的细胞颜色
		updateGateColorSample(this);
		
		
		d_plot->replot();
	}
}
/**
* @brief 更新直方图统计数据
*/
void PlotWidget::updateStaticsSamples()
{
	if (ui.barChatStaticsCheckBox->isChecked())
	{
		//先清空父类的临时曲线
		this->d_plot->clearTempCurve();

		dataMutex.lock();
		QVector<double> barChartDataVector;
		QVector<double> xIndexVectorLog;//log值x轴坐标
		QVector<double> xIndexVectorOri;//原值x轴坐标

		//选择通道和数据单元类型
		QVector<BarStruct>* vecotrData = barStructList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		for (int i = 0; i < vecotrData->size(); i++)
		{
			barChartDataVector.append(vecotrData->at(i).m_value);
			//barChartDataVector.append(0);//置隔离值为0，凸显曲线
			//xIndexVectorLog.append(vecotrData->at(i).m_index);
			xIndexVectorOri.append(vecotrData->at(i).m_index);
			//xIndexVectorOri.append(qPow(10,vecotrData->at(i).m_index));//添加log值，求指数得到原数

			//xIndexVector.append(vecotrData->at(i).m_index+10/256/2);//置隔离值横坐标为中间坐标0.05
		}
		//全部更新源数据
		//因为用log坐标轴，所以所有数据只需用原数据即可，不用判断Log了。
		d_plot->setSamples(xIndexVectorOri, barChartDataVector);
		//如果选择log模式
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
* @brief 更新参数数据
*/
void PlotWidget::updateParamsStatics()
{

}
/**
* @brief 更新参数-细胞个数
*/
double PlotWidget::computerEvents()
{
	double events = origialDataList->at(0)->at(0)->size();
	return events;
}
/**
* @brief 更新参数-%Parent:当前设门的细胞数目，占父类的百分比
*/
double PlotWidget::computerPercentageParent()
{
	return 0;

}
/**
* @brief 更新参数-%Total:当前设门的细胞数目，占源数据细胞总数的百分比
*/
double PlotWidget::computerPercentageTotal()
{
	return 0;

}
/**
* @brief 更新参数-平均值（x1+x2+x3+...+xn）/n
*/
void PlotWidget::computerAverageValue(QList<QList<double>>& averageList, QList<QList<double>>& midList, QList<QList<double>>& cvList)
{
	int passage = 0;
	int dataUnit = 0;
	double averageValue =0;

	//一共24个平均值
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			averageValue = 0;//初始化置0
			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				averageValue += origialDataList->at(i)->at(j)->at(k);
			}
			//如果为空
			if (origialDataList->at(i)->at(j)->size() != 0)
				averageValue = averageValue / origialDataList->at(i)->at(j)->size();
			else
				averageValue = 0;
			list.append(averageValue);
		}
		
		averageList.append(list);
	}


	double midValue = 0;//中间值
	//一共24个中间值
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			QList<double> valueList;//申请成Vector，可以提高append速度。这样就不需要不断开辟空间
			QVector<double> valueVector;
			//memcpy(&valueVector, origialDataList->at(i)->at(j), origialDataList->at(i)->at(j)->size());
			midValue = 0;//初始化置0
			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				valueVector.append(origialDataList->at(i)->at(j)->at(k));
			}

			qSort(valueVector.begin(), valueVector.end());
			if (valueVector.size()>0)
			{
				//如果是偶数项，数组是从0开始的
				if (valueVector.size() % 2 == 0)
				{
					midValue = (valueVector.at(valueVector.size() / 2) + valueVector.at(valueVector.size() / 2 -1))/2;
				}
				//如果是奇数项
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

	double stdEv = 0;//标准方差
	double cvValue = 0;//CV值
	double sum = 0;

	/*
	CV=σ/|μ|，其中 σ=√∑(xi-u)^2/(n-1)，u=(∑xi)/n
	测试代码
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

	//一共24个CV值
	for (int i = 0; i < origialDataList->size(); i++)
	{
		QList<double> list;
		for (int j = 0; j < origialDataList->at(i)->size(); j++)
		{
			double average = averageList.at(i).at(j);
			sum = 0;//初始化置0
			stdEv = 0;//初始化置0
			cvValue = 0;//初始化置0

			for (int k = 0; k < origialDataList->at(i)->at(j)->size(); k++)
			{
				double diff = qAbs(origialDataList->at(i)->at(j)->at(k) - average);
				sum = sum+ diff*diff;//累加所有平方差
			}
			//如果为空
			if (origialDataList->at(i)->at(j)->size() != 0)
			{
				sum = sum / (origialDataList->at(i)->at(j)->size() - 1);//
				stdEv = qSqrt(sum);//标准方差
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
* @brief 更新参数-中间值（排序后，中间的值）
*/
double PlotWidget::computerMidValue()
{
	return 0;

}
/**
* @brief 更新参数-变异系数 CV(Coefficient of Variance):标准差与均值的比率
*CV=σ/|μ|，其中 σ=√∑(xi-u)^2/(n-1)，u=(∑xi)/n
*/
double PlotWidget::computerCvValue()
{
	
	return 0;

}



/**
* @brief 清楚plot旧数据
*
*/
void PlotWidget::clearPlotSamples()
{
	dataMutex.lock();

	//初始化该绘图的数据结构
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
* @brief 选择的十字坐标
*
*/
void PlotWidget::selectedCrossPickerSlot(QPointF pointf)
{
	//是否有存在的点
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
	//无点
	if (crossPickerList.size() == 0)
	{
		crossPickerList.append(pointf);
	}
	//已经有一个点
	if (crossPickerList.size() == 1)
	{
		//d_parallelLinePicker_1->setEnabled(false);
		d_crossPicker_1->setTrackerMode(QwtPicker::AlwaysOff);

		d_crossPicker_2->setEnabled(true);
		d_crossPicker_2->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//已经有2个点
	if (crossPickerList.size() >= 2)
	{

		//emit selectedParallelLinePicker(parallelLineList);
		//修改处
		selectedCrossPickerSlot(crossPickerList);
	}

	
}
/**
* @brief 选择的十字坐标
*
*/
void PlotWidget::selectedCrossPickerSlot(QList<QPointF> crossPickerList)
{
	//生成设门窗口
	computeCrossPickerSlot(crossPickerList);
}
/**
* @brief 矩形设门
*
*/
void PlotWidget::selectedRectPickerSlot(QRectF rectf1)
{
	QRectF rectf = rectf1;
	//生成设门窗口
	computeRectPickerSlot(rectf);
	
}

/**
* @brief 平行线设门,判断是否有两个点
*
*/
void PlotWidget::selectedParallelLinePickerSlot(QPointF pointf)
{
	//是否有存在的点
	for (int i = 0; i < parallelLineList.size(); i++)
	{
		if (pointf == parallelLineList.at(i))
		{
			return;
		}
		/*else
		{
			parallelLineList.append(pointf);
			break;
		}*/
	}
	//无点
// 	if (parallelLineList.size() == 0)
// 	{
		parallelLineList.append(pointf);
	//}
	//已经有一个点
	if (parallelLineList.size() == 1)
	{
		//d_parallelLinePicker_1->setEnabled(false);
		//d_parallelLinePicker_1->reset();
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);

		d_parallelLinePicker_2->setEnabled(true);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//已经有2个点
	if (parallelLineList.size() == 2)
	{
		
		//emit selectedParallelLinePicker(parallelLineList);
		//修改处
		selectedParallelLinePickerSlot(parallelLineList);
	}

}
/**
* @brief 平行线设门
*
*/
void PlotWidget::selectedParallelLinePickerSlot(QList<QPointF> pointFList)
{

	computeParallelLinePickerSlot(pointFList);
}

/**
* @brief 椭圆设门
*
*/
void PlotWidget::selectedEllipsePickerSlot(QRectF rectf1)
{
	QRectF rectf = rectf1;
	//生成设门窗口
	computeEllipsePickerSlot(rectf);

}

/**
* @brief 多边形设门
*
*/
void PlotWidget::selectedPolygonPickerSlot(QVector<QPointF> vector1)
{
	QVector<QPointF> vector = vector1;
	//生成设门窗口
	computePolygonPickerSlot(vector);

}


/**
* @brief 获取界面控件的状态
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
* @brief 设置界面控件的状态
*/
void PlotWidget::setStatusControl(QMap<QString,int> map)
{
	//设置Y通道
	int index = ui.passageYCombox->findData(map.value("passageYCombox"));
	ui.passageYCombox->setCurrentIndex(index);
	setPassage(ui.passageYCombox->currentData().toInt());//更新显示当前通道数据

	//设置Y通道数据单元
	index = ui.dataUnitYCombox->findData(map.value("dataUnitYCombox"));
	ui.dataUnitYCombox->setCurrentIndex(index);
	setDataUnit(ui.dataUnitYCombox->currentData().toInt());//更新显示当前通道当前参数数据



	//设置X通道
	index = ui.passageXCombox->findData(map.value("passageXCombox"));
	ui.passageXCombox->setCurrentIndex(index);
	setPassage(ui.passageYCombox->currentData().toInt());//更新显示当前通道数据

	//设置X通道数据单元
	index = ui.dataUnitXCombox->findData(map.value("dataUnitXCombox"));
	ui.dataUnitXCombox->setCurrentIndex(index);
	setDataUnit(ui.dataUnitYCombox->currentData().toInt());//更新显示当前通道当前参数数据

	//设置背景方格线
	ui.gridCheckBox->setChecked(map.value("gridCheckBox"));
	setGridEnable(map.value("gridCheckBox"));

	//设置log状态
	ui.logCheckBox->setChecked(map.value("logCheckBox"));
	setLogEnable(map.value("logCheckBox"));
	//设置散点图状态
	ui.scatterCheckBox->setChecked(map.value("scatterCheckBox"));
	setScatterMode(map.value("scatterCheckBox"));
	//设置直方图状态
	ui.barChatStaticsCheckBox->setChecked(map.value("barChatStaticsCheckBox"));
	setBarStatisticsMode(map.value("barChatStaticsCheckBox"));

}
/**
* @brief 添加设门
*/
void PlotWidget::addGate(GateStorage::GateType type)
{
	GateStorage* gateStorage = new GateStorage();
	gateStorage->setParentWidget((QObject*)this);//当前父窗口
	gateStorage->setPlotWidget(d_plotWidgetGate);//设门新生成的窗口
	gateStorage->setGatePointer(d_rectPicker);//当前设门指针
	gateStorage->setGateName(QString("P%1").arg(ViewWidget::s_plotWidgetList.size() + 1));//设门名字
	//先降qsrand(seed)随机,然后qrand()在程序运行的时候，才会每次都不一样
	qsrand(QDateTime::currentDateTime().toTime_t());
	QColor color(qrand() % 255, qrand() % 255, qrand() % 255);//设置设门的颜色名称
	gateStorage->setGateColorName(color.name());



	QString title;
	PlotWidget* plotwidget = (PlotWidget*)gateStorage->getParentWidget();
	if (gateStorage->getParentWidget() != 0)
		title = QString("%1-%2").arg(plotwidget->getTitle()).arg(gateStorage->getGateName());
	//给新设门窗口的画布命名
	d_plotWidgetGate->setTitle(title);
	//设置实验名
	d_plotWidgetGate->setExperimentName(ViewWidget::s_experimentName);//设置实验名
	d_plotWidgetGate->setCellEvents(d_plotWidgetGate->origialDataList->at(0)->at(0)->size());//设置细胞数据
	//临时测试2015-02-11，更改当前新设门的颜色 宽度0，即用系统默认宽度
	d_plotWidgetGate->d_plot->setScatterCurve(color.name(), 0, "");
	
	gateStorage->setGateType(type);//设门类型
	m_gateStorageList.append(gateStorage);//添加设门

	emit addGateSignal((QWidget*)d_plotWidgetGate);
}


/**
* @brief 删除指定设门
*/
void PlotWidget::deleteGate(GateStorage* gateStorage)
{
	for (int i = 0; i < m_gateStorageList.size(); i++)
	{
		GateStorage* gate = m_gateStorageList.at(i);
		//找到设门
		if (gate == gateStorage)
		{
			//设门类型
			GateStorage::GateType m_gateType = gate->getGateType();
			//矩形设门
			if (m_gateType == GateStorage::RECT)
			{
				RectPicker* rectPicker = (RectPicker*)gate->getGatePointer();
				rectPicker->setEnabled(false);
				delete rectPicker;
			}
			//平行线设门
			else if (m_gateType == GateStorage::PARALLEL)
			{
				ParallelLinePicker* parallLinePicker = (ParallelLinePicker*)gate->getGatePointer();
				parallLinePicker->setEnabled(false);
				delete parallLinePicker;
			}
			//设门数组删除该设门
			m_gateStorageList.removeAt(i);
		}
	}
	
}
/**
* @brief 根据矩形筛选
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
	d_plotWidgetGate = new PlotWidget();//新plot窗口

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//X轴和Y轴应该是同一个通道的才有意义
	for (int i = 0; i < vectorY->size(); i++)
	{
		if (rectf.contains(vectorX->at(i), vectorY->at(i)))
		{
			indexVector.append(i);
		}
		////如果Y坐标在矩形内
		//if (vectorY->at(i) >= topLeft.y() && vectorY->at(i) <= bottomRight.y())
		//{
		//	//比较X坐标
		//	for (int j = 0; j < vectorX->size(); j++)
		//	{
		//		//如果X坐标在矩形内
		//		if (vectorX->at(j) <= bottomRight.x() && vectorX->at(j) >= topLeft.x())
		//			indexVector.append(j);
		//	}
		//}

	}
	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//添加至设门数组
	addGate(GateStorage::RECT);
	//矩形设门完成
	//enableRectBtn(false);
	//置假
	//ui.rectBtn->setChecked(false);//会自动调用槽函数enableRectBtn(false);
}

/**
* @brief 根据十字线筛选
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
	d_plotWidgetGate = new PlotWidget();//新plot窗口

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//X轴和Y轴应该是同一个通道的才有意义
	for (int i = 0; i < vectorY->size(); i++)
	{
		if (rectf.contains(vectorX->at(i), vectorY->at(i)))
		{
			indexVector.append(i);
		}
	}
	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//添加至设门数组
	addGate(GateStorage::CROSS);
	//矩形设门完成
	//enableRectBtn(false);

	//置假
	//ui.crossBtn->setChecked(false);//会自动调用槽函数enableCrossBtn(false);
}
//void PlotWidget::computeCrossPickerSlot(QPointF pointF)
//{
//	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
//	double x = pointF.x();
//	double y = pointF.y();//当前中心点的坐标
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
//	QVector<int> indexVector1;//四个象限
//	QVector<int> indexVector2;
//	QVector<int> indexVector3;
//	QVector<int> indexVector4;
//	//判断象限区间
//	for (int i = 0; i < vectorY->size(); i++)
//	{
//		if (vectorX->at(i) < x)
//		{
//			if (vectorY->at(i) < y)
//			{
//				indexVector2.append(i);//第二象限
//			}
//			else if (vectorY->at(i) >= y)
//			{
//				indexVector1.append(i);//第一象限
//			}
//		}
//		else if (vectorX->at(i) >= x)
//		{
//			if (vectorY->at(i) < y)
//			{
//				indexVector3.append(i);//第三象限
//			}
//			else if (vectorY->at(i) >= y)
//			{
//				indexVector4.append(i);//第四象限
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
//		d_plotWidgetGate = new PlotWidget();//新plot窗口
//		//复制数据至新窗口
//		copyData(indexVectorList.at(i));
//		//传递控件状态参数
//		d_plotWidgetGate->setStatusControl(getStatusControl());
//
//		d_plotWidgetGate->show();
//		d_plotWidgetGate->updateSamples();
//
//		//添加至设门数组
//		addGate(GateStorage::CROSS);
//	}
//
//	
//	//置假
//	ui.crossBtn->setChecked(false);//会自动调用槽函数enableCrossBtn(false);
//}
/**
* @brief 根据多边形筛选
*
*/
void PlotWidget::computePolygonPickerSlot(QVector<QPointF> vector)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
	
	d_plotWidgetGate = new PlotWidget();//新plot窗口

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;


	int polySides = vector.size();//总共点数
	float* polyX = new float[polySides];
	float* polyY = new float[polySides];
	//将顶点赋值
	for (int i = 0; i < polySides; i++)
	{
		polyX[i] = vector.at(i).x();
		polyY[i] = vector.at(i).y();
	}

	//X轴和Y轴应该是同一个通道的才有意义
	for (int i = 0; i < vectorY->size(); i++)
	{
		QPointF pointF(vectorX->at(i), vectorY->at(i));
		if (pointInPolygon(pointF,polyX, polyY, polySides))
			indexVector.append(i);
	}



	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//添加至设门数组
	addGate(GateStorage::POLYGON);
	//矩形设门完成
	//enableRectBtn(false);
	//置假
	//ui.polygonBtn->setChecked(false);//会自动调用槽函数enablePolygonBtn(false);

	delete[] polyX;//释放
	delete[] polyY;
}

/**
* @brief 判断点是否在多边形内部
* @param QPointF 当前点
* @param float* polyX 多边形顶点X坐标
* @param float* polyY 多边形顶点Y坐标
* @param int polySides 多边形顶点数
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
* @brief 拷贝数据至新控件
*/
void PlotWidget::copyData(QVector<int> indexVector)
{
	//复制数据
	for (int t = 0; t < indexVector.size(); t++)
	{
		//8个通道
		for (int i = 0; i < origialDataList->size(); i++)
		{
			QList < QVector<double>* > * list1 = d_plotWidgetGate->origialDataList->at(i);//原始数据
			QList < QVector<double>* > * list2 = d_plotWidgetGate->logDataList->at(i);//log数据
			QList < QVector<BarStruct>* >* list3 = d_plotWidgetGate->barStructList->at(i);//条件数据
			//3组参数
			for (int j = 0; j < 3; j++)
			{
				QVector<double>* vector1 = list1->at(j);//原始数据
				QVector<double>* vector2 = list2->at(j);//log数据
				QVector<BarStruct>* vector3 = list3->at(j);//条件数据
				vector1->append(origialDataList->at(i)->at(j)->at(indexVector.at(t)));//拷贝原始数据
				vector2->append(logDataList->at(i)->at(j)->at(indexVector.at(t)));//拷贝log数据
				//vector3->append(barStructList->at(i)->at(j)->at(indexVector.at(t)));//不需要拷贝，每次点击都计算最新的条件数
			}
		}

	}
}
/**
* @brief 根据平行线筛选
*
*/
void PlotWidget::computeParallelLinePickerSlot(QList<QPointF> pointFList)
{
	QPointF pointF1 = pointFList.at(0);
	QPointF pointF2 = pointFList.at(1);
	d_plotWidgetGate = new PlotWidget();//新plot窗口
	
	double a = 0;//默认左边为apointF2.x()
	double b = 0;//右边为b
	if (pointF1.x() <= pointF2.x())
	{
		a = pointF1.x();
		b = pointF2.x();
	}
	else
	{
		a = pointF2.x();
		b = pointF1.x();
	}
	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//X轴当前通道和当前的参数
	for (int i = 0; i < vectorX->size(); i++)
	{
		if (vectorX->at(i) >= a && vectorX->at(i) <= b)
		{
			indexVector.append(i);
		}
		
	}

	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());
	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//添加至设门数组
	addGate(GateStorage::PARALLEL);
	//平行线设门完成
	//enableParallelLineBtn(false);
	//置假
	//ui.parallelLineBtn->setChecked(false);//会自动调用槽函数enableParallelLineBtn(false);
}


/**
* @brief 根据椭圆筛选
*
* 点在椭圆内 椭圆方程（x-p）^2/(a*a)+(y-q)^2/(b*b)=1 原本嘛 只需要代入 判断（x-p）^2/(a*a)+(y-q)^2/(b*b）≤1就好了

* 不过引入了除法很不爽 所以判断（x-p）^2*(b*b)+(y-q)^2*(a*a）≤a*a*b*b
*/
void PlotWidget::computeEllipsePickerSlot(QRectF rectf)
{
	//PlotWidget *plotWidgetRect = qobject_cast<PlotWidget *>(parent);
	

	d_plotWidgetGate = new PlotWidget();//新plot窗口

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
	//如果是log模式
	if (ui.logCheckBox->isChecked())
	{
		//取log值
		vectorY = logDataList->at(passageY)->at(dataUnitY);
		vectorX = logDataList->at(passageX)->at(dataUnitX);
		//取椭圆log坐标
		top = qLn(top) / qLn(10);
		left = qLn(left) / qLn(10);
		right = qLn(right) / qLn(10);
		bottom = qLn(bottom) / qLn(10);

	}
	else if (ui.scatterCheckBox->isChecked())
	{
		//取原值
		vectorY = origialDataList->at(passageY)->at(dataUnitY);
		vectorX = origialDataList->at(passageX)->at(dataUnitX);
	}
	//计算椭圆参数
	double a = qFabs(right - left) / 2;
	double b = qFabs(top - bottom) / 2;
	double p = (right + left) / 2;//中心x坐标
	double q = (top + bottom) / 2;//中心y坐标
	qDebug() << QString("坐标(%1,%2)，长度a:%3,高度b:%4").arg(p).arg(q).arg(a).arg(b);

	QVector<int> indexVector;
	//筛选数据
	//X轴和Y轴应该是同一个序号标签的才有意义
	for (int i = 0; i < vectorY->size(); i++)
	{

		//比较X坐标
		QPointF pointF(vectorX->at(i), vectorY->at(i));
		//如果(x,y)坐标在矩形内
		/*if(((pointF.x() - p)*(pointF.x() - p)*(b*b) + (pointF.y() - q)*(pointF.y() - q)*(a*a)) <= a*a*b*b)
			indexVector.append(i);*/
		if (((pointF.x() - p)*(pointF.x() - p)/(a*a) + (pointF.y() - q)*(pointF.y() - q)/(b*b)) <= 1)
			indexVector.append(i);

		/*if (pointF.y()>top && pointF.y()<bottom)
			indexVector.append(i);*/

	}


	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());

	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();

	//添加至设门数组
	addGate(GateStorage::ELLIPSE);
	//矩形设门完成
	//enableRectBtn(false);
	//置假
	//ui.ellipseBtn->setChecked(false);//会自动调用槽函数enableRectBtn(false);
}
/**
* @brief 保存文件
* @param QString:文件类型
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
* @brief 保存USB格式文件
* @param QString 文件名称，QString:文件类型
*/
void PlotWidget::saveUSBFile(QString fileName)
{
	
}
/**
* @brief 保存FCM/MatLab格式文件
* @param QString 文件名称，QString:文件类型
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
		//n个细胞
		for (int i = 0; i < origialDataList->at(0)->at(0)->size(); i++)
		{
			//8个通道
			for (int j = 0; j < origialDataList->size(); j++)
			{
				//3组参数
				double valueHH = origialDataList->at(j)->at(0)->at(i);
				double valueAA = origialDataList->at(j)->at(1)->at(i);
				double valueWW = origialDataList->at(j)->at(2)->at(i);



				valueAA = valueAA + 32768 * valueWW;
				valueHH = valueHH + 32768 * 8;

				qint32 valueAAInt = valueAA;
				qint32 valueHHInt = valueHH;
				qint32 valueWWInt = valueWW;


				//numwritten = fwrite(&valueAAInt, sizeof(qint32), 1, stream);//错误顺序
				numwritten = fwrite(&valueHHInt, sizeof(qint32), 1, stream);//正确顺序HH\AA\WW
				numwritten = fwrite(&valueAAInt, sizeof(qint32), 1, stream);
				numwritten = fwrite(&valueWWInt, sizeof(qint32), 1, stream);


			}

			qDebug() << "【PlotWidget】 保存文件成功:" << fileName;
		}

		//关闭文件
		if (stream)
		{
			if (fclose(stream))
			{
				qDebug() << "【PlotWidget】文件关闭失败:" << fileName;
			}
		}
	}
}
/**
* @brief 保存FCS标准格式文件
* @param QString 文件名称，QString:文件类型
*/
void PlotWidget::saveFCSFile(QString fileName)
{

}
/**
* @brief 一次性统计直方图
* @param passage通道
* @param dataUnit数据单元
*/ 
void PlotWidget::statisticsHistogram(int passage,int dataUnit)
{

	dataMutex.lock();
	int i = passage;//第i个通道
	int j = dataUnit;//第j组参数
	QVector<double>* originalList = origialDataList->at(i)->at(j);//原始数据
	QVector<BarStruct>* barList = barStructList->at(i)->at(j);//条件数据

	//清空上次统计数据，避免点一次直方图递增+1
	BarStruct bar;
	for (int i = 0; i < barList->size(); i++)
	{
		bar = barList->at(i);
		bar.m_value = 0;
		barList->replace(i, bar);
	}
	//对源数据筛选一次
	for (int m = 0; m < originalList->size(); m++)
	{

		double value = originalList->at(m);//原值计算范围1024组不精细
		int start = 0;
		int end = barList->size()-1;
		int mid = start+ (end - start) / 2;
		while (mid > 0)//二分查找
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
* @brief 清空该窗口所有数据-恢复空数据
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
	//清除设门窗口关系
	m_gateStorageList.clear();
	//清空画布数据，重新画图
	clearPlotSamples();


	//reportTree->updateReport();//更新报告界面
}
/**
* @brief 设置画布标题
*/
void PlotWidget::setTitle(QString title)
{
	d_plot->setTitle(title);
}
/**
* @brief 设置画布标题
*/
QString PlotWidget::getTitle()
{
	return d_plot->title().text();
}

/**
* @brief 初始化属性窗口及其动画
*/
void PlotWidget::initAnimation()
{	//属性窗口
	plotConfig = new PlotConfig(this);
	plotConfig->setVisible(false);
	//属性窗口显示的动画
	showPropertyAnimation = new QPropertyAnimation(plotConfig, "geometry", this);

	//属性窗口消失的动画
	closePropertyAnimation = new QPropertyAnimation(plotConfig, "geometry", this);
	//显示
	connect(plotConfig, SIGNAL(plotConfigClosed()), this, SLOT(setPropertyBtnStatus()));
	//关闭
	connect(closePropertyAnimation, SIGNAL(finished()), this, SLOT(setVisiblePropertyWidget()));
	//画布的参数改变
	connect(plotConfig, SIGNAL(plotConfigChange(QMap<QString, QVariant>)), this, SLOT(setPlotConfig(QMap<QString, QVariant>)));

	//散点图的参数改变
	connect(plotConfig, SIGNAL(scatterPlotConfigChange(QMap<QString, QVariant>)), this, SLOT(setScatterPlotConfig(QMap<QString, QVariant>)));

	//直方图的参数改变
	connect(plotConfig, SIGNAL(barchartPlotConfigChange(QMap<QString, QVariant>)), this, SLOT(setBarChartPlotConfig(QMap<QString, QVariant>)));

	//初始化参数数据
	initPlotConfigData();
}
/**
* @brief 设置按钮弹出属性窗口
*/
void PlotWidget::on_propertyBtn_clicked()
{
	if (!plotConfig->isVisible())
	{
		showPlotConfig();
	}
	else
	{
		closePlotConfig();

	}

}
/**
* @brief 设置按钮属性
*/
void PlotWidget::setPropertyBtnStatus()
{
	ui.propertyBtn->setChecked(false);

}

/**
* @brief 显示属性窗口
*/
void PlotWidget::showPlotConfig()
{
	plotConfig->setVisible(true);

	int width = plotConfig->width();
	int height = plotConfig->height();

	showPropertyAnimation->setDuration(100);
	QPoint pos = ui.cellXFrame->mapTo(this, ui.propertyBtn->pos());
	pos.setX(pos.x() + ui.propertyBtn->width());
	showPropertyAnimation->setStartValue(QRect(pos.x(), pos.y(), 0, 300));//开始位置
	showPropertyAnimation->setEndValue(QRect(pos.x(), pos.y(), 530, 300));//结束位置

	showPropertyAnimation->start();

}
/**
* @brief 关闭属性窗口
*/
void PlotWidget::closePlotConfig()
{
	//int width = plotConfig->width();
	//int height = plotConfig->height();
	//closePropertyAnimation->setDuration(100);
	//QPoint pos = ui.cellXFrame->mapTo(this, ui.propertyBtn->pos());
	//closePropertyAnimation->setStartValue(QRect(pos.x() + width, pos.y(), 530, 300));//开始位置
	//closePropertyAnimation->setEndValue(QRect(pos.x(), pos.y(), 0, 300));//结束位置
	//closePropertyAnimation->start();
	plotConfig->setVisible(false);
}
/**
* @brief 设置属性窗口不可见
*/
void PlotWidget::setVisiblePropertyWidget()
{
	plotConfig->setVisible(false);
	update();
}
/**
* @brief 复制窗口事件
*/
void PlotWidget::on_copyBtn_clicked()
{
	
	d_plotWidgetGate = new PlotWidget();//新拷贝的plot窗口

	int passageY = ui.passageYCombox->currentData().toInt();
	int dataUnitY = ui.dataUnitYCombox->currentData().toInt();
	int passageX = ui.passageXCombox->currentData().toInt();
	int dataUnitX = ui.dataUnitXCombox->currentData().toInt();

	QVector<double>* vectorY = origialDataList->at(passageY)->at(dataUnitY);
	QVector<double>* vectorX = origialDataList->at(passageX)->at(dataUnitX);

	QVector<int> indexVector;
	//复制序号
	for (int i = 0; i < vectorY->size(); i++)
	{
			indexVector.append(i);

	}
	//复制数据至新窗口
	copyData(indexVector);
	//传递控件状态参数
	d_plotWidgetGate->setStatusControl(getStatusControl());
	//给新设门窗口的画布命名
	d_plotWidgetGate->setTitle(QString("%1").arg(this->getTitle()));
	d_plotWidgetGate->setParent(this);
	d_plotWidgetGate->show();
	d_plotWidgetGate->updateSamples();
	emit addGateSignal((QWidget*)d_plotWidgetGate);//仿作新增设门，其实新增复制窗口
}

/**
* @brief 关闭窗口事件
*/
void PlotWidget::on_closeBtn_clicked()
{
	this->close();
	ViewWidget::m_gridPlotWidgetList.removeOne(this);

}
/**
* @brief 鼠标按下事件
*/
void PlotWidget::mousePressEvent(QMouseEvent *event)
{
	qDebug("mousePressEvent");
	//只能是鼠标左键移动和改变大小
	if (event->button() == Qt::LeftButton)
	{
		if (event->y() > 33)//控制在标题栏内，才可以拖动窗口
		{
			event->ignore();
			return;
		}
		else
		{
			setCursor(Qt::SizeAllCursor);
			mouse_press = true;

			//窗口移动距离
			move_point = event->globalPos() - pos();
		}
		
	}


	
}
/**
* @brief 鼠标释放事件
*/
void PlotWidget::mouseReleaseEvent(QMouseEvent *)
{
	mouse_press = false;
	setCursor(Qt::ArrowCursor);
}
/**
* @brief 鼠标移动事件
*/
void PlotWidget::mouseMoveEvent(QMouseEvent *event)
{
	//if (event->y() <= 33)//控制在标题栏内，才可以拖动窗口
	//{
	//	setCursor(Qt::SizeAllCursor);
	//}
	//else
	//{
	//	setCursor(Qt::ArrowCursor);
	//}

	//移动窗口
	if (mouse_press)
	{
		QPoint move_pos = event->globalPos();
		move(move_pos - move_point);
		QWidget* parentW = this->parentWidget();
		QRect rect = parentW->rect();
		/*rect.setWidth(rect.width() + move_pos.x() - move_point.x());
		rect.setHeight(rect.height() + move_pos.y() - move_point.y());
		parentW->resize(rect.width(), rect.height());*/
	}
}

/**
* @brief 设置密度图显示模式
*/
void PlotWidget::setSpectrogramMode(bool mode)
{
	d_plot->showSpectrogram(mode);
	//如果显示
	if (mode)
	{
		QList<PointColorData> pointList;
	

		QVector<double>* vectorX;
		QVector<double>* vectorY;
		//因为用log坐标轴，所以所有数据只需用原数据即可，不用判断Log了。
		int m = ui.passageXCombox->currentData().toInt();
		int n = ui.dataUnitXCombox->currentData().toInt();
		vectorX = origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
		vectorY = origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

		////判断点四周的点数，半径为r
		//for (int i = 0; i < vectorX->size(); i++)
		//{
		//	//原点
		//	PointColorData originPoint;
		//	originPoint.setX(vectorX->at(i));
		//	originPoint.setY(vectorY->at(i));

		//	qint32 sum = 0;

		//	//判断一共有多少个点在半径为r的园内
		//	double r = 100;
		//	for (int j = 0; j < vectorX->size(); j++)
		//	{
		//		//目标点
		//		PointColorData aimPoint;
		//		aimPoint.setX(vectorX->at(j));
		//		aimPoint.setY(vectorY->at(j));

		//		bool tag = (originPoint.x() - aimPoint.x())*(originPoint.x() - aimPoint.x()) + (originPoint.y() - aimPoint.y())*(originPoint.y() - aimPoint.y()) <= r*r;
		//		if (tag)
		//			sum++;
		//	}
		//	originPoint.setValue(sum);
		//	pointList.append(originPoint);
		//}



		//d_plot->updateSpectrogramData(pointList);
		d_plot->updateSpectrogramData(vectorX, vectorY);

	}

}
/**
* @brief 设置等高线显示模式
*/
void PlotWidget::setContourMode(bool mode)
{
	d_plot->showContour(mode);
}
/**
* @brief 设置实验名称
*/
void PlotWidget::setExperimentName(QString experimentName)
{
	ui.experimentLabel->setText(experimentName);
}
/**
* @brief 设置细胞个数
*/
void PlotWidget::setCellEvents(double events)
{
	QString cellEvents = QString::number(events);
	ui.cellsEventsLabel->setText(cellEvents);
}
/**
* @brief 测试补偿当前通道 Y-X*percent
*/
void PlotWidget::compensationSlot(int passageY, int passageX, double percent)
{
	QVector<double>* vectorX = 0;
	QVector<double>* vectorY = 0;
	//三组参数HH、AA、WW，相继补偿
	for (int i = 0; i < 3; i++)
	{
		vectorX = origialDataList->at(passageX)->at(i);
		vectorY = origialDataList->at(passageY)->at(i);

		//进行补偿
		for (int j = 0; j < vectorY->size(); j++)
		{
			vectorY->replace(j, vectorY->at(j) - percent* vectorX->at(j));
		}
	}
	
	updateSamples();//更新画布数据
}



/**
* @brief 更新孩子散点图统计数据
*/
void PlotWidget::updateChildGateScatterSamples(PlotWidget* childPlotWidget,QString colorName)
{
	
	QVector<double>* vectorX;
	QVector<double>* vectorY;
	//因为用log坐标轴，所以所有数据只需用原数据即可，不用判断Log了。
	int m = ui.passageXCombox->currentData().toInt();
	int n = ui.dataUnitXCombox->currentData().toInt();
	vectorX = childPlotWidget->origialDataList->at(ui.passageXCombox->currentData().toInt())->at(ui.dataUnitXCombox->currentData().toInt());
	vectorY = childPlotWidget->origialDataList->at(ui.passageYCombox->currentData().toInt())->at(ui.dataUnitYCombox->currentData().toInt());

	QVector<double> vecX;
	QVector<double> vecY;
	for (int i = 0; i < vectorX->size(); i++)
	{
		vecX.append(vectorX->at(i));
		vecY.append(vectorY->at(i));
	}
	

	d_plot->addCurve(colorName, vecX, vecY);
	d_plot->replot();
}

/**
* @brief 更新当前窗口中所有设门的颜色
*/
void PlotWidget::updateGateColorSample(PlotWidget* parentWidget)
{

	//先清空父类的临时曲线
	parentWidget->d_plot->clearTempCurve();

	//绘画出各个设门的曲线
	QList<GateStorage*> gateList = parentWidget->m_gateStorageList;
	for (int i = 0; i < gateList.size(); i++)
	{
		GateStorage* gate = gateList.at(i);

		PlotWidget* childPlotWidget = (PlotWidget*)gate->getPlotWidget();

		//childPlotWidget->updateSamples();
		//在父亲画布上，更新自己的儿子节点
		parentWidget->updateChildGateScatterSamples(childPlotWidget, gate->getGateColorName());
		//再更新儿子的后代节点
		putColorAllChildren(parentWidget, childPlotWidget);
		//最后在儿子画布上继续更新
		updateGateColorSample(childPlotWidget);
		////更新自己的子子孙孙。
		//if (childPlotWidget->m_gateStorageList.size() != 0)
		//{
		//	//先把孙子们在根上绘图一下
		//	for (int j = 0; j < childPlotWidget->m_gateStorageList.size(); j++)
		//	{
		//		GateStorage* childGate = childPlotWidget->m_gateStorageList.at(j);
		//		PlotWidget* grandSonPlotWidget = (PlotWidget*)childGate->getPlotWidget();
		//		
		//		parentWidget->updateChildGateScatterSamples(grandSonPlotWidget, childGate->getGateColorName());
		//	}

		//	//再去儿子节点上递归，绘图
		//	updateGateColorSample(childPlotWidget);
		//}
		//plotWidget->updateSamples();
	}
}

/**
* @brief 将parentWiget节点下所有儿子，孙子等等孩子，全绘制在rootWidget上。
*/
void PlotWidget::putColorAllChildren(PlotWidget* rootWidget, PlotWidget* parentWiget)
{
	//还有孩子
	if (parentWiget->m_gateStorageList.size() != 0)
	{
		//先把孙子们在根上绘图一下
		for (int j = 0; j < parentWiget->m_gateStorageList.size(); j++)
		{
			GateStorage* childGate = parentWiget->m_gateStorageList.at(j);
			PlotWidget* childPlotWidget = (PlotWidget*)childGate->getPlotWidget();

			rootWidget->updateChildGateScatterSamples(childPlotWidget, childGate->getGateColorName());

			putColorAllChildren(rootWidget,childPlotWidget);
		}

	}
	
}