#include "Plot.h"
#include <qwt_plot_magnifier.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_layout.h>

//密度图需要的头文件
#include <qwt_raster_data.h>
#include <qwt_color_map.h>
#include "Ui/Library/BarStruct.h"
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

//class CrossPicker : public QwtPlotPicker
//{
//public:
//	//提供选择类
//	CrossPicker(QWidget *canvas) :
//		QwtPlotPicker(canvas)
//	{
//
//		setAxis(QwtPlot::xBottom, QwtPlot::yLeft);
//		//设置一个状态机，并删除上一个
//		setStateMachine(new QwtPickerDragPointMachine());
//		setRubberBandPen(QColor(Qt::red));
//		//设置橡胶圈样式：十字形
//		setRubberBand(QwtPicker::CrossRubberBand);
//		setTrackerPen(QColor(Qt::blue));
//		//设置跟踪模式
//		setTrackerMode(QwtPicker::ActiveOnly);
//		setEnabled(false);
//	}
//	//将位置转换成字符串
//	virtual QwtText trackerTextF(const QPointF &pos) const
//	{
//		QwtText text;
//
//		const QPolygon points = selection();//选择的点
//		if (!points.isEmpty())
//		{
//			QString num;
//			QPoint point = points[0];
//			QPointF point2 = invTransform(point);
//			num = QString("%1,%2").arg(point2.x()).arg(point2.y());
//			QColor bg(Qt::white);
//			bg.setAlpha(200);
//
//			text.setBackgroundBrush(QBrush(bg));
//			text.setText(num);
//		}
//		return text;
//	}
//
//	virtual void 	reset()
//	{
//		QwtPlotPicker::reset();
//	}
//	//virtual void 	begin()
//	//{
//
//	//}
//
//	//virtual void 	append(const QPoint &)
//	//{
//
//	//}
//
//	virtual void 	move(const QPoint & pos)
//	{
//		QwtPlotPicker::move(pos);
//	}
//
//	virtual void append(const QPoint & 	pos)
//	{
//		QwtPlotPicker::append(pos);
//	}
//
//	virtual void 	remove()
//	{
//		/*if (d_data->isActive)
//		{
//		const int idx = d_data->pickedPoints.count() - 1;
//		if (idx > 0)
//		{
//		const int idx = d_data->pickedPoints.count();
//
//		const QPoint pos = d_data->pickedPoints[idx - 1];
//		d_data->pickedPoints.resize(idx - 1);
//
//		updateDisplay();
//		Q_EMIT removed(pos);
//		}
//		}*/
//		QwtPlotPicker::remove();
//		int m = 0;
//	}
//	virtual bool 	end(bool ok = false)
//	{
//		/*QwtPlotPicker::end(ok);
//		return true;*/
//		if (!ok)
//			return false;
//
//		QwtPlot *plot = QwtPlotPicker::plot();
//		if (!plot)
//			return false;
//
//		const QPolygon points = selection();
//		if (points.count() == 0)
//			return false;
//
//		QwtPickerMachine::SelectionType selectionType =
//			QwtPickerMachine::NoSelection;
//
//		if (stateMachine())
//			selectionType = stateMachine()->selectionType();
//
//		switch (selectionType)
//		{
//		case QwtPickerMachine::PointSelection:
//		{
//												 const QPointF pos = invTransform(points.first());
//												 Q_EMIT selected(pos);
//												 break;
//		}
//		case QwtPickerMachine::RectSelection:
//		{
//												if (points.count() >= 2)
//												{
//													const QPoint p1 = points.first();
//													const QPoint p2 = points.last();
//
//													const QRect rect = QRect(p1, p2).normalized();
//													Q_EMIT selected(invTransform(rect));
//												}
//												break;
//		}
//		case QwtPickerMachine::PolygonSelection:
//		{
//												   QVector<QPointF> dpa(points.count());
//												   for (int i = 0; i < points.count(); i++)
//													   dpa[i] = invTransform(points[i]);
//
//												   Q_EMIT selected(dpa);
//		}
//		default:
//			break;
//		}
//
//		return true;
//	}
//
//	
//
//};
////矩形设门
//class RectPicker : public QwtPlotPicker
//{
//public:
//	//提供选择类
//	RectPicker(QWidget *canvas) :
//		QwtPlotPicker(canvas)
//	{
//
//		setAxis(QwtPlot::xBottom, QwtPlot::yLeft);
//		setResizeMode(QwtPicker::Stretch);//变形模式
//		//设置一个状态机，并删除上一个
//		setStateMachine(new QwtPickerDragRectMachine());
//		setRubberBandPen(QColor(Qt::red));
//		//设置橡胶圈样式：椭圆
//		setRubberBand(QwtPicker::RectRubberBand);
//		setTrackerPen(QColor(Qt::blue));
//		//设置跟踪模式
//		setTrackerMode(QwtPicker::ActiveOnly);
//		setEnabled(false);
//	}
//	//将位置转换成字符串
//	virtual QwtText trackerTextF(const QPointF &pos) const
//	{
//		QwtText text;
//
//		const QPolygon points = selection();//选择的点
//		if (!points.isEmpty())
//		{
//			QString num;
//			QPoint point = points[0];
//			QPointF point2 = invTransform(point);
//			num = QString("(%1,%2),(,)").arg(point2.x()).arg(point2.y());
//			QColor bg(Qt::white);
//			bg.setAlpha(200);
//			if (points.size() == 2)
//			{
//
//				QPointF point0 = invTransform(points[0]);
//				QPointF point1 = invTransform(points[1]);
//				num = QString("(%1,%2),(%3,%4)").arg(point0.x()).arg(point0.y()).arg(point1.x()).arg(point1.y());
//			}
//			text.setBackgroundBrush(QBrush(bg));
//			text.setText(num);
//		}
//		return text;
//	}
//	virtual void 	move(const QPoint & pos)
//	{
//		QwtPlotPicker::move(pos);
//	}
//	virtual void 	stretchSelection(const QSize &oldSize, const QSize &newSize)
//	{
//		QwtPlotPicker::stretchSelection(oldSize, newSize);//拉伸
//		//if (oldSize.isEmpty())
//		//{
//		//	// avoid division by zero. But scaling for small sizes also
//		//	// doesn't make much sense, because of rounding losses. TODO ...
//		//	return;
//		//}
//		//const double xRatio =
//		//	double(newSize.width()) / double(oldSize.width());
//		//const double yRatio =
//		//	double(newSize.height()) / double(oldSize.height());
//
//		//for (int i = 0; i < int(d_data->pickedPoints.count()); i++)
//		//{
//		//	QPoint &p = d_data->pickedPoints[i];
//		//	p.setX(qRound(p.x() * xRatio));
//		//	p.setY(qRound(p.y() * yRatio));
//
//		//	Q_EMIT changed(d_data->pickedPoints);
//		//}
//		QwtPlotPicker::updateDisplay();//显示
//	}
//	virtual bool 	end(bool ok)
//	{
//		if (!ok)//更改代码处：，正常结束后，并不停止。只有reset时候，end(false)停止选择，重置状态机
//			QwtPlotPicker::end(ok);
//		if (!ok)
//			return false;
//
//		QwtPlot *plot = QwtPlotPicker::plot();
//		if (!plot)
//			return false;
//
//		const QPolygon points = selection();
//		if (points.count() == 0)
//			return false;
//
//		QwtPickerMachine::SelectionType selectionType =
//			QwtPickerMachine::NoSelection;
//
//		if (stateMachine())
//			selectionType = stateMachine()->selectionType();
//
//		switch (selectionType)
//		{
//		case QwtPickerMachine::PointSelection:
//		{
//												 const QPointF pos = invTransform(points.first());
//												 Q_EMIT selected(pos);
//												 break;
//		}
//		case QwtPickerMachine::RectSelection:
//		{
//												if (points.count() >= 2)
//												{
//													const QPoint p1 = points.first();
//													const QPoint p2 = points.last();
//													QPointF pF1 = invTransform(p1);
//													QPointF pF2 = invTransform(p2);
//													const QRect rect = QRect(p1, p2).normalized();
//													const QRect rect11 = QRect(p1, p2);
//													QPoint pp1 = rect.topLeft();
//													QPoint pp2 = rect.bottomRight();
//													//const QRect rect = QRect(p1, p2);
//													QRectF rect1 = invTransform(rect);
//													QPointF topLeft = rect1.topLeft();
//													QPointF bottomRight = rect1.bottomRight();
//													Q_EMIT selected(invTransform(rect));
//												}
//												break;
//		}
//		case QwtPickerMachine::PolygonSelection:
//		{
//												   QVector<QPointF> dpa(points.count());
//												   for (int i = 0; i < points.count(); i++)
//													   dpa[i] = invTransform(points[i]);
//
//												   Q_EMIT selected(dpa);
//		}
//		default:
//			break;
//		}
//		return true;
//	}
//	virtual void reset()
//	{
//		QwtPicker::reset();
//	}
//	virtual void 	remove()
//	{
//		QwtPlotPicker::remove();
//	}
//};
////平行线设门
//class ParallelLinePicker : public QwtPlotPicker
//{
//public:
//	//提供选择类
//	ParallelLinePicker(QWidget *canvas) :
//		QwtPlotPicker(canvas)
//	{
//
//		setAxis(QwtPlot::xBottom, QwtPlot::yLeft);
//		setResizeMode(QwtPicker::Stretch);//变形模式
//		//设置一个状态机，并删除上一个
//		setStateMachine(new QwtPickerDragPointMachine());
//		setRubberBandPen(QColor(Qt::red));
//		//设置橡胶圈样式：多边形
//		setRubberBand(QwtPicker::VLineRubberBand);
//		setTrackerPen(QColor(Qt::blue));
//		//设置跟踪模式
//		setTrackerMode(QwtPicker::ActiveOnly);
//		setEnabled(false);
//	}
//	//将位置转换成字符串
//	virtual QwtText trackerTextF(const QPointF &pos) const
//	{
//		QwtText text;
//
//		const QPolygon points = selection();//选择的点
//		if (!points.isEmpty())
//		{
//			QString num;
//			QPoint point = points[0];
//			QPointF point2 = invTransform(point);
//			num = QString("(%1,%2),(,)").arg(point2.x()).arg(point2.y());
//			QColor bg(Qt::white);
//			bg.setAlpha(200);
//			if (points.size() == 2)
//			{
//
//				QPointF point0 = invTransform(points[0]);
//				QPointF point1 = invTransform(points[1]);
//				num = QString("(%1,%2),(%3,%4)").arg(point0.x()).arg(point0.y()).arg(point1.x()).arg(point1.y());
//			}
//			text.setBackgroundBrush(QBrush(bg));
//			text.setText(num);
//		}
//		return text;
//	}
//	virtual void 	move(const QPoint & pos)
//	{
//		QwtPlotPicker::move(pos);
//	}
//	virtual void 	stretchSelection(const QSize &oldSize, const QSize &newSize)
//	{
//		QwtPlotPicker::stretchSelection(oldSize, newSize);//拉伸
//		//if (oldSize.isEmpty())
//		//{
//		//	// avoid division by zero. But scaling for small sizes also
//		//	// doesn't make much sense, because of rounding losses. TODO ...
//		//	return;
//		//}
//		//const double xRatio =
//		//	double(newSize.width()) / double(oldSize.width());
//		//const double yRatio =
//		//	double(newSize.height()) / double(oldSize.height());
//
//		//for (int i = 0; i < int(d_data->pickedPoints.count()); i++)
//		//{
//		//	QPoint &p = d_data->pickedPoints[i];
//		//	p.setX(qRound(p.x() * xRatio));
//		//	p.setY(qRound(p.y() * yRatio));
//
//		//	Q_EMIT changed(d_data->pickedPoints);
//		//}
//		QwtPlotPicker::updateDisplay();//显示
//	}
//	virtual bool 	end(bool ok)
//	{
//		if (!ok)//更改代码处：，正常结束后，并不停止。只有reset时候，end(false)停止选择，重置状态机
//			QwtPlotPicker::end(ok);
//		if (!ok)
//			return false;
//
//		QwtPlot *plot = QwtPlotPicker::plot();
//		if (!plot)
//			return false;
//
//		const QPolygon points = selection();
//		if (points.count() == 0)
//			return false;
//
//		QwtPickerMachine::SelectionType selectionType =
//			QwtPickerMachine::NoSelection;
//
//		if (stateMachine())
//			selectionType = stateMachine()->selectionType();
//
//		switch (selectionType)
//		{
//		case QwtPickerMachine::PointSelection:
//		{
//												 const QPointF pos = invTransform(points.first());
//												 Q_EMIT selected(pos);
//												 break;
//		}
//		case QwtPickerMachine::RectSelection:
//		{
//												if (points.count() >= 2)
//												{
//													const QPoint p1 = points.first();
//													const QPoint p2 = points.last();
//													const QRect rect = QRect(p1, p2).normalized();
//													Q_EMIT selected(invTransform(rect));
//												}
//												break;
//		}
//		case QwtPickerMachine::PolygonSelection:
//		{
//												   QVector<QPointF> dpa(points.count());
//												   for (int i = 0; i < points.count(); i++)
//													   dpa[i] = invTransform(points[i]);
//
//												   Q_EMIT selected(dpa);
//		}
//		default:
//			break;
//		}
//		return true;
//	}
//	virtual void reset()
//	{
//		QwtPicker::reset();
//	}
//	virtual void 	remove()
//	{
//		QwtPlotPicker::remove();
//	}
//};
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
/**
* @brief 光谱数据
*/
class SpectrogramData : public QwtRasterData
{
public:
	SpectrogramData()
	{
		//坐标轴范围
		/*setInterval(Qt::XAxis, QwtInterval(0, 10));
		setInterval(Qt::YAxis, QwtInterval(0, 10));
		setInterval(Qt::ZAxis, QwtInterval(0.0, 10.0));*/


		/*setInterval(Qt::XAxis, QwtInterval(-1000, 100000));
		setInterval(Qt::YAxis, QwtInterval(0, 200000));*/
		setInterval(Qt::ZAxis, QwtInterval(0.0, 50));
		
		QList<PointColorData>* m_pointNumList = new QList<PointColorData>();
		m_count = 0;
		m_vectorX = 0;
		m_vectorY = 0;
	}

	virtual double value(double x, double y) const
	{
		const double c = 0.842;

		//const double v1 = x * x + (y - c) * (y + c);
		//const double v2 = x * (y + c) + x * (y + c);
		////根据xy坐标值，得出当前的z轴值，选择颜色
		//return 1.0 / (v1 * v1 + v2 * v2);
		double m = 0;
		//for (int i = 0; i < m_pointNumList.size(); i++)
		//{
		//	if (m_pointNumList.at(i).x() <= x &&m_pointNumList.at(i).x() >= x-1)
		//	{
		//		if (m_pointNumList.at(i).y() <= y && m_pointNumList.at(i).y() >= y - 1)
		//		{
		//			m = m_pointNumList.at(i).value();
		//			break;
		//		}
		//	}
		//}
		
		//判断点四周的点数，半径为r
		//原点
		PointColorData originPoint;
		originPoint.setX(x);
		originPoint.setY(y);

		qint32 sum = 0;
		if (m_vectorY != 0)
		{


			//判断一共有多少个点在半径为r的园内
			double r = 50;
			double s = r*r;
			for (int j = 0; j < m_vectorY->size(); j++)
			{
				//目标点
				PointColorData aimPoint;
				aimPoint.setX(m_vectorX->at(j));
				aimPoint.setY(m_vectorY->at(j));
				//double length = (originPoint.x() - aimPoint.x())*(originPoint.x() - aimPoint.x()) + (originPoint.y() - aimPoint.y())*(originPoint.y() - aimPoint.y());
				////qDebug() << QString("原点(%1,%2)到目标点(%3,%4) = 距离%5").arg(x).arg(y).arg(aimPoint.x()).arg(aimPoint.y()).arg(qSqrt(length));

				//if (length <= s)
				//{
				//	sum++;
				//}
				
				if (qFabs(originPoint.x() - aimPoint.x()) <= r)
				{
					if (qFabs(originPoint.y() - aimPoint.y()) <= r)
						sum++;
				}
			}
			originPoint.setValue(sum);
		}
		else
			sum = 0;
		//qDebug() << "[" << x << "," << y << "]" << "<==>"<<",sum = "<< sum;
		return sum;

	}
	/**
	* @brief 设置光谱颜色值
	*/
	void setPointSpectData(QList<PointColorData> pointList)
	{
		for (int i = 0; i < pointList.size(); i++)
		{
			PointColorData data;
			m_pointNumList.append(pointList.at(i));
		}
	}
	void setPointSpectData(QVector<double>* vectorX, QVector<double>* vectorY)
	{
		m_vectorX = vectorX;
		m_vectorY = vectorY;
	}
private:
	QList<PointColorData> m_pointNumList;
	QVector<double>* m_vectorX;
	QVector<double>* m_vectorY;
	double m_count;
};
/**
* @brief 颜色表
*/
class ColorMap : public QwtLinearColorMap
{
public:
	ColorMap() :
		QwtLinearColorMap(Qt::darkCyan, Qt::red)
		//线性颜色范围from A to B
	{
		addColorStop(0.1, Qt::cyan);
		addColorStop(0.5, Qt::green);
		//addColorStop(0.4, Qt::blue);
		addColorStop(0.9, Qt::yellow);
	}
};
Plot::Plot(QWidget *parent)
: QwtPlot(parent),
d_curve(NULL)
{
	setAutoFillBackground(true);
	


	//自定义曲线的颜色和宽度
	m_scatterColorName = "DarkBlue";
	m_scatterWidth = 2;
	m_scatterBrushColorName = "";

	m_barChartColorName ="#325481";
	m_barChartWidth = 2;
	m_barChartBrushColorName = "#DDE9FD";


	
	setPalette(QColor("#FFFFFF"));//plot的窗口背景色
	//setStyleSheet(
	//	"border-top: 1px solid #9D9D9D;"
	//	"border-radius: 0px;"
	//	"margin-right: 10px;"
	//	"background-color:#FFFFFF;"
	//	);//画布背景色
	//setTitle("散点图显示");//画布标题

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
	QColor penColor(m_scatterColorName);
	QColor brushColor(m_scatterBrushColorName);
	d_curve->setPen(penColor, m_scatterWidth);
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

	////支持滑轮放大缩小zoom in/out with the wheel
	//QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(canvas);
	//magnifier->setMouseButton(Qt::RightButton);//默认就是右键鼠标

	//右键测量 distanve measurement with the right mouse button
	DistancePicker *picker = new DistancePicker(canvas);
	picker->setMousePattern(QwtPlotPicker::MouseSelect1, Qt::RightButton);
	picker->setRubberBandPen(QPen(Qt::blue));
	picker->setEnabled(false);

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

	////矩形
	//d_rectPicker = new RectPicker(canvas);
	//connect(d_rectPicker, SIGNAL(selected(QRectF)), this, SLOT(selectedRectPickerSlot(QRectF)));

	////平行线设门
	//d_parallelLinePicker_1 = new ParallelLinePicker(canvas);
	//connect(d_parallelLinePicker_1, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));
	////平行线设门
	//d_parallelLinePicker_2 = new ParallelLinePicker(canvas);
	//d_parallelLinePicker_2->setRubberBandPen(QPen(Qt::blue));
	//connect(d_parallelLinePicker_2, SIGNAL(selected(QPointF)), this, SLOT(selectedParallelLinePickerSlot(QPointF)));
	
	//初始化密度图
	initSpectrogram();
	//plotLayout()->setCanvasMargin(0);
	plotLayout()->setAlignCanvasToScales(true);//设置对齐画布、坐标轴、刻度 会掩盖setCanvasMargin()
	replot();

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
void Plot::setGridEnable(bool checked, bool barMode)
{
	
	d_grid->enableX(checked);
	d_grid->enableXMin(checked);
	d_grid->enableY(checked);
	d_grid->enableYMin(false);
	if (checked)
	{
		//QColor brushColor("#DDE9FD");
		//d_curve->setBrush(brushColor);//设置笔刷
		
		//设置统计曲线样式
		//设置颜色
		//若是直方图统计模式，设置画布样式
		if (barMode)
		{
			enableStaticsMode();
		}
		else
			enableScatterMode();
	}
	else
	{
		//若是直方图统计模式，设置画布样式
		if (barMode)
		{
			enableStaticsMode();
		}
		else
			enableScatterMode();
	}
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
	QColor penColor(m_barChartColorName);
	QColor brushColor(m_barChartBrushColorName);
	d_curve->setPen(penColor, m_barChartWidth);
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
	QColor penColor(m_scatterColorName);
	d_curve->setPen(penColor, m_scatterWidth);
	d_curve->setBrush(Qt::NoBrush);
	d_curve->setStyle(QwtPlotCurve::Dots);
	d_curve->setRenderHint(QwtPlotItem::RenderAntialiased);
	////坐标轴刻度修饰
	//this->setAxisScale(QwtPlot::xBottom, 1, 1e6);//设置x轴坐标刻度大小
	//this->setAxisScale(QwtPlot::yLeft, 1, 1e6);//设置y轴坐标刻度大小
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
* @brief 启用平行线设门
*/
void Plot::enableParallelLinePicker(bool mode)
{
	
	if (mode)
	{
		d_parallelLinePicker_1->setEnabled(true);
		d_parallelLinePicker_2->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::ActiveOnly);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);
		
	}
	else
	{
		d_parallelLinePicker_1->setEnabled(false);
		d_parallelLinePicker_2->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::AlwaysOff);
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
void Plot::selectedParallelLinePickerSlot(QPointF pointf)
{
	//是否有存在的点
	for (int i = 0; i < parallelLineList.size(); i++)
	{
		if (pointf == parallelLineList.at(i))
		{
			return;
		}
		else
		{
			parallelLineList.append(pointf);
			break;
		}
	}
	//无点
	if (parallelLineList.size() == 0)
	{
		parallelLineList.append(pointf);
	}
	//已经有一个点
	if (parallelLineList.size() == 1)
	{
		//d_parallelLinePicker_1->setEnabled(false);
		d_parallelLinePicker_1->setTrackerMode(QwtPicker::AlwaysOff);

		d_parallelLinePicker_2->setEnabled(true);
		d_parallelLinePicker_2->setTrackerMode(QwtPicker::ActiveOnly);
	}
	//已经有2个点
	if (parallelLineList.size() >= 2)
	{
		emit selectedParallelLinePicker(parallelLineList);
	}

}

/**
* @brief 设置画布背景
*/
void Plot::setCanvasBackgroundColor(QString colorName)
{
	canvas->setStyleSheet(
		QString(
		"border: 0px solid #000000;"
		"border-radius: 0px;"
		"background-color:%1;"
		"margin:0 0px;"
		).arg(colorName));//画布背景色
	setCanvas(canvas);
}
/**
* @brief 设置散点图曲线颜色 width = 0,即不改变宽度，用系统默认的宽度
*/
void Plot::setScatterCurve(QString colorName,int width,QString brushColorName)
{
	//设置颜色
	m_scatterColorName = colorName;
	if (width!=0)
		m_scatterWidth = width;
	m_scatterBrushColorName = brushColorName;
	//散点模式
	enableScatterMode();
}
/**
* @brief 设置散点图曲线颜色
*/
void Plot::setBarChartCurve(QString colorName, int width, QString brushColorName)
{
	//设置颜色
	m_barChartColorName = colorName;
	m_barChartWidth = width;
	m_barChartBrushColorName = "#DDE9FD";//默认背景色
	//直方图模式
	enableStaticsMode();
}

/**
* @brief 初始化密度图
*/
void Plot::initSpectrogram()
{
	d_spectrogram = 0;
	d_spectrogramData = 0;
	//光谱图
	d_spectrogram = new QwtPlotSpectrogram();
	//指定渲染系统是否采用多核的线程数
	d_spectrogram->setRenderThreadCount(1); // use system specific thread count
	//在另外一个坐标轴工具栏，显示密度和显色的映射关系
	d_spectrogram->setColorMap(new ColorMap());
	//缓存策略：
	d_spectrogram->setCachePolicy(QwtPlotRasterItem::PaintCache);

	//设置光谱数据
	d_spectrogram->setData(new SpectrogramData());
	//Attach the item to a plot.
	d_spectrogram->attach(this);

	//等高线设置
	QList<double> contourLevels;
	for (double level = 1; level < 1000; level += 10)
		contourLevels += level;
	//设置等高线分层数据
	d_spectrogram->setContourLevels(contourLevels);

	//QwtRasterData数据Z轴的坐标范围
	const QwtInterval zInterval = d_spectrogram->data()->interval(Qt::ZAxis);

	//右边坐标轴上放上颜色表
	// A color bar on the right axis
	QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
	rightAxis->setTitle("Intensity");
	rightAxis->setColorBarEnabled(true);
	//设置颜色表和坐标范围，给颜色工具栏用。
	rightAxis->setColorMap(zInterval, new ColorMap());

	


	//设置画布yRight坐标显示范围
	setAxisScale(QwtPlot::yRight, zInterval.minValue(), zInterval.maxValue());
	enableAxis(QwtPlot::yRight);

	
	showSpectrogram(false);//默认不显示密度图
}
/**
* @brief 更新密度图数据
*/
void Plot::updateSpectrogramData(QList<PointColorData>  pointList)
{
	if (d_spectrogramData != 0)
	{
		delete d_spectrogramData;
		d_spectrogramData = 0;
	}
	
	d_spectrogramData = new SpectrogramData();
	/*QRectF rectF(QPointF(0, 0), QSize(1e6, 1e6));
	QSize raster(1000, 1000);
	d_spectrogramData->initRaster(rectF, raster);*/

	//设置光谱颜色值
	d_spectrogramData->setPointSpectData(pointList);
	//设置光谱数据
	d_spectrogram->setData(d_spectrogramData);
}
/**
* @brief 更新密度图数据
*/
void Plot::updateSpectrogramData(QVector<double>* vectorX, QVector<double>* vectorY)
{
	if (d_spectrogramData != 0)
	{
		delete d_spectrogramData;
		d_spectrogramData = 0;
	}
	
	d_spectrogramData = new SpectrogramData();
	QRectF rectF(QPointF(0, 0), QSize(10, 10));
	QSize raster(10, 10);
	d_spectrogramData->initRaster(rectF, raster);
	//设置光谱颜色值
	d_spectrogramData->setPointSpectData(vectorX, vectorY);
	//设置光谱数据
	d_spectrogram->setData(d_spectrogramData);
}
/**
* @brief 显示密度图
*/
void Plot::showSpectrogram(bool on)
{
	
	
	d_spectrogram->setDisplayMode(QwtPlotSpectrogram::ImageMode, on);
	d_spectrogram->setDefaultContourPen(
		on ? QPen(Qt::black, 0) : QPen(Qt::NoPen));
	enableAxis(QwtPlot::yRight,on);
	replot();
}
/**
* @brief 显示等高线
*/
void Plot::showContour(bool on)
{
	d_spectrogram->setDisplayMode(QwtPlotSpectrogram::ContourMode, on);
	replot();
}


/**
* @brief 新添加curve
*/
void Plot::addCurve(QString colorName, const QVector< double > & xData, const QVector< double > & yData)
{
	// attach curve
	QwtPlotCurve* l_curve = new QwtPlotCurve("Scattered Points");
	l_curve->setLegendAttribute(QwtPlotCurve::LegendShowLine);//设置描述的样式
	// when using QwtPlotCurve::ImageBuffer simple dots can be
	// rendered in parallel on multicore systems.
	l_curve->setRenderThreadCount(0); // 0: use QThread::idealThreadCount()

	//设置统计曲线样式
	QColor penColor(colorName);
	l_curve->setPen(penColor, m_scatterWidth);
	l_curve->setBrush(Qt::NoBrush);
	l_curve->setStyle(QwtPlotCurve::Dots);
	l_curve->setRenderHint(QwtPlotItem::RenderAntialiased);

	l_curve->attach(this);

	l_curve->setSamples(xData, yData);


	l_curveList.append(l_curve);//将临时曲线保存好
	replot();

}
/**
* @brief 清空临时曲线
*/
void Plot::clearTempCurve()
{
	for (int i = 0; i < l_curveList.size(); i++)
	{
		QwtPlotCurve* curve = l_curveList.at(i);
		delete curve;
	}
	l_curveList.clear();
}
