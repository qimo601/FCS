#include "WheelBox.h"

WheelBox::WheelBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//��QLCDNumber��ʾ
	connect(ui.d_wheel, SIGNAL(valueChanged(double)),
		ui.d_number, SLOT(display(double)));
	//��ValueChanged�¼�
	connect(ui.d_wheel, SIGNAL(valueChanged(double)),
		this, SIGNAL(valueChanged(double)));
}

WheelBox::~WheelBox()
{

}
/**
* @brief   ����WheelBox������
*/
void WheelBox::setProperty(const QString &title, double min, double max, double stepSize)
{
	ui.d_label->setText(title);
	ui.d_wheel->setRange(min, max);
	ui.d_wheel->setSingleStep(stepSize);
}
void WheelBox::setValue(double value)
{
	ui.d_wheel->setValue(value);
	ui.d_number->display(value);
}

double WheelBox::value() const
{
	return ui.d_wheel->value();
}
