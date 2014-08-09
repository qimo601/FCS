
#include "ReadCellThread.h"
#include <QDebug>
#include "Include/OscDataCenter.h"
ReadCellThread::ReadCellThread(QObject *parent) :QThread(parent)
{  
	stepValue = 0;
	m_goOn = true;//默认就自动进入循环
	m_opertaeEnum = Operate::NORMAL;//默认普通操作
	iCellStaticData = ICellStaticData::getInstance();//初始化细胞数据接口
}  

ReadCellThread::~ReadCellThread()  
{  
  
}
bool ReadCellThread::saveTag = false;//默认为false
QString ReadCellThread::fileName = "cellFile";
FILE* ReadCellThread::projectFile = 0;
void ReadCellThread::run()  
{ 
	qDebug() << "【USB监听线程】启动ReadCellThread,线程Id" << QThread::currentThreadId();
	
	while (1)
	{
		switch (m_opertaeEnum)
		{
		case Operate::START_ACQ:
			emit cellReadySignal(true);//新USB格式实时数据，请对方清空
			startReadCellDataFromCircleBuffer();
			break;
		case Operate::Read_USB_FILE:
			emit cellReadySignal(true);//新USB格式本地文件数据，请对方清空
			getCellDataFromFile(m_filePath, true);
			break;
		case Operate::Read_MatLab_FILE:
			emit cellReadySignal(true);//新MatLab格式本地文件数据，请对方清空
			getCellDataFromMatlabFile(m_filePath, true);
			break;
		case Operate::Read_FCS_FILE:
			emit cellReadySignal(true);//新FCS格式本地文件数据，请对方清空
			getCellDataFromFCSFile(m_filePath, true);
			break;
		default:
			sleep(1);
		}

	}
	//只要不是停止
	//while (ctrlTag != CTRL_TAG::STOP_TAG)
	//{

	//}
	//qint64 step = 0;
	//while (m_goOn)
	//{
	//	
	//	getCellData(false);
	//	emit cellReadySignal();
	//	step++;
	//	//qDebug() << "【ReadCellThread】step:" <<step;
	//	msleep(10);
	//}
	//qDebug() << "【ReadCellThread】运行结束!";
	this->exec();

}
/**
* @brief 开始循环读取环形缓冲区中细胞数据
*/
void ReadCellThread::startReadCellDataFromCircleBuffer()
{
	qint64 step = 0;
	//必须先清空原先的全局数据;
	clearCellStaticData();
	while (m_goOn)
	{
		
		getCellData(false);
		//降低新数据发送频率，减少界面卡死
		if (step >= 4)
		{
			emit cellReadySignal(false);
			step = 0;
		}
		step++;
		//qDebug() << "【ReadCellThread】step:" <<step;
		msleep(50);
	}
	m_opertaeEnum = NORMAL;//回复默认状态
}
/**
* @brief 获取细胞显示数据，环形缓冲区中读一个单元
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

				//继续转换
				valueAA = valueAA - 32768 * valueWW;
				valueHH = valueHH - 32768 * 4;

				iCellStaticData->insert(j, valueHH, valueAA, valueWW);
			}
		}

		//将读到的数据写入文件以便对比
		if (saveTag)
			saveToFile(m_buffer, 512);

	}
	else//如果没有这个等待，就会有很多空循环，CPU会很高。
	{
		return;
		//Global::S_CCycleBuffer->waitNotEmpty();

	}
}

/**
* @brief 通过文件读取matlab版本本地细胞数据
*/
void ReadCellThread::getCellDataFromMatlabFile(QString filePath, bool clear)
{

	qint32 valueHH;
	quint8 valueHH1;
	quint8 valueHH2;
	quint8 valueHH3;
	qint32 valueAA;
	quint8 valueAA1;
	quint8 valueAA2;
	quint8 valueAA3;
	qint32 valueWW;
	quint8 valueWW1;
	quint8 valueWW2;
	int value;
	stepValue = 1;
	//如果需要清空
	if (clear)
	{
		clearCellStaticData();
	}
	char * tmp = new char[4*3*8*8]();//指向临时数组 long int *3 *8 *8
	FILE *stream;
	int err;
	int numwritten;
	char *buffer = tmp;
	//文件路径：QString 转换成char*
	QByteArray pathByteArray = filePath.toLocal8Bit();
	if ((stream = fopen(pathByteArray.data(), "rb")) != NULL)
	{
		while (!feof(stream))
		{
			buffer = tmp;
			//读取原始数据文件头
			fread(buffer, sizeof(char), 4 * 3 * 8 * 8, stream);
			//一次8个细胞
			for (int i = 0; i < 8; i++)
			{
				QList<QVector<double>> list;
				//8个通道
				for (int j = 0; j < 8; j++)
				{
					QVector<double> vector;
					memcpy(&valueAA, buffer, 4);//格式有错，必须先读valueAA后读valueHH，其他USB和FCS格式顺序正常
					buffer = buffer + 4;
					memcpy(&valueHH, buffer, 4);
					buffer = buffer + 4;
					memcpy(&valueWW, buffer, 4);
					buffer = buffer + 4;


					//继续转换
					valueAA = valueAA - 32813 * valueWW;
					valueHH = valueHH - 32813 * 4;


					double valueH = valueHH;
					double valueA = valueAA;
					double valueW = valueWW;
					vector.append(valueH);
					vector.append(valueA);
					vector.append(valueW);
					list.append(vector);


					
				}
				if (list.size() == 8)
				{
					//8个通道
					for (int k = 0; k < 8; k++)
					{
						for (int i = 0; i < 3; i++)
						{
							QVector<double> vector = list.at(k);
							iCellStaticData->insert(k, vector.at(0), vector.at(1), vector.at(2));
						}

					}

				}

			}
			
			emit cellReadySignal(false);
		}





		//关闭文件
		if (stream)
		{
			if (fclose(stream))
			{
				qDebug() << "文件关闭失败:" << filePath;
			}
		}
	}
	m_opertaeEnum = NORMAL;//回复默认状态
}


/**
* @brief 通过文件读取USB版本本地细胞数据
*/
void ReadCellThread::getCellDataFromFile(QString filePath, bool clear)
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
	//如果需要清空
	if (clear)
	{
		clearCellStaticData();
	}
	char * tmp = new char[512]();//指向临时数组
	FILE *stream;
	int err;
	int numwritten;
	char *buffer = tmp;
	//文件路径：QString 转换成char*
	QByteArray pathByteArray = filePath.toLocal8Bit();
	if ((stream = fopen(pathByteArray.data(), "rb")) != NULL)
	{
		while (!feof(stream))
		{
			buffer = tmp;
			//读取原始数据文件头
			fread(buffer, sizeof(char), 512, stream);
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


					//继续转换
					valueAA = valueAA - 32768 * valueWW;
					valueHH = valueHH - 32768 * 4;


					iCellStaticData->insert(j, valueHH, valueAA, valueWW);
				}
			}

			emit cellReadySignal(false);
		}





		//关闭文件
		if (stream)
		{
			if (fclose(stream))
			{
				qDebug() << "文件关闭失败:" << filePath;
			}
		}
	}
	m_opertaeEnum = NORMAL;//回复默认状态
}
/**
* @brief 通过文件读取FCS格式本地细胞数据
*/
void ReadCellThread::getCellDataFromFCSFile(QString filePath, bool clear)
{
	m_opertaeEnum = NORMAL;//回复默认状态
}
/**
* @brief 设置循环读取标签
*/
void ReadCellThread::setGoOn(bool on)
{
	mutex.lock();
	m_goOn = on;
	mutex.unlock();
}
/**
* @brief 设置该线程操作
*/
void ReadCellThread::setOperate(Operate operate)
{
	mutex.lock();
	m_opertaeEnum = operate;
	mutex.unlock();
}
/**
* @brief 设置读取文件路径
*/
void ReadCellThread::setFilePath(QString filePath)
{
	mutex.lock();
	m_filePath = filePath;
	mutex.unlock();
}
/**
* @brief 清楚全局细胞缓冲区旧数据，
*        每次切换采集和读取本地文件必须调用
*/
void ReadCellThread::clearCellStaticData()
{
	//清空每个通道
	for (int i = 0; i < 8; i++)
		iCellStaticData->clear(i);
}
/**
* @brief 保存细胞文件
*/
void ReadCellThread::saveToFile(char* buffer, qint32 DataLength)
{
	//从界面打开
	//QString filename = "addata.txt";
	//FILE *projectFile = fopen(filename.toLocal8Bit().data(), "wb+");
	if (!projectFile)
	{
		qDebug() << "【ReadCellThread】数据文件" << projectFile << "，打开失败！\n";
	}
	//写入磁盘
	int result = fwrite(buffer, sizeof(char), DataLength, projectFile);
	//拷贝数据失败
	if (result < 0)
	{
		qDebug() << "【ReadCellThread】写入文件失败,文件名：" << fileName;

	}
	else
	{
		qDebug() << "【ReadCellThread】将USB数据写入文件成功,文件名：" << fileName;
	}
	//从界面关闭
	////关闭文件
	//if (fclose(projectFile) != 0)
	//	qDebug() << "【ReadCellThread】关闭文件失败，文件名：" << fileName;
}