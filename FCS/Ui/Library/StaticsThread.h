/**
* 项    目:  FCS软件
* 文件名称:   StaticsThread.h
* 文件路径：  Bll/DataCenter/StaticsThread.h
* 摘    要:  细胞数据统计线程-从循环缓冲区里读取进行统计
* 作    者： 刘兆邦
* 日    期： 2014年06月17日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef StaticsThread_H  
#define StaticsThread_H
#include <QThread> 
#include "Include/Global.h"
#include "Bll/DataCenter/BllDataCenter.h"
class BarChartWidget;
class BarStruct;
class StaticsThread : public QThread  
{  
	Q_OBJECT
public:  
	StaticsThread(BarChartWidget* dataWidget = 0, QObject *parent = 0);
    ~StaticsThread();  
	void setDataWidget(BarChartWidget* dataWidget);
    void run();
public slots:
	void staticsCellData();//统计细胞数据

signals:
	void staticsFinished();//数据统计完成信号
private:
	//细胞数据业务类
	BllDataCenter m_bllDataCenter;
	//数据来源窗口
	BarChartWidget* m_dataWidgetParent;
}; 

#endif