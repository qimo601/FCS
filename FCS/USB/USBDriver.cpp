#include "USBDriver.h"

USBDriver::USBDriver(QObject *parent)
	: QObject(parent)
{

}

USBDriver::~USBDriver()
{

}

//全局USB控制接口
USBControl* USBDriver::usbControl = NULL;