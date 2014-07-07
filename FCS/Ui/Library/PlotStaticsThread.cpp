
#include "PlotStaticsThread.h"
#include <QDebug>
#include "PlotWidget.h"
PlotStaticsThread::PlotStaticsThread(PlotWidget* dataWidget, QObject *parent) :QThread(parent)
{  
	m_dataWidgetParent = dataWidget;
}  

PlotStaticsThread::~PlotStaticsThread()  
{  
  
}

void PlotStaticsThread::run()  
{ 
	qDebug() << "【PlotStaticsThread】启动PlotStaticsThread,线程Id" << QThread::currentThreadId();
	//

	//qint64 step = 0;
	//while (m_goOn)
	//{
	//	
	//	getCellData(false);
	//	emit cellReadySignal();
	//	step++;
	//	//qDebug() << "【PlotStaticsThread】step:" <<step;
	//	msleep(10);
	//}
	qDebug() << "【PlotStaticsThread】运行结束!";
	this->exec();

}
void PlotStaticsThread::setDataWidget(PlotWidget* dataWidget)
{
	m_dataWidgetParent = dataWidget;
}
/**
* @brief 统计细胞数据
*/
void PlotStaticsThread::staticsCellData(bool newData)
{
	if (newData)
	{
		m_dataWidgetParent->clearPlotSamples();
		emit staticsFinished();
		return;
	}
	else
	{
		m_dataWidgetParent->dataMutex.lock();
		m_bllDataCenter.getCellDataVector(m_dataWidgetParent->origialDataList, m_dataWidgetParent->logDataList, m_dataWidgetParent->barStructList);//更新最新的数据给当前plot
		m_dataWidgetParent->dataMutex.unlock();
		emit staticsFinished();
	}

	

}