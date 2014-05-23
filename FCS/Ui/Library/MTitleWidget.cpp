#include "MTitleWidget.h"

MTitleWidget::MTitleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.minBtn->setPicName(":/sysButton/Resources/Images/SysButton/min");
	ui.maxBtn->setPicName(":/sysButton/Resources/Images/SysButton/max");
	ui.closeBtn->setPicName(":/sysButton/Resources/Images/SysButton/close");

	connect(ui.minBtn, SIGNAL(clicked()), this, SIGNAL(minWidget()));
	connect(ui.maxBtn, SIGNAL(clicked()), this, SIGNAL(maxWidget()));
	connect(ui.closeBtn, SIGNAL(clicked()), this, SIGNAL(closeWidget()));
}

MTitleWidget::~MTitleWidget()
{

}
void MTitleWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}