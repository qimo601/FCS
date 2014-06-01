#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
PlotWidget::PlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	d_plot = new Plot(this);
	d_plot->setObjectName(QStringLiteral("d_plot"));
	d_plot->setGeometry(QRect(10, 20, 461, 341));
	m_timerId = 0;//初始化


}

PlotWidget::~PlotWidget()
{

}

double PlotWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}


void PlotWidget::updateSamples(int numPoints)
{
	QPolygonF samples;

	bllDataCenter.getCellData(false);
	QVector<double>* vectorX = bllDataCenter.getCellDataVector(1, 0);
	QVector<double>* vectorY = bllDataCenter.getCellDataVector(2, 0);
	d_plot->setRawSamples(vectorX->data(), vectorY->data(), vectorY->size());
	d_plot->replot();
}
void PlotWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	if (event->timerId() == m_timerId)
	{
		updateSamples(0);
	}
}

void PlotWidget::startAcqTimer()
{
	//开启定时器
	m_timerId = startTimer(10);
}
void PlotWidget::stopAcqTimer()
{
	//关闭定时器
	killTimer(m_timerId);
}