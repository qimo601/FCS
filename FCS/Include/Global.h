// 源代码编码必须是: UTF-8(BOM)  
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef Global_H
#define Global_H

#ifndef Simulation_Test 
//若Simulation_Test=1，表示模拟测试，Simulation_Test=0表示正是通过USB采集
#define Simulation_Test 1
#endif


#include <QObject>
#include <QTranslator>
#include "Bll/DataCenter/CCycleBuffer.h"
#include <qt_windows.h>
class Global : public QObject
{    
	Q_OBJECT
public:
    Global(QObject *parent = 0);
    ~Global();
	///环形缓冲区
	static CCycleBuffer* S_CCycleBuffer;

	//示波器X轴显示数据
	static QVector<double> oscXData;
	//示波器Y轴显示数据
	static QList<QVector<double>> oscYData;

	

	///全局初始化
	void init();
	///初始化qss
	void initQss();
	///初始化语言
	void initLanguage();
	/** 
	* @brief   初始化环形缓冲区
	*
	* @param   int size : 缓冲区大小 Byte
	* @return  bool
	* @author  Liuzhaobang
	* @date    2014-5-10
	*/
	bool initCCycleBuffer(int size);
public slots:

private:	
	QTranslator translator;

};

#endif // Global_H