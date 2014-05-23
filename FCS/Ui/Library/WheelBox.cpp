#include "WheelBox.h"

WheelBox::WheelBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//绑定QLCDNumber显示
	connect(ui.d_wheel, SIGNAL(valueChanged(double)),
		ui.d_number, SLOT(display(double)));
	//绑定ValueChanged事件
	connect(ui.d_wheel, SIGNAL(valueChanged(double)),
		this, SIGNAL(valueChanged(double)));
}

WheelBox::~WheelBox()
{

}
/**
* @brief   设置WheelBox的属性
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
