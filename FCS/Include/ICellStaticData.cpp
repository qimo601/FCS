
#include "ICellStaticData.h"

ICellStaticData::ICellStaticData(QObject *parent)
	: QObject(parent)
{
	
	//���ϸ��������δ��ʼ����Ĭ���Զ���ʼ��
	init();//�����ǵ�����ֻ���ʼ��һ��
}

ICellStaticData::~ICellStaticData()
{

}
//�ⲿ��ʼ�� before invoke main     
ICellStaticData* ICellStaticData::m_instance = new ICellStaticData();

/**
* @brief ����ϸ������ȫ�ֵ���ָ��
*/
ICellStaticData* ICellStaticData::getInstance()
{
	return m_instance;
}
void ICellStaticData::init()
{
	//��ʼ��8��ͨ��ϸ�����ݵ�����
	cellFullData = new QList<QList< QVector<double>* >* > ();
	QList< QVector<double>* >* passageData = 0;
	for (int i = 0; i < 8; i++)
	{
		passageData = new QList < QVector<double>* >();
		for (int j = 0; j < 3; j++)
		{
			
			QVector<double>* vector = new QVector<double>();
			passageData->append(vector);
		}
		cellFullData->append(passageData);
	}
}
/**
* @brief ����ĳͨ��ĳֵ
*/
void ICellStaticData::insert(int passage,double valueHH,double valueAA,double valueWW)
{
	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	//mutex.lock();
	QVector <double> * HH = passageData->at(0);
	QVector <double> * AA = passageData->at(1);
	QVector <double> * WW = passageData->at(2);
	HH->append(valueHH);
	AA->append(valueAA);
	WW->append(valueWW);
	//mutex.unlock();
}
/**
* @brief ���ĳ��ͨ��ֵ
*/
void ICellStaticData::clear(int passage)
{

	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	mutex.lock();
	passageData->at(0)->clear();//�������ֵ
	passageData->at(1)->clear();
	passageData->at(2)->clear();
	mutex.unlock();
}
/**
* @brief ��ȡĳ��ͨ��ĳ��ֵ
*/
QVector<double>* ICellStaticData::getDataVector(int passage, int valuePos)
{
	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	QVector<double>* vector = passageData->at(valuePos);
	return vector;
}