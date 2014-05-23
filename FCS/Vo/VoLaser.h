/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoLaser.h
* �ļ�·����  Vo/VoLaser.h
* ժ    Ҫ:  ��ͼ�����ü������
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��09��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoLaser_H
#define VoLaser_H

#include <QtCore>
#include "VoCmd.h"
class VoLaser : public VoCmd
{
	Q_OBJECT

public:
	VoLaser(QObject *parent = 0);
	~VoLaser();
	VoLaser& operator = (const VoLaser&);


	friend QDataStream& operator >> (QDataStream&, VoLaser&);
	friend QDataStream& operator << (QDataStream&, const VoLaser&);
	
	/** 
	 * @brief   ��ȡ����ͨ��
	 * @return  int 
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getPassage() const
	{
		return m_passage;
	}
	/**
	 * @brief   ���ü���ͨ��
	 *
	 * @param   int
	 *          passage������ͨ��
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setPassage(int passage)
	{
		m_passage = passage;
	}
	/**
	* @brief   ��ȡ����ǿ��
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	int getStrength() const
	{
		return m_strength;
	}
	/**
	 * @brief   ���ü���ǿ��
	 *
	 * @param   int
	 *          passage������ͨ��
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setStrength(int strength)
	{
		m_strength = strength;
	}
	///������̳У����Ա������еĺ���������ĺ������Լ�����Ԫ��������,�����ܱ�����Ķ������ 
protected:

	///ͨ������
	int m_passage;
	///ǿ�Ȳ���
	int m_strength;
};

#endif // VOLASER_H
