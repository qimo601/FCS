#include "testwidget.h"
#include <QBitmap>
TestWidget::TestWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	QPixmap acqPixmap(":/MainWindow/Resources/Images/TestLeft.png");
	ui.pushButton->setMask(acqPixmap.mask());
	this->setMouseTracking(true);
}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton_clicked()
{
	//ui.pushButton_2->move(ui.pushButton_2->pos().x()+5, 0);
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
	QPoint mousePos = ui.posBtn->mapFromGlobal(QCursor::pos());
	if (widgetRect.contains(mousePos))
	{
		ui.posBtn->setText("摸到我了");
	}
	else
	{
		ui.posBtn->setText("....");
	}

}