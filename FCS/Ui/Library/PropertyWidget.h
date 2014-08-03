/**
* 项    目:  FCS软件
* 文件名称:   PropertyWidget.h
* 文件路径：  Ui/Libary/PropertyWidget.h
* 摘    要:  属性窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月23日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include "ui_PropertyWidget.h"

class PropertyWidget : public QWidget
{
	Q_OBJECT
public:
	PropertyWidget(QWidget *parent = 0);
	~PropertyWidget();
public slots:
	void on_colorBtnProperty_clicked();
	void on_fileNameBtnProperty_clicked();
	void on_midMarkBtnProperty_clicked();
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::PropertyWidget ui;
	QPropertyAnimation* animation;
	QPropertyAnimation* animation1;
};

#endif // PROPERTYWIDGET_H
