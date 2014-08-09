#ifndef CROSSPICKER_H
#define CROSSPICKER_H

#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_picker.h>
#include <qwt_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_widget.h>
#include <qwt_plot_canvas.h>
class CrossPicker : public QwtPlotPicker
{
	Q_OBJECT

public:
	CrossPicker(QWidget *canvas);
	~CrossPicker();
	//将位置转换成字符串
	virtual QwtText trackerTextF(const QPointF &pos) const;
	virtual void 	reset();
	virtual void 	move(const QPoint & pos);
	virtual void append(const QPoint & 	pos);
	virtual void 	remove();
	virtual bool 	end(bool ok = false);

private:
	
};

#endif // CROSSPICKER_H
