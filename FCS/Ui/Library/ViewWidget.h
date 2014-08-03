#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ViewWidget.h"
#include "PlotWidget.h"
#include "Bll/DataCenter/ReadCellThread.h"
#include "Ui/Report/ReportTree.h"
class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget *parent = 0);
	~ViewWidget();
public slots:
	/**
	* @brief 开始采集
	*/
	void startAcqSlot();
	/**
	* @brief 结束采集
	*/
	void stopAcqSlot();
	/**
	* @brief 新添加plot
	*/
	void addNewPlot();
	/**
	* @brief 删除plot
	*/
	void delPlot();
	/**
	* @brief 清空所有画布
	*/
	void clearPlotWidget();
	/**
	* @brief 重新布局画布
	*/
	void relayoutPlotWidget();
	/**
	* @brief 打开文件
	*/
	void openExpFileSlot();
	/**
	* @brief 保存文件
	*/
	void saveExpFileSlot();
	void showReport(bool on);
signals:
	void openExpSignal(QString,bool);
	void getCellDataFromFile();
	void startReadCellDataFromCircleBuffer();
	/**
	* @brief 保存文件信号
	*/
	void saveExpFileToPlotwigetSignal(QString fileName,QString filetype);
protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void timerEvent(QTimerEvent *event);
private:
	Ui::ViewWidget ui;
	//PlotWidget* plotWidget;
	QList<QWidget*> plotWidgetList;
	QWidget* focusPlotWidget;
	//真正的定时器
	int m_timerId;
	ReadCellThread* readCellThread;

	ReportTree* reportTree;//树形报告
};

#endif // VIEWWIDGET_H
