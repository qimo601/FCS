/**
* 项    目:  FCS软件
* 文件名称:   BarChart.h
* 文件路径：  Ui/Libary/BarChart.h
* 摘    要:  自定义直方图
* 作    者： 刘兆邦
* 日    期： 2014年06月12日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef BARCHART_H
#define BARCHART_H

#include <qwt_plot.h>
#include <qstringlist.h>
#include "Include/Global.h"
class DistroChartItem;
class BarStruct;

class BarChart : public QwtPlot
{
	Q_OBJECT

public:
	BarChart(QWidget * = NULL);


	void initBarChart();//初始化直方图
	//void initBarData();//初始化直方图数据
	QList<BarStruct> barStructList;//直方图所有节点源数据

public slots:
	void setOrientation(int);
	void exportChart();
	/**
	* @brief 设置直方图列标题和颜色
	*/
	void setBarChartData(QList<BarStruct>& barStructList);
	/**
	* @brief 更新数据
	*/
	void setSamples(const QVector<double> &samples);

private:
	void populate();

	DistroChartItem *m_barChartItem;//自定义直方图类
	QStringList m_titleList;//改变方向重置标题用
	
	QVector< double > m_samples;//数据源
};


#endif // BARCHART_H
