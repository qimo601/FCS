
#include "ReadOscThread.h"
#include <QDebug>
#include "Include/OscDataCenter.h"
ReadOscThread::ReadOscThread(QObject *parent) :QThread(parent)
{  
	stepValue = 0;
	m_goOn = true;//默认就自动进入循环
}  

ReadOscThread::~ReadOscThread()  
{  
  
}

void ReadOscThread::run()  
{ 
	qDebug() << "【USB监听线程】启动ReadOscThread,线程Id" << QThread::currentThreadId();
	

	////只要不是停止
	//while (ctrlTag != CTRL_TAG::STOP_TAG)
	//{

	//}
	qint64 step = 0;
	while (m_goOn)
	{
		
		getOscData();
		emit oscReadySignal();
		step++;
		qDebug() << "【ReadOscThread】step:" <<step;
		msleep(10);
	}
	qDebug() << "【ReadOscThread】运行结束!";
	this->exec();

}

/**
* @brief 获取示波器显示数据
*/
void ReadOscThread::getOscData()
{
	quint8 valueA;
	quint8 valueB;
	int value;
	stepValue = 1;

	//添加至环形缓冲区:示波器一个数据包大小512Byte
	if (Global::S_CCycleBuffer->getUsedSize() >= 1024 * 16)
	{
		OscDataCenter::setLock();
		OscDataCenter::oscXData.clear();
		for (int i = 0; i < OscDataCenter::oscYData.count(); i++)
			OscDataCenter::oscYData[i].clear();

		char * buffer = m_bufferOSC;
		memset(buffer, 0, 1024 * 16);//清空数组
		Global::S_CCycleBuffer->read(m_bufferOSC, 1024 * 16);
		//一次1024组
		for (int i = 0; i < 1024; i++)
		{
			stepValue = i;
			OscDataCenter::oscXData.append(stepValue);
			for (int j = 0; j < 8; j++)
			{
				memcpy((char *)&valueA, buffer++, 1);
				memcpy((char *)&valueB, buffer++, 1);
				//Global::S_CCycleBuffer->read((char *)&valueA, 1);
				//Global::S_CCycleBuffer->read((char *)&valueB, 1);
				value = (valueB * 256 + valueA);//高低位

				OscDataCenter::oscYData[j].append(value);
			}


		}

		OscDataCenter::setUnlock();
	}
	else//如果没有这个等待，就会有很多空循环，CPU会很高。
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}