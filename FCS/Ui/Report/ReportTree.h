#ifndef REPORTTREE_H
#define REPORTTREE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "ui_ReportTree.h"
#include "Include/Global.h"
#include "Ui/Library/PlotWidget.h"
#include "Bll/DataCenter/BllDataCenter.h"
class ViewWidget;
class ReportTree : public QWidget
{
	Q_OBJECT

public:
	ReportTree(QWidget *parent = 0);
	~ReportTree();
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
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
signals:

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
};

#endif // REPORTTREE_H
