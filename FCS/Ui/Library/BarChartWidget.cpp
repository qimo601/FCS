#include "BarChartWidget.h"

#include "plot.h"
#include <qmath.h>
#include <QTime>
#include <QPainter>
BarChartWidget::BarChartWidget(QWidget *parent)
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
	//���÷Ŵ�/��С��ť��ѡ��
	ui.zoomerBtn->setCheckable(true);
	//���÷Ŵ���С�����Ƿ�����
	connect(ui.zoomerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enableZoomMode(bool)));
	//����ƽ�ư�ť��ѡ��
	ui.pannerBtn->setCheckable(true);
	//����ƽ�ư�ť�����Ƿ�����
	connect(ui.pannerBtn, SIGNAL(toggled(bool)), d_plot, SLOT(enablePannerMode(bool)));

	m_timerId = 0;//��ʼ��


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
	//ÿ��10ms����һ��
	if (event->timerId() == m_timerId)
	{
		updateSamples(0);
	}
}

void BarChartWidget::startAcqTimer()
{
	//������ʱ��
	m_timerId = startTimer(10);
}
void BarChartWidget::stopAcqTimer()
{
	//�رն�ʱ��
	killTimer(m_timerId);
}

void BarChartWidget::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}