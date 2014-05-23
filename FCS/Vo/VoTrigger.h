/**
* 项    目:  FCS软件
* 文件名称:   VoTrigger.h
* 文件路径：  Vo/VoTrigger.h
* 摘    要:  视图类-设置触发参数
* 作    者： 刘兆邦
* 日    期： 2014年04月09日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	* @brief   获取通道1-暂不支持
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel1() const
	{
		return m_channel1;
	}
	/**
	* @brief   设置通道1-暂不支持
	*
	* @param   int：通道1
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel1(int channel1)
	{
		m_channel1 = channel1;
	}
	/**
	* @brief   获取通道2
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel2() const
	{
		return m_channel2;
	}
	/**
	* @brief   设置通道2
	*
	* @param   int：通道2
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel2(int channel2)
	{
		m_channel2 = channel2;
	}
	/**
	* @brief   获取触发值
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getTriggerValue() const
	{
		return m_triggerValue;
	}
	/**
	* @brief   设置触发值
	*
	* @param   int：触发值
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setTriggerValue(int triggerValue)
	{
		m_triggerValue = triggerValue;
	}

	///被子类继承，可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问 
protected:
	///通道1-暂不支持
	int m_channel1;
	///通道1-暂时这个有效
	int m_channel2;
	///触发值
	int m_triggerValue;
};

#endif // VOLASER_H
