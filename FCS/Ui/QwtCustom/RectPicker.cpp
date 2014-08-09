#include "RectPicker.h"

//矩形设门
//提供选择类
RectPicker::RectPicker(QWidget *canvas)
:QwtPlotPicker(canvas)
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
RectPicker::~RectPicker()
{

}
//将位置转换成字符串
QwtText RectPicker::trackerTextF(const QPointF &pos) const
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
void RectPicker::move(const QPoint & pos)
{
	QwtPlotPicker::move(pos);
}
void RectPicker::stretchSelection(const QSize &oldSize, const QSize &newSize)
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
bool RectPicker::end(bool ok)
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
												const QRect rect11 = QRect(p1, p2);
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
 void RectPicker::reset()
{
	QwtPicker::reset();
}
 void RectPicker::remove()
{
	QwtPlotPicker::remove();
}
