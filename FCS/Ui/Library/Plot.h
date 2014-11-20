/**
* 项    目:  FCS软件
* 文件名称:   Plot.h
* 文件路径：  Ui/Libary/Plot.h
* 摘    要:  自定义绘图控件
* 作    者： 刘兆邦
* 日    期： 2014年05月29日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef PLOT_H
#define PLOT_H

#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include "Include/Global.h"
#include "Ui/QwtCustom/RectPicker.h"
#include "Ui/QwtCustom/CrossPicker.h"
#include "Ui/QwtCustom/ParallelLinePicker.h"

#include <qwt_plot_spectrogram.h>
#include "Ui/QwtCustom/PointColorData.h"
class QwtPlotCurve;
class QwtSymbol;
class Zoomer;
class QwtPlotCanvas;
class SpectrogramData;
class Plot : public QwtPlot
{
	Q_OBJECT

public:
	Plot(QWidget *parent = 0);
	~Plot();
	void setSymbol(QwtSymbol *);
	void setSamples(const QVector<QPointF> &samples);
	void setSamples(const QVector< double > & xData, const QVector< double > & 	yData);
	void setRawSamples(const double * xData, const double * yData, int size);

	//设置画布
	QwtPlotCanvas *canvas;
public slots:

	/**  
	 * @brief  启动背景方格线 
	 * 
	 * @param   bool::checked   是否启动背景方格线
	 * @return  bool::needBrush  是否是直方图模式，如果是背景刷填充色彩，如果不是，背景刷无色。 
	 * @author  Liuzhaobang 
	 * @date    2014/08/09 
	 */ 
void setGridEnable(bool checked, bool barMode);
	/**
	* @brief 设置放大/缩小按钮功能启用
	*/
	void enableZoomMode(bool checked);
	/**
	* @brief 设置平移功能启用
	*/
	void enablePannerMode(bool checked);
	/**
	* @brief 设置统计模式的样式
	*/
	void enableStaticsMode();
	/**
	* @brief 设置散点图模式的样式
	*/
	void enableScatterMode();
	/**
	* @brief 设置跟踪鼠标显示当前值
	*/
	void enableViewTrueValue(bool mode);
	/**
	* @brief 设置跟踪鼠标显示当前值
	*/
	void enableViewTrueValue2(bool mode);
	/**
	* @brief 启用矩形设门
	*/
	void enableRectPicker(bool mode);
	/**
	* @brief 启用平行线设门
	*/
	void enableParallelLinePicker(bool mode);
	/**
	* @brief 增加-测试选择
	*/
	void setUpBtnMode(bool mode);
	/**
	* @brief 减少-测试选择
	*/
	void setDownBtnMode(bool mode);
	/**
	* @brief 十字设门
	*/
	void selectedCrossPickerSlot(QPointF);
	void selectedRectPickerSlot(QRectF rectf);

	void selectedParallelLinePickerSlot(QPointF pointf);
	/**
	* @brief 设置画布背景
	*/
	void setCanvasBackgroundColor(QString colorName);
	/**
	* @brief 设置散点图曲线颜色
	*/
	void setScatterCurve(QString colorName, int width,QString brushColorName);
	/**
	* @brief 设置散点图曲线颜色
	*/
	void setBarChartCurve(QString colorName, int width, QString brushColorName);
	/**
	* @brief 初始化密度图
	*/
	void initSpectrogram();
	/**
	* @brief 显示密度图
	*/
	void showSpectrogram(bool on);
	/**
	* @brief 显示等高线
	*/
	void showContour(bool on);
	/**
	* @brief 更新密度图数据
	*/
	void updateSpectrogramData(QList<PointColorData>  pointList);
	/**
	* @brief 更新密度图数据
	*/
	void updateSpectrogramData(QVector<double>* vectorX, QVector<double>* vectorY);
signals:
	void selectedCrossPicker(QPointF);
	void selectedRectPicker(QRectF);
	void selectedParallelLinePicker(QList<QPointF>);
private:
	QwtPlotCurve *d_curve;
	//背景方格
	QwtPlotGrid* d_grid;
	//放大器
	Zoomer* d_zoomer;
	// 平移画布，根据鼠标左键
	QwtPlotPanner* d_panner;
	
	//十字线设门
	CrossPicker* d_picker;

	//十字线设门2
	CrossPicker* d_picker2;
	//矩形
	RectPicker* d_rectPicker;
	//平行线1
	ParallelLinePicker* d_parallelLinePicker_1;
	//平行线2
	ParallelLinePicker* d_parallelLinePicker_2;
	QList<QPointF> parallelLineList;


	//自定义曲线的颜色和宽度
	QString m_scatterColorName;
	int m_scatterWidth;
	QString m_scatterBrushColorName;

	QString m_barChartColorName;
	int m_barChartWidth;
	QString m_barChartBrushColorName;


	//密度图
	//光谱图
	QwtPlotSpectrogram* d_spectrogram;
	//光谱图数据源
	SpectrogramData* d_spectrogramData;

};

#endif // PLOT_H
