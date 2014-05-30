/**
* 项    目:  FCS软件
* 文件名称:   ReportWidget.h
* 文件路径：  Ui/Libary/ReportWidget.h
* 摘    要:  数据报告窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef REPORTWIDGET_H
#define REPORTWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ReportWidget.h"
class ReportWidget : public QWidget
{
	Q_OBJECT

public:
	ReportWidget(QWidget *parent = 0);
	~ReportWidget();

protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::ReportWidget ui;
};

#endif // REPORTWIDGET_H

