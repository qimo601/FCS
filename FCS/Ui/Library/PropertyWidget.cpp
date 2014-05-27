#include "PropertyWidget.h"
#include <QPainter>
PropertyWidget::PropertyWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//����ԭ������
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

}

PropertyWidget::~PropertyWidget()
{

}
/**
* @brief ����ͨ����ɫ�˵�
*/
void PropertyWidget::on_colorBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(0);
}
/**
* @brief �����ļ�����ʽ�˵�
*/
void PropertyWidget::on_fileNameBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(1);
}
/**
* @brief �����м�ֵ�˵�
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