/**
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
#include "ui_PlotWidget.h"
class Plot;

class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	PlotWidget(QWidget *parent = 0);
	~PlotWidget();

	/**
	* @brief 设置数据
	*/
	void setSamples(int samples);
	/**
	* @brief 随机值
	*/
	double randomValue();
private:
	Ui::PlotWidget ui;
	Plot *d_plot;
};

#endif // PLOTWIDGET_H
