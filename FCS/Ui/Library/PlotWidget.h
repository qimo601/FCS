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
#include <QPaintEvent>
#include "ui_PlotWidget.h"
#include "Bll/DataCenter/BllDataCenter.h"
#include "PlotStaticsThread.h"
#include "plot.h"
#include "Ui/Library/GateStorage.h"
#include "Ui/QwtCustom/RectPicker.h"
#include "Ui/QwtCustom/CrossPicker.h"
#include "Ui/QwtCustom/CrossPicker.h"
#include "Ui/QwtCustom/ParallelLinePicker.h"
class Plot;
class BarStruct;
class ViewWidget;
class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	PlotWidget(QWidget *parent = 0);
	~PlotWidget();


	/**
	* @brief 随机值
	*/
	double randomValue();

	/**
	* @brief 初始化
	*/
	void init();
	void initUi();//初始化界面
	//初始化Bar列标题、颜色，模拟数据
	void initBarData();
	QList < QList < QVector<double>* >*  >* origialDataList;//符合条件的原始数据
	QList < QList < QVector<double>* >*  >* logDataList;//符合条件的log值

	QList < QList < QVector<BarStruct>* >*  >* barStructList;//符合条件统计值
	QMutex dataMutex;//外界更改上面三组数据，必用该锁

	PlotStaticsThread staticsThread;//统计线程




	QList<GateStorage*> m_gateStorageList;//当前画布的所有设门
public slots:
	void startAcqTimer();
	void stopAcqTimer();
	/**
	* @brief 设置通道
	*/
	void setPassage(int index);
	/**
	* @brief 一次性统计直方图
	* @param passage通道
	* @param dataUnit数据单元
	*/
	void statisticsHistogram(int passage, int dataUnit);

	/**
	* @brief 设置数据单元类型
	*/
	void setDataUnit(int index);
	/**
	* @brief 最大化当前plot窗口
	*/
	void maximizedPlotWidget();
	/**
	* @brief 还原窗口
	*/
	void normalPlotWidget();
	
	/**
	* @brief 重新设置刻度
	*/
	void setAxisScale();
	/**
	* @brief 启动log数据显示
	*/
	void setLogEnable(bool enable);
	/**
	* @brief 启动背景方格线
	*/
	void setGridEnable(bool enable);
	/**
	* @brief 设置直方图统计显示模式
	*/
	void setBarStatisticsMode(bool mode);
	/**
	* @brief 设置散点图显示模式
	*/
	void setScatterMode(bool mode);
	/**
	* @brief 启用放大缩小按钮
	*/
	void enableZoomMode(bool mode);
	/**
	* @brief 显示鼠标指向的点的真值
	*/
	void enableViewTrueValueMode(bool mode);
	/**
	* @brief 显示鼠标指向的点的真值
	*/
	void enableViewTrueValueMode2(bool mode);
	/**
	* @brief 启用平行线设门
	*/
	void enableParallelLineBtn(bool mode);
	/**
	* @brief 启用矩形设门
	*/
	void enableRectBtn(bool mode);
	/**
	* @brief 增加-测试
	*/
	void testUpBtnMode(bool mode);
	/**
	* @brief 减少-测试
	*/
	void testDownBtnMode(bool mode);
	/**
	* @brief 更新数据
	*/
	void updateSamples();
	/**
	* @brief 更新统计数据
	*/
	void updateStaticsSamples();
	/**
	* @brief 更新散点图统计数据
	*/
	void updateScatterSamples();
	/**
	* @brief 清楚plot旧数据
	*
	*/
	void clearPlotSamples();

	/**
	* @brief 选择的十字坐标
	*
	*/
	void selectedCrossPickerSlot(QPointF pointf1);
	/**
	* @brief 矩形设门
	*
	*/
	void selectedRectPickerSlot(QRectF rectf);
	/**
	* @brief 平行线设门,判断是否有两个点
	*
	*/
	void selectedParallelLinePickerSlot(QPointF pointf);
	/**
	* @brief 平行线设门
	*
	*/
	void selectedParallelLinePickerSlot(QList<QPointF> pointFList);
	/**
	* @brief 根据矩形筛选
	*
	*/
	void computeRectPickerSlot(QRectF rectf);
	/**
	* @brief 根据平行线筛选
	*
	*/
	void computeParallelLinePickerSlot(QList<QPointF> pointFList);
	/**
	* @brief 保存文件
	* @param QString:文件类型
	*/
	void saveExpFileSlot(QString fileName, QString fileType);
	/**
	* @brief 保存USB格式文件
	* @param QString 文件名称，QString:文件类型
	*/
	void saveUSBFile(QString fileName);
	/**
	* @brief 保存FCM/MatLab格式文件
	* @param QString 文件名称，QString:文件类型
	*/
	void saveFcmFile(QString fileName);
	/**
	* @brief 保存FCS标准格式文件
	* @param QString 文件名称，QString:文件类型
	*/
	void saveFCSFile(QString fileName);
	/**
	* @brief 更新参数数据
	*/
	void updateParamsStatics();
	/**
	* @brief 更新参数-细胞个数
	*/
	double computerEvents();
	/**
	* @brief 更新参数-%Parent:当前设门的细胞数目，占父类的百分比
	*/
	double computerPercentageParent();
	/**
	* @brief 更新参数-%Total:当前设门的细胞数目，占源数据细胞总数的百分比
	*/
	double computerPercentageTotal();
	/**
	* @brief 更新参数-平均值（x1+x2+x3+...+xn）/n
	*/
	double computerAverageValue();
	/**
	* @brief 更新参数-中间值（排序后，中间的值）
	*/
	double computerMidValue();
	/**
	* @brief 更新参数-变异系数 CV(Coefficient of Variance):标准差与均值的比率
	*/
	double computerCvValue();
	/**
	* @brief 获取界面控件的状态
	*/
	QMap<QString, int>  getStatusControl();
	/**
	* @brief 设置界面控件的状态
	*/
	void setStatusControl(QMap<QString, int> map);
	/**
	* @brief 添加设门
	* @param type:设门类型 RECT:矩形，PARALLEL: 平行线设门
	*/
	void addGate(GateStorage::GateType type);
	/**
	* @brief 删除指定设门
	*/
	void deleteGate(GateStorage* gateStorage);

signals:
	void normalPlot();//正常显示信号
	void addGateSignal(QWidget*);
protected:
	virtual void paintEvent(QPaintEvent * event);
	virtual void timerEvent(QTimerEvent * event);

private:
	Ui::PlotWidget ui;
	Plot *d_plot;
	BllDataCenter bllDataCenter;

	QVBoxLayout *vLayoutCellPlotFrame;//细胞绘图布局控件
	
	int m_timerId;//真正的定时器
	bool logEnable;//是否启动log绘图

	QWidget* m_parent;//临时存储当前窗口的父窗口


	int condition;//直方图统计条件数

	//矩形
	RectPicker* d_rectPicker;
	//平行线1
	ParallelLinePicker* d_parallelLinePicker_1;
	//平行线2
	ParallelLinePicker* d_parallelLinePicker_2;
	QList<QPointF> parallelLineList;



	//当前设门生成的窗口
	PlotWidget* d_plotWidgetGate;

	
};

#endif // PLOTWIDGET_H
