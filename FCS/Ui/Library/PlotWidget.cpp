#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
PlotWidget::PlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//ϸ����ͼ�ؼ���ʼ��
	vLayoutCellPlotFrame = new QVBoxLayout(ui.cellPlotFrame);
	vLayoutCellPlotFrame->setSpacing(6);
	vLayoutCellPlotFrame->setContentsMargins(11, 11, 11, 11);
	vLayoutCellPlotFrame->setObjectName(QStringLiteral("verticalLayout_4"));
	d_plot = new Plot(ui.cellPlotFrame);
	d_plot->setObjectName(QStringLiteral("d_plot"));

	vLayoutCellPlotFrame->addWidget(d_plot);

	//���ñ������Ƿ���ʾ
	connect(ui.gridCheckBox, SIGNAL(clicked(bool)), d_plot, SLOT(setGridEnable(bool)));


	m_timerId = 0;//��ʼ��


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
	//ÿ��10ms����һ��
	if (event->timerId() == m_timerId)
	{
		updateSamples(0);
	}
}

void PlotWidget::startAcqTimer()
{
	//������ʱ��
	m_timerId = startTimer(10);
}
void PlotWidget::stopAcqTimer()
{
	//�رն�ʱ��
	killTimer(m_timerId);
}

void PlotWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}
void PlotWidget::focusInEvent(QFocusEvent * event)
{

}
void PlotWidget::focusOutEvent(QFocusEvent * event)
{

}