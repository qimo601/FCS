/**
* 项    目:  FCS软件
* 文件名称:   ReadCellThread.h
* 文件路径：  Bll/DataCenter/ReadCellThread.h
* 摘    要:  细胞数据读取线程-从循环缓冲区里读取
* 作    者： 刘兆邦
* 日    期： 2014年06月17日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef ReadCellThread_H  
#define ReadCellThread_H
#include <QThread> 
#include "Include/Global.h"
#include "Include/ICellStaticData.h"
class ReadCellThread : public QThread  
{  
	Q_OBJECT
public:  
	ReadCellThread(QObject *parent = 0);
    ~ReadCellThread();  
    void run(); 
	void setGoOn(bool on)
	{
		m_goOn = on;
	}
public slots:
	/**
	* @brief 获取细胞数据
	*/
	void getCellData(bool clear);
signals:
	void cellReadySignal();
private:
	double stepValue;
	char m_buffer[512];//一个USB细胞的数据包//细胞数据
	bool m_goOn;//继续标志
	//细胞数据接口
	ICellStaticData* iCellStaticData;
}; 

#endif