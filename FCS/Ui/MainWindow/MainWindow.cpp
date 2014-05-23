
#include "MainWindow.h"
#include <QDebug>

#include "USB/USBThread.h"
#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
#include <QBitmap>
MainWindow::MainWindow(QWidget *parent)
	: DropShadowWidget(parent)
{
	ui.setupUi(this);
	//系统日志线程启动
	usbControl = new USBControl(this);
	//ui.menuBar->setPalette(palette1);
// 	QString ss("QMenuBar::item { background: green; color: orange }");
// 	ui.menuBar->setStyleSheet(ss);
	//ui.btnLeft->setPalette(palette);
	
// 	USBThread* usbThread = new USBThread();
// 	usbControl->moveToThread(usbThread);
	//启动试采样
// 	QObject::connect(this, SIGNAL(startOscAcq()), usbControl, SLOT(onButtonRd()));
// 	//启动采集
// 	QObject::connect(this, SIGNAL(startOscAcq()), usbControl, SLOT(onButtonRd()));
/*	usbThread->start();*/

	QPixmap pixmapLeft(":/MainWindow/Resources/Images/TestLeft.png");
// 	ui.labelLeft->setPixmap(pixmapLeft);
// 	ui.labelLeft->setMask(pixmapLeft.mask());
	ui.btnLeft->setMask(pixmapLeft.mask());
	QPixmap pixmapRight(":/MainWindow/Resources/Images/TestRight.png");
// 	ui.labelRight->setPixmap(pixmapRight);
// 	ui.labelRight->setMask(pixmapRight.mask());
	ui.btnRight->setMask(pixmapRight.mask());


	this->setWindowTitle("QQ ");
	this->setWindowIcon(QIcon(":/images/po.jpg"));



	titleWidget = new TitleWidget();
	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addWidget(titleWidget);
	//main_layout->addLayout(center_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
	setLayout(main_layout);

}

MainWindow::~MainWindow()
{
}

/**
* @brief 测试下发命令
*/
void MainWindow::on_loadCmdBtn_clicked()
{
	//开始采集命令
	VoCmd voCmd;
	voCmd.setCmd(8);
	//voCmd.setCmd(5);
	voCmd.setLength(2);
	usbControl->sendCmd(voCmd);

}
/**
* @brief 测试采集示波器数据
*/
void MainWindow::on_startOscBtn_clicked()
{
	
}
/**
* @brief 测试开始采集细胞数据
*/
void MainWindow::on_startAcqBtn_clicked()
{
	emit startOscAcq();
}

/**
* @brief 设置激光
*/
void MainWindow::on_setLaserBtn_clicked()
{
	VoLaser voLaser;
	voLaser.setCmd(1);
	voLaser.setLength(2);
	voLaser.setPassage(1);
	voLaser.setStrength(50);
	usbControl->setLaser(voLaser);
}
/**
* @brief 设置鞘液
*/
void MainWindow::on_setFluidBtn_clicked()
{

}
/**
* @brief 设置样本流
*/
void MainWindow::on_setSampleBtn_clicked()
{

}
/**
* @brief 设置通道偏压
*/
void MainWindow::on_setChannelBiasBtn_clicked()
{

}

/**
* @brief 设置触发值
*/
void MainWindow::on_setTriggerBtn_clicked()
{

}
/**
* @brief 打开USB设备
*/
void MainWindow::on_openUsbBtn_clicked()
{
	usbControl->openDevice();
}
/**
* @brief 关闭USB设备
*/
void MainWindow::on_closeUsbBtn_clicked()
{

	usbControl->closeDevice();
}
/**
* @brief 读取数据
*/
void MainWindow::on_readBtn_clicked()
{


	usbControl->onButtonRd();
}