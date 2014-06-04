﻿/**
* 项    目:  FCS软件
* 文件名称:   PlotWidget.h
* 文件路径：  Ui/Libary/PlotWidget.h
* 摘    要:  绘图窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月29日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include "ui_PlotWidget.h"
#include "Bll/DataCenter/BllDataCenter.h"
class Plot;

class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	PlotWidget(QWidget *parent = 0);
	~PlotWidget();

	/**
	* @brief 更新数据
	*/
	void updateSamples(int samples);
	/**
	* @brief 随机值
	*/
	double randomValue();
protected:
	void paintEvent(QPaintEvent *event);
public slots:
	void startAcqTimer();
	void stopAcqTimer();
protected:
	virtual void timerEvent(QTimerEvent *);
private:
	Ui::PlotWidget ui;
	Plot *d_plot;
	BllDataCenter bllDataCenter;

	QVBoxLayout *vLayoutCellPlotFrame;//细胞绘图布局控件
	
	int m_timerId;//真正的定时器
};

#endif // PLOTWIDGET_H