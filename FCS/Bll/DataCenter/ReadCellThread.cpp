
#include "ReadCellThread.h"
#include <QDebug>
#include "Include/OscDataCenter.h"
ReadCellThread::ReadCellThread(QObject *parent) :QThread(parent)
{  
	stepValue = 0;
	m_goOn = true;//默认就自动进入循环
	iCellStaticData = ICellStaticData::getInstance();//初始化细胞数据接口
}  

ReadCellThread::~ReadCellThread()  
{  
  
}

void ReadCellThread::run()  
{ 
	qDebug() << "【USB监听线程】启动ReadCellThread,线程Id" << QThread::currentThreadId();
	

	////只要不是停止
	//while (ctrlTag != CTRL_TAG::STOP_TAG)
	//{

	//}
	qint64 step = 0;
	while (m_goOn)
	{
		
		getCellData(false);
		emit cellReadySignal();
		step++;
		//qDebug() << "【ReadCellThread】step:" <<step;
		msleep(10);
	}
	qDebug() << "【ReadCellThread】运行结束!";
	this->exec();

}

/**
* @brief 获取细胞显示数据
*/
void ReadCellThread::getCellData(bool clear)
{
	double valueHH;
	quint8 valueHH1;
	quint8 valueHH2;
	quint8 valueHH3;
	double valueAA;
	quint8 valueAA1;
	quint8 valueAA2;
	quint8 valueAA3;
	double valueWW;
	quint8 valueWW1;
	quint8 valueWW2;
	int value;
	stepValue = 1;

	//添加至环形缓冲区:示波器一个数据包大小512Byte
	if (Global::S_CCycleBuffer->getUsedSize() >= 512)
	{
		//如果需要清空
		if (clear)
		{
			//清空每个通道
			for (int i = 0; i < 8; i++)
				iCellStaticData->clear(i);
		}
		char * buffer = m_buffer;//指向临时数组
		memset(buffer, 0, 512);//清空数组
		Global::S_CCycleBuffer->read(m_buffer, 512);//一次读8个细胞的数据
		//qDebug() <<"【ReadCellThread】getCellData，读完后，循环缓冲区有效数据：" << Global::S_CCycleBuffer->getUsedSize()<<"B.";
		//一次8个细胞
		for (int i = 0; i < 8; i++)
		{
			//8个通道
			for (int j = 0; j < 8; j++)
			{
				//一个通道8个字节
				/*Global::S_CCycleBuffer->read((char *)&valueHH1, 1);
				Global::S_CCycleBuffer->read((char *)&valueHH2, 1);
				Global::S_CCycleBuffer->read((char *)&valueHH3, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA1, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA2, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA3, 1);
				Global::S_CCycleBuffer->read((char *)&valueWW1, 1);
				Global::S_CCycleBuffer->read((char *)&valueWW2, 1);*/

				memcpy((char *)&valueHH1, buffer++, 1);
				memcpy((char *)&valueHH2, buffer++, 1);
				memcpy((char *)&valueHH3, buffer++, 1);
				memcpy((char *)&valueAA1, buffer++, 1);
				memcpy((char *)&valueAA2, buffer++, 1);
				memcpy((char *)&valueAA3, buffer++, 1);
				memcpy((char *)&valueWW1, buffer++, 1);
				memcpy((char *)&valueWW2, buffer++, 1);

				//解析细胞数据结构
				valueHH = (valueHH1 * 65536 + valueHH2 * 256 + valueHH3);//细胞高度
				valueAA = (valueAA1 * 65536 + valueAA2 * 256 + valueAA3);//细胞面积
				valueWW = (valueWW1 * 256 + valueWW2);//细胞宽度


				iCellStaticData->insert(j, valueHH, valueAA, valueWW);
			}
		}


	}
	else//如果没有这个等待，就会有很多空循环，CPU会很高。
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}
