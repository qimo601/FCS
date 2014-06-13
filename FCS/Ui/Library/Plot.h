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

class QwtPlotCurve;
class QwtSymbol;
class Zoomer;
class Plot : public QwtPlot
{
	Q_OBJECT

public:
	Plot(QWidget *parent = 0);
	~Plot();
	void setSymbol(QwtSymbol *);
	void setSamples(const QVector<QPointF> &samples);
	void setRawSamples(const double * xData, const double * yData, int size);
public slots:
	void setGridEnable(bool checked);
	/**
	* @brief 设置放大/缩小按钮功能启用
	*/
	void enableZoomMode(bool checked);
	/**
	* @brief 设置平移功能启用
	*/
	void enablePannerMode(bool checked);
private:
	QwtPlotCurve *d_curve;
	//背景方格
	QwtPlotGrid* d_grid;
	//放大器
	Zoomer* d_zoomer;
	// 平移画布，根据鼠标左键
	QwtPlotPanner* d_panner;
};

#endif // PLOT_H
