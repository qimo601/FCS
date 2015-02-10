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
#include "Ui/QwtCustom/EllipsePicker.h"
#include "Ui/QwtCustom/PolygonPicker.h"
#include "Ui/Library/PlotConfig.h"
#include "Ui/QwtCustom/PointColorData.h"
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
	//初始化参数数据
	void initPlotConfigData();
	QList < QList < QVector<double>* >*  >* origialDataList;//符合条件的原始数据
	QList < QList < QVector<double>* >*  >* logDataList;//符合条件的log值

	QList < QList < QVector<BarStruct>* >*  >* barStructList;//符合条件统计值
	QMutex dataMutex;//外界更改上面三组数据，必用该锁

	PlotStaticsThread staticsThread;//统计线程




	QList<GateStorage*> m_gateStorageList;//当前画布的所有设门




	//矩形
	RectPicker* d_rectPicker;
	//平行线1
	ParallelLinePicker* d_parallelLinePicker_1;
	//平行线2
	ParallelLinePicker* d_parallelLinePicker_2;
	QList<QPointF> parallelLineList;

	//椭圆设门
	EllipsePicker* d_ellipsePicker;
	//十字线设门
	CrossPicker* d_crossPicker_1;
	CrossPicker* d_crossPicker_2;
	QList<QPointF> crossPickerList;
	//多边形
	PolygonPicker* d_polygonPicker;

	Plot *d_plot;
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
	* @brief 启用十字线设门
	*/
	void enableCrossBtnMode(bool mode);
	/**
	* @brief 显示鼠标指向的点的真值
	*/
	void enableViewTrueValueMode2(bool mode);
	/**
	* @brief 启用平行线设门
	*/
	void enableParallelLineBtn(bool mode);
	///**
	//* @brief 矩形设门事件
	//*/
	//void on_rectBtn_toggled(bool mode);
	/**
	* @brief 启用椭圆形设门
	*/
	void enableEllipseBtn(bool mode);
	/**
	* @brief 启用矩形设门
	*/
	void enableRectBtn(bool mode);
	/**
	* @brief 启用多边形设门
	*/
	void enablePolygonBtn(bool mode);

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
	* @brief 选择的十字坐标
	*
	*/
	void selectedCrossPickerSlot(QList<QPointF> crossPickerList);
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
	* @brief 椭圆设门
	*
	*/
	void selectedEllipsePickerSlot(QRectF rectf);
	/**
	* @brief 根据矩形筛选
	*
	*/
	void computeRectPickerSlot(QRectF rectf);
	/**
	* @brief 多边形设门
	*
	*/
	void selectedPolygonPickerSlot(QVector<QPointF> vector1);
	/**
	* @brief 根据平行线筛选
	*
	*/
	void computeParallelLinePickerSlot(QList<QPointF> pointFList);
	/**
	* @brief 根据椭圆筛选
	*
	*/
	void computeEllipsePickerSlot(QRectF rectf);
	/**
	* @brief 根据十字线筛选
	*
	*/
	//void computeCrossPickerSlot(QPointF pointF);
	/**
	* @brief 根据十字线筛选
	*
	*/
	void computeCrossPickerSlot(QList<QPointF> pointFList);
	/**
	* @brief 根据多边形筛选
	*
	*/
	void computePolygonPickerSlot(QVector<QPointF> vector);
	/**
	* @brief 判断点是否在多边形内部
	*/
	bool pointInPolygon(QPointF pointF, float* polyX, float* polyY, int polySides);
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
	void computerAverageValue(QList<QList<double>>& averageList, QList<QList<double>>& midList, QList<QList<double>>& cvList);
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

	/**
	* @brief 清空该窗口所有数据-恢复空数据
	*/
	void unistall();
	/**
	* @brief 设置画布标题
	*/
	void setTitle(QString title);
	/**
	* @brief 设置画布标题
	*/
	QString getTitle();
	/**
	* @brief 拷贝数据至新控件
	*/
	void copyData(QVector<int> indexVector);

	/**
	* @brief 初始化属性窗口及其动画
	*/
	void initAnimation();
	/**
	* @brief 设置按钮弹出属性窗口
	*/
	void on_propertyBtn_clicked();
	/**
	* @brief 显示属性窗口
	*/
	void showPlotConfig();
	/**
	* @brief 关闭属性窗口
	*/
	void closePlotConfig();
	/**
	* @brief 设置属性窗口不可见
	*/
	void setVisiblePropertyWidget();

	/**
	* @brief 重新设置画布参数
	*/
	void setPlotConfig(QMap<QString, QVariant> valueMap);
	/**
	* @brief 重新设置画布参数
	*/
	void setScatterPlotConfig(QMap<QString, QVariant> valueMap);
	/**
	* @brief 重新设置画布参数
	*/
	void setBarChartPlotConfig(QMap<QString, QVariant> valueMap);
	/**
	* @brief 设置按钮属性
	*/
	void setPropertyBtnStatus();
	/**
	* @brief 复制窗口事件
	*/
	void on_copyBtn_clicked();
	/**
	* @brief 关闭窗口事件
	*/
	void on_closeBtn_clicked();
	/**
	* @brief 设置密度图显示模式
	*/
	void setSpectrogramMode(bool mode);
	/**
	* @brief 设置等高线显示模式
	*/
	void setContourMode(bool mode);
	/**
	* @brief 设置实验名称
	*/
	void setExperimentName(QString experimentName);
	/**
	* @brief 设置细胞个数
	*/
	void setCellEvents(double events);
	/**
	* @brief 测试补偿当前通道 Y-X*percent
	*/
	void compensationSlot(int passageY, int passageX, double percent);
	/**
	* @brief 更新孩子散点图统计数据
	*/
	void updateChildGateScatterSamples(PlotWidget* childPlotWidget, QString colorName);
	/**
	* @brief 更新当前窗口中所有设门的颜色
	*/
	void updateGateColorSample(PlotWidget* parentWidget);
	/**
	* @brief 将parentWiget节点下所有儿子，孙子等等孩子，全绘制在rootWidget上。
	*/
	void putColorAllChildren(PlotWidget* rootWidget, PlotWidget* parentWiget);
signals:
	void normalPlot();//正常显示信号
	void addGateSignal(QWidget*);
protected:
	virtual void paintEvent(QPaintEvent * event);
	virtual void timerEvent(QTimerEvent * event);
	/**
	* @brief 鼠标按下事件
	*/
	void mousePressEvent(QMouseEvent *event);
	/**
	* @brief 鼠标释放事件
	*/
	void mouseReleaseEvent(QMouseEvent *);
	/**
	* @brief 鼠标移动事件
	*/
	void mouseMoveEvent(QMouseEvent *event);


	
private:
	Ui::PlotWidget ui;
	//Plot *d_plot;
	BllDataCenter bllDataCenter;

	QVBoxLayout *vLayoutCellPlotFrame;//细胞绘图布局控件
	
	int m_timerId;//真正的定时器
	bool logEnable;//是否启动log绘图

	QWidget* m_parent;//临时存储当前窗口的父窗口


	int condition;//直方图统计条件数

	



	//当前设门生成的窗口
	PlotWidget* d_plotWidgetGate;
	//当前窗口右键菜单
	QMenu* m_menu;


	PlotConfig* plotConfig;//配置窗口
	//属性窗口出现动画
	QPropertyAnimation* showPropertyAnimation;
	//属性窗口出现动画
	QPropertyAnimation* closePropertyAnimation;




	//直方图线条粗细颜色
	QString m_barChatColor;
	int m_barChatWide;
	bool m_barChartDefault;
	//x轴坐标
	double m_xLeftBarchart;
	double m_xRightBarchart;
	bool m_xAutoBarchart;

	//y轴坐标
	double m_yDownBarchart;
	double m_yTopBarchart;
	bool m_yAutoBarchart;

	//散点图线条粗细颜色
	QString m_scatterColor;
	int m_scatterWide;
	bool m_scatterDefault;
	//x轴坐标
	double m_xLeftScatter;
	double m_xRightScatter;
	bool m_xAutoScatter;

	//y轴坐标
	double m_yDownScatter;
	double m_yTopScatter;
	bool m_yAutoScatter;

	//画布颜色
	QString m_plotColor;
	bool m_defaultCheck;



	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键
	bool notMoveStaus;
};

#endif // PLOTWIDGET_H
