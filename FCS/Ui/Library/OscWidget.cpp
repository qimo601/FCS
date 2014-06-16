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
//m_interval_x设置大于1024，方便观察边界值
{
	ui.setupUi(this);
	//初始化
	init();
}


OscWidget::~OscWidget()
{
	if (d_origin!=0)
		delete d_origin;//删除十字中间线
	if (grid != 0)
		delete grid;//删除背景方格
	if (canvas != 0)
		delete canvas;//删除画布
	if (legend != 0)
		delete legend;//删除描述
	//删除曲线数组
	while (m_curveList.size() != 0)
	{
		delete m_curveList.takeFirst();
	}
	//关闭定时器
	if (m_timerId != 0)
		killTimer(m_timerId);
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
	initAnimation();//初始化属性窗口及其动画
	this->setMouseTracking(true);
	m_timerId = 0;//初始化

	readOscThread = new ReadOscThread();//示波器数据读取线程
	connect(readOscThread, SIGNAL(oscReadySignal()), this, SLOT(updateOscPlot()));
	
}
/**
* @brief 初始化属性窗口及其动画
*/
void OscWidget::initAnimation()
{	//属性窗口
	propertyWidget = new PropertyWidget(this);
	propertyWidget->setVisible(false);
	//属性窗口显示的动画
	showPropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry", this);

	//属性窗口消失的动画
	closePropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry", this);
	//
	connect(this, SIGNAL(propertyClicked()), this, SLOT(on_propertyBtn_clicked()));

	connect(closePropertyAnimation, SIGNAL(finished()), this, SLOT(setVisiblePropertyWidget()));
}
/**
* @brief 初始化Plot
*/
void OscWidget::initPlot()
{
	//设置画布
	canvas = new QwtPlotCanvas();//画布
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
	
	legend = new QwtLegend();//曲线描述
	legend->setDefaultItemMode(QwtLegendData::Checkable);//设置描述是QCheckBox类型
	ui.oscPlot->insertLegend(legend, QwtPlot::RightLegend);//插入位置，可以分别是上下左右
	//初始化曲线
	for (int i = 1; i < 9; i++)
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

		/*oscCurve->setPen(c, 1);
		QColor bg(Qt::blue);
		bg.setAlpha(150);
		oscCurve->setBrush(QBrush(bg));
		oscCurve->setStyle(QwtPlotCurve::Lines);*/

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

	grid = new QwtPlotGrid();
	grid->setPen(Qt::gray, 0.0, Qt::DotLine);
	grid->enableX(true);
	grid->enableXMin(true);
	grid->enableY(true);
	grid->enableYMin(true);
	grid->attach(ui.oscPlot);

	//添加一个中间十字标记
	d_origin = new QwtPlotMarker();
	d_origin->setLineStyle(QwtPlotMarker::Cross);
	d_origin->setValue(m_markPos.x(), m_markPos.y());
	d_origin->setLinePen(Qt::gray, 0.0, Qt::DashLine);
	d_origin->attach(ui.oscPlot);
// 
// 	//标记
// 	QwtPlotMarker* d_marker = new QwtPlotMarker();
// 	//标记值
// 	d_marker->setValue(0, 20);
// 	QwtText text("alert");
// 	text.setFont(QFont("Helvetica", 10));
// 	//text.setFont(QFont("Helvetica", 10, QFont::Bold));
// 	text.setColor(QColor(200, 15, 370));
// 	//设置标记线的标签
// 	d_marker->setLabel(text);
// 	d_marker->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
// 	//标记线的线风格 水平线，竖直线，十字线
// 	d_marker->setLineStyle(QwtPlotMarker::HLine);
// 	d_marker->setLinePen(QPen(Qt::red, 0, Qt::DashDotLine));
// 	//标记线的标志符
// 	d_marker->setSymbol(new QwtSymbol(QwtSymbol::Diamond,
// 		QColor(Qt::yellow), QColor(Qt::red), QSize(7, 7)));
// 	d_marker->attach(ui.oscPlot);


	//刷新plot
	ui.oscPlot->replot();


	//初始化定时器，自动更新画布
	//m_timer = new QTimer(this);
	//connect(m_timer, SIGNAL(timeout()), this, SLOT(updateOscPlot()));

}
/**
* @brief 初始化WheelBox
*/
void OscWidget::initWheelBox()
{
	ui.xScalewheelBox->setProperty("X轴调节", 0, 100000, 40);
	ui.yScalewheelBox->setProperty("Y轴调节", 0, 100000, 400);
	ui.xMarkwheelBox->setProperty("X轴中间线", 0, 100000, 40);
	ui.yMarkwheelBox->setProperty("Y轴中间与线", 0, 100000,400);

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
* @brief 更新绘图数据
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
* @brief 开始示波器采集
*/
void OscWidget::on_startOscAcqBtn_clicked()
{
	emit startOscAcq();
	//停止采集命令
	VoCmd voCmd;
	voCmd.setCmd(8);
	voCmd.setLength(0);
	bllControl.sendCmd(voCmd);


	m_timerId = startTimer(10);//定时器读取
	//readOscThread->start();//示波器线程读取
	//readOscThread->setGoOn(true);//启动真读循环
	ui.startOscAcqBtn->setEnabled(false);
	ui.stopOscAcqBtn->setEnabled(true);
}

/**
* @brief 停止示波器采集
*/
void OscWidget::on_stopOscAcqBtn_clicked()
{
	//停止采集命令
	VoCmd voCmd;
	voCmd.setCmd(9);
	voCmd.setLength(0);
	bllControl.sendCmd(voCmd);
	//关闭定时器
	killTimer(m_timerId);
	//readOscThread->setGoOn(false);//停止真读循环，线程进入待读阶段
	ui.startOscAcqBtn->setEnabled(true);
	ui.stopOscAcqBtn->setEnabled(false);
}
void OscWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
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
* @brief 设置X轴坐标-范围
*/
void OscWidget::setXAxisScale(double interval)
{
	//判断是否有效
	if (interval > 0.0 && interval != m_interval_x.width())
	{
		double xChange = (interval - m_interval_x.width()) / 2;
		m_interval_x.setMaxValue(m_interval_x.maxValue() + xChange);//重新设置间隔
		m_interval_x.setMinValue(m_interval_x.minValue() - xChange);//重新设置间隔
		//重新设置x轴坐标范围
		ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());
		//更新一下mark是否变化，其实不会变
		ui.xMarkwheelBox->setValue(m_markPos.x());
		ui.oscPlot->replot();
	}
}
/**
* @brief 设置Y轴坐标-范围
*/
void OscWidget::setYAxisScale(double interval)
{
	//判断是否有效
	if (interval > 0.0 && interval != m_interval_y.width())
	{
		double yChange = (interval - m_interval_y.width())/2;
		m_interval_y.setMaxValue(m_interval_y.maxValue() + yChange);//重新设置间隔
		m_interval_y.setMinValue(m_interval_y.minValue() - yChange);//重新设置间隔
		//重新设置y轴坐标范围
		ui.oscPlot->setAxisScale(QwtPlot::yLeft,  m_interval_y.minValue(),  m_interval_y.maxValue());
		//更新一下mark是否变化，其实不会变
		ui.yMarkwheelBox->setValue(m_markPos.y());
		ui.oscPlot->replot();
	}
}
/**
* @brief 设置X轴中间线
*/
void OscWidget::setXMark(double mark_x)
{
	//判断是否有效
	if (mark_x > 0.0 && mark_x != m_markPos.x())
	{
		double xchange = mark_x - m_markPos.x();
		//设置十字中间线坐标
		m_markPos.setX(mark_x);
		//设置十字中间线具体位置
		d_origin->setValue(m_markPos);
		//更新间隔值
		m_interval_x.setInterval(m_interval_x.minValue() + xchange, m_interval_x.maxValue() + xchange);
		//重新设置x轴坐标范围
		ui.oscPlot->setAxisScale(QwtPlot::xBottom, m_interval_x.minValue(), m_interval_x.maxValue());
		//更新一下mark
		ui.xMarkwheelBox->setValue(m_markPos.x());
		ui.oscPlot->replot();
	}
}
/**
* @brief 设置Y轴中间线
*/
void OscWidget::setYMark(double mark_y)
{
	//判断是否有效
	if (mark_y > 0.0 && mark_y != m_markPos.y())
	{
		double ychange = mark_y - m_markPos.y();
		//设置十字中间线坐标
		m_markPos.setY(mark_y);
		//设置十字中间线具体位置
		d_origin->setValue(m_markPos);
		//更新间隔值
		m_interval_y.setInterval(m_interval_y.minValue() + ychange, m_interval_y.maxValue() + ychange);
		//重新设置y轴坐标范围
		ui.oscPlot->setAxisScale(QwtPlot::yLeft, m_interval_y.minValue(), m_interval_y.maxValue());
		//更新一下mark
		ui.yMarkwheelBox->setValue(m_markPos.y());
		ui.oscPlot->replot();
	}
}
/**
* @brief 设置按钮弹出属性窗口
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
* @brief 鼠标滑动事件
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
* @brief 显示属性窗口
*/
void OscWidget::showPropertyWidget()
{
	propertyWidget->setVisible(true);

	int width = propertyWidget->width();
	int height = propertyWidget->height();

	showPropertyAnimation->setDuration(100);
	QPoint pos = ui.toolFrame->mapTo(this, ui.propertyBtn->pos());
	showPropertyAnimation->setStartValue(QRect(pos.x(), pos.y(), 0, 300));//开始位置
	showPropertyAnimation->setEndValue(QRect(pos.x() - 530, pos.y(), 530, 300));//结束位置

	showPropertyAnimation->start();

}
/**
* @brief 关闭属性窗口
*/
void OscWidget::closePropertyWidget()
{
	int width = propertyWidget->width();
	int height = propertyWidget->height();
	closePropertyAnimation->setDuration(100);
	QPoint pos = ui.toolFrame->mapTo(this, ui.propertyBtn->pos());
	closePropertyAnimation->setStartValue(QRect(pos.x() - width, pos.y(), 530, 300));//开始位置
	closePropertyAnimation->setEndValue(QRect(pos.x(), pos.y(), 0, 300));//结束位置
	closePropertyAnimation->start();
	//propertyWidget->setVisible(false);
}
/**
* @brief 设置属性窗口不可见
*/
void OscWidget::setVisiblePropertyWidget()
{
	propertyWidget->setVisible(false);
	update();
}

/**
* @brief 保存示波器数据
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
		//关闭文件
		if (fclose(USBThread::projectFile) != 0)
			qDebug() << "【on_saveCheckBox_clicked】关闭文件失败，文件名：" << USBThread::fileName;
	}
}