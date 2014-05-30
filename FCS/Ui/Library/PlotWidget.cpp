#include "PlotWidget.h"

#include "plot.h"
#include <qmath.h>
PlotWidget::PlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	d_plot = new Plot(this);
	d_plot->setObjectName(QStringLiteral("d_plot"));
	d_plot->setGeometry(QRect(10, 20, 461, 341));

	// a million points
	setSamples(100000);
}

PlotWidget::~PlotWidget()
{

}

double PlotWidget::randomValue()
{
	// a number between [ 0.0, 1.0 ]
	return (qrand() % 100000) / 100000.0;
}


void PlotWidget::setSamples(int numPoints)
{
	QPolygonF samples;

	for (int i = 0; i < numPoints; i++)
	{
		const double x = randomValue() * 24.0 + 1.0;
		const double y = ::log(10.0 * (x - 1.0) + 1.0)
			* (randomValue() * 0.5 + 0.9);

		samples += QPointF(x, y);
	}

	d_plot->setSamples(samples);
}
