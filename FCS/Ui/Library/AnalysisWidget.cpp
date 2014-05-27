#include "AnalysisWidget.h"

AnalysisWidget::AnalysisWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

AnalysisWidget::~AnalysisWidget()
{

}
void AnalysisWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}