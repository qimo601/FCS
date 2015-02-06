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
#include "Bll/DataCenter/BllDataCenter.h"
#include <QTimer>
#include <QFileSystemModel>
#include <QTreeView>
#include <QMenu>
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
	* @brief 打开/关闭USB设备
	*/
	void on_usbBtn_toggled(bool toggled);

	/**
	* @brief 测试下发命令
	*/
	void on_loadCmdBtn_clicked();
	
	/**
	* @brief 下发开始采集命令
	*/
	void on_startAcquisitionBtn_clicked();
	/**
	* @brief 下发停止采集命令
	*/
	void on_stopAcquisitionBtn_clicked();
	/**
	* @brief 示波器显示处理槽函数
	*/
	void oscHandle();
	/**
	* @brief 数据分析与报告处理
	*/
	void dataAnalyHandle();
	/**
	* @brief 细胞数据采集
	*/
	void acqHandle();
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
	* @brief 导出PDF
	*/
	void exportPDF();
	/**
	* @brief 方格布局
	*/
	void gridLayoutSlot();
	/**
	* @brief 荧光补偿
	*/
	void showCompensationWidget(bool on);
	/**
	* @brief 新建实验
	*/
	void newExpSlot();
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
	void on_saveCheckBox_toggled(bool checked);
	/**
	* @brief 时间计时
	*/
	void on_timeCheckBox_toggled(bool checked);
	/**
	* @brief 细胞计数
	*/
	void on_eventsCheckBox_toggled(bool checked);
	/**
	* @brief 更新细胞个数
	*/
	void updateEvents();
	/**
	* @brief 流量统计
	*/
	void on_flowCheckBox_clicked();
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
	/**
	* @brief 设置删除画布按钮状态
	*/
	void setDelPlotActSlot(bool focus);
	/**
	* @brief 更新时间
	*/
	void updateTime();

	/**
	* @brief创建文件管理目录
	*/
	void createTreeFileDir();
	/**
	* @brief 右键菜单
	*/
	void onCustomContextMenuRequested(const QPoint& pos);
	/**
	* @brief 打开文件目录
	*/
	void on_openFileBtn_clicked();
	/**
	* @brief 右键菜单
	*/
	void oepnExpFileFromRight(bool enable);
	/**
	* @brief 设置报告按钮状态
	*/
	void setCloseReportActSlot();

signals:
	void newExpSignal();
	void openExpFileSignal();
	void saveExpFileSignal();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::StackedWidget ui;
	OscWidget* oscWidgetPage;//示波器显示窗口

	BllControl* bllControl;//采集控制业务类



	QAction* m_newExpAct;//新建实验
	QAction* m_newPlotAct;//新建画布
	QAction* m_delPlotAct;//删除画布
	QAction* m_savePlotAct;//保存画布
	QAction* m_reportAct;//显示报告
	QAction* m_pdfAct;//导出pdf
	QAction* m_gridLayoutAct;//方格布局
	QAction* m_compensationAct;//荧光补偿

	QToolBar* m_fileToolBar;//菜单

	QTimer* m_timer;//时间计时
	qint32 m_timeCount;//时间长短单位s

	QTimer* m_timerEvents;//时间计时
	BllDataCenter bllDataCenter;//数据采集业务类
	qint32 m_cellEvents;//细胞个数


	QFileSystemModel* model;//文件目录模型
	QTreeView* treeView;//树形视图
	QString m_currentMatLabPath;//当前实验路径
	QMenu* m_menu;
	QString m_fileName;//选中的文件名


	
};

#endif // STACKEDWIDGET_H
