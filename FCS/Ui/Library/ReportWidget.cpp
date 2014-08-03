#include "ReportWidget.h"
ReportWidget::ReportWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ReportWidget::~ReportWidget()
{

}
void ReportWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}