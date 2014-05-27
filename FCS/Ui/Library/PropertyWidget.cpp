#include "PropertyWidget.h"
#include <QPainter>
PropertyWidget::PropertyWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//隐藏原标题栏
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

}

PropertyWidget::~PropertyWidget()
{

}
/**
* @brief 设置通道颜色菜单
*/
void PropertyWidget::on_colorBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(0);
}
/**
* @brief 设置文件名格式菜单
*/
void PropertyWidget::on_fileNameBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(1);
}
/**
* @brief 设置中间值菜单
*/
void PropertyWidget::on_midMarkBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(2);
}
void PropertyWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}