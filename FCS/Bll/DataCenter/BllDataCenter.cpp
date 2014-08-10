#include "BllDataCenter.h"
#include "Include/OscDataCenter.h"
#include "Ui/Library/BarStruct.h"
BllDataCenter::BllDataCenter(QObject *parent)
	: QObject(parent)
{
	stepValue = 0;
	iCellStaticData =  ICellStaticData::getInstance();//��ʼ��ϸ�����ݽӿ�
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

		char * buffer = m_bufferOSC;
		memset(buffer, 0, 1024*16);//�������
		Global::S_CCycleBuffer->read(m_bufferOSC, 1024*16);
		//һ��1024��
		for (int i = 0; i < 1024; i++)
		{
			stepValue = i;
			Global::oscXData.append(stepValue);
			for (int j = 0; j < 8; j++)
			{
			memcpy((char *)&valueA, buffer++,1);
			memcpy((char *)&valueB, buffer++, 1);
			//Global::S_CCycleBuffer->read((char *)&valueA, 1);
			//Global::S_CCycleBuffer->read((char *)&valueB, 1);
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


/**
* @brief ��ȡϸ����ʾ����
*/
void BllDataCenter::getCellData(bool clear)
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
	
	//��������λ�����:ʾ����һ�����ݰ���С512Byte
	if (Global::S_CCycleBuffer->getUsedSize() >= 512)
	{
		//�����Ҫ���
		if (clear)
		{
			//���ÿ��ͨ��
			for (int i = 0; i < 8; i++)
				iCellStaticData->clear(i);
		}

		
		char * buffer = m_buffer;//ָ����ʱ����
		memset(buffer, 0, 512);//�������
		Global::S_CCycleBuffer->read(m_buffer, 512);//һ�ζ�8��ϸ��������
		//һ��8��ϸ��
		for (int i = 0; i < 8; i++)
		{
			//8��ͨ��
			for (int j = 0; j < 8; j++)
			{
				//һ��ͨ��8���ֽ�
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

				//����ϸ�����ݽṹ
				valueHH = (valueHH1 * 65536 + valueHH2 * 256 + valueHH3);//ϸ���߶�
				valueAA = (valueAA1 * 65536 + valueAA2 * 256 + valueAA3);//ϸ�����
				valueWW = (valueWW1 * 256 + valueWW2);//ϸ�����

				

				iCellStaticData->insert(j, valueHH, valueAA, valueWW);
			}
		}


	}
	else//���û������ȴ����ͻ��кܶ��ѭ����CPU��ܸߡ�
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}

/**
* @brief ��ȡϸ����ʾ��������
*/
QVector<double>* BllDataCenter::getCellDataVector(int passage, int valuePos)
{
	return iCellStaticData->getDataVector(passage, valuePos);
}
/**
* @brief ɢ��ͼ��ȡ���ݷ���
*/
void BllDataCenter::getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList)
{
	iCellStaticData->getDataVector(origialDataList,logDataList);
}
/**
* @brief ֱ��ͼ��ȡ���ݷ���
*/
void BllDataCenter::getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList, QList < QList < QVector<BarStruct>* >*  >* barStructList)
{
	iCellStaticData->getDataVector(origialDataList, logDataList, barStructList);
}
/**
* @brief ��ȡԴ����ϸ������
*/
double BllDataCenter::getAllEvents()
{
	return iCellStaticData->getAllEvents();
}