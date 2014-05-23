#include "testwidget.h"
#include <QBitmap>
TestWidget::TestWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPixmap acqPixmap(":/MainWindow/Resources/Images/TestLeft.png");
	ui.pushButton->setMask(acqPixmap.mask());
	ui.pushButton_2->move(5, 0);
}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton_clicked()
{
	//ui.pushButton_2->move(ui.pushButton_2->pos().x()+5, 0);
	ui.pushButton_2->setGeometry(ui.pushButton_2->pos().x() + 5, 0, ui.pushButton_2->width(),ui.pushButton_2->height());
}
void TestWidget::resizeEvent(QResizeEvent * event)
{
	QSize size = event->size();
	int widgetHeight = size.rheight();
	int widgetWidth = size.rwidth();
	ui.pushButton_2->move(0, ui.pushButton_2->pos().y());
	int width = ui.pushButton_2->pos().x();
	int height = ui.pushButton_2->pos().y();


}
/**
* @brief 鼠标滑动事件
*/
void TestWidget::mouseMoveEvent(QMouseEvent* event)
{

}