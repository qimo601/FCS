/**
* 项    目:  FCS软件 
* 文件名称:  USBControl.h
* 文件路径： USB/USBControl.h
* 摘    要:  USB控制类
* 作    者： 刘兆邦
* 日    期： 2014年03月31日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef USBCONTROL_H
#define USBCONTROL_H

#include <QObject>
#include <QDebug>
#include <qt_windows.h>
#include "ezusbsys.h"
//#include <atlstr.h>
#include "USB/USBThread.h"
class USBControl : public QObject
{
	Q_OBJECT

public:
	USBControl(QObject *parent = 0);
	~USBControl();
	
	
  /** 
	* @brief   写函数
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-04-01
	*/
	BOOL write(PUCHAR buffer, DWORD DataLength);
  /**
	* @brief   设置端点，输出操作
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-04-01
	*/
	BOOL onSetOutDir();

  /**
	* @brief   读函数
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-04-01
	*/
	BOOL read(PUCHAR buffer, DWORD PreDataLength, PDWORD PDataLength);
  /**
	* @brief   设置端口，接收操作
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-04-01
	*/
	BOOL onSetInDir(void);
  /** 
	* @brief   打开设备
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-03-31
	*/
	BOOL openDevice();

  /** 
	* @brief   关闭设备
	* @return  Bool   True:成功，False:失败
	* @author  Liuzhaobang
	* @date    2014-03-31
	*/
	BOOL closeDevice();

	public slots:
	/**
	* @brief 监听USB接收端口
	* @author  Liuzhaobang
	* @date    2014-05-10
	*/
	void listen();
	/**
	* @brief 设置监听状态
	*/
	void setListen(USBThread::CTRL_TAG tag);
	/**
	* @brief   一次读事件
	* @author  Liuzhaobang
	* @date    2014-04-01
	*/
	void onButtonRd();

	/**
	* @brief   一次写事件
	* @author  Liuzhaobang
	* @date    2014-03-31
	*/
	void onButtonWr();
	/**
	* @brief 重置USB设备
	*/
	bool resetDevice();
private:
	//USB设备句柄
	HANDLE  m_hDevice;
	//设备名
	QString m_strName;
	//USB监听线程
	USBThread* usbThread;
};

#endif // USBCONTROL_H
