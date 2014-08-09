#include "CrossPicker.h"

//提供选择类
CrossPicker::CrossPicker(QWidget *canvas) :
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
CrossPicker::~CrossPicker()
{

}
//将位置转换成字符串
 QwtText CrossPicker::trackerTextF(const QPointF &pos) const
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

 void 	CrossPicker::reset()
{
	QwtPlotPicker::reset();
}
//virtual void 	begin()
//{

//}

//virtual void 	append(const QPoint &)
//{

//}

 void 	CrossPicker::move(const QPoint & pos)
{
	QwtPlotPicker::move(pos);
}

 void CrossPicker::append(const QPoint & 	pos)
{
	QwtPlotPicker::append(pos);
}

 void 	CrossPicker::remove()
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
 bool CrossPicker::end(bool ok)
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
