#include "ViewWidget.h"
ViewWidget::ViewWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	/*plotWidget = new PlotWidget(ui.scrollAreaWidgetContents);
	ui.gridLayout->addWidget(plotWidget, 1, 0, 1, 1);*/

}

ViewWidget::~ViewWidget()
{

}
void ViewWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}

/**
* @brief 开始采集
*/
void ViewWidget::startAcqSlot()
{

	ui.plotWidget_1->startAcqTimer();
}
/**
* @brief 结束采集
*/
void ViewWidget::stopAcqSlot()
{
	ui.plotWidget_1->stopAcqTimer();
}
