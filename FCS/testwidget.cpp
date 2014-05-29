#include "testwidget.h"
#include <QBitmap>
#include <QMdiSubWindow>
TestWidget::TestWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	

	for (int i = 0; i < 50; i++)
	{
		QLabel *label = new QLabel("<--------->", ui.scrollAreaWidgetContents_3);
		label->move(i * 10, i * 10);
		
	}

	//隐藏原标题栏
	QList<QMdiSubWindow *> mlist = ui.mdiArea->subWindowList();
	mlist[2]->showMaximized();

}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton123_clicked()
{
	
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