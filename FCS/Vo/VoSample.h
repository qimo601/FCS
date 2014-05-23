/**
* 项    目:  FCS软件
* 文件名称:   VoSample.h
* 文件路径：  Vo/VoSample.h
* 摘    要:  视图类-设置样品参数
* 作    者： 刘兆邦
* 日    期： 2014年04月09日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	* @brief   获取流速
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	int getVelocity() const
	{
		return m_velocity;
	}
	/**
	* @brief   设置流速
	*
	* @param   int
	*          velocity：流速
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void setVelocity(int velocity)
	{
		m_velocity = velocity;
	}
	///被子类继承，可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问 
protected:

	///流速参数
	int m_velocity;
};

#endif // VOLASER_H
