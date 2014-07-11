#include "MenuWidget.h"
#include <QPainter>
#include <QMenu>
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//�ļ��˵�
	QMenu* fileMenu = new QMenu();
	fileMenu->addAction(ui.newExpAction);
	fileMenu->addAction(ui.openExpAction);
	fileMenu->addAction(ui.saveExpAction);
	ui.fileBtn->setMenu(fileMenu);
	connect(ui.openExpAction, SIGNAL(triggered()), this, SLOT(openExpFile()));
	connect(ui.saveExpAction, SIGNAL(triggered()), this, SLOT(saveExpFile()));
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
* @brief ��ʵ���ļ�
*/
void MenuWidget::openExpFile()
{
	emit openExpFileSignal();
}
/**
* @brief ����ʵ���ļ�
*/
void MenuWidget::saveExpFile()
{
	emit saveExpFileSignal();
}

