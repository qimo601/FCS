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
* @brief ��ȡʾ������ʾ����
*/
void BllDataCenter::getOscData(QVector<double>& oscXData, QVector<double>& oscYData)
{
	quint8 valueA;
	quint8 valueB;
	int value;
	stepValue = 1;

	//��������λ�����:ʾ����һ�����ݰ���С512Byte
	if (Global::S_CCycleBuffer->getUsedSize() >= 1024*16)
	{
		Global::oscXData.clear();
		for (int i = 0; i < Global::oscYData.count(); i++)
			Global::oscYData[i].clear();
		//һ��32��
		for (int i = 0; i < 1024; i++)
		{
			stepValue = i;
			Global::oscXData.append(stepValue);
			for (int j = 0; j < 8; j++)
			{
			Global::S_CCycleBuffer->read((char *)&valueA, 1);
			Global::S_CCycleBuffer->read((char *)&valueB, 1);
			value = (valueB * 256 + valueA);//�ߵ�λ
			
			Global::oscYData[j].append(value);
			}


		}


	}
	else//���û������ȴ����ͻ��кܶ��ѭ����CPU��ܸߡ�
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}