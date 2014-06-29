#include "MenuWidget.h"
#include <QPainter>
#include <QMenu>
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//文件菜单
	QMenu* fileMenu = new QMenu();
	fileMenu->addAction(ui.newExpAction);
	fileMenu->addAction(ui.openExpAction);
	ui.fileBtn->setMenu(fileMenu);
	connect(ui.openExpAction, SIGNAL(triggered()), this, SLOT(openExpFile()));
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
/**
* @brief 打开实验文件
*/
void MenuWidget::openExpFile()
{
	emit openExpFileSignal();
}