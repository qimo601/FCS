/**
* 项    目:  FCS软件
* 文件名称:  BllControl.h
* 文件路径： Control/BllControl.h
* 摘    要:  采集控制业务类
* 作    者： 刘兆邦
* 日    期： 2014年05月13日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef BLLCONTROL_H
#define BLLCONTROL_H

#include <QObject>
#include "Include/Global.h"
#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
#include "USB/USBDriver.h"
class BllControl : public QObject
{
	Q_OBJECT

public:
	BllControl(QObject *parent=0);
	~BllControl();
	/**
	* @brief 关闭USB设备
	*/
	static void closeUSBControl();
public slots:
	/**
	* @brief 初始化USB控制
	*/
	void initUSBControl();
	/**
	* @brief 打开USB设备
	*/
	void openUSBControl();

	/**
	* @brief USB开始监听（持续读数据，非阻塞）
	*/
	void startListening();
	/**
	* @brief  设置激光
	*
	* @param   VoLaser voLaser
	*   		VoLaser:设置激光参数
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-9
	*/
	bool setLaser(VoLaser& vo);
	/**
	* @brief   设置鞘液参数
	*
	* @param   VoFluid
	*
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-10
	*/
	bool setFluid(VoFluid& vo);
	/**
	* @brief 设置样本参数
	*/
	/**
	* @brief   设置样本参数
	*
	* @param   VoSample
	*          vo:样本参数
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setSample(VoSample& vo);
	/**
	* @brief  设置通道偏压
	*
	* @param   VoLaser
	*   	   vo:通道偏压
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setChannelBias(VoChannelBias& vo);

	/**
	* @brief   设置触发值参数
	*
	* @param   VoTrigger
	*   	   vo:触发值
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	bool setTrigger(VoTrigger& vo);
	/**
	* @brief   下发命令
	*
	* @param   VoCmd    命令
	* @return  bool  true:成功,false:失败
	* @author  Liuzhaobang
	* @date    2014-4-10
	*/
	bool sendCmd(VoCmd& vo);

	/**
	* @brief   获取高8位的值
	*
	* @param   int    value(应该是16位无符号整型值)
	* @return  char
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	uchar getHighInt(int value);

	/**
	* @brief   获取低8位的值
	*
	* @param   int    value(应该是16位无符号整型值)
	* @return  char
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	uchar getLowInt(int value);

	/**
	* @brief   封装通道偏压参数
	*
	* @param   VoChannelBias,char&,char&
	*          vo:通道偏压类,buffer2:协议参数，buffer3：协议参数
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-4-11
	*/
	void getChannelBias(VoChannelBias& vo, char& buffer2, char& buffer3);
private:
};

#endif // BLLCONTROL_H
