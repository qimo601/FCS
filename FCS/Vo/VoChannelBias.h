/**
* 项    目:  FCS软件
* 文件名称:   VoChannelBias.h
* 文件路径：  Vo/VoChannelBias.h
* 摘    要:  视图类-通道偏压参数
* 作    者： 刘兆邦
* 日    期： 2014年04月11日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	* @brief   获取通道
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getChannel() const
	{
		return m_channel;
	}
	/**
	* @brief   设置通道
	*
	* @param   int
	*          channel：通道
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setChannel(int channel)
	{
		m_channel = channel;
	}
	/**
	* @brief   获取通道电压
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getVoltage() const
	{
		return m_voltage;
	}
	/**
	* @brief   设置通道电压
	*
	* @param   int
	*          voltage：通道电压
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setVoltage(int voltage)
	{
		m_voltage = voltage;
	}
	///被子类继承，可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问 
protected:

	///通道
	int m_channel;
	///通道电压
	int m_voltage;
};

#endif // VOLASER_H
