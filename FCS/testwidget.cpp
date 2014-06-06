#include "testwidget.h"
#include <QBitmap>
#include <QMdiSubWindow>
#include <QPainter>
#include <QTimer>
TestWidget::TestWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton123_clicked()));
	//timer->start(1000);

}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton123_clicked()
{

	this->focusNextChild();
}
void TestWidget::resizeEvent(QResizeEvent * event)
{

	
}
/**
* @brief 鼠标滑动事件
*/
void TestWidget::mouseMoveEvent(QMouseEvent* event)
{
	
}
void TestWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}