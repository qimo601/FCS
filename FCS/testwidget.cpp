#include "testwidget.h"
#include <QBitmap>
TestWidget::TestWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	QPixmap acqPixmap(":/MainWindow/Resources/Images/TestLeft.png");
	ui.pushButton123->setMask(acqPixmap.mask());
	this->setMouseTracking(true);

	propertyWidget = new PropertyWidget(this);
	propertyWidget->setVisible(false);
	showPropertyAnimation = new QPropertyAnimation(propertyWidget, "geometry");
}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton123_clicked()
{
	//ui.pushButton_2->move(ui.pushButton_2->pos().x()+5, 0);
	QPoint p = ui.pushButton123->pos();
	QPoint pos = ui.frame_2->mapTo(this, ui.pushButton123->pos());
	QPoint pos1 = ui.frame_2->mapTo(this,ui.pushButton123->pos());
	QPoint pos1_1 = ui.pushButton123->mapTo(this, ui.pushButton123->pos());
	QPoint pos2 = ui.frame_2->mapToParent(ui.pushButton123->pos());
	QPoint pos2_1 = ui.pushButton123->mapToParent(ui.pushButton123->pos());
	QPoint pos3 = ui.frame_2->mapToGlobal(ui.pushButton123->pos());
	QPoint pos3_1 = ui.pushButton123->mapToGlobal(ui.pushButton123->pos());


	//propertyWidget->setGeometry(pos.x(), pos.y(), 300, 200);
	propertyWidget->setVisible(true);
	showPropertyAnimation->setDuration(10000);
	showPropertyAnimation->setStartValue(QRect(300, pos.y(), 300, 200));
	showPropertyAnimation->setEndValue(QRect(pos.x(), pos.y(), 300, 200));
	showPropertyAnimation->start();
}
void TestWidget::resizeEvent(QResizeEvent * event)
{
	QSize size = event->size();
	int widgetHeight = size.rheight();
	int widgetWidth = size.rwidth();


}
/**
* @brief 鼠标滑动事件
*/
void TestWidget::mouseMoveEvent(QMouseEvent* event)
{
	QPoint m = event->globalPos();
	ui.lblMouseEventGlobalPos->setText(QString("(%1,%2)").arg(m.x()).arg(m.y()));
	QPoint n = QCursor::pos();
	ui.lblCursorPos->setText(QString("(%1,%2)").arg(n.x()).arg(n.y()));
	QPoint k = ui.posBtn->pos();
	QPoint h = ui.posBtn->mapToGlobal(ui.posBtn->pos());
	QPoint i = ui.posBtn->mapToGlobal(ui.posBtn->pos());

	ui.lblPushBttonPos->setText(QString("(%1,%2)").arg(k.x()).arg(k.y()));
	ui.lblToParentPos->setText(QString("(%1,%2)").arg(h.x()).arg(h.y()));
	ui.lblToGlobalPos->setText(QString("(%1,%2)").arg(i.x()).arg(i.y()));
	

	QRect widgetRect = ui.posBtn->geometry();
	QPoint widgetPos = ui.posBtn->mapTo(this, ui.posBtn->pos());
	QPoint mousePos = mapFromGlobal(QCursor::pos());
	if (widgetRect.contains(mousePos))
	{
		ui.posBtn->setText("摸到我了");
	}
	else
	{
		ui.posBtn->setText("....");
	}
	//propertyWidget->setGeometry(widgetPos.x(), widgetPos.y(), 300, 200);

}