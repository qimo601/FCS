#include "Plot.h"
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
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

Plot::Plot(QWidget *parent)
: QwtPlot(parent),
d_curve(NULL)
{

	canvas()->setStyleSheet(
		"border: 1px solid Black;"
		"border-radius: 15px;"
		"background-color:#FFFFFF;"
		);

	// attach curve
	d_curve = new QwtPlotCurve("Scattered Points");
	//设置颜色
	QColor c(42,93,169);
	d_curve->setPen(c, 1);

	// when using QwtPlotCurve::ImageBuffer simple dots can be
	// rendered in parallel on multicore systems.
	d_curve->setRenderThreadCount(0); // 0: use QThread::idealThreadCount()

	d_curve->attach(this);

	setSymbol(NULL);

	// 重新调整画布，根据鼠标左键
	(void)new QwtPlotPanner(canvas());

	//支持滑轮放大缩小zoom in/out with the wheel
	QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(canvas());
	magnifier->setMouseButton(Qt::NoButton);

	//右键测量 distanve measurement with the right mouse button
	DistancePicker *picker = new DistancePicker(canvas());
	picker->setMousePattern(QwtPlotPicker::MouseSelect1, Qt::RightButton);
	picker->setRubberBandPen(QPen(Qt::blue));
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