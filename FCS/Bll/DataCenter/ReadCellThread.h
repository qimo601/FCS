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
#include <QMutex>
#include "Include/Global.h"
#include "Include/ICellStaticData.h"
class ReadCellThread : public QThread  
{  
	Q_OBJECT
public:  
	ReadCellThread(QObject *parent = 0);
    ~ReadCellThread();  
    void run(); 
	//设置循环读取标签
	void setGoOn(bool on);

	//操作枚举值
	enum Operate {
		CLEAR = 0x0001,//清空全局缓存
		START_ACQ = 0x0002,//采集缓冲区数据
		Read_USB_FILE = 0x0003,//读取USB协议格式本地文件
		Read_MatLab_FILE = 0x0004,//读取MatLab格式本地文件
		Read_FCS_FILE = 0x0005,//读取FCS格式本地文件
		NORMAL = 0x0006//正常状态
	};


	static bool saveTag;//保存文件标示符
	static QString fileName;//细胞文件
	static FILE *projectFile;//文件指针
public slots:
	/**
	* @brief 开始循环读取环形缓冲区中细胞数据
	*/
	void startReadCellDataFromCircleBuffer();
	/**
	* @brief 获取细胞数据
	*/
	void getCellData(bool clear);
	/**
	* @brief 通过文件读取本地细胞数据
	* @param filepath:文件地址
	* @param clear:每次读一个文件，默认清空缓存
	*/
	void getCellDataFromFile(QString filePath, bool clear=true);
	/**
	* @brief 通过文件读取matlab版本本地细胞数据
	*/
	void getCellDataFromMatlabFile(QString filePath, bool clear);
	/**
	* @brief 通过文件读取FCS格式本地细胞数据
	*/
	void getCellDataFromFCSFile(QString filePath, bool clear);
	/**
	* @brief 清楚全局细胞缓冲区旧数据，
	*        每次切换采集和读取本地文件必须调用
	*/
	void clearCellStaticData();

	/**
	* @brief 设置该线程操作
	*/
	void setOperate(Operate operate);
	/**
	* @brief 设置读取文件路径
	*/
	void setFilePath(QString filePath);
	/**
	* @brief 保存细胞文件
	*/
	void saveToFile(char* buffer, qint32 DataLength);
signals:
	//信号 new = false,表示正常采集。true，表示新数据源数据，需要对方清空
	void cellReadySignal(bool newData = false);
private:
	double stepValue;
	char m_buffer[512];//一个USB细胞的数据包//细胞数据
	bool m_goOn;//继续标志
	QMutex mutex;//互斥锁
	

	QString m_filePath;//文件路径
	Operate m_opertaeEnum;//操作枚举值
	//细胞数据接口
	ICellStaticData* iCellStaticData;
}; 

#endif