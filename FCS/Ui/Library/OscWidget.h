﻿/**
* 项    目:  FCS软件
* 文件名称:  OscWidget.h
* 文件路径： Ui/Libarary/OscWidget.h
* 摘    要:  示波器窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月05日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef OSCWIDGET_H
#define OSCWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include "ui_OscWidget.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QTimer>
#include <qwt_legend.h>
#include <qwt_system_clock.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_interval.h>
#include "Include/Global.h"
#include "Bll/DataCenter/BllDataCenter.h"
#include "Ui/Library/PropertyWidget.h"
#include "Bll/Control/BllControl.h"
#include "Bll/DataCenter/ReadOscThread.h"
class OscWidget : public QWidget
{
	Q_OBJECT

public:
	OscWidget(QWidget *parent = 0);
	~OscWidget();
	/**
	* @brief 初始化
	*/
	void init();
	/**
	* @brief 初始化Plot
	*/
	void initPlot();
	/**
	* @brief 初始化WheelBox
	*/
	void initWheelBox();

	/**
	* @brief 初始化属性窗口及其动画
	*/
	void initAnimation();
	/**
	* @brief 显示属性窗口
	*/
	void showPropertyWidget();
	/**
	* @brief 关闭属性窗口
	*/
	void closePropertyWidget();
	/**
	* @brief 控制一下哪个曲线显示
	*/
	void showCurve(QwtPlotItem *item, bool on);
public slots:
	/**
	* @brief 更新界面参数
	*/
	void updateParams();
	/**
	* @brief 更新绘图数据
	*/
	void updateOscPlot();
	/**
	* @brief 开始示波器采集
	*/
	void on_startOscAcqBtn_clicked();
	/**
	* @brief 停止示波器采集
	*/
	void on_stopOscAcqBtn_clicked();
	/**
	* @brief 保存示波器数据
	*/
	void on_saveCheckBox_clicked();
	/**
	* @brief 曲线描述激活槽函数
	*/
	void legendChecked(const QVariant &itemInfo, bool on);

	/**
	* @brief 设置X轴坐标
	*/
	void setXAxisScale(double interval);
	/**
	* @brief 设置Y轴坐标
	*/
	void setYAxisScale(double interval);
	/**
	* @brief 设置X轴中间线
	*/
	void setXMark(double mark_x);
	/**
	* @brief 设置Y轴中间线
	*/
	void setYMark(double mark_y);
	/**
	* @brief 设置按钮弹出属性窗口
	*/
	void on_propertyBtn_clicked();
	/**
	* @brief 设置属性窗口不可见
	*/
	void setVisiblePropertyWidget();
protected:
	virtual void timerEvent(QTimerEvent *);
	virtual void mouseMoveEvent(QMouseEvent *event);
signals:
	void startOscAcq();
	void propertyClicked();
private:
	Ui::OscWidget ui;
	//数据中心业务类
	BllDataCenter bllDataCenter;
	
	//绘图定时器
	//QTimer *m_timer;
	//测试用
	int stepValue;
	//示波器曲线
	QwtPlotCurve* oscCurve;
	//曲线的描述
	QwtLegend* legend;
	//示波器曲线 列表
	QList<QwtPlotCurve*> m_curveList;
	//曲线的描述 列表
	QList<QwtLegend*> m_legendList;
	//计算消耗事件
	QwtSystemClock m_clock;
	//真正的定时器
	int m_timerId;

	//设置画布
	QwtPlotCanvas* canvas;
	//中间十字标记
	QwtPlotMarker* d_origin;
	//背景方格
	QwtPlotGrid* grid;

	//曲线X轴坐标范围，间隔时间
	QwtInterval m_interval_x;
	//曲线Y轴坐标范围
	QwtInterval m_interval_y;
	//设置按钮图标
	QPixmap settingPixmap;
	//中间线位置
	QPoint m_markPos;

	//属性窗口
	PropertyWidget* propertyWidget;
	//属性窗口出现动画
	QPropertyAnimation* showPropertyAnimation;
	//属性窗口出现动画
	QPropertyAnimation* closePropertyAnimation;
	

	BllControl bllControl;//采集控制业务类
	ReadOscThread* readOscThread;//示波器读取线程




	///参数

};

#endif // OSCWIDGET_H
