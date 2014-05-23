/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoTrigger.h
* �ļ�·����  Vo/VoTrigger.h
* ժ    Ҫ:  ��ͼ��-���ô�������
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��09��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoTrigger_H
#define VoTrigger_H

#include <QtCore>

#include "VoCmd.h"
class VoTrigger : public VoCmd
{
	Q_OBJECT

public:
	VoTrigger(QObject *parent = 0);
	~VoTrigger();
	VoTrigger& operator = (const VoTrigger&);


	friend QDataStream& operator >> (QDataStream&, VoTrigger&);
	friend QDataStream& operator << (QDataStream&, const VoTrigger&);
	
	/**
	* @brief   ��ȡͨ��1-�ݲ�֧��
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel1() const
	{
		return m_channel1;
	}
	/**
	* @brief   ����ͨ��1-�ݲ�֧��
	*
	* @param   int��ͨ��1
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel1(int channel1)
	{
		m_channel1 = channel1;
	}
	/**
	* @brief   ��ȡͨ��2
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel2() const
	{
		return m_channel2;
	}
	/**
	* @brief   ����ͨ��2
	*
	* @param   int��ͨ��2
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel2(int channel2)
	{
		m_channel2 = channel2;
	}
	/**
	* @brief   ��ȡ����ֵ
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getTriggerValue() const
	{
		return m_triggerValue;
	}
	/**
	* @brief   ���ô���ֵ
	*
	* @param   int������ֵ
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setTriggerValue(int triggerValue)
	{
		m_triggerValue = triggerValue;
	}

	///������̳У����Ա������еĺ���������ĺ������Լ�����Ԫ��������,�����ܱ�����Ķ������ 
protected:
	///ͨ��1-�ݲ�֧��
	int m_channel1;
	///ͨ��1-��ʱ�����Ч
	int m_channel2;
	///����ֵ
	int m_triggerValue;
};

#endif // VOLASER_H
