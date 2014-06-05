#include "Plot.h"
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_curve.h>
class DistancePicker : public QwtPlotPicker
{
public:
	//�ṩѡ����
	DistancePicker(QWidget *canvas) :
		QwtPlotPicker(canvas)
	{
		//���ø���ģʽ
		setTrackerMode(QwtPicker::ActiveOnly);
		//����һ��״̬������ɾ����һ��
		setStateMachine(new QwtPickerDragLineMachine());
		//������Ȧ��ʽ�������
		setRubberBand(QwtPlotPicker::PolygonRubberBand);
	}
	//��λ��ת�����ַ���
	virtual QwtText trackerTextF(const QPointF &pos) const
	{
		QwtText text;

		const QPolygon points = selection();//ѡ��ĵ�
		if (!points.isEmpty())
		{
			QString num;
			num.setNum(QLineF(pos, invTransform(points[0])).length());

			QColor bg(Qt::white);
			bg.setAlpha(200);

			text.setBackgroundBrush(QBrush(bg));
			text.setText(num);
		}
		return text;
	}
};

Plot::Plot(QWidget *parent)
: QwtPlot(parent),
d_curve(NULL)
{

	canvas()->setStyleSheet(
		"border: 1px solid Black;"
		"border-radius: 15px;"
		"background-color:#FFFFFF;"
		);

	// attach curve
	d_curve = new QwtPlotCurve("Scattered Points");
	//������ɫ
	QColor c(42,93,169);
	d_curve->setPen(c, 2);

	// when using QwtPlotCurve::ImageBuffer simple dots can be
	// rendered in parallel on multicore systems.
	d_curve->setRenderThreadCount(0); // 0: use QThread::idealThreadCount()

	d_curve->attach(this);

	setSymbol(NULL);

	// ƽ�ƻ���������������
	(void)new QwtPlotPanner(canvas());

	//֧�ֻ��ַŴ���Сzoom in/out with the wheel
	QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(canvas());
	magnifier->setMouseButton(Qt::NoButton);

	//�Ҽ����� distanve measurement with the right mouse button
	DistancePicker *picker = new DistancePicker(canvas());
	picker->setMousePattern(QwtPlotPicker::MouseSelect1, Qt::RightButton);
	picker->setRubberBandPen(QPen(Qt::blue));

	grid = new QwtPlotGrid();
	grid->setPen(QColor(233, 228, 225), 0.0, Qt::DashLine);
	grid->enableX(true);
	grid->enableXMin(false);
	grid->enableY(true);
	grid->enableYMin(false);
	grid->attach(this);


	this->setAxisScale(QwtPlot::xBottom, 4000000, 6000000);//����x������̶ȴ�С
	this->setAxisScale(QwtPlot::yLeft, 4000000, 6000000);//����y������̶ȴ�С

}

Plot::~Plot()
{

}
void Plot::setSymbol(QwtSymbol *symbol)
{
	//����һ������
	d_curve->setSymbol(symbol);

	if (symbol == NULL)
	{
		d_curve->setStyle(QwtPlotCurve::Dots);
	}
}

void Plot::setSamples(const QVector<QPointF> &samples)
{
	/**ָ�����߻滭����ΪImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	d_curve->setPaintAttribute(
		QwtPlotCurve::ImageBuffer, samples.size() > 1000);

	d_curve->setSamples(samples);
}
void Plot::setRawSamples(const double * xData,	const double * 	yData,	int size)
{
	/**ָ�����߻滭����ΪImageBufferRender the points to a temporary image and paint the image.
	This is a very special optimization for Dots style, when having a huge amount of points.
	With a reasonable number of points QPainter::drawPoints() will be faster.*/
	d_curve->setPaintAttribute(
		QwtPlotCurve::ImageBuffer, size > 1000);

	d_curve->setRawSamples(xData, yData,size);
}
/**
* @brief ���ñ������Ƿ���ʾ
*/
void Plot::setGridEnable(bool checked)
{
	
	grid->enableX(checked);
	grid->enableXMin(false);
	grid->enableY(checked);
	grid->enableYMin(false);

	replot();
}