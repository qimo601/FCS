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
void PropertyWidget::on_pushButton1_clicked()
{
	animation1->start();
	animation->start();

}