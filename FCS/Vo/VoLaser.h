/**
* 项    目:  FCS软件
* 文件名称:   VoLaser.h
* 文件路径：  Vo/VoLaser.h
* 摘    要:  视图类设置激光参数
* 作    者： 刘兆邦
* 日    期： 2014年04月09日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	 * @brief   获取激光通道
	 * @return  int 
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getPassage() const
	{
		return m_passage;
	}
	/**
	 * @brief   设置激光通道
	 *
	 * @param   int
	 *          passage：激光通道
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setPassage(int passage)
	{
		m_passage = passage;
	}
	/**
	* @brief   获取激光强度
	* @return  int
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	int getStrength() const
	{
		return m_strength;
	}
	/**
	 * @brief   设置激光强度
	 *
	 * @param   int
	 *          passage：激光通道
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setStrength(int strength)
	{
		m_strength = strength;
	}
	///被子类继承，可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问 
protected:

	///通道参数
	int m_passage;
	///强度参数
	int m_strength;
};

#endif // VOLASER_H
