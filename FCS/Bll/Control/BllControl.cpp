#include "BllControl.h"
#include <QMessageBox>
BllControl::BllControl(QObject *parent)
	: QObject(parent)
{
	initUSBControl();//��Ĭ����������ʼ����ʱ��������
}

BllControl::~BllControl()
{
}

/**
* @brief ��ʼ��USB����
*/
void BllControl::initUSBControl()
{
	
	//�ж��Ƿ�USB�Ƿ��Ѿ���
	if (USBDriver::usbControl == 0)
		USBDriver::usbControl = new USBControl();
	else
		return;
#if Simulation_Test == 0
	if (!USBDriver::usbControl->openDevice())
	{
		QMessageBox msgBox;
		msgBox.setText("��USB�豸ʧ��.");
		msgBox.setInformativeText("USB�豸��ʧ�ܣ����庯����\n"\
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
* @brief ��USB�豸
*/
void BllControl::openUSBControl()
{
	//�ж��Ƿ�USB�Ƿ��Ѿ���
	if (USBDriver::usbControl == 0)
		USBDriver::usbControl = new USBControl();
	USBDriver::usbControl->openDevice();
}
/**
* @brief �ر�USB�豸
*/
void BllControl::closeUSBControl()
{
	USBDriver::usbControl->closeDevice();
	USBDriver::usbControl = 0;
}
/**
* @brief USB��ʼ���������������ݣ���������
*/
void BllControl::startListening()
{
	USBDriver::usbControl->listen();
}


/**
* @brief ���ü���
*/
bool BllControl::setLaser(VoLaser& vo)
{
	//���ü���Э��01 02 xx yy
	UCHAR buffer[4];
	DWORD DataLength = 4;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = vo.getPassage();
	buffer[3] = vo.getStrength();

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		QMessageBox msgBox;
		msgBox.setText("���ü������,ʧ��.");
		msgBox.setInformativeText("���庯����\n"\
			"BllControl::setLaser(VoLaser& vo)");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return false;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("���ü���������ɹ�!");
		msgBox.setInformativeText("���ü���������ɹ�!\n");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		int ret = msgBox.exec();
		return true;
	}

}

/**
* @brief ������Һ����
*/
bool BllControl::setFluid(VoFluid& vo)
{
	//������Һ����Э��01 02 xx xx
	//xx xxΪ���٣�0~4095
	UCHAR buffer[4];
	DWORD DataLength = 4;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = getHighInt(vo.getVelocity());
	buffer[3] = getLowInt(vo.getVelocity());

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		QMessageBox msgBox;
		msgBox.setText("������Һ������ʧ��!");
		msgBox.setInformativeText("���庯����\n"\
			"bool BllControl::setFluid(VoFluid& vo)");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return false;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("������Һ�������ɹ�!");
		msgBox.setInformativeText("������Һ�������ɹ�!\n");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		int ret = msgBox.exec();
		return true;
	}

}
/**
* @brief ��������������
*/
bool BllControl::setSample(VoSample& vo)
{
	//������Ʒ��������03 02 xx xx
	//xx xxΪ���٣�0~4095

	UCHAR buffer[4];
	DWORD DataLength = 4;
	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();
	buffer[2] = getHighInt(vo.getVelocity());
	buffer[3] = getLowInt(vo.getVelocity());

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		QMessageBox msgBox;
		msgBox.setText("������������ʧ��!");
		msgBox.setInformativeText("��BllControl��������������ʧ��!���庯����\n"\
			"bool BllControl::setSample(VoSample& vo)");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return false;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("�������������ɹ�!!");
		msgBox.setInformativeText("�������������ɹ�!!\n");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		int ret = msgBox.exec();
		return true;
	}
}
/**
* @brief ����ͨ��ƫѹ
*/
bool BllControl::setChannelBias(VoChannelBias& vo)
{
	//������Һ����Э��04 02 xy yy
	//xΪͨ������Χ��1-8��	y yy��Ӧͨ����ѹ���˴����Ϊ12λ���ݣ�

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
		QMessageBox msgBox;
		msgBox.setText("����ͨ��ƫѹ��ʧ��!");
		msgBox.setInformativeText("��BllControl������ͨ��ƫѹ��ʧ��!���庯����\n"\
			"bool BllControl::setChannelBias(VoChannelBias& vo)");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return false;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("����ͨ��ƫѹ���ɹ�!");
		msgBox.setInformativeText("����ͨ��ƫѹ���ɹ�!\n");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		int ret = msgBox.exec();
		return true;
	}
}
/**
* @brief ���ô���ֵ����
*/
bool BllControl::setTrigger(VoTrigger& vo)
{
	//������Ʒ��������07 04 xx xx yy yy
	//xxΪͨ������Χ��1-8�����ڶ���xx��Ч��
	//yy yyΪ���Դ���ֵ��16λ��Ч


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

		QMessageBox msgBox;
		msgBox.setText("���ô���ֵ��ʧ��!�Ƿ�USB�Ѿ��Ͽ���!");
		msgBox.setInformativeText("�����ô���ֵ��ʧ��!�Ƿ�USB�Ѿ��Ͽ���!���庯����\n"\
			"bool BllControl::setTrigger(VoTrigger& vo)");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return false;
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("���ô���ֵ���ɹ�!");
		msgBox.setInformativeText("���ô���ֵ���ɹ�!\n");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Information);
		int ret = msgBox.exec();
		return true;
	}
}
/**
* @brief �·�����
*/
bool BllControl::sendCmd(VoCmd& vo)
{

	UCHAR buffer[2];
	DWORD DataLength = 2;

	buffer[0] = vo.getCmd();
	buffer[1] = vo.getLength();

	if (!USBDriver::usbControl->write(buffer, DataLength))
	{
		qDebug() << QString("��BllControl���·����%1��ʧ��!�Ƿ�USB�Ѿ��Ͽ�").arg(buffer[0]);
		return false;
	}
	else
	{
		qDebug() << QString("��BllControl���·����%1���ɹ�!").arg(buffer[0]);
		return true;
	}

}

/**
* @brief ��ȡ��8λ��ֵ
*/
uchar BllControl::getHighInt(int value)
{
	//int m = 0x0512,����ȡ��ʱ0x05
	return value >> 8;
}
/**
* @brief ��ȡ��8λ��ֵ
*/
uchar BllControl::getLowInt(int value)
{
	//int m = 0x0512,����ȡ��ʱ0x12
	return value & 0x00FF;
}
/**
* @brief ��װͨ��ƫѹ����
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