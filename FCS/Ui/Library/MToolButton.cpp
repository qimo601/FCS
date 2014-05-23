#include "MToolButton.h"

MToolButton::MToolButton(QWidget *parent)
: QToolButton(parent)
{
	ui.setupUi(this);
	this->setMouseTracking(true);
}

MToolButton::~MToolButton()
{

}
/**
* @brief ��껬���¼�
*/
void MToolButton::mouseMoveEvent(QMouseEvent* event)
{

	int x = event->x();
	int y = event->y();
	int propertyX = this->x();
	int propertyY = this->y();
	int propertWidth = this->width();
	int propertHeight = this->height();

	if (x > propertyX && x <propertyX + propertWidth && y>propertyY && y < propertyY + propertHeight)
	{
		this->setCursor(Qt::OpenHandCursor);
	}
	else{
		this->setCursor(Qt::ArrowCursor);
	}
}
/**
* @brief ����ͼ��
*/
void MToolButton::setIcon(QIcon icon)
{
	QToolButton::setIcon(icon);
}