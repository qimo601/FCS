#include "Plot.h"
#include <qwt_plot_magnifier.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_widget.h>
class DistancePicker : public QwtPlotPicker
{
public:
	//提供选择类
	DistancePicker(QWidget *canvas) :
		QwtPlotPicker(canvas)
	{
		//设置跟踪模式
		setTrackerMode(QwtPicker::ActiveOnly);
		//设置一个状态机，并删除上一个
		setStateMachine(new QwtPickerDragLineMachine());
		//设置橡胶圈样式：多边形
		setRubberBand(QwtPlotPicker::PolygonRubberBand);
	}
	//将位置转换成字符串
	virtual QwtText trackerTextF(const QPointF &pos) const
	{
		QwtText text;

		const QPolygon points = selection();//选择的点
		if (!points.isEmpty())
		{
			QString num;
			num.setNum(QLineF(pos, invTransform(points[0])).length());

			QColor bg(Qt::white);
			bg.setAlpha(200);

			text.setBackgroundBrush(QBrush(bg));
			text.setText(num);
		}
		return text;
	}
};


class Zoomer : public QwtPlotZoomer
{
public:
	Zoomer(int xAxis, int yAxis, QWidget *canvas) :
		QwtPlotZoomer(xAxis, yAxis, canvas)
	{
		//setTrackerMode(QwtPicker::AlwaysOff);
		//setRubberBand(QwtPicker::NoRubberBand);

		//// RightButton: zoom out by 1
		//// Ctrl+RightButton: zoom out to full size

		//setMousePattern(QwtEventPattern::MouseSelect2,
		//	Qt::RightButton, Qt::ControlModifier);
		//setMousePattern(QwtEventPattern::MouseSelect3,
		//	Qt::RightButton);
	}
};


Plot::Plot(QWidget *parent)
: QwtPlot(parent),
d_curve(NULL)
{
	setAutoFillBackground(true);
	setPalette(QColor("#D4D3CC"));//plot背景色
	setTitle("散点图显示");//画布标题
	canvas()->setStyleSheet(
		"border: 1px solid #666666;"
		"border-radius: 15px;"
		"background-color:#FFFFFF;"
		);//画布背景色
	canvas()->setFocusPolicy(Qt::StrongFocus);

	////设置画布
	//QwtPlotCanvas *canvas = new QwtPlotCanvas();
	//canvas->setLineWidth(2);
	//canvas->setFrameStyle(QFrame::Box | QFrame::Sunken);
	//canvas->setBorderRadius(10);

	//QPalette canvasPalette(QColor("Plum"));
	//canvasPalette.setColor(QPalette::Foreground, QColor("Indigo"));
	//canvas->setPalette(canvasPalette);

	//setCanvas(canvas);


	// attach curve
	d_curve = new QwtPlotCurve("Scattered Points");
	//设置颜色
	QColor c(42,93,169);
	d_curve->setPen(c, 2);

	// when using QwtPlotCurve::ImageBuffer simple dots can be
	// rendered in parallel on multicore systems.
	d_curve->setRenderThreadCount(0); // 0: use QThread::idealThreadCount()

	d_curve->attach(this);

	setSymbol(NULL);

	// 平移画布，根据鼠标左键
	d_panner = new QwtPlotPanner(canvas());
	d_panner->setEnabled(false);

	//支持滑轮放大缩小zoom in/out with the wheel
	QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(canvas());
	magnifier->setMouseButton(Qt::RightButton);//默认就是右键鼠标

	//右键测量 distanve measurement with the right mouse button
	DistancePicker *picker = new DistancePicker(canvas());
	picker->setMousePattern(QwtPlotPicker::MouseSelect1, Qt::RightButton);
	picker->setRubberBandPen(QPen(Qt::blue));

	d_grid = new QwtPlotGrid();
	d_grid->setPen(QColor(215, 215, 215), 0.0, Qt::DashLine);
	d_grid->enableX(true);
	d_grid->enableXMin(false);
	d_grid->enableY(true);
	d_grid->enableYMin(false);
	d_grid->attach(this);
	//坐标轴刻度修饰
	QwtScaleWidget *scaleXWidget = this->axisWidget(QwtPlot::xBottom);//x轴刻度控件
	scaleXWidget->setStyleSheet(
		"color:#666666;"
		);
	QwtScaleWidget *scaleYWidget = this->axisWidget(QwtPlot::yLeft);//x轴刻度控件
	scaleYWidget->setStyleSheet(
		"color:#666666;"
		);
	this->setAxisScale(QwtPlot::xBottom, 4000000, 6000000);//设置x轴坐标刻度大小
	this->setAxisScale(QwtPlot::yLeft, 4000000, 6000000);//设置y轴坐标刻度大小

	//this->setFocusPolicy(Qt::TabFocus);//设置画布聚焦策略为键盘TAB，这样父类可以影响到子控件

	//放大器
	d_zoomer = new Zoomer(QwtPlot::xBottom, QwtPlot::yLeft,this->canvas());
	d_zoomer->setRubberBand(QwtPicker::RectRubberBand);
	d_zoomer->setRubberBandPen(QColor(Qt::green));
	d_zoomer->setTrackerMode(QwtPicker::ActiveOnly);
	d_zoomer->setTrackerPen(QColor(Qt::white));
	d_zoomer->setEnabled(false);


}

Plot::~Plot()
{

}
void Plot::setSymbol(QwtSymbol *symbol)
{
	//设置一个符号
	d_curve->setSymbol(symbol);

	if (symbol == NULL)
	{
		d_curve->setStyle(QwtPlotCurve::Dots);
	}
}

void Plot::setSamples(const QVector<QPointF> &samples)
{
	/**指定曲线绘画类型为ImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	d_curve->setPaintAttribute(
		QwtPlotCurve::ImageBuffer, samples.size() > 1000);

	d_curve->setSamples(samples);
}
void Plot::setRawSamples(const double * xData,	const double * 	yData,	int size)
{
	/**指定曲线绘画类型为ImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	d_curve->setPaintAttribute(
		QwtPlotCurve::ImageBuffer, size > 1000);

	d_curve->setRawSamples(xData, yData,size);
}
/**
* @brief 设置背景线是否显示
*/
void Plot::setGridEnable(bool checked)
{
	
	d_grid->enableX(checked);
	d_grid->enableXMin(false);
	d_grid->enableY(checked);
	d_grid->enableYMin(false);

	replot();
}
/**
* @brief 设置放大/缩小按钮功能启用
*/
void Plot::enableZoomMode(bool checked)
{
	d_zoomer->setEnabled(checked);
	d_zoomer->zoom(0);
	if (checked)
	{
		canvas()->setCursor(QCursor(Qt::CrossCursor));
	}
	else
	{
		canvas()->setCursor(QCursor(Qt::ArrowCursor));
	}
	
}
/**
* @brief 设置平移功能启用
*/
void Plot::enablePannerMode(bool checked)
{
	d_panner->setEnabled(checked);
	if (checked)
	{
		canvas()->setCursor(QCursor(Qt::SizeAllCursor));
	}
	else
	{
		canvas()->setCursor(QCursor(Qt::ArrowCursor));
	}
}