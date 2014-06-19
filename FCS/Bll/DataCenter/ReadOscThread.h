/**
* 项    目:  FCS软件
* 文件名称:   ReadOscThread.h
* 文件路径：  Bll/DataCenter/ReadOscThread.h
* 摘    要:  示波器读取线程-从循环缓冲区里读取
* 作    者： 刘兆邦
* 日    期： 2014年06月15日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef ReadOscThread_H  
#define ReadOscThread_H
#include <QThread> 
#include "Include/Global.h"
class ReadOscThread : public QThread  
{  
	Q_OBJECT
public:  
	ReadOscThread(QObject *parent = 0);
    ~ReadOscThread();  
    void run(); 
	void setGoOn(bool on)
	{
		m_goOn = on;
	}
public slots:
	/**
	* @brief 获取示波器显示数据
	*/
	void getOscData();
signals:
	void oscReadySignal();
private:
	double stepValue;
	char m_bufferOSC[1024 * 16];//一个示波器要显示的数据
	bool m_goOn;//继续标志
}; 

#endif