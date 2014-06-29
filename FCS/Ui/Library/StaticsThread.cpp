
#include "StaticsThread.h"
#include <QDebug>
#include "BarChartWidget.h"
#include "BarStruct.h"
StaticsThread::StaticsThread(BarChartWidget* dataWidget, QObject *parent) :QThread(parent)
{  
	m_dataWidgetParent = dataWidget;
}  

StaticsThread::~StaticsThread()  
{  
  
}

void StaticsThread::run()  
{ 
	qDebug() << "【StaticsThread】启动StaticsThread,线程Id" << QThread::currentThreadId();
	//

	//qint64 step = 0;
	//while (m_goOn)
	//{
	//	
	//	getCellData(false);
	//	emit cellReadySignal();
	//	step++;
	//	//qDebug() << "【StaticsThread】step:" <<step;
	//	msleep(10);
	//}
	qDebug() << "【StaticsThread】运行结束!";
	this->exec();

}
void StaticsThread::setDataWidget(BarChartWidget* dataWidget)
{
	m_dataWidgetParent = dataWidget;
}
/**
* @brief 统计细胞数据
*/
void StaticsThread::staticsCellData()
{
	m_dataWidgetParent->dataMutex.lock();
	m_bllDataCenter.getCellDataVector(m_dataWidgetParent->origialDataList, m_dataWidgetParent->logDataList, m_dataWidgetParent->barStructList);//更新最新的数据给当前plot
	m_dataWidgetParent->dataMutex.unlock();

	emit staticsFinished();
}