
#include "TestUsb.h"
#include <QDebug>

#include "USB/USBThread.h"
#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
TestUsb::TestUsb(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//系统日志线程启动
	usbControl = new USBControl(this);
	
// 	USBThread* usbThread = new USBThread();
// 	usbControl->moveToThread(usbThread);
	//启动试采样
// 	QObject::connect(this, SIGNAL(startOscAcq()), usbControl, SLOT(onButtonRd()));
// 	//启动采集
// 	QObject::connect(this, SIGNAL(startOscAcq()), usbControl, SLOT(onButtonRd()));
/*	usbThread->start();*/


	
	
}

TestUsb::~TestUsb()
{
}

/**
* @brief 测试下发命令
*/
void TestUsb::on_loadCmdBtn_clicked()
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
void TestUsb::on_startOscBtn_clicked()
{
	
}
/**
* @brief 测试开始采集细胞数据
*/
void TestUsb::on_startAcqBtn_clicked()
{
	emit startOscAcq();
}

/**
* @brief 设置激光
*/
void TestUsb::on_setLaserBtn_clicked()
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
void TestUsb::on_setFluidBtn_clicked()
{

}
/**
* @brief 设置样本流
*/
void TestUsb::on_setSampleBtn_clicked()
{

}
/**
* @brief 设置通道偏压
*/
void TestUsb::on_setChannelBiasBtn_clicked()
{

}

/**
* @brief 设置触发值
*/
void TestUsb::on_setTriggerBtn_clicked()
{

}
/**
* @brief 打开USB设备
*/
void TestUsb::on_openUsbBtn_clicked()
{
	usbControl->openDevice();
}
/**
* @brief 关闭USB设备
*/
void TestUsb::on_closeUsbBtn_clicked()
{

	usbControl->closeDevice();
}
/**
* @brief 读取数据
*/
void TestUsb::on_readBtn_clicked()
{


	usbControl->onButtonRd();
}