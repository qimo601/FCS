/**
* 项    目:  FCS软件
* 文件名称:  BllDataCenter.h
* 文件路径： DataCenter/BllDataCenter.h
* 摘    要:  数据中心业务类
* 作    者： 刘兆邦
* 日    期： 2014年05月08日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef BLLDATACENTER_H
#define BLLDATACENTER_H

#include <QObject>
#include "Include/Global.h"
#include "Include/ICellStaticData.h"
#include "Bll/DataCenter/ReadCellThread.h"
class BllDataCenter : public QObject
{
	Q_OBJECT

public:
	BllDataCenter(QObject *parent = 0);
	~BllDataCenter();

	/**
	* @brief 获取示波器显示数据
	*/
	void getOscData(QVector<double>& oscXData,QVector<double>& oscYData);
	/**
	* @brief 获取细胞显示数据
	* @param bool 是否清空旧的数据
	*/
	void getCellData(bool clear = true);
	/**
	* @brief 获取细胞显示数据
	* @param passage 通道
	* @param valuePos 值位置
	*/
	QVector<double>* getCellDataVector(int passage, int valuePos);
	/**
	* @brief 获取细胞显示数据接口
	*/
	void getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList);
	/**
	* @brief 直方图获取数据方法
	*/
	void getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList, QList < QList < QVector<BarStruct>* >*  >* barStructList);
	/**
	* @brief 获取源数据细胞总数
	*/
	double getAllEvents();
	/**
	* @brief 清空源数据细胞总数
	*/
	void clearAllEvents();
	/**
	* @brief 设置屏幕刷新频率 freq * 8
	*/
	void setFreq(int freq);
	/**
	* @brief 设置屏幕清空频率 clear * 8
	*/
	void setClear(int clear);
private:
	double stepValue;
	//细胞数据接口
	ICellStaticData* iCellStaticData;

	char m_buffer[512];//一个USB细胞的数据包
	char m_bufferOSC[1024 * 16];//一个示波器要显示的数据

};

#endif // BLLDATACENTER_H
