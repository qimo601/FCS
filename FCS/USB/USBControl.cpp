#include "USBControl.h"
#include <QFile>
USBControl::USBControl(QObject *parent)
	: QObject(parent)
{
	//设备名
	m_strName = "EZUSB-0";
	//设备初始化
	m_hDevice = NULL;
	//一个USB只有一个监听线程
	usbThread = new USBThread();

}

USBControl::~USBControl()
{
	delete usbThread;
}


/**
 * @brief 写事件
 */
void USBControl::onButtonWr()
{

	UCHAR buffer[2];
	DWORD DataLength =2;

	buffer[0] =	0;//1
	buffer[1] = 5;//0

	if (!write(buffer,DataLength))
	{
		qDebug("write got failed!");
		return;
	}
	else
	{
		qDebug("AD Started!");
	}

}


/**
 * @brief 写函数
 */
BOOL USBControl::write(PUCHAR buffer, DWORD DataLength)
{

	BULK_TRANSFER_CONTROL   outBulkControl;//inBulkControl,

	//设置写的方向，为OUT
	if (!onSetOutDir())
	{

		return FALSE;
	}


	BOOL   status=FALSE;
	ULONG BytesReturned=0;
	outBulkControl.pipeNum=0;//端点选择EP2

	status =  DeviceIoControl (m_hDevice,
		IOCTL_EZUSB_BULK_WRITE,
		(PVOID)&outBulkControl,
		sizeof(BULK_TRANSFER_CONTROL),
		buffer,//输出缓冲区
		DataLength,//传送的字节数
		&BytesReturned,
		NULL);	 

	if(status==TRUE)
	{

		return TRUE ;
	}
	else
	{

		return FALSE ;
	}

}
/**
 * @brief 设置端点，输出操作
 */
BOOL USBControl::onSetOutDir()
{

	BOOL    bResult = FALSE;
	int		nBytes = 0;	
	VENDOR_OR_CLASS_REQUEST_CONTROL	myRequest;
	unsigned char *buffer;
	unsigned char databuffer[256];
	ULONG bufferSize = 0;


	myRequest.request = 0XBA;	//发送数据命令，与固件中BOOL DR_VendorCmnd(void)的命令配对
	myRequest.value = (USHORT) 0x0000;	//发送数据
	myRequest.index = (USHORT) 0xbeef;
	myRequest.direction = 0x00;	//out
	bufferSize = 0x10;
	buffer = databuffer;	
	myRequest.requestType=0x02;
	myRequest.recepient=0x00;

	if (m_hDevice != NULL) 
	{
		bResult = DeviceIoControl (m_hDevice,
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
/**
 * @brief 读事件
 */
void USBControl::onButtonRd()
{
	// TODO: Add your control notification handler code here
	PUCHAR buffer; //存放读来的数据的buffer
	DWORD BufferLength = 5120;  //buffer的大小，可自行定义
	DWORD PreDataLength = 5120; //预设的读数据长度
	//	DWORD PreDataLength=256; 
	DWORD DataLength=0;      //实际读的数据长度
	DWORD *PDataLength=&DataLength; 

	buffer=new UCHAR[BufferLength];

	//	int data

	QString string;
	quint16 i = 0;

	if (!read(buffer, PreDataLength, PDataLength))
	{
		//		MessageBox(_T("read got failed!"));
		//string.Format("%d",DataLength);
		//MessageBox(string,"A",0);
		qDebug()<<"【onButtonRd】read failed!实际读取长度："<<DataLength;
	}

	else
	{
		i = i +1;
		qDebug("read succeed! 第%d次",i);
		//m_strTestDisplay = string;
		//m_strTestDisplay = "read succeed!";
	}

	//将读到的数据写入文件以便对比

// 	CFile file;
// 	file.Open("addata.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
// 	file.SeekToEnd();
// 
// 	file.write(buffer, DataLength);
// 	file.Close();


	QString filename = "addata.txt";
	FILE *projectFile = fopen(filename.toLocal8Bit().data(),"wb+");

	if (!projectFile)
	{
		qDebug() << "【onButtonRd】数据文件" << projectFile<<"，打开失败！\n" ;
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



	delete buffer;
	//FreeLibrary(hInstLibrary);

}
/**
* @brief 监听USB接收端口
*/
void USBControl::listen()
{
	//必须先将USB句柄传给读线程
	usbThread->setHdevice(m_hDevice);
	usbThread->start();

}
/**
* @brief 设置监听状态
*/
void USBControl::setListen(USBThread::CTRL_TAG tag)
{
	usbThread->setCtrlTag(tag);
}
/**
 * @brief 读函数
 */
BOOL USBControl::read(PUCHAR buffer, DWORD PreDataLength, PDWORD PDataLength)

{
	ULONG nBytesReturned=0;

	BULK_TRANSFER_CONTROL   inBulkControl;
	//THREAD_CONTROL  inThreadControl;

	//HANDLE ReadCompleteEvent;
	//ReadCompleteEvent = CreateEvent(0,FALSE,FALSE,NULL);

	//设置读的方向，为IN
	if (!onSetInDir())
	{
		return FALSE;
	}

	BOOL   status=FALSE;
	ULONG BytesReturned=0;
	inBulkControl.pipeNum=1;//端点选择EP6

	status =  DeviceIoControl (m_hDevice,
		IOCTL_EZUSB_BULK_READ,
		(PVOID)&inBulkControl,
		sizeof(BULK_TRANSFER_CONTROL),
		buffer,//输出缓冲区
		PreDataLength,//传送的字节数
		&nBytesReturned,  
		NULL);	 


	*PDataLength=nBytesReturned;

	if(status&&(PreDataLength==nBytesReturned))
		return TRUE;
	else
		return FALSE;


}


/**
 * @brief 设置端口，接收操作
 */
BOOL USBControl::onSetInDir(void)
{

	BOOL    bResult = FALSE;
	int		nBytes = 0;	
	VENDOR_OR_CLASS_REQUEST_CONTROL	myRequest;
	unsigned char *buffer;
	unsigned char databuffer[256];
	ULONG bufferSize = 0;


	myRequest.request = 0XBB;	//发送数据命令，与固件中BOOL DR_VendorCmnd(void)的命令配对
	myRequest.value = (USHORT) 0x0000;	//发送数据
	myRequest.index = (USHORT) 0xbeef;
	myRequest.direction = 0x00;	//out
	bufferSize = 0x10;
	buffer = databuffer;	
	myRequest.requestType=0x02;
	myRequest.recepient=0x00;

	if (m_hDevice != NULL) 
	{
		bResult = DeviceIoControl (m_hDevice,
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

/**
 * @brief 打开设备
 */
BOOL USBControl::openDevice ()
{
// 	char completeDeviceName[64] = "";
// 
// 	strcat(completeDeviceName, "\\\\.\\");
// 
// 	strcat(completeDeviceName,
// 		m_strName.GetBuffer(m_strName.GetLength()));

	QString completeDeviceName = "\\\\.\\";
	completeDeviceName += m_strName;

	m_hDevice = CreateFileA(completeDeviceName.toLocal8Bit().data(),//要打开的文件的名字
		GENERIC_WRITE|GENERIC_READ,//设备读写权限
		FILE_SHARE_WRITE|FILE_SHARE_READ,//表示允许对文件进行共享访问
		NULL,//定义了文件的安全特性
		OPEN_EXISTING, //文件必须已经存在。由设备提出要求
		FILE_FLAG_OVERLAPPED,//文件属性
		NULL);//如果不为零，则指定一个文件句柄。
	
	

	usbThread->setHdevice(m_hDevice);


	if (m_hDevice == INVALID_HANDLE_VALUE)
	{
		return (FALSE);
	}
	else
	{
		return (TRUE);
	}
}
/**
 * @brief 关闭设备
 */
BOOL USBControl::closeDevice()
 {	
	//先停止监听
	setListen(USBThread::STOP_TAG);
	//退出run函数
	usbThread->quit();
	//关闭USB设备
	return CloseHandle(m_hDevice);
 }