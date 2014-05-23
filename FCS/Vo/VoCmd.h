/**
* ��    Ŀ:  FCS���
* �ļ�����:   VoCmd.h
* �ļ�·����  Vo/VoCmd.h
* ժ    Ҫ:  ��ͼ��-����޲������ͣ�
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��09��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/

#ifndef VoCmd_H
#define VoCmd_H

#include <QObject>
#include <QtCore>
class VoCmd : public QObject
{
	Q_OBJECT

public:
	VoCmd(QObject *parent = 0);
	~VoCmd();
	VoCmd& operator = (const VoCmd&);


	friend QDataStream& operator >> (QDataStream&, VoCmd&);
	friend QDataStream& operator << (QDataStream&, const VoCmd&);
	/** 
	 * @brief   ��ȡ����
	 *
	 * @return  int  ��������ֵ
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getCmd() const
	{
		return m_cmd;
	}
	/***
	/** 
	 * @brief   ��������
	 *
	 * @param   int
				cmd������
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setCmd(int cmd)
	{
		m_cmd = cmd;
	}

	/**
	 * @brief   ��ȡ��������
	 *
	 * @return  int  ���ز�������
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getLength() const
	{
		return m_length;
	}
	/**
	* @brief   ���ò�������
	*
	* @param   int
	length����������
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	void setLength(int length)
	{
		m_length = length;
	}
	///������̳У����Ա������еĺ���������ĺ������Լ�����Ԫ��������,�����ܱ�����Ķ������ 
protected:
	///����
	int m_cmd;
	///��������
	int m_length;
};

#endif // VoCmd_H
