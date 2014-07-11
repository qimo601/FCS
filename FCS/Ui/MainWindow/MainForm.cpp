#include "MainForm.h"
#include "Ui/Library/MTitleWidget.h"
MainForm::MainForm(QWidget *parent)
: DropShadowWidget(parent)
{

	ui.setupUi(this);

	init();

	widgetStatus = WidgetStatus::NORMAL_WIDGET;

	//�󶨱������¼�
	connect(ui.titleWidget, SIGNAL(minWidget()), this, SLOT(showMin()));
	connect(ui.titleWidget, SIGNAL(maxWidget()), this, SLOT(showMaxOrNormal()));
	connect(ui.titleWidget, SIGNAL(closeWidget()), this, SLOT(close()));



	connect(ui.toolWidget, SIGNAL(acqBtnClicked()), ui.stackedWidget, SLOT(oscHandle()));//ʾ�����ɼ���ť
	connect(ui.toolWidget, SIGNAL(analyBtnClicked()), ui.stackedWidget, SLOT(dataAnalyHandle()));//ϸ����ͼ�����뱨�水ť


	connect(ui.menuWidget, SIGNAL(openExpFileSignal()), ui.stackedWidget, SLOT(openExpFileSlot()));//�򿪱����ļ�
	connect(ui.menuWidget, SIGNAL(saveExpFileSignal()), ui.stackedWidget, SLOT(saveExpFileSlot()));//�򿪱����ļ�
}

MainForm::~MainForm()
{

}
/**
* @brief ��ʼ��
*/
void MainForm::init()
{

}
/**
* @brief ��󻯻�������
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

	//����������
	ui.toolWidget->resetGeometry(30);
}
/**
* @brief ��С��
*/
void MainForm::showMin()
{
	showMinimized();
	widgetStatus = WidgetStatus::MIN_WIDGET;
}
/**
* @brief �ػ�˴���
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