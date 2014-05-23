#include "BllDataCenter.h"

BllDataCenter::BllDataCenter(QObject *parent)
	: QObject(parent)
{
	stepValue = 0;
}

BllDataCenter::~BllDataCenter()
{

}
/**
* @brief 获取示波器显示数据
*/
void BllDataCenter::getOscData(QVector<double>& oscXData, QVector<double>& oscYData)
{
	quint8 valueA;
	quint8 valueB;
	int value;
	stepValue = 1;

	//添加至环形缓冲区:示波器一个数据包大小512Byte
	if (Global::S_CCycleBuffer->getUsedSize() >= 1024*16)
	{
		Global::oscXData.clear();
		for (int i = 0; i < Global::oscYData.count(); i++)
			Global::oscYData[i].clear();
		//一次32组
		for (int i = 0; i < 1024; i++)
		{
			stepValue = i;
			Global::oscXData.append(stepValue);
			for (int j = 0; j < 8; j++)
			{
			Global::S_CCycleBuffer->read((char *)&valueA, 1);
			Global::S_CCycleBuffer->read((char *)&valueB, 1);
			value = (valueB * 256 + valueA);//高低位
			
			Global::oscYData[j].append(value);
			}


		}


	}
	else//如果没有这个等待，就会有很多空循环，CPU会很高。
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}