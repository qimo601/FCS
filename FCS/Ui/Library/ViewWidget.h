#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ViewWidget.h"
#include "PlotWidget.h"
#include "Bll/DataCenter/ReadCellThread.h"
#include "Ui/Report/ReportTree.h"
#include <QFileDialog>
class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget *parent = 0);
	~ViewWidget();
	//全局所有画布数组
	static QList<QWidget*> s_plotWidgetList;

	//在gridLayout中的画布
	static QList<QWidget*> m_gridPlotWidgetList;
	//实验名
	static QString s_experimentName;
public slots:
	/**
	* @brief 注销界面，清空所有数据
	*/
	void uninstall();
	/**
	* @brief 初始化
	*/
	void init();
	/**
	* @brief 开始采集
	*/
	void startAcqSlot();
	/**
	* @brief 结束采集
	*/
	void stopAcqSlot();
	/**
	* @brief 新建画布-新建按钮
	*/
	void addNewPlotFromUi();
	/**
	* @brief 新建画布-新加设门
	*/
	void addNewPlotFromGate(PlotWidget* widget);
	/**
	* @brief 新增加设门窗口槽函数
	*/
	void addGateSlot(QWidget* widget);
	/**
	* @brief 新添加plot
	* @param PlotWidget* widget:新增窗口指针
	* @param bool addNew = false: 是否新增的窗口
	*/
	void addNewPlot(PlotWidget* widget=0,bool addNew = false);
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
	* @brief 新建实验
	*/
	void newExpSlot();
	/**
	* @brief 打开文件
	*/
	void openExpFileSlot();
	/**
	* @brief 保存文件
	*/
	void saveExpFileSlot();
	void showReport(bool on);
	/**
	* @brief 右键打开文件
	*/
	void openExpFileFromRightSlot(QString fileName);
	/**
	* @brief 显示指定的设门窗口
	*/
	void viewGateSlot(QString gateName);
	/**
	* @brief 递归查找设门窗口
	*/
	PlotWidget* findGate(GateStorage* gate, QString gateName);
	/**
	* @brief 关闭报告窗口槽函数
	*/
	void closeReportSlot();
	/**
	* @brief 删除画布对应的窗口
	*/
	void delGateSlot(QString gateName);
	/**
	* @brief 导出PDF文档
	*/
	void savePdfSlot();
	/**
	* @brief 初始化新实验名
	*/
	void initExperimentName();
signals:
	void openExpSignal(QString,bool);//打开实验文件
	void getCellDataFromFile();//读本地文件
	void startReadCellDataFromCircleBuffer();//读循环缓冲用去
	void reportTreeWidgetClose();//关闭报告窗口
	/**
	* @brief 保存文件信号
	*/
	void saveExpFileToPlotwigetSignal(QString fileName,QString filetype);
	/**
	* @brief 是否有选中的画布窗口
	*/
	void haveFocusPlotWidgetSignal(bool focus);

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void timerEvent(QTimerEvent *event);
private:
	Ui::ViewWidget ui;
	//PlotWidget* plotWidget;
	QWidget* focusPlotWidget;
	//真正的定时器
	int m_timerId;
	ReadCellThread* readCellThread;

	ReportTree* reportTree;//树形报告
	//当前窗口被选中
	bool m_focusing;
	//鼠标最后选中位置
	double m_lastPoint;

	//PDF保存窗口
	QFileDialog* m_fdPDF;
	//PDF保存路径
	QString m_pdfSavePath;
	
};

#endif // VIEWWIDGET_H
