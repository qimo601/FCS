#include "MainForm.h"
#include "Ui/Library/MTitleWidget.h"
MainForm::MainForm(QWidget *parent)
: DropShadowWidget(parent)
{

	ui.setupUi(this);

	init();

	widgetStatus = WidgetStatus::NORMAL_WIDGET;

	//绑定标题栏事件
	connect(ui.titleWidget, SIGNAL(minWidget()), this, SLOT(showMin()));
	connect(ui.titleWidget, SIGNAL(maxWidget()), this, SLOT(showMaxOrNormal()));
	connect(ui.titleWidget, SIGNAL(closeWidget()), this, SLOT(close()));



	connect(ui.toolWidget, SIGNAL(acqBtnClicked()), ui.stackedWidget, SLOT(oscHandle()));//示波器采集按钮
	connect(ui.toolWidget, SIGNAL(analyBtnClicked()), ui.stackedWidget, SLOT(dataAnalyHandle()));//细胞绘图分析与报告按钮


	connect(ui.menuWidget, SIGNAL(openExpFileSignal()), ui.stackedWidget, SLOT(openExpFileSlot()));//打开本地文件
	connect(ui.menuWidget, SIGNAL(saveExpFileSignal()), ui.stackedWidget, SLOT(saveExpFileSlot()));//打开本地文件
}

MainForm::~MainForm()
{

}
/**
* @brief 初始化
*/
void MainForm::init()
{

}
/**
* @brief 最大化或者正常
*/
void MainForm::showMaxOrNormal()
{
	if (widgetStatus == WidgetStatus::MAX_WIDGET)
	{
		showNormal();
		widgetStatus = WidgetStatus::NORMAL_WIDGET;
	}
	else
	{
		showMaximized();
		widgetStatus = WidgetStatus::MAX_WIDGET;
	}

	//工具栏窗口
	ui.toolWidget->resetGeometry(30);
}
/**
* @brief 最小化
*/
void MainForm::showMin()
{
	showMinimized();
	widgetStatus = WidgetStatus::MIN_WIDGET;
}
/**
* @brief 重绘此窗口
*/
void MainForm::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MainForm::resetGeometry(int x)
{
	
	ui.toolWidget->resetGeometry(x);
}