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
	*/
	QVector<double>* getCellDataVector(int passage, int valuePos);

private:
	double stepValue;
	//细胞数据接口
	ICellStaticData* iCellStaticData;
};

#endif // BLLDATACENTER_H
