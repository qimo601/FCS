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
class QwtPlotCurve;
class QwtSymbol;
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

private:
	QwtPlotCurve *d_curve;
	//背景方格
	QwtPlotGrid* grid;
};

#endif // PLOT_H
