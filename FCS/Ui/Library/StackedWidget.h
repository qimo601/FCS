/**
* 项    目:  FCS软件
* 文件名称:   StackedWidget.h
* 文件路径：  Ui/Libary/StackedWidget.h
* 摘    要:  主窗口动态显示栏
* 作    者： 刘兆邦
* 日    期： 2014年04月10日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QStackedWidget>
#include "Include/Global.h"
#include "ui_StackedWidget.h"
#include "Bll/Control/BllControl.h"
#include "Ui/Library/OscWidget.h"
#include <QToolBar>
#include "Ui/Library/GateStorage.h"
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
	//静态变量：设门数组
	static QList<GateStorage> gatingDataList;

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
	* @brief 下发开始采集命令
	*/
	void on_startAcquisitionBtn_clicked();
	/**
	* @brief 下发停止采集命令
	*/
	void on_stopAcquisitionBtn_clicked();
	/**
	* @brief 数据分析与报告处理
	*/
	void dataAnalyHandle();
	/**
	* @brief 下发命令
	*/
	void sendCmd();
	/**
	* @brief 新建plot
	*/
	void on_newPlotBtn_clicked();
	/**
	* @brief 删除plot
	*/
	void on_delPlotBtn_clicked();
	/**
	* @brief 报告按钮
	*/
	void showReport(bool on);
	/**
	* @brief 打开实验文件
	*/
	void openExpFileSlot();
	/**
	* @brief 保存实验文件
	*/
	void saveExpFileSlot();
	/**
	* @brief 保存细胞数据
	*/
	void on_saveCheckBox_clicked();
	/**
	* @brief 菜单Action
	*/
	void createActions();
	/**
	* @brief 创建菜单
	*/
	void createMenus();
	/**
	* @brief 创建工具栏
	*/
	void createToolBars();
signals:
	void openExpFileSignal();
	void saveExpFileSignal();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::StackedWidget ui;
	OscWidget* oscWidgetPage;//示波器显示窗口

	BllControl* bllControl;//采集控制业务类




	QAction* newPlotAct;//新建画布
	QAction* delPlotAct;//删除画布
	QAction* savePlotAct;//保存画布
	QAction* reportAct;//显示报告

	QToolBar* fileToolBar;//菜单
};

#endif // STACKEDWIDGET_H
