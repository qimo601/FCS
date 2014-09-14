
#include "ICellStaticData.h"
#include "Ui/Library/BarStruct.h"
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
	mutex.lock();

	QList< QVector<double>* >* passageData = cellFullData->at(passage);
	
	QVector <double> * HH = passageData->at(0);
	QVector <double> * AA = passageData->at(1);
	QVector <double> * WW = passageData->at(2);
	HH->append(valueHH);
	AA->append(valueAA);
	WW->append(valueWW);
	mutex.unlock();
}
/**
* @brief 清空某个通道值
*/
void ICellStaticData::clear(int passage)
{
	mutex.lock();
	QList< QVector<double>* >* passageData = cellFullData->at(passage);
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
/**
* @brief 散点图获取数据方法
*/
void ICellStaticData::getDataVector(QList < QList < QVector<double>* > * >*  origialDataList, QList < QList < QVector<double>* >*  >* logDataList)
{
	mutex.lock();
	//8个通道
	for (int i = 0; i < cellFullData->size(); i++)
	{
		QList < QVector<double>* > * list = cellFullData->at(i);
		QList < QVector<double>* > * list1 = origialDataList->at(i);
		QList < QVector<double>* > * list2 = logDataList->at(i);
		//3组参数
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = list->at(j);
			QVector<double>* vector1 = list1->at(j);
			QVector<double>* vector2 = list2->at(j);

			//递增数据
			for (int m = vector1->size(); m < vector->size(); m++)//int m = vector1->size()表示从上次数据开始读，不读旧数据，提高筛选概率
			{
				origialDataList->at(i)->at(j)->append(vector->at(m));
				logDataList->at(i)->at(j)->append(qLn(vector->at(m)) / qLn(10));
			}
			//memcpy(cellDataVector->at(i)->at(j), vector, vector->size());
			
		}
	}
	mutex.unlock();
			
}
/**
* @brief 直方图读取数据方法
*/
void ICellStaticData::getDataVector(QList < QList < QVector<double>* > * >*  origialDataList, QList < QList < QVector<double>* >*  >* logDataList, QList < QList < QVector<BarStruct>* >*  >* barStructList)
{
	mutex.lock();
	//8个通道
	for (int i = 0; i < cellFullData->size(); i++)
	{
		QList < QVector<double>* > * list = cellFullData->at(i);//缓冲区
		QList < QVector<double>* > * list1 = origialDataList->at(i);//原始数据
		QList < QVector<double>* > * list2 = logDataList->at(i);//log数据
		QList < QVector<BarStruct>* >* list3 = barStructList->at(i);//条件数据
		//3组参数
		for (int j = 0; j < 3; j++)
		{
			QVector<double>* vector = list->at(j);//缓冲区
			QVector<double>* vector1 = list1->at(j);//原始数据
			QVector<double>* vector2 = list2->at(j);//log数据
			QVector<BarStruct>* vector3 = list3->at(j);//条件数据
			//递增数据
			for (int m = vector1->size(); m < vector->size(); m++)//int m = vector1->size()表示从上次数据开始读，不读旧数据，提高筛选概率
			{
				double value = vector->at(m);//原值计算范围1024组不精细
				double valueLog = qLn(vector->at(m)) / qLn(10);//取log计算范围比较准

				origialDataList->at(i)->at(j)->append(value);//追加原始数据
				logDataList->at(i)->at(j)->append(valueLog);//追加log数据


				//if (i == 2)//默认3通道,其他通道现场算
				//{
				//	for (int k = 0; k < vector3->size(); k++)
				//	{
				//		BarStruct barStruct = vector3->at(k);
				//		if (value >= barStruct.m_point.x() && value < barStruct.m_point.y())
				//		{
				//			barStruct.m_value++;
				//			vector3->replace(k, barStruct);
				//			break;
				//		}
				//	}
		
				//}
				int start = 0;
				int end = vector3->size() - 1;
				int mid = start + (end - start) / 2;
				while (mid > 0)//二分查找
				{
					BarStruct barStruct = vector3->at(mid);
					if (value >= barStruct.m_point.x())
					{
						if (value < barStruct.m_point.y())
						{
							barStruct.m_value++;
							vector3->replace(mid, barStruct);
							break;
						}
						else
						{
							start = mid;
						}
					}
					else if (value < barStruct.m_point.x())
					{
						end = mid;
					}
					mid = start + (end - start) / 2;

				}
				


			}
			//memcpy(cellDataVector->at(i)->at(j), vector, vector->size());

		}
	}
	mutex.unlock();

}
/**
* @brief 获取细胞数目
*/
double ICellStaticData::getAllEvents()
{
	 mutex.lock();
	 double events = cellFullData->at(0)->at(0)->size();
	 mutex.unlock();
	 return events;
}