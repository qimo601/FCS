#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QStackedWidget>
#include "Include/Global.h"
#include "ui_StackedWidget.h"
#include "Bll/Control/BllControl.h"
#include "Ui/Library/OscWidget.h"
class StackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	StackedWidget(QWidget *parent = 0);
	~StackedWidget();
	/** 
	* @brief   初始化
	*
	* @author  Liuzhaobang
	* @date    2014-5-15
	*/
	void init();
public slots:

	/**
	* @brief 打开USB设备
	*/
	void on_openUsbBtn_clicked();

	/**
	* @brief 关闭USB设备
	*/
	void on_closeUsbBtn_clicked();
	/**
	* @brief 测试下发命令
	*/
	void on_loadCmdBtn_clicked();
	/**
	* @brief 设置激光
	*/
	void on_setLaserBtn_clicked();
	/**
	* @brief 设置鞘液
	*/
	void on_setFluidBtn_clicked();
	/**
	* @brief 设置样本流速
	*/
	void on_setSampleBtn_clicked();
	/**
	* @brief 设置通道偏压
	*/
	void on_setChannelBiasBtn_clicked();
	/**
	* @brief 设置触发值
	*/
	void on_setTriggerBtn_clicked();
	/**
	* @brief 示波器显示处理槽函数
	*/
	void oscHandle();
	/**
	* @brief 设置样品流速-中档
	*/
	void on_midRadioButton_clicked();

	/**
	* @brief 设置样品流速-高档
	*/
	void on_hightRadioButton_clicked();

	/**
	* @brief 设置样品流速-低档
	*/
	void on_lowRadioButton_clicked();

	/**
	* @brief 数据分析与报告处理
	*/
	void dataAnalyHandle();
	/**
	* @brief 下发命令
	*/
	void sendCmd();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::StackedWidget ui;
	OscWidget* oscWidgetPage;//示波器显示窗口

	BllControl* bllControl;//采集控制业务类
};

#endif // STACKEDWIDGET_H
