#include "Plot.h"
#include <qwt_plot_magnifier.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_layout.h>

//重新绘制刻度标尺
class OtherScaleDraw : public QwtScaleDraw
{
public:
	OtherScaleDraw()
	{
		setTickLength(QwtScaleDiv::MinorTick, 1);
		setTickLength(QwtScaleDiv::MediumTick, 2);
		setTickLength(QwtScaleDiv::MajorTick, 4);

		enableComponent(QwtScaleDraw::Backbone, true);
		//setLabelRotation(-20.0);

		setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	}

	//刻度标签值
	virtual QwtText label(double value) const
	{
		QwtText lbl ="";
		
		return lbl;
	}

private:
	const QStringList d_labels;
};

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

class CrossPicker : public QwtPlotPicker
{
public:
	//提供选择类
	CrossPicker(QWidget *canvas) :
		QwtPlotPicker(canvas)
	{

		setAxis(QwtPlot::xBottom, QwtPlot::yLeft);
		//设置一个状态机，并删除上一个
		setStateMachine(new QwtPickerDragPointMachine());
		setRubberBandPen(QColor(Qt::red));
		//设置橡胶圈样式：十字形
		setRubberBand(QwtPicker::CrossRubberBand);
		setTrackerPen(QColor(Qt::blue));
		//设置跟踪模式
		setTrackerMode(QwtPicker::ActiveOnly);
		setEnabled(false);
	}
	//将位置转换成字符串
	virtual QwtText trackerTextF(const QPointF &pos) const
	{
		QwtText text;

		const QPolygon points = selection();//选择的点
		if (!points.isEmpty())
		{
			QString num;
			QPoint point = points[0];
			QPointF point2 = invTransform(point);
			num = QString("%1,%2").arg(point2.x()).arg(point2.y());
			QColor bg(Qt::white);
			bg.setAlpha(200);

			text.setBackgroundBrush(QBrush(bg));
			text.setText(num);
		}
		return text;
	}

	virtual void 	reset()
	{
		QwtPlotPicker::reset();
	}
	//virtual void 	begin()
	//{

	//}

	//virtual void 	append(const QPoint &)
	//{

	//}

	virtual void 	move(const QPoint & pos)
	{
		QwtPlotPicker::move(pos);
	}

	virtual void append(const QPoint & 	pos)
	{
		QwtPlotPicker::append(pos);
	}

	virtual void 	remove()
	{
		/*if (d_data->isActive)
		{
		const int idx = d_data->pickedPoints.count() - 1;
		if (idx > 0)
		{
		const int idx = d_data->pickedPoints.count();

		const QPoint pos = d_data->pickedPoints[idx - 1];
		d_data->pickedPoints.resize(idx - 1);

		updateDisplay();
		Q_EMIT removed(pos);
		}
		}*/
		QwtPlotPicker::remove();
		int m = 0;
	}
	virtual bool 	end(bool ok = false)
	{
		/*QwtPlotPicker::end(ok);
		return true;*/
		if (!ok)
			return false;

		QwtPlot *plot = QwtPlotPicker::plot();
		if (!plot)
			return false;

		const QPolygon points = selection();
		if (points.count() == 0)
			return false;

		QwtPickerMachine::SelectionType selectionType =
			QwtPickerMachine::NoSelection;

		if (stateMachine())
			selectionType = stateMachine()->selectionType();

		switch (selectionType)
		{
		case QwtPickerMachine::PointSelection:
		{
												 const QPointF pos = invTransform(points.first());
												 Q_EMIT selected(pos);
												 break;
		}
		case QwtPickerMachine::RectSelection:
		{
												if (points.count() >= 2)
												{
													const QPoint p1 = points.first();
													const QPoint p2 = points.last();

													const QRect rect = QRect(p1, p2).normalized();
													Q_EMIT selected(invTransform(rect));
												}
												break;
		}
		case QwtPickerMachine::PolygonSelection:
		{
												   QVector<QPointF> dpa(points.count());
												   for (int i = 0; i < points.count(); i++)
													   dpa[i] = invTransform(points[i]);

												   Q_EMIT selected(dpa);
		}
		default:
			break;
		}

		return true;
	}

	

};
//矩形设门
class RectPicker : public QwtPlotPicker
{
public:
	//提供选择类
	RectPicker(QWidget *canvas) :
		QwtPlotPicker(canvas)
	{

		setAxis(QwtPlot::xBottom, QwtPlot::yLeft);
		setResizeMode(QwtPicker::Stretch);//变形模式
		//设置一个状态机，并删除上一个
		setStateMachine(new QwtPickerDragRectMachine());
		setRubberBandPen(QColor(Qt::red));
		//设置橡胶圈样式：椭圆
		setRubberBand(QwtPicker::RectRubberBand);
		setTrackerPen(QColor(Qt::blue));
		//设置跟踪模式
		setTrackerMode(QwtPicker::ActiveOnly);
		setEnabled(false);
	}
	//将位置转换成字符串
	virtual QwtText trackerTextF(const QPointF &pos) const
	{
		QwtText text;

		const QPolygon points = selection();//选择的点
		if (!points.isEmpty())
		{
			QString num;
			QPoint point = points[0];
			QPointF point2 = invTransform(point);
			num = QString("(%1,%2),(,)").arg(point2.x()).arg(point2.y());
			QColor bg(Qt::white);
			bg.setAlpha(200);
			if (points.size() == 2)
			{

				QPointF point0 = invTransform(points[0]);
				QPointF point1 = invTransform(points[1]);
				num = QString("(%1,%2),(%3,%4)").arg(point0.x()).arg(point0.y()).arg(point1.x()).arg(point1.y());
			}
			text.setBackgroundBrush(QBrush(bg));
			text.setText(num);
		}
		return text;
	}
	virtual void 	move(const QPoint & pos)
	{
		QwtPlotPicker::move(pos);
	}
	virtual void 	stretchSelection(const QSize &oldSize, const QSize &newSize)
	{
		QwtPlotPicker::stretchSelection(oldSize, newSize);//拉伸
		//if (oldSize.isEmpty())
		//{
		//	// avoid division by zero. But scaling for small sizes also
		//	// doesn't make much sense, because of rounding losses. TODO ...
		//	return;
		//}
		//const double xRatio =
		//	double(newSize.width()) / double(oldSize.width());
		//const double yRatio =
		//	double(newSize.height()) / double(oldSize.height());

		//for (int i = 0; i < int(d_data->pickedPoints.count()); i++)
		//{
		//	QPoint &p = d_data->pickedPoints[i];
		//	p.setX(qRound(p.x() * xRatio));
		//	p.setY(qRound(p.y() * yRatio));

		//	Q_EMIT changed(d_data->pickedPoints);
		//}
		QwtPlotPicker::updateDisplay();//显示
	}
	virtual bool 	end(bool ok)
	{
		if (!ok)//更改代码处：，正常结束后，并不停止。只有reset时候，end(false)停止选择，重置状态机
			QwtPlotPicker::end(ok);
		if (!ok)
			return false;

		QwtPlot *plot = QwtPlotPicker::plot();
		if (!plot)
			return false;

		const QPolygon points = selection();
		if (points.count() == 0)
			return false;

		QwtPickerMachine::SelectionType selectionType =
			QwtPickerMachine::NoSelection;

		if (stateMachine())
			selectionType = stateMachine()->selectionType();

		switch (selectionType)
		{
		case QwtPickerMachine::PointSelection:
		{
												 const QPointF pos = invTransform(points.first());
												 Q_EMIT selected(pos);
												 break;
		}
		case QwtPickerMachine::RectSelection:
		{
												if (points.count() >= 2)
												{
													const QPoint p1 = points.first();
													const QPoint p2 = points.last();
													QPointF pF1 = invTransform(p1);
													QPointF pF2 = invTransform(p2);
													const QRect rect = QRect(p1, p2).normalized();
													QPoint pp1 = rect.topLeft();
													QPoint pp2 = rect.bottomRight();
													//const QRect rect = QRect(p1, p2);
													QRectF rect1 = invTransform(rect);
													QPointF topLeft = rect1.topLeft();
													QPointF bottomRight = rect1.bottomRight();
													Q_EMIT selected(invTransform(rect));
												}
												break;
		}
		case QwtPickerMachine::PolygonSelection:
		{
												   QVector<QPointF> dpa(points.count());
												   for (int i = 0; i < points.count(); i++)
													   dpa[i] = invTransform(points[i]);

												   Q_EMIT selected(dpa);
		}
		default:
			break;
		}
		return true;
	}
	virtual void reset()
	{
		QwtPicker::reset();
	}
	virtual void 	remove()
	{
		QwtPlotPicker::remove();
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
	
	//plotLayout()->setCanvasMargin(0);
	plotLayout()->setAlignCanvasToScales(true);//设置对齐画布、坐标轴、刻度 会掩盖setCanvasMargin()
	setPalette(QColor("#FFFFFF"));//plot背景色
	//setStyleSheet(
	//	"border-top: 1px solid #9D9D9D;"
	//	"border-radius: 0px;"
	//	"margin-right: 10px;"
	//	"background-color:#FFFFFF;"
	//	);//画布背景色
	setTitle("散点图显示");//画布标题

	//设置画布
	canvas = new QwtPlotCanvas();

	canvas->setStyleSheet(
		"border: 0px solid #000000;"
		"border-radius: 0px;"
		"background-color:#FFFFFF;"
		"margin:0 0px;"
		);//画布背景色
	setCanvas(canvas);
    canvas->setFrameStyle(QFrame::Box | QFrame::Sunken);
	canvas->setFocusPolicy(Qt::StrongFocus);
	canvas->setBorderRadius(0);
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
	QColor penColor("DarkBlue");
	QColor brushColor("#DDE9FD");
	d_curve->setPen(penColor, 2);
	//d_curve->setBrush(brushColor);//设置笔刷
	d_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine);//设置描述的样式
	// when using QwtPlotCurve::ImageBuffer simple dots can be
	// rendered in parallel on multicore systems.
	d_curve->setRenderThreadCount(0); // 0: use QThread::idealThreadCount()

	d_curve->attach(this);

	setSymbol(NULL);

	// 平移画布，根据鼠标左键
	d_panner = new QwtPlotPanner(canvas);
	d_panner->setEnabled(false);

	//支持滑轮放大缩小zoom in/out with the wheel
	QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(canvas);
	magnifier->setMouseButton(Qt::RightButton);//默认就是右键鼠标

	//右键测量 distanve measurement with the right mouse button
	DistancePicker *picker = new DistancePicker(canvas);
	picker->setMousePattern(QwtPlotPicker::MouseSelect1, Qt::RightButton);
	picker->setRubberBandPen(QPen(Qt::blue));

	//十字线
	d_picker = new CrossPicker(canvas);
	connect(d_picker, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));
	//十字线
	d_picker2 = new CrossPicker(canvas);
	d_picker2->setRubberBandPen(QColor(Qt::green));

	connect(d_picker2, SIGNAL(selected(QPointF)), this, SLOT(selectedCrossPickerSlot(QPointF)));

	//背景方格
	d_grid = new QwtPlotGrid();
	//d_grid->setPen(QColor(215, 215, 215), 0.0, Qt::DashLine);
	d_grid->enableX(true);
	d_grid->enableXMin(true);
	d_grid->enableY(true);
	d_grid->enableYMin(false);

	d_grid->setMajorPen(Qt::gray, 0, Qt::DotLine);
	d_grid->setMinorPen(QColor("#DDDDDD"), 0, Qt::DotLine);

	d_grid->attach(this);
	//默认坐标轴刻度
	this->setAxisScale(QwtPlot::xBottom, 0, 1e6);//设置x轴坐标刻度大小
	//setAxisMaxMajor(QwtPlot::xBottom, 6);//主要刻度的最大间隔数量
	//setAxisMaxMinor(QwtPlot::xBottom, 9);//次要刻度的最大间隔数量
	this->setAxisScale(QwtPlot::yLeft, 0, 1e6);//设置y轴坐标刻度大小
	QwtScaleWidget *scaleXWidget = this->axisWidget(QwtPlot::xBottom);//x轴刻度控件
	scaleXWidget->setStyleSheet(
		"color:#666666;"
		);
	const int fmh = QFontMetrics(scaleXWidget->font()).height();
	scaleXWidget->setMinBorderDist(0, fmh / 2);//设置刻度的边界最小值，防止因为标签变化，引起跳动  
	QwtScaleWidget *scaleYWidget = this->axisWidget(QwtPlot::yLeft);//x轴刻度控件
	scaleYWidget->setStyleSheet(
		"color:#666666;"
		);

	//其它两坐标也显示
	this->setAxisScaleDraw(QwtPlot::xTop, new OtherScaleDraw());
	this->setAxisScaleDraw(QwtPlot::yRight, new OtherScaleDraw());
	QwtScaleWidget *scaleXTopWidget = this->axisWidget(QwtPlot::xTop);//x轴刻度控件
	scaleXTopWidget->setStyleSheet(
		"color:#666666;"
		);
	QwtScaleWidget *scaleYRightWidget = this->axisWidget(QwtPlot::yRight);//x轴刻度控件
	scaleYRightWidget->setStyleSheet(
		"color:#666666;"
		);
	enableAxis(QwtPlot::yRight);
	enableAxis(QwtPlot::xTop);
	setAxisAutoScale(QwtPlot::yRight, true);
	setAxisAutoScale(QwtPlot::xTop, true);

	this->setAxisScale(QwtPlot::xTop, 0, 1e6);//设置y轴坐标刻度大小
	this->setAxisScale(QwtPlot::yRight, 0, 1e6);//设置y轴坐标刻度大小


	//this->setFocusPolicy(Qt::TabFocus);//设置画布聚焦策略为键盘TAB，这样父类可以影响到子控件

	//放大器
	d_zoomer = new Zoomer(QwtPlot::xBottom, QwtPlot::yLeft, canvas);
	d_zoomer->setRubberBand(QwtPicker::RectRubberBand);
	d_zoomer->setRubberBandPen(QColor(Qt::green));
	d_zoomer->setTrackerMode(QwtPicker::ActiveOnly);
	d_zoomer->setTrackerPen(QColor(Qt::white));
	d_zoomer->setEnabled(false);

	//矩形
	d_rectPicker = new RectPicker(canvas);
	connect(d_rectPicker, SIGNAL(selected(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));

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


void Plot::setSamples(const QVector< double > & xData,	const QVector< double > & 	yData)
{
	/**指定曲线绘画类型为ImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	/*d_curve->setPaintAttribute(
	QwtPlotCurve::ImageBuffer, size > 1000);*/

	d_curve->setSamples(xData, yData);
}
void Plot::setRawSamples(const double * xData,	const double * 	yData,	int size)
{
	/**指定曲线绘画类型为ImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	/*d_curve->setPaintAttribute(
		QwtPlotCurve::ImageBuffer, size > 1000);*/

	d_curve->setRawSamples(xData, yData,size);
}
/**
* @brief 设置背景线是否显示
*/
void Plot::setGridEnable(bool checked)
{
	
	d_grid->enableX(checked);
	d_grid->enableXMin(checked);
	d_grid->enableY(checked);
	d_grid->enableYMin(false);
	if (checked)
	{
		//QColor brushColor("#DDE9FD");
		//d_curve->setBrush(brushColor);//设置笔刷
	}
	else
		d_curve->setBrush(Qt::NoBrush);
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
		canvas->setCursor(QCursor(Qt::CrossCursor));
	}
	else
	{
		canvas->setCursor(QCursor(Qt::ArrowCursor));
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
		canvas->setCursor(QCursor(Qt::SizeAllCursor));
	}
	else
	{
		canvas->setCursor(QCursor(Qt::ArrowCursor));
	}
}
/**
* @brief 设置直方图统计模式的样式
*/
void Plot::enableStaticsMode()
{
	//设置统计曲线样式
	//设置颜色
	QColor penColor("#325481");
	QColor brushColor("#DDE9FD");
	d_curve->setPen(penColor, 2);
	d_curve->setBrush(brushColor);//设置笔刷
	d_curve->setStyle(QwtPlotCurve::Lines);
	d_curve->setRenderHint(QwtPlotItem::RenderAntialiased);

	replot();
}
/**
* @brief 设置散点图模式的样式
*/
void Plot::enableScatterMode()
{
	//设置统计曲线样式
	QColor penColor("DarkBlue");
	d_curve->setPen(penColor,2);
	d_curve->setBrush(Qt::NoBrush);
	d_curve->setStyle(QwtPlotCurve::Dots);

	//坐标轴刻度修饰
	this->setAxisScale(QwtPlot::xBottom, 0, 1e6);//设置x轴坐标刻度大小
	this->setAxisScale(QwtPlot::yLeft, 0, 1e6);//设置y轴坐标刻度大小
	replot();
}
/**
* @brief 设置跟踪鼠标显示当前值
*/
void Plot::enableViewTrueValue(bool mode)
{
	d_picker->setEnabled(mode);
	if (!mode)
	{
		//d_picker2->remove();
		d_picker->setTrackerMode(QwtPicker::AlwaysOff);
	}
	else
	{
		d_picker2->setTrackerMode(QwtPicker::AlwaysOff);
		d_picker->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//d_picker->setStateMachine(new QwtPickerDragPointMachine());
}
/**
* @brief 设置跟踪鼠标显示当前值
*/
void Plot::enableViewTrueValue2(bool mode)
{
	d_picker2->setEnabled(mode);
	if (!mode)
	{
		//d_picker2->remove();
		d_picker2->setTrackerMode(QwtPicker::AlwaysOff);
	}
	else
	{
		d_picker2->setTrackerMode(QwtPicker::ActiveOnly);
		d_picker->setTrackerMode(QwtPicker::AlwaysOff);
	}
	//d_picker->setStateMachine(new QwtPickerDragPointMachine());
}
/**
* @brief 启用矩形设门
*/
void Plot::enableRectPicker(bool mode)
{
	d_rectPicker->setEnabled(mode);
	if (!mode)
	{


		d_rectPicker->reset();//状态机清空reset the state machine and terminate ( end(false) ) the selection
		//d_rectPicker->remove(); //remove the last point of the selection The removed() signal is emitted.
		//d_rectPicker->remove();
		//d_rectPicker->end(true);
	}
}
/**
* @brief 增加-测试选择
*/
void Plot::setUpBtnMode(bool mode)
{
	const QPolygon points = d_rectPicker->selection();//选择的点
	QPoint p0 = points[0];
	QPoint p1 = points[1];
	p1.setX(p1.x() + 0);
	p1.setY(p1.y() + 10);
	QSize size1(p1.x() - p0.x(), p1.y() - p0.y());
	QSize size2 = size1 * 1.05;
	d_rectPicker->stretchSelection(size1, size2);
	//d_rectPicker->move(p1);//移动最后一点
}
/**
* @brief 减少-测试选择
*/
void Plot::setDownBtnMode(bool mode)
{
	const QPolygon points = d_rectPicker->selection();//选择的点
	QPoint p0 = points[0];
	QPoint p1 = points[1];
	p1.setX(p1.x() + 0);
	p1.setY(p1.y() + 10);
	QSize size1(p1.x() - p0.x(), p1.y() - p0.y());
	QSize size2 = size1 * 0.05;
	d_rectPicker->stretchSelection(size1, size2);
	//d_rectPicker->move(p1);//移动最后一点
}
void Plot::selectedCrossPickerSlot(QPointF pointf)
{
	emit selectedCrossPicker(pointf);
}
void Plot::selectedRectPickerSlot(QRectF rectf)
{
	emit selectedRectPicker(rectf);
}