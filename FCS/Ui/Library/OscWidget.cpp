#include "OscWidget.h"
#include <qwt_scale_draw.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>
#include <qwt_legend_label.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>
#include <QTime>
#include <QBitmap>
OscWidget::OscWidget(QWidget *parent)
: QWidget(parent), m_interval_x(0.0, 1028), m_interval_y(0.0,45000)
{
	ui.setupUi(this);
	//初始化
	init();
}


OscWidget::~OscWidget()
{

}

//时间刻度表
class TimeScaleDraw : public QwtScaleDraw
{
public:
	TimeScaleDraw(const QTime &base) :
		baseTime(base)
	{
	}
	virtual QwtText label(double v) const
	{
		//自定义返回的标签类型
		/*QTime upTime = baseTime.addSecs(static_cast<int>(v));
		return upTime.toString();*/

		return QString::number(v);
	}
private:
	QTime baseTime;
};

/**
* @brief 初始化
*/
void OscWidget::init()
{
	initPlot();//初始化plot
	initWheelBox();//初始化滑轮
	//bool m = settingPixmap.load(":/MainWindow/Resources/Images/MainWindow/settings");
	//settingPixmap = settingPixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	//QPixmap pixmapRight(":/MainWindow/Resources/Images/MainWindow/acq");
	//ui.propertyBtn->setMask(settingPixmap.mask());
	propertyWidget = new PropertyWidget(this);
	propertyWidget->setVisible(false);
	showPropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry");
	showPropertyAnimation->setDuration(10000);
	int width = propertyWidget->width();
	int height = propertyWidget->height();
	/*
	int x = ui.propertyBtn->pos().x();
	int y = ui.propertyBtn->pos().y();*/
	showPropertyAnimation->setStartValue(QRect(0, 0, 300, 200));
	showPropertyAnimation->setEndValue(QRect(250, 250, 300, 200));


	//ui.propertyBtn->setMouseTracking(true);//设置鼠标监控轨迹
	this->setMouseTracking(true);

	connect(this, SIGNAL(propertyClicked()), this, SLOT(on_propertyBtn_clicked()));
}
/**
* @brief 初始化Plot
*/
void OscWidget::initPlot()
{
	//设置画布
	QwtPlotCanvas *canvas = new QwtPlotCanvas();//画布
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

	canvas->setBorderRadius(10);//画布四周边框角半径
	ui.oscPlot->setCanvas(canvas);//设置绘图的画布


	ui.oscPlot->plotLayout()->setAlignCanvasToScales(true);//设置对齐画布、坐标轴、刻度
	
	legend = new QwtLegend;//曲线描述
	legend->setDefaultItemMode(QwtLegendData::Checkable);//设置描述是QCheckBox类型
	ui.oscPlot->insertLegend(legend, QwtPlot::RightLegend);//插入位置，可以分别是上下左右
	//初始化曲线
	for (int i = 0; i < 8; i++)
	{
		QPolygonF points;
		for (int j = 0; j < 20; j++)
		{
			points << QPointF(qrand()%1000, qrand()%500) ;
		}
		// add curves
		oscCurve = new QwtPlotCurve(QString("通道%1").arg(i));
		oscCurve->setRenderHint(QwtPlotItem::RenderAntialiased);//抗锯齿
		//设置颜色
		QColor c(qrand() % 255, qrand() % 255, qrand() % 255);
		oscCurve->setPen(c,1);
		//oscCurve->setBrush(c);//填充色

		oscCurve->setZ(oscCurve->z() - i*10);//设置z轴上下先后顺序，哪个曲线在上。


		// 测试数据
		oscCurve->setSamples(points);
		//将曲线附上plot
		oscCurve->attach(ui.oscPlot);

		//设置默认显示曲线
		if (i == 3)
			showCurve(oscCurve, true);//默认显示哪个曲线
		else
			showCurve(oscCurve, false);//不显示显示哪个曲线

		m_curveList.append(oscCurve);//将曲线进入数组
		
	}
	connect(legend, SIGNAL(checked(const QVariant &, bool, int)),
		SLOT(legendChecked(const QVariant &, bool)));//控制曲线显示，注意传递的参数类型
	//设置X轴属性
	ui.oscPlot->setAxisTitle(QwtPlot::xBottom, " 时间[us]");//坐标轴标题-x轴
	
	QTime t(1, 0, 0);
	ui.oscPlot->setAxisScaleDraw(QwtPlot::xBottom,new TimeScaleDraw(t));//设置x轴的刻度绘画
	ui.oscPlot->setAxisLabelRotation(QwtPlot::xBottom, -50.0);//标签旋转50度
	ui.oscPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);
	ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());//设置x轴坐标刻度大小
	/*
	In situations, when there is a label at the most right position of the
	scale, additional space is needed to display the overlapping part
	of the label would be taken by reducing the width of scale and canvas.
	To avoid this "jumping canvas" effect, we add a permanent margin.
	We don't need to do the same for the left border, because there
	is enough space for the overlapping label below the left scale.
	*/

	QwtScaleWidget *scaleWidget = ui.oscPlot->axisWidget(QwtPlot::xBottom);//x轴刻度控件
	const int fmh = QFontMetrics(scaleWidget->font()).height();
	scaleWidget->setMinBorderDist(0, fmh / 2);//设置刻度的边界最小值，防止因为标签变化，引起跳动


	//Y轴配置
	ui.oscPlot->setAxisTitle(QwtPlot::yLeft, "通道值 [无]");//Y轴设置标题
	ui.oscPlot->setAxisScale(QwtPlot::yLeft, m_interval_y.minValue(), m_interval_y.maxValue());//Y轴刻度


	//修饰

	QwtPlotGrid *grid = new QwtPlotGrid();
	grid->setPen(Qt::gray, 0.0, Qt::DotLine);
	grid->enableX(true);
	grid->enableXMin(true);
	grid->enableY(true);
	grid->enableYMin(true);
	grid->attach(ui.oscPlot);

	//添加一个中间十字标记
	QwtPlotMarker* d_origin = new QwtPlotMarker();
	d_origin->setLineStyle(QwtPlotMarker::Cross);
	d_origin->setValue(150, 30);
	d_origin->setLinePen(Qt::gray, 0.0, Qt::DashLine);
	d_origin->attach(ui.oscPlot);

	//标记
	QwtPlotMarker* d_marker = new QwtPlotMarker();
	//标记值
	d_marker->setValue(0, 20);
	QwtText text("alert");
	text.setFont(QFont("Helvetica", 10));
	//text.setFont(QFont("Helvetica", 10, QFont::Bold));
	text.setColor(QColor(200, 15, 370));
	//设置标记线的标签
	d_marker->setLabel(text);
	d_marker->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
	//标记线的线风格 水平线，竖直线，十字线
	d_marker->setLineStyle(QwtPlotMarker::HLine);
	d_marker->setLinePen(QPen(Qt::red, 0, Qt::DashDotLine));
	//标记线的标志符
	d_marker->setSymbol(new QwtSymbol(QwtSymbol::Diamond,
		QColor(Qt::yellow), QColor(Qt::red), QSize(7, 7)));
	d_marker->attach(ui.oscPlot);


	//刷新plot
	ui.oscPlot->replot();


	//初始化定时器，自动更新画布
	m_timer = new QTimer(this);
	//connect(m_timer, SIGNAL(timeout()), this, SLOT(updateOscPlot()));

}
/**
* @brief 初始化WheelBox
*/
void OscWidget::initWheelBox()
{
	ui.xScalewheelBox->setProperty("X轴调节", 0, 100000, 1);
	ui.yScalewheelBox->setProperty("Y轴调节", 0, 100000, 1);
	connect(ui.xScalewheelBox, SIGNAL(valueChanged(double)), this, SLOT(setXAxisScale(double)));
	connect(ui.yScalewheelBox, SIGNAL(valueChanged(double)), this, SLOT(setYAxisScale(double)));
}
/**
* @brief 更新绘图数据
*/
void OscWidget::updateOscPlot()
{
	QVector<double> oscXData;
	QVector<double> oscYData;
	bllDataCenter.getOscData(oscXData,oscYData);
	for (int i = 0; i < Global::oscYData.count(); i++)

	{
		oscCurve = m_curveList[i];
		oscCurve->setSamples(Global::oscXData, Global::oscYData[i]);
	}
	ui.oscPlot->replot();
}
/**
* @brief 开始示波器采集
*/
void OscWidget::on_startOscAcqBtn_clicked()
{
	emit startOscAcq();
	//m_timer->start(100);
	m_clock.start();
	m_timerId = startTimer(10);
	ui.startOscAcqBtn->setEnabled(false);
	ui.stopOscAcqBtn->setEnabled(true);
}

/**
* @brief 停止示波器采集
*/
void OscWidget::on_stopOscAcqBtn_clicked()
{
	killTimer(m_timerId);
	//m_timer->stop();
	ui.startOscAcqBtn->setEnabled(true);
	ui.stopOscAcqBtn->setEnabled(false);
}
void OscWidget::timerEvent(QTimerEvent *event)
{
	//每个100ms更新一次
	if (event->timerId() == m_timerId)
	{
		updateOscPlot();

		

		//const double elapsed = m_clock.elapsed() / 1000.0;
		////3秒后清空
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
* @brief 曲线描述激活槽函数
*/
void OscWidget::legendChecked(const QVariant &itemInfo, bool on)
{
	//识别所选项
	QwtPlotItem *plotItem = ui.oscPlot->infoToItem(itemInfo);
	//如果选中，即显示该曲线
	if (plotItem)
		showCurve(plotItem, on);
}
/**
* @brief 控制一下哪个曲线显示
*/
void OscWidget::showCurve(QwtPlotItem *item, bool on)
{
	item->setVisible(on);
	//获取该绘图的描述
	QwtLegend *lgd = qobject_cast<QwtLegend *>( ui.oscPlot->legend());
	//获取所有描述组件
	QList<QWidget *> legendWidgets =
		lgd->legendWidgets( ui.oscPlot->itemToInfo(item));

	if (legendWidgets.size() == 1)
	{
		//获取这个描述组件的标签值
		QwtLegendLabel *legendLabel =
			qobject_cast<QwtLegendLabel *>(legendWidgets[0]);
		//如果标签有值，即显示
		if (legendLabel)
			legendLabel->setChecked(on);
	}

	ui.oscPlot->replot();
}
/**
* @brief 设置X轴坐标
*/
void OscWidget::setXAxisScale(double interval)
{
	//判断是否有效
	if (interval > 0.0 && interval != m_interval_x.width())
	{
		m_interval_x.setMaxValue(m_interval_x.minValue() + interval);
		ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());

		ui.oscPlot->replot();
	}
}
/**
* @brief 设置Y轴坐标
*/
void OscWidget::setYAxisScale(double interval)
{
	//判断是否有效
	if (interval > 0.0 && interval != m_interval_y.width())
	{
		m_interval_y.setMaxValue(m_interval_y.minValue() + interval);
		ui.oscPlot->setAxisScale(QwtPlot::yLeft, m_interval_y.minValue(), m_interval_y.maxValue());

		ui.oscPlot->replot();
	}
}

/**
* @brief 设置按钮弹出属性窗口
*/
void OscWidget::on_propertyBtn_clicked()
{
	propertyWidget->setVisible(true);
	int x = ui.propertyBtn->pos().x();
	int y = ui.propertyBtn->pos().y();
	propertyWidget->move(QPoint(x, y));
	showPropertyAnimation->start();
}
/**
* @brief 鼠标滑动事件
*/
void OscWidget::mouseMoveEvent(QMouseEvent* event)
{
	int x = mapToGlobal(event->pos()).x();
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
	}

}