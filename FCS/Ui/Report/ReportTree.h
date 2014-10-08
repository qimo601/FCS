#ifndef REPORTTREE_H
#define REPORTTREE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "ui_ReportTree.h"
#include "Include/Global.h"
#include "Ui/Library/PlotWidget.h"
#include "Bll/DataCenter/BllDataCenter.h"
#include "Bll/DataCenter/BllSettings.h"
class ViewWidget;
class ReportTree : public QWidget
{
	Q_OBJECT

public:
	ReportTree(QWidget *parent = 0);
	~ReportTree();

	QTreeWidget* treeWidgetPdf;

public slots:

	/**
	* @brief 初始化报表数据
	*/
	void initReportData();
	/**
	* @brief 刷新按钮
	*/
	void on_refreshBtn_clicked();
	/**
	* @brief 刷新生成报告
	*/
	void updateReport();
	/**
	* @brief 获得窗口的所有设门报告
	* @param plotwidget:画布
	* @param int i:第i个树
	*/
	void getTreeReport(PlotWidget* plotWidget,int i);
	/**
	* @brief 获得root报告
	* @param plotwidget:画布
	* @param int i:第i个树
	*/
	void getTreeRootReport(PlotWidget* plotWidget, int i);
	/**
	* @brief 获得Child报告-递归查询
	* @param currentItem:当前节点
	* @param int i:第i个树
	*/
	void getTreeChildReport(QTreeWidgetItem* currentItem, PlotWidget* plotWidget, int i);
	/**
	* @brief 添加根目录
	*/
	void insertRootReport(QTreeWidgetItem* &rootItem, GateStorage* gateStorage);
	/**
	* @brief 添加孩子目录
	*/
	void insertChildReport(QTreeWidgetItem* parentItem, QTreeWidgetItem* &currentItem, GateStorage* gateStorage);
	/**
	* @brief 展开所有节点
	*/
	void expandTreeReport(QTreeWidgetItem* rootItem);
	/**
	* @brief 显示设门对应的画布窗口
	*/
	void on_plotBtn_clicked();
	/**
	* @brief 使能绘图按钮
	*/
	void enablePlotBtn(QTreeWidgetItem * item, int column);
	/**
	* @brief 删除该设门对应的窗口
	*/
	void on_delGateBtn_clicked();
	/**
	* @brief 设置按钮
	*/
	void on_settingBtn_toggled(bool enable);
	/**
	* @brief 添加按钮
	*/
	void on_addBtn_clicked();

	/**
	* @brief 删除按钮
	*/
	void on_delBtn_clicked();
	/**
	* @brief 初始报告参数
	* @param indexNotVisibleList 不需要显示的参数
	*/
	void initReportSettings(QList<int>& indexNotVisibleList);
	/**
	* @brief 更新报告参数
	*/
	void updateReportSettings();
	/**
	* @brief 更新报表显示参数
	*/
	void updatevisibleParams();

	/**
	* @brief 返回可以打印的报表
	*/
	QTreeWidget* getTreeWidgetPdf();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	/**
	* @brief 关闭事件
	*/
	virtual void closeEvent(QCloseEvent *event);
signals:
	void viewGateWidget(QString gateName);//显示某Gate的窗口
	void willClose();
	void delGateWidget(QString gateName);
	void reportParamChanged();//report显示参数变化，report统计需发生更改
private:
	Ui::ReportTree ui;

	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键


	QTreeWidgetItem *rootItem0;//根节点
	QTreeWidgetItem *rootItem1;//根节点
	QTreeWidgetItem *currentItem0;//当前节点
	QTreeWidgetItem *currentItem1;//当前节点
	QTreeWidgetItem *parentItem0;//父节点
	QTreeWidgetItem *parentItem1;//父节点


	BllDataCenter bllDataCenter;
	//永远只有两个根目录
	//根节点的假设设门1
	GateStorage* gateStorageRoot1;
	//根节点的假设设门1
	GateStorage* gateStorageRoot2;
	//配置业务
	BllSettings bllSettings;
	//所有可显示参数
	QMap<int, QStringList> m_stringListMap;
};

#endif // REPORTTREE_H
