#include "BllControl.h"
#include <QMessageBox>
BllControl::BllControl(QObject *parent)
	: QObject(parent)
{
	initUSBControl();//不默认启动，开始启动时，菜启动
}

BllControl::~BllControl()
{
}

/**
* @brief 初始化USB控制
*/
void BllControl::initUSBControl()
{
	
	//判断是否USB是否已经打开
	if (USBDriver::usbControl == 0)
		USBDriver::usbControl = new USBControl();
	else
		return;
#if Simulation_Test == 0
	if (!USBDriver::usbControl->openDevice())
	{
		QMessageBox msgBox;
		msgBox.setText("打开USB设备失败.");
		msgBox.setInformativeText("USB设备打开失败，具体函数：\n"\
			"BllControl::initUSBControl()");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return;
	}
#endif

	startListening();
}
/**
* @brief 打开USB设备
*/
void BllControl::openUSBControl()
{
	//判断是否USB是否已经打开
	if (USBDriver::usbControl == 0)
		USBDriver::usbControl = new USBControl();
	USBDriver::usbControl->openDevice();
}
/**
* @brief 关闭USB设备
*/
void BllControl::closeUSBControl()
{
	USBDriver::usbControl->closeDevice();
	USBDriver::usbControl = 0;
}
/**
* @brief USB开始监听（持续读数据，非阻塞）
*/
void BllControl::startListening()
{
	USBDriver::usbControl->listen();
}


/**
* @brief 设置激光
*/
bool BllControl::setLaser(VoLaser& vo)
{
	//设置激光协议01 02 xx yy
	UCHAR buffer[4];
	DWORD DataLength = 4;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = vo.getPassage();
	buffer[3] = vo.getStrength();

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug("【BllControl】设置激光参数，失败!");
		return false;
	}
	else
	{
		qDebug("【BllControl】设置激光参数，成功!");
		return true;
	}

}

/**
* @brief 设置鞘液参数
*/
bool BllControl::setFluid(VoFluid& vo)
{
	//设置鞘液参数协议01 02 xx xx
	//xx xx为流速，0~4095
	UCHAR buffer[4];
	DWORD DataLength = 4;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = getHighInt(vo.getVelocity());
	buffer[3] = getLowInt(vo.getVelocity());

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug("【BllControl】设置鞘液参数，失败!");
		return false;
	}
	else
	{
		qDebug("设置鞘液参数，成功!");
		return true;
	}

}
/**
* @brief 设置样本流参数
*/
bool BllControl::setSample(VoSample& vo)
{
	//设置样品流参数：03 02 xx xx
	//xx xx为流速，0~4095

	UCHAR buffer[4];
	DWORD DataLength = 4;
	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = getHighInt(vo.getVelocity());
	buffer[3] = getLowInt(vo.getVelocity());

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug("【BllControl】设置样本流，失败!");
		return false;
	}
	else
	{
		qDebug("【BllControl】设置样本流，成功!");
		return true;
	}
}
/**
* @brief 设置通道偏压
*/
bool BllControl::setChannelBias(VoChannelBias& vo)
{
	//设置鞘液参数协议04 02 xy yy
	//x为通道，范围：1-8；	y yy对应通道电压，此处最大为12位数据，

	UCHAR buffer[4];
	DWORD DataLength = 4;
	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	char c2, c3;
	getChannelBias(vo, c2, c3);
	buffer[2] = c2;
	buffer[3] = c3;

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug("【BllControl】设置通道偏压，失败!");
		return false;
	}
	else
	{
		qDebug("【BllControl】设置通道偏压，成功!");
		return true;
	}
}
/**
* @brief 设置触发值参数
*/
bool BllControl::setTrigger(VoTrigger& vo)
{
	//设置样品流参数：07 04 xx xx yy yy
	//xx为通道，范围：1-8；（第二个xx有效）
	//yy yy为各自触发值，16位有效


	UCHAR buffer[6];
	DWORD DataLength = 6;
	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = vo.getChannel1();
	buffer[3] = vo.getChannel2();
	buffer[4] = getHighInt(vo.getTriggerValue());
	buffer[5] = getLowInt(vo.getTriggerValue());

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug("【BllControl】设置触发值，失败!");
		return false;
	}
	else
	{
		qDebug("【BllControl】设置触发值，成功!");
		return true;
	}
}
/**
* @brief 下发命令
*/
bool BllControl::sendCmd(VoCmd& vo)
{

	UCHAR buffer[2];
	DWORD DataLength = 2;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug() << "【BllControl】下发命令：" << buffer[0] << (",失败!");
		return false;
	}
	else
	{
		qDebug() << "【BllControl】下发命令：" << buffer[0] << (",成功!");
		return true;
	}

}

/**
* @brief 获取高8位的值
*/
uchar BllControl::getHighInt(int value)
{
	//int m = 0x0512,后面取得时0x05
	return value >> 8;
}
/**
* @brief 获取低8位的值
*/
uchar BllControl::getLowInt(int value)
{
	//int m = 0x0512,后面取得时0x12
	return value & 0x00FF;
}
/**
* @brief 封装通道偏压参数
*/
void BllControl::getChannelBias(VoChannelBias& vo, char& buffer2, char& buffer3)
{
	// 	int m1 = 0x01;
	// 	int n1 = 0x213;
	// 
	// 	char c1 = m1 << 4;
	// 	c1 += n1 >> 8;//c1 = 0x12
	// 	char c2 = n1 & 0xFF; //c2 = 0x13

	int channel = vo.getChannel();
	int voltage = vo.getVoltage();

	buffer2 = channel << 4;
	buffer2 += voltage >> 8;
	buffer3 = voltage & 0xFF;
}