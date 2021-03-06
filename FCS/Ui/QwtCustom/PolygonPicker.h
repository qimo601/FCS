﻿#ifndef PolygonPicker_H
#define PolygonPicker_H

#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_picker.h>
#include <qwt_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_canvas.h>
class PolygonPicker : public QwtPlotPicker
{
	Q_OBJECT

public:
	PolygonPicker(QWidget *canvas = 0);
	~PolygonPicker();
	//将位置转换成字符串
	virtual QwtText trackerTextF(const QPointF &pos) const;
	virtual void move(const QPoint & pos);
	virtual void stretchSelection(const QSize &oldSize, const QSize &newSize);
	virtual bool end(bool ok);
	virtual void reset();
	virtual void remove();
private:
	
};

#endif // PolygonPicker_H
