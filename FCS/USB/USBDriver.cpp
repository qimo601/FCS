#include "USBDriver.h"

USBDriver::USBDriver(QObject *parent)
	: QObject(parent)
{

}

USBDriver::~USBDriver()
{

}

//ȫ��USB���ƽӿ�
USBControl* USBDriver::usbControl = NULL;