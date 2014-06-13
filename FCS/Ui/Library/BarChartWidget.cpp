#include "BarChartWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
BarChartWidget::BarChartWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//细胞绘图控件初始化
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(6);
	vLayoutCellPlotFrame->setContentsMargins(11, 11, 11, 11);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_plot = new Plot(ui.cellPlotFrame);
	d_plot->setObjectName(QStringLiteral("d_plot"));

	vLayoutCellPlotFrame->addWidget(d_plot);



	//设置背景线是否显示
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), d_plot, SLOT(setGridEnable(bool)));
	//设置放大/缩小按钮可选择
	ui.zoomerBtn->setCheckable(true);
	//设置放大缩小功能是否启用
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enableZoomMode(bool)));
	//设置平移按钮可选择
	ui.pannerBtn->setCheckable(true);
	//设置平移按钮功能是否启用
	connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enablePannerMode(bool)));

	m_timerId = 0;//初始化


}

BarChartWidget::~BarChartWidget()
{

}

double BarChartWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}


void BarChartWidget::updateSamples(int numPoints)
{
	QPolygonF samples;

	bllDataCenter.getCellData(false);
	QVector<double>* vectorX = bllDataCenter.getCellDataVector(3, 1);
	QVector<double>* vectorY = bllDataCenter.getCellDataVector(3, 0);
	d_plot->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());
	d_plot->replot();
}
void BarChartWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	if (event->timerId() == m_timerId)
	{
		updateSamples(0);
	}
}

void BarChartWidget::startAcqTimer()
{
	//开启定时器
	m_timerId = startTimer(10);
}
void BarChartWidget::stopAcqTimer()
{
	//关闭定时器
	killTimer(m_timerId);
}

void BarChartWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}