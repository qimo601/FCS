/**
* 项    目:  FCS软件
* 文件名称:   BarChartWidget.h
* 文件路径：  Ui/Libary/BarChartWidget.h
* 摘    要:  直方图窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月29日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef BarChartWidget_H
#define BarChartWidget_H

#include <QWidget>
#include <QPaintEvent>
#include "ui_BarChartWidget.h"
#include "Bll/DataCenter/BllDataCenter.h"
#include "PlotWidget.h"

class BarChart;
class BarChartWidget : public QWidget
{
	Q_OBJECT

public:
	BarChartWidget(QWidget *parent = 0);
	~BarChartWidget();

	/**
	* @brief 更新数据
	*/
	void updateSamples(int samples);
	/**
	* @brief 随机值
	*/
	double randomValue();
public slots:
	void startAcqTimer();
	void stopAcqTimer();

protected:
	virtual void paintEvent(QPaintEvent * event);
	virtual void timerEvent(QTimerEvent * event);
private:
	Ui::BarChartWidget ui;
	BarChart *d_barChart;//直方图控件
	BllDataCenter bllDataCenter;

	QVBoxLayout *vLayoutCellPlotFrame;//细胞绘图布局控件
	
	int m_timerId;//真正的定时器
};

#endif // BarChartWidget_H
