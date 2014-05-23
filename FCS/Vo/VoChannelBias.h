/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoChannelBias.h
* �ļ�·����  Vo/VoChannelBias.h
* ժ    Ҫ:  ��ͼ��-ͨ��ƫѹ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��11��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoChannelBias_H
#define VoChannelBias_H

#include <QtCore>
#include "VoCmd.h"
class VoChannelBias : public VoCmd
{
	Q_OBJECT

public:
	VoChannelBias(QObject *parent = 0);
	~VoChannelBias();
	VoChannelBias& operator = (const VoChannelBias&);


	friend QDataStream& operator >> (QDataStream&, VoChannelBias&);
	friend QDataStream& operator << (QDataStream&, const VoChannelBias&);
	
	/**
	* @brief   ��ȡͨ��
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel() const
	{
		return m_channel;
	}
	/**
	* @brief   ����ͨ��
	*
	* @param   int
	*          channel��ͨ��
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel(int channel)
	{
		m_channel = channel;
	}
	/**
	* @brief   ��ȡͨ����ѹ
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getVoltage() const
	{
		return m_voltage;
	}
	/**
	* @brief   ����ͨ����ѹ
	*
	* @param   int
	*          voltage��ͨ����ѹ
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setVoltage(int voltage)
	{
		m_voltage = voltage;
	}
	///������̳У����Ա������еĺ���������ĺ������Լ�����Ԫ��������,�����ܱ�����Ķ������ 
protected:

	///ͨ��
	int m_channel;
	///ͨ����ѹ
	int m_voltage;
};

#endif // VOLASER_H
