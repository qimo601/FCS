#ifndef USBDRIVER_H
#define USBDRIVER_H

#include <QObject>
#include "USBControl.h"
class USBDriver : public QObject
{
	Q_OBJECT

public:
	USBDriver(QObject *parent);
	~USBDriver();

	//全局USB控制接口
	static USBControl* usbControl;
private:
	
};

#endif // USBDRIVER_H
