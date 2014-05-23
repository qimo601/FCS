#ifndef WHEELBOX_H
#define WHEELBOX_H

#include <QWidget>
#include "ui_WheelBox.h"

class WheelBox : public QWidget
{
	Q_OBJECT

public:
	WheelBox(QWidget *parent = 0);
	~WheelBox();
	void setValue(double value);
	double value() const;
	/** 
	* @brief   设置WheelBox的属性
	*
	* @param   const QString &title
	* @param   double min
	* @param   double max
	* @param   double stepSize
	* @return  无
	* @author  Liuzhaobang
	* @date    2014-5-21
	*/
	void setProperty(const QString &title,double min, double max, double stepSize);

signals:
	double valueChanged(double);
private:
	Ui::WheelBox ui;
};

#endif // WHEELBOX_H
