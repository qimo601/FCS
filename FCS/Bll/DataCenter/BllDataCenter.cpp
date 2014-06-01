#include "BllDataCenter.h"

BllDataCenter::BllDataCenter(QObject *parent)
	: QObject(parent)
{
	stepValue = 0;
	iCellStaticData =  ICellStaticData::getInstance();//初始化细胞数据接口
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
/**
* @brief 获取细胞显示数据
*/
void BllDataCenter::getCellData(bool clear)
{
	quint8 valueHH;
	quint8 valueHH1;
	quint8 valueHH2;
	quint8 valueHH3;
	quint8 valueAA;
	quint8 valueAA1;
	quint8 valueAA2;
	quint8 valueAA3;
	quint8 valueWW;
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

		//一次8个细胞
		for (int i = 0; i < 8; i++)
		{
			//8个通道
			for (int j = 0; j < 8; j++)
			{
				//一个通道8个字节
				Global::S_CCycleBuffer->read((char *)&valueHH1, 1);
				Global::S_CCycleBuffer->read((char *)&valueHH2, 1);
				Global::S_CCycleBuffer->read((char *)&valueHH3, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA1, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA2, 1);
				Global::S_CCycleBuffer->read((char *)&valueAA3, 1);
				Global::S_CCycleBuffer->read((char *)&valueWW1, 1);
				Global::S_CCycleBuffer->read((char *)&valueWW2, 1);
				valueHH = (valueHH1 * 65536 + valueHH2 * 256 + valueHH3);
				valueAA = (valueAA1 * 65536 + valueAA2 * 256 + valueAA3);
				valueWW = (valueWW1 * 256 + valueWW2);

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

/**
* @brief 获取细胞显示数据数组
*/
QVector<double>* BllDataCenter::getCellDataVector(int passage, int valuePos)
{
	return iCellStaticData->getDataVector(passage, valuePos);
}