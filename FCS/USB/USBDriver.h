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

	//ȫ��USB���ƽӿ�
	static USBControl* usbControl;
private:
	
};

#endif // USBDRIVER_H
