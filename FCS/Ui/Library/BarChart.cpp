#include "barchart.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_barchart.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <qwt_scale_widget.h>
#include "BarStruct.h"
#include <qwt_plot_zoomer.h>
class DistroScaleDraw : public QwtScaleDraw
{
public:
	DistroScaleDraw(Qt::Orientation orientation, const QStringList &labels) :
		d_labels(labels)
	{
		setTickLength(QwtScaleDiv::MinorTick, 0);
		setTickLength(QwtScaleDiv::MediumTick, 0);
		setTickLength(QwtScaleDiv::MajorTick, 2);

		enableComponent(QwtScaleDraw::Backbone, false);

		if (orientation == Qt::Vertical)
		{
			setLabelRotation(-60.0);
		}
		else
		{
			setLabelRotation(-20.0);
		}

		setLabelAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		
	}

	//刻度标签值
	virtual QwtText label(double value) const
	{
		QwtText lbl = 0;

		const int index = qRound(value);//四舍五入
		if (index >= 0 && index < d_labels.size())//无数据的时候
		{
			lbl = d_labels[index];
		}
		return lbl;
	}

private:
	const QStringList d_labels;
};

//直方图
//QwtPlotBarChart将一系列数据显示为bar
class DistroChartItem : public QwtPlotBarChart
{
public:
	DistroChartItem() :
		QwtPlotBarChart("Page Hits")
	{
		setLegendMode(QwtPlotBarChart::LegendBarTitles);//显示所有bar各自的标题，而QwtPlotBarChart::LegendChartTitle 显示这个表的标题
		setLegendIconSize(QSize(10, 14));
	}

	//分配颜色和标题给bar，并更新
	void addDistro(const QString& title, const QColor& color)
	{
		m_colorList.append(color);
		m_titleList.append(title);
		itemChanged();//Update the legend of the parent plot.
	}

	//自定义每个Bar
	virtual QwtColumnSymbol *specialSymbol(
		int index, const QPointF&) const
	{


		QwtColumnSymbol *symbol = new QwtColumnSymbol(QwtColumnSymbol::Box);
		symbol->setLineWidth(1);
		symbol->setFrameStyle(QwtColumnSymbol::Plain);//Raised

		QColor c(Qt::white);
		if (index >= 0 && index < m_colorList.size())
			c = m_colorList[index];

		symbol->setPalette(c);

		return symbol;
	}
	//自定义每个bar的标题
	virtual QwtText barTitle(int sampleIndex) const
	{
		QwtText title;
		if (sampleIndex >= 0 && sampleIndex < m_titleList.size())
			title = m_titleList[sampleIndex];

		return title;
	}

private:
	QList<QColor> m_colorList;
	QList<QString> m_titleList;
};

////直方图的单个节点结构体
//class BarStruct
//{
//public:
//	BarStruct(){}
//	BarStruct(QString title, double value, QColor color)
//	{
//		m_title = title;
//		m_value = value;
//		m_color = color;
//	}
//	~BarStruct(){}
//	QString m_title;//当前节点Bar标题
//	double m_value; //当前节点Bar值
//	QColor m_color;//当前节点颜色
//};
BarChart::BarChart(QWidget *parent) :
QwtPlot(parent)
{	
	//initBarData();//初始化数据
	initBarChart();//初始化直方图


}

class MyZoomer : public QwtPlotZoomer
{
public:
	MyZoomer(QWidget *canvas) :
		QwtPlotZoomer(canvas)
	{
		setTrackerMode(AlwaysOn);
	}

	virtual QwtText trackerTextF(const QPointF &pos) const
	{
		QColor bg(Qt::white);
		bg.setAlpha(200);

		QwtText text = QwtPlotZoomer::trackerTextF(pos);
		text.setBackgroundBrush(QBrush(bg));
		return text;
	}
};

/**
* @brief 
*/
//void BarChart::updateBarData()
//{
//}
/**
* @brief 初始化直方图
*/
void BarChart::initBarChart()
{
	setAutoFillBackground(true);
	setPalette(QColor("#D4D3CC"));//plot背景色

	//设置画布
	QwtPlotCanvas *canvas = new QwtPlotCanvas();
	canvas->setLineWidth(2);
	canvas->setFrameStyle(QFrame::Box | QFrame::Sunken);
	canvas->setBorderRadius(10);

	QPalette canvasPalette(QColor("Plum"));//画布背景色
	canvasPalette.setColor(QPalette::Foreground, QColor("Indigo"));//画布前景色
	canvas->setPalette(canvasPalette);

	setCanvas(canvas);

	setTitle("直方图显示");//画布标题




	//m_barChartItem->setSamples(m_samples);
	
	
	m_barChartItem = new DistroChartItem();//直方图
	m_barChartItem->attach(this);
	//insertLegend(new QwtLegend());//插入直方图描述

	setAutoReplot(false);

	QwtPlotZoomer* zoomer = new MyZoomer(canvas);
	zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
		Qt::RightButton, Qt::ControlModifier);
	zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
		Qt::RightButton);
	replot();

		
}
/**
* @brief 设置直方图列标题和颜色
*/
void BarChart::setBarChartData(QList<BarStruct>& barStructList)
{
	
	setAxisScaleDraw(QwtPlot::yLeft, new DistroScaleDraw(Qt::Vertical, m_titleList));//需要重新更新标题

	//数据源
	for (int i = 0; i < barStructList.size(); i++)
	{
		m_titleList.append(barStructList.at(i).m_title); //给标题赋值
		m_samples.append(barStructList.at(i).m_value);//给数据赋值
		m_barChartItem->addDistro(barStructList.at(i).m_title, barStructList.at(i).m_color);//更新颜色和标题
	}
	m_barChartItem->setSamples(m_samples);//更新初始数据完，要更新legend
	updateLegend();//更新legend
	setOrientation(0);
}

void BarChart::setOrientation(int orient)
{
	const Qt::Orientation orientation =
		(orient == 0) ? Qt::Vertical : Qt::Horizontal;

	int axis1 = QwtPlot::xBottom;
	int axis2 = QwtPlot::yLeft;

	if (orientation == Qt::Horizontal)
		qSwap(axis1, axis2);

	m_barChartItem->setOrientation(orientation);//直方图方向
	m_barChartItem->setSpacing(5);//spacing 是两个样本之间的距离（两个直方图之间的距离，或者每组直方图之间的距离
	m_barChartItem->setMargin(5);// margin 最外层的直方图与画布的边框矩形之间的距离
	m_barChartItem->setLayoutHint(5);//bar的宽度

	setAxisTitle(axis1, "值范围");


	setAxisMaxMinor(axis1, 0);//设置坐标轴小刻度的最大值
	setAxisMaxMajor(axis1, 10);//设置坐标轴大刻度的最大值

	setAxisScaleDraw(axis1, new DistroScaleDraw(orientation, m_titleList));//需要重新更新标题


	setAxisTitle(axis2, "个数");
	setAxisMaxMinor(axis2, 3);

	QwtScaleDraw *scaleDraw = new QwtScaleDraw();
	scaleDraw->setTickLength(QwtScaleDiv::MediumTick, 4);
	setAxisScaleDraw(axis2, scaleDraw);


	//坐标轴刻度修饰
	QwtScaleWidget *scaleXWidget = this->axisWidget(axis1);//x轴刻度控件
	scaleXWidget->setStyleSheet(
		"color:#666666;"
		);
	const int fmh = QFontMetrics(scaleXWidget->font()).height();
	scaleXWidget->setMinBorderDist(0, fmh / 2);//设置刻度的边界最小值，防止因为标签变化，引起跳动  
	QwtScaleWidget *scaleYWidget = this->axisWidget(axis2);//x轴刻度控件
	this->setAxisScale(axis2, 0, 1000000);//设置x轴坐标刻度大小
	scaleYWidget->setStyleSheet(
		"color:#666666;"
		);
	
	plotLayout()->setCanvasMargin(0);
	replot();
}

void BarChart::exportChart()
{
	QwtPlotRenderer renderer;
	renderer.exportTo(this, "Barchart.pdf");
}
/**
* @brief 更新数据
*/
void BarChart::setSamples(const QVector<double> &samples)
{
	if (samples.size() <= 0)
		m_barChartItem->setSamples(m_samples);//更新数据
	else
		m_barChartItem->setSamples(samples);
	//m_samples.append(samples);//追加数据
	//m_barChartItem->setSamples(m_samples);//更新数据

	//replot();
}
/**
* @brief 更新数据
*/
//void BarChart::setBarX(const QVector<double> &samples)
//{
//
////数据源
//for (int i = 0; i < barStructList.size(); i++)
//{
//	m_titleList.append(barStructList.at(i).m_title); //给标题赋值
//	m_samples.append(barStructList.at(i).m_value);//给数据赋值
//
//	m_barChartItem->addDistro(barStructList.at(i).m_title, barStructList.at(i).m_color);//更新颜色和标题
//}

//}