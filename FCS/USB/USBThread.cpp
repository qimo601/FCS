
#include <QDebug> 
#include "USBThread.h"
#include "Include/Global.h"
USBThread::USBThread():QThread()
{  
	ctrlTag = CTRL_TAG::START_TAG;//默认开始采集
	stepValue = 0;
	m_hDevice = 0;//初始化设备为空
}  
  
USBThread::~USBThread()  
{  
  
}


void USBThread::run()  
{ 
	qDebug() << "【USB监听线程】启动USBThread,线程Id" << QThread::currentThreadId();
	//只要不是停止
	while (ctrlTag != CTRL_TAG::STOP_TAG)
	{

		//如果是暂停
		if (ctrlTag == CTRL_TAG::SUSPEND_TAG)
		{
			qDebug() << "【USBThread】USB线程处于监听暂停状态。";
			sleep(1);
			return;
		}
		//如果是停止
		else if (ctrlTag == CTRL_TAG::STOP_TAG)
		{
			qDebug() << "【USBThread】停止USB监听线程。";
			break;
		}
		//开始状态或者继续状态
		else
		{

			
#if Simulation_Test == 0
			//真正读取USB
			onButtonRd();
#else
			//测试代码
			onButtonRd1();
#endif
			msleep(10);
		}
	}
	qDebug() << "【USBThread】运行结束!";
	this->exec();

}


/**
* @brief 设置控制标签状态
*/
void USBThread::setCtrlTag(CTRL_TAG tag)
{
	ctrlTagMutex.lock();
	ctrlTag = tag;
	ctrlTagMutex.unlock();
}
/**
* @brief 读函数
*/
BOOL USBThread::read(PUCHAR buffer, DWORD PreDataLength, PDWORD PDataLength)

{
	ULONG nBytesReturned = 0;

	BULK_TRANSFER_CONTROL   inBulkControl;
	//THREAD_CONTROL  inThreadControl;

	//HANDLE ReadCompleteEvent;
	//ReadCompleteEvent = CreateEvent(0,FALSE,FALSE,NULL);

	//设置读的方向，为IN
	if (!onSetInDir())
	{
		return FALSE;
	}

	BOOL   status = FALSE;
	ULONG BytesReturned = 0;
	inBulkControl.pipeNum = 1;//端点选择EP6

	status = DeviceIoControl(m_hDevice,
		IOCTL_EZUSB_BULK_READ,
		(PVOID)&inBulkControl,
		sizeof(BULK_TRANSFER_CONTROL),
		buffer,//输出缓冲区
		PreDataLength,//传送的字节数
		&nBytesReturned,
		NULL);


	*PDataLength = nBytesReturned;
// 	if (status && (PreDataLength == nBytesReturned))
// 		return TRUE;
// 	else
// 		return FALSE;
	return true;


}


/**
* @brief 设置端口，接收操作
*/
BOOL USBThread::onSetInDir(void)
{

	BOOL    bResult = FALSE;
	int		nBytes = 0;
	VENDOR_OR_CLASS_REQUEST_CONTROL	myRequest;
	unsigned char *buffer;
	unsigned char databuffer[256];
	ULONG bufferSize = 0;


	myRequest.request = 0XBB;	//发送数据命令，与固件中BOOL DR_VendorCmnd(void)的命令配对
	myRequest.value = (USHORT)0x0000;	//发送数据
	myRequest.index = (USHORT)0xbeef;
	myRequest.direction = 0x00;	//out
	bufferSize = 0x10;
	buffer = databuffer;
	myRequest.requestType = 0x02;
	myRequest.recepient = 0x00;

	if (m_hDevice != NULL)
	{
		bResult = DeviceIoControl(m_hDevice,
			IOCTL_EZUSB_VENDOR_OR_CLASS_REQUEST,
			&myRequest,
			sizeof(VENDOR_OR_CLASS_REQUEST_CONTROL),
			buffer,
			bufferSize,
			(unsigned long *)&nBytes,
			NULL);
	}

	return bResult;
}

void USBThread::onButtonRd()
{
	// TODO: Add your control notification handler code here
	PUCHAR buffer; //存放读来的数据的buffer
	DWORD BufferLength = 512;  //buffer的大小，可自行定义
	DWORD PreDataLength = 512; //预设的读数据长度
	//	DWORD PreDataLength=256; 
	DWORD DataLength = 0;      //实际读的数据长度
	DWORD *PDataLength = &DataLength;

	buffer = new UCHAR[BufferLength];

	//	int data

	QString string;
	quint16 i = 0;

	if (!read(buffer, PreDataLength, PDataLength))
	{
		//		MessageBox(_T("read got failed!"));
		//string.Format("%d",DataLength);
		//MessageBox(string,"A",0);
		qDebug() << "【USBThread】read failed!实际读取长度：" << DataLength;
	}

	else
	{
		i = i + 1;
		qDebug() << QString("【USBThread】read succeed! 第%1次,大小为：%2B").arg(i).arg(DataLength);
		//m_strTestDisplay = string;
		//m_strTestDisplay = "read succeed!";
	}

	//将读到的数据写入文件以便对比


	QString filename = "addata.txt";
	FILE *projectFile = fopen(filename.toLocal8Bit().data(), "wb+");

	if (!projectFile)
	{
		//qDebug() << "【onButtonRd】数据文件" << projectFile << "，打开失败！\n";
	}
	//写入磁盘
	int result = 0;
	fwrite(buffer, sizeof(quint16), DataLength, projectFile);
	//拷贝数据失败
	if (result < 0)
	{
		//qDebug() << "【onButtonRd】写入文件失败,文件名：" << filename;

	}
	else
	{
		//qDebug() << "【onButtonRd】将USB数据写入文件成功,文件名：" << filename;
	}
	//关闭文件
	if (fclose(projectFile) != 0)
		qDebug() << "【onButtonRd】关闭文件失败，文件名：" << filename;


	/********************************************/
	//添加至环形缓冲区
	if (Global::S_CCycleBuffer->getFreeSize() >= DataLength)
	{
		Global::S_CCycleBuffer->write((char *)buffer, DataLength);

		//Global::S_CCycleBuffer->write((char *)&stepValue, 4);
		stepValue++;

	}
	else//如果没有这个等待，会有很多空循环，CPU会很高
	{
		Global::S_CCycleBuffer->waitNotFull();
	}

	delete buffer;
	//FreeLibrary(hInstLibrary);

}
void USBThread::onButtonRd1()
{
	//示波器测试数据
	quint8 testOscData[512];
	for (int i = 0; i < 512; i++)
	{
		testOscData[i] = 150 + qrand() % 50;
	}
	// TODO: Add your control notification handler code here
	PUCHAR buffer; //存放读来的数据的buffer
	DWORD BufferLength = 5120;  //buffer的大小，可自行定义
	DWORD PreDataLength = 5120; //预设的读数据长度
	//	DWORD PreDataLength=256; 
	DWORD DataLength = 0;      //实际读的数据长度
	DWORD *PDataLength = &DataLength;

	buffer = new UCHAR[BufferLength];

	//	int data

	QString string;
	quint16 i = 0;

	if (!read(buffer, PreDataLength, PDataLength))
	{
		//		MessageBox(_T("read got failed!"));
		//string.Format("%d",DataLength);
		//MessageBox(string,"A",0);
		qDebug() << "【onButtonRd】read failed!实际读取长度：" << DataLength;
	}

	else
	{
		i = i + 1;
		qDebug("read succeed! 第%d次", i);
		//m_strTestDisplay = string;
		//m_strTestDisplay = "read succeed!";
	}

	//将读到的数据写入文件以便对比


	QString filename = "addata.txt";
	FILE *projectFile = fopen(filename.toLocal8Bit().data(), "wb+");

	if (!projectFile)
	{
		qDebug() << "【onButtonRd】数据文件" << projectFile << "，打开失败！\n";
	}
	//写入磁盘
	int result = fwrite(buffer, sizeof(quint16), DataLength, projectFile);
	//拷贝数据失败
	if (result < 0)
	{
		qDebug() << "【onButtonRd】写入文件失败,文件名：" << filename;

	}
	else
	{
		qDebug() << "【onButtonRd】将USB数据写入文件成功,文件名：" << filename;
	}
	//关闭文件
	if (fclose(projectFile) != 0)
		qDebug() << "【onButtonRd】关闭文件失败，文件名：" << filename;


	/********************************************/
	//添加至环形缓冲区
	if (Global::S_CCycleBuffer->getFreeSize() >= DataLength)
	{
		//Global::S_CCycleBuffer->write((char *)buffer, DataLength);

		Global::S_CCycleBuffer->write((char *)&testOscData, 512);
		stepValue++;

	}
	else//如果没有这个等待，会有很多空循环，CPU会很高
	{
		Global::S_CCycleBuffer->waitNotFull();
	}

	delete buffer;
	//FreeLibrary(hInstLibrary);

}
/**
* @brief 设置USB句柄
*/
void USBThread::setHdevice(HANDLE device)
{
	m_hDevice = device;
}