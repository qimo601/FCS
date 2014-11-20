/**
* ��    Ŀ:  FCS���
* �ļ�����:  BllControl.h
* �ļ�·���� Control/BllControl.h
* ժ    Ҫ:  �ɼ�����ҵ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��13��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef BLLCONTROL_H
#define BLLCONTROL_H

#include <QObject>
#include "Include/Global.h"
#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
#include "USB/USBDriver.h"
class BllControl : public QObject
{
	Q_OBJECT

public:
	BllControl(QObject *parent=0);
	~BllControl();
	/**
	* @brief �ر�USB�豸
	*/
	static void closeUSBControl();
public slots:
	/**
	* @brief ��ʼ��USB����
	*/
	void initUSBControl();
	/**
	* @brief ��USB�豸
	*/
	void openUSBControl();

	/**
	* @brief USB��ʼ���������������ݣ���������
	*/
	void startListening();
	/**
	* @brief  ���ü���
	*
	* @param   VoLaser voLaser
	*   		VoLaser:���ü������
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	bool setLaser(VoLaser& vo);
	/**
	* @brief   ������Һ����
	*
	* @param   VoFluid
	*
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-10
	*/
	bool setFluid(VoFluid& vo);
	/**
	* @brief ������������
	*/
	/**
	* @brief   ������������
	*
	* @param   VoSample
	*          vo:��������
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setSample(VoSample& vo);
	/**
	* @brief  ����ͨ��ƫѹ
	*
	* @param   VoLaser
	*   	   vo:ͨ��ƫѹ
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setChannelBias(VoChannelBias& vo);

	/**
	* @brief   ���ô���ֵ����
	*
	* @param   VoTrigger
	*   	   vo:����ֵ
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setTrigger(VoTrigger& vo);
	/**
	* @brief   �·�����
	*
	* @param   VoCmd    ����
	* @return  bool  true:�ɹ�,false:ʧ��
	* @author  Liuzhaobang
	* @date    2014-4-10
	*/
	bool sendCmd(VoCmd& vo);

	/**
	* @brief   ��ȡ��8λ��ֵ
	*
	* @param   int    value(Ӧ����16λ�޷�������ֵ)
	* @return  char
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	uchar getHighInt(int value);

	/**
	* @brief   ��ȡ��8λ��ֵ
	*
	* @param   int    value(Ӧ����16λ�޷�������ֵ)
	* @return  char
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	uchar getLowInt(int value);

	/**
	* @brief   ��װͨ��ƫѹ����
	*
	* @param   VoChannelBias,char&,char&
	*          vo:ͨ��ƫѹ��,buffer2:Э�������buffer3��Э�����
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void getChannelBias(VoChannelBias& vo, char& buffer2, char& buffer3);
private:
};

#endif // BLLCONTROL_H
