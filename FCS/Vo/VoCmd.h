/**
* 项    目:  FCS软件
* 文件名称:   VoCmd.h
* 文件路径：  Vo/VoCmd.h
* 摘    要:  视图类-命令（无参数类型）
* 作    者： 刘兆邦
* 日    期： 2014年04月09日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	 * @brief   获取命令
	 *
	 * @return  int  返回命令值
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getCmd() const
	{
		return m_cmd;
	}
	/***
	/** 
	 * @brief   设置命令
	 *
	 * @param   int
				cmd：命令
	 * @return  void
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	void setCmd(int cmd)
	{
		m_cmd = cmd;
	}

	/**
	 * @brief   获取参数长度
	 *
	 * @return  int  返回参数长度
	 * @author  Liuzhaobang
	 * @date    2014-4-9
	 */
	int getLength() const
	{
		return m_length;
	}
	/**
	* @brief   设置参数长度
	*
	* @param   int
	length：参数长度
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	void setLength(int length)
	{
		m_length = length;
	}
	///被子类继承，可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问 
protected:
	///命令
	int m_cmd;
	///参数长度
	int m_length;
};

#endif // VoCmd_H
