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

	//�̶ȱ�ǩֵ
	virtual QwtText label(double value) const
	{
		QwtText lbl = 0;

		const int index = qRound(value);//��������
		if (index >= 0 && index < d_labels.size())//�����ݵ�ʱ��
		{
			lbl = d_labels[index];
		}
		return lbl;
	}

private:
	const QStringList d_labels;
};

//ֱ��ͼ
//QwtPlotBarChart��һϵ��������ʾΪbar
class DistroChartItem : public QwtPlotBarChart
{
public:
	DistroChartItem() :
		QwtPlotBarChart("Page Hits")
	{
		setLegendMode(QwtPlotBarChart::LegendBarTitles);//��ʾ����bar���Եı��⣬��QwtPlotBarChart::LegendChartTitle ��ʾ�����ı���
		setLegendIconSize(QSize(10, 14));
	}

	//������ɫ�ͱ����bar��������
	void addDistro(const QString& title, const QColor& color)
	{
		m_colorList.append(color);
		m_titleList.append(title);
		itemChanged();//Update the legend of the parent plot.
	}

	//�Զ���ÿ��Bar
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
	//�Զ���ÿ��bar�ı���
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

////ֱ��ͼ�ĵ����ڵ�ṹ��
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
//	QString m_title;//��ǰ�ڵ�Bar����
//	double m_value; //��ǰ�ڵ�Barֵ
//	QColor m_color;//��ǰ�ڵ���ɫ
//};
BarChart::BarChart(QWidget *parent) :
QwtPlot(parent)
{	
	//initBarData();//��ʼ������
	initBarChart();//��ʼ��ֱ��ͼ


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
* @brief ��ʼ��ֱ��ͼ
*/
void BarChart::initBarChart()
{
	setAutoFillBackground(true);
	setPalette(QColor("#D4D3CC"));//plot����ɫ

	//���û���
	QwtPlotCanvas *canvas = new QwtPlotCanvas();
	canvas->setLineWidth(2);
	canvas->setFrameStyle(QFrame::Box | QFrame::Sunken);
	canvas->setBorderRadius(10);

	QPalette canvasPalette(QColor("Plum"));//��������ɫ
	canvasPalette.setColor(QPalette::Foreground, QColor("Indigo"));//����ǰ��ɫ
	canvas->setPalette(canvasPalette);

	setCanvas(canvas);

	setTitle("ֱ��ͼ��ʾ");//��������




	//m_barChartItem->setSamples(m_samples);
	
	
	m_barChartItem = new DistroChartItem();//ֱ��ͼ
	m_barChartItem->attach(this);
	//insertLegend(new QwtLegend());//����ֱ��ͼ����

	setAutoReplot(false);

	QwtPlotZoomer* zoomer = new MyZoomer(canvas);
	zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
		Qt::RightButton, Qt::ControlModifier);
	zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
		Qt::RightButton);
	replot();

		
}
/**
* @brief ����ֱ��ͼ�б������ɫ
*/
void BarChart::setBarChartData(QList<BarStruct>& barStructList)
{
	
	setAxisScaleDraw(QwtPlot::yLeft, new DistroScaleDraw(Qt::Vertical, m_titleList));//��Ҫ���¸��±���

	//����Դ
	for (int i = 0; i < barStructList.size(); i++)
	{
		m_titleList.append(barStructList.at(i).m_title); //�����⸳ֵ
		m_samples.append(barStructList.at(i).m_value);//�����ݸ�ֵ
		m_barChartItem->addDistro(barStructList.at(i).m_title, barStructList.at(i).m_color);//������ɫ�ͱ���
	}
	m_barChartItem->setSamples(m_samples);//���³�ʼ�����꣬Ҫ����legend
	updateLegend();//����legend
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

	m_barChartItem->setOrientation(orientation);//ֱ��ͼ����
	m_barChartItem->setSpacing(5);//spacing ����������֮��ľ��루����ֱ��ͼ֮��ľ��룬����ÿ��ֱ��ͼ֮��ľ���
	m_barChartItem->setMargin(5);// margin ������ֱ��ͼ�뻭���ı߿����֮��ľ���
	m_barChartItem->setLayoutHint(5);//bar�Ŀ��

	setAxisTitle(axis1, "ֵ��Χ");


	setAxisMaxMinor(axis1, 0);//����������С�̶ȵ����ֵ
	setAxisMaxMajor(axis1, 10);//�����������̶ȵ����ֵ

	setAxisScaleDraw(axis1, new DistroScaleDraw(orientation, m_titleList));//��Ҫ���¸��±���


	setAxisTitle(axis2, "����");
	setAxisMaxMinor(axis2, 3);

	QwtScaleDraw *scaleDraw = new QwtScaleDraw();
	scaleDraw->setTickLength(QwtScaleDiv::MediumTick, 4);
	setAxisScaleDraw(axis2, scaleDraw);


	//������̶�����
	QwtScaleWidget *scaleXWidget = this->axisWidget(axis1);//x��̶ȿؼ�
	scaleXWidget->setStyleSheet(
		"color:#666666;"
		);
	const int fmh = QFontMetrics(scaleXWidget->font()).height();
	scaleXWidget->setMinBorderDist(0, fmh / 2);//���ÿ̶ȵı߽���Сֵ����ֹ��Ϊ��ǩ�仯����������  
	QwtScaleWidget *scaleYWidget = this->axisWidget(axis2);//x��̶ȿؼ�
	this->setAxisScale(axis2, 0, 1000000);//����x������̶ȴ�С
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
* @brief ��������
*/
void BarChart::setSamples(const QVector<double> &samples)
{
	if (samples.size() <= 0)
		m_barChartItem->setSamples(m_samples);//��������
	else
		m_barChartItem->setSamples(samples);
	//m_samples.append(samples);//׷������
	//m_barChartItem->setSamples(m_samples);//��������

	//replot();
}
/**
* @brief ��������
*/
//void BarChart::setBarX(const QVector<double> &samples)
//{
//
////����Դ
//for (int i = 0; i < barStructList.size(); i++)
//{
//	m_titleList.append(barStructList.at(i).m_title); //�����⸳ֵ
//	m_samples.append(barStructList.at(i).m_value);//�����ݸ�ֵ
//
//	m_barChartItem->addDistro(barStructList.at(i).m_title, barStructList.at(i).m_color);//������ɫ�ͱ���
//}

//}