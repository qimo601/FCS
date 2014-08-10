/**
* 项    目:  FCS软件
* 文件名称:   ICellStaticData.h
* 文件路径：  Include/ICellStaticData.h
* 摘    要:  细胞全局数据接口
* 作    者： 刘兆邦
* 日    期： 2014年06月01日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef ICELLSTATICDATA_H
#define ICELLSTATICDATA_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <QtCore/qmath.h>
class BarStruct;
class ICellStaticData : public QObject
{
	Q_OBJECT

private:
	
	ICellStaticData(QObject *parent = 0);
	~ICellStaticData();
	//
	static  ICellStaticData* m_instance;


	//当前实验细胞全局数据
	QList < QList < QVector<double>* > * >* cellFullData;

	//数据锁
	QMutex mutex;
public:
	/**
	* @brief 返回细胞数据全局单例指针
	*/
	static ICellStaticData* getInstance();

	void init();
	/**
	* @brief 插入某通道某值
	*/
	void insert(int passage, double valueHH, double valueAA, double valueWW);
	/**
	* @brief 清空某个通道值
	*/
	void clear(int passage);
	/**
	* @brief 获取某个通道某列值
	*/
	QVector<double>* getDataVector(int passage, int valuePos);
	/**
	* @brief 获取细胞所有数据
	*/
	void getDataVector(QList < QList < QVector<double>* > * >*  origialDataList, QList < QList < QVector<double>* >*  >* logDataList);
	/**
	* @brief 直方图读取数据方法
	*/
	void getDataVector(QList < QList < QVector<double>* > * >*  origialDataList, QList < QList < QVector<double>* >*  >* logDataList, QList < QList < QVector<BarStruct>* >*  >* barStructList);
	/**
	* @brief 获取细胞数目
	*/
	double getAllEvents();
};

#endif // ICELLSTATICDATA_H
