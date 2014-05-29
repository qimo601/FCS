/**
* 项    目:  FCS软件
* 文件名称:  AnalysisWidget.h
* 文件路径： Ui/Libarary/AnalysisWidget.h
* 摘    要:  数据分析与报告窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月28日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef ANALYSISWIDGET_H
#define ANALYSISWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_AnalysisWidget.h"

class AnalysisWidget : public QWidget
{
	Q_OBJECT

public:
	AnalysisWidget(QWidget *parent = 0);
	~AnalysisWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::AnalysisWidget ui;
};

#endif // ANALYSISWIDGET_H
