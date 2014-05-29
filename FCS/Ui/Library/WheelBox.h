/**
* 项    目:  FCS软件
* 文件名称:   WheelBox.h
* 文件路径：  Ui/Libary/WheelBox.h
* 摘    要:  自定义滑轮窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月03日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
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
