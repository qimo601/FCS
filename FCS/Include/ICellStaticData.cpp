
#include "ICellStaticData.h"

ICellStaticData::ICellStaticData(QObject *parent)
	: QObject(parent)
{
	
	//如果细胞数据尚未初始化，默认自动初始化
	init();//由于是单例，只会初始化一次
}

ICellStaticData::~ICellStaticData()
{

}
//外部初始化 before invoke main     
ICellStaticData* ICellStaticData::m_instance = new ICellStaticData();

/**
* @brief 返回细胞数据全局单例指针
*/
ICellStaticData* ICellStaticData::getInstance()
{
	return m_instance;
}
void ICellStaticData::init()
{
	//初始化8个通道细胞数据的数组
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
* @brief 插入某通道某值
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
* @brief 清空某个通道值
*/
void ICellStaticData::clear(int passage)
{

	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	mutex.lock();
	passageData->at(0)->clear();//清楚三个值
	passageData->at(1)->clear();
	passageData->at(2)->clear();
	mutex.unlock();
}
/**
* @brief 获取某个通道某列值
*/
QVector<double>* ICellStaticData::getDataVector(int passage, int valuePos)
{
	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	QVector<double>* vector = passageData->at(valuePos);
	return vector;
}