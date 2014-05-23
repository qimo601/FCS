/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoSample.h
* �ļ�·����  Vo/VoSample.h
* ժ    Ҫ:  ��ͼ��-������Ʒ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��09��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoSample_H
#define VoSample_H

#include <QtCore>
#include "VoCmd.h"
class VoSample : public VoCmd
{
	Q_OBJECT

public:
	VoSample(QObject *parent = 0);
	~VoSample();
	VoSample& operator = (const VoSample&);


	friend QDataStream& operator >> (QDataStream&, VoSample&);
	friend QDataStream& operator << (QDataStream&, const VoSample&);
	
	/**
	* @brief   ��ȡ����
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getVelocity() const
	{
		return m_velocity;
	}
	/**
	* @brief   ��������
	*
	* @param   int
	*          velocity������
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setVelocity(int velocity)
	{
		m_velocity = velocity;
	}
	///������̳У����Ա������еĺ���������ĺ������Լ�����Ԫ��������,�����ܱ�����Ķ������ 
protected:

	///���ٲ���
	int m_velocity;
};

#endif // VOLASER_H
