/**
* 项    目:  FCS软件
* 文件名称:   USBThread.h
* 文件路径：  USB/USBThread.h
* 摘    要:  USB监听线程
* 作    者： 刘兆邦
* 日    期： 2014年04月11日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef USBThread_H  
#define USBThread_H
#include <QThread> 
#include <QWaitCondition>
#include <QMutex>
#include <QList>
#include <QSemaphore>
#include <qt_windows.h>
#include "ezusbsys.h"
#include <QMutex>
#include "Include/Global.h"
class USBThread : public QThread  
{  
public:  
	USBThread();
    ~USBThread();  
	enum CTRL_TAG {
		///开始采集
		START_TAG = 0x0001,
		///停止采集
		STOP_TAG = 0x0002,
		//暂停采集
		SUSPEND_TAG = 0x0003,
		//继续采集
		GOON_TAG = 0x0004
	};
	static bool saveTag;
	static QString fileName;
	static FILE *projectFile;
    void run();  
	/**
	* @brief 保存文件
	*/
	void saveToFile(PUCHAR buffer, DWORD DataLength);
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
	* @date    2014-05-10
	*/
	BOOL onSetInDir(void);
	/**
	* @brief   界面读事件
	* @author  Liuzhaobang
	* @date    2014-05-10
	*/
	void onButtonRd();
	/**
	* @brief   界面读事件
	* @author  Liuzhaobang
	* @date    2014-05-10
	*/
	void onButtonRd1();
	/** 
	* @brief   设置控制标签状态
	*
	* @param   CTRL_TAG tag 标签状态
	* @return  void
	* @author  Liuzhaobang
	* @date    2014-5-10
	*/
	void setCtrlTag(CTRL_TAG tag);
	/**
	* @brief 设置USB句柄
	*/
	void setHdevice(HANDLE device);
	

private:
	//控制标志位
	CTRL_TAG ctrlTag;
	//USB设备句柄
	HANDLE m_hDevice;
	QMutex ctrlTagMutex;
	//测试用，模拟采集数据
	int stepValue;
}; 

#endif