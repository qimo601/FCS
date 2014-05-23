/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoFluid.h
* �ļ�·����  Vo/VoFluid.h
* ժ    Ҫ:  ��ͼ��-������Һ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��10��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoFluid_H
#define VoFluid_H

#include <QtCore>
#include "VoCmd.h"
class VoFluid : public VoCmd
{
	Q_OBJECT

public:
	VoFluid(QObject *parent = 0);
	~VoFluid();
	VoFluid& operator = (const VoFluid&);


	friend QDataStream& operator >> (QDataStream&, VoFluid&);
	friend QDataStream& operator << (QDataStream&, const VoFluid&);
		
	/**
	* @brief   ��ȡ����
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	int getVelocity() const
	{
		return m_velocity;
	}
	/**
	 * @brief   ��������
	 *
	 * @param   int
	 *          velocity����Ʒ����
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
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
