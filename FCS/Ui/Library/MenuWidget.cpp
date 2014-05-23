#include "MenuWidget.h"
#include <QPainter>
#include <QMenu>
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ÎÄ¼þ²Ëµ¥
	QMenu* fileMenu = new QMenu();
	fileMenu->addAction(ui.newExpAction);
	fileMenu->addAction(ui.openExpAction);
	ui.fileBtn->setMenu(fileMenu);
}

MenuWidget::~MenuWidget()
{

}
void MenuWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}