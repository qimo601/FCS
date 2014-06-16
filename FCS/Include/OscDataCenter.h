/**
* 项    目:  FCS软件
* 文件名称:   OscDataCenter.h
* 文件路径：  Include/OscDataCenter.h
* 摘    要:  示波器全局数据接口
* 作    者： 刘兆邦
* 日    期： 2014年06月01日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef OSCDATACENTER_H
#define OSCDATACENTER_H

#include <QObject>
#include <QMutex>
class OscDataCenter : public QObject
{
	Q_OBJECT

public:
	OscDataCenter(QObject *parent=0);
	~OscDataCenter();

	//示波器X轴显示数据
	static QVector<double> oscXData;
	//示波器Y轴显示数据
	static QList<QVector<double>> oscYData;


	static QMutex mutex;
	static void setLock();
	static void setUnlock();



private:
	
	
};

#endif // OSCDATACENTER_H
