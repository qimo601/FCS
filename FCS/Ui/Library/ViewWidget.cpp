#include "ViewWidget.h"
#include <QScrollBar>
#include <QFileDialog>
#include <QDir>
ViewWidget::ViewWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	/*plotWidget = new PlotWidget(ui.scrollAreaWidgetContents);
	ui.gridLayout->addWidget(plotWidget, 1, 0, 1, 1);*/

	//barChartWidget = new BarChartWidget(ui.scrollAreaWidgetContents);

	//初始化当前plot数组
	plotWidgetList.append(ui.plotWidget_1);
	plotWidgetList.append(ui.plotWidget_2);
	plotWidgetList.append(ui.plotWidget_3);
	plotWidgetList.append(ui.plotWidget_4);

	connect(ui.plotWidget_1, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//初始化当前焦点plot
	focusPlotWidget = 0;
	m_timerId = 0;//初始化
	this->setFocusPolicy(Qt::StrongFocus);


	/****线程读取细胞数据****/
	readCellThread = new ReadCellThread();//从全局缓冲区读取细胞数据线程
	readCellThread->start();//细胞数据线程读取
	//循环读取缓冲区
	connect(this, SIGNAL(startReadCellDataFromCircleBuffer()), readCellThread, SLOT(startReadCellDataFromCircleBuffer()));
	//读取本地文件--已经没用了
	connect(this, SIGNAL(openExpSignal(QString, bool)), readCellThread, SLOT(getCellDataFromFile(QString, bool)));

	/****线程读取细胞数据****/
	

	/****线程传递细胞数据****/
	//connect(readCellThread, SIGNAL(cellReadySignal()), ui.plotWidget_1, SLOT(updateSamples()));
	//统计线程
	connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_1->staticsThread, SLOT(staticsCellData(bool)));
	//统计线程
	connect(this, SIGNAL(saveExpFileToPlotwigetSignal(QString, QString)), ui.plotWidget_1, SLOT(saveExpFileSlot(QString,QString)));

	//直方图统计，这个速度有点卡
	//connect(readCellThread, SIGNAL(cellReadySignal()), &ui.plotWidget_2->staticsThread, SLOT(staticsCellData()));
	//统计线程
	///////connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_2->staticsThread, SLOT(staticsCellData(bool)));
	//connect(readCellThread, SIGNAL(cellReadySignal()), ui.plotWidget_3, SLOT(updateSamples()));
	//统计线程
	///////connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_3->staticsThread, SLOT(staticsCellData(bool)));
	//connect(readCellThread, SIGNAL(cellReadySignal()), ui.plotWidget_4, SLOT(updateSamples()));
	//统计线程
	///////connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_4->staticsThread, SLOT(staticsCellData(bool)));
	/****线程传递细胞数据****/


	//统计报告初始化
	reportTree = new ReportTree(this);
	reportTree->setVisible(false);
	
}

ViewWidget::~ViewWidget()
{
	readCellThread->quit();//线程离开exec循环
}
/**
* @brief 统计报告展示
*/
void ViewWidget::showReport(bool on)
{
	if (on)
		reportTree->show();
	else
		reportTree->hide();
}
void ViewWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}

/**
* @brief 开始采集
*/
void ViewWidget::startAcqSlot()
{

	//ui.plotWidget_1->startAcqTimer();
	//m_timerId = startTimer(10);//定时器读取



	/****测试线程获取细胞数据****/
	readCellThread->setGoOn(true);//设置真读循环槽函标志位为真
	readCellThread->setOperate(ReadCellThread::START_ACQ);
	//emit startReadCellDataFromCircleBuffer();//启动真读循环槽函数

	/****测试线程获取细胞数据****/

	
}
/**
* @brief 结束采集
*/
void ViewWidget::stopAcqSlot()
{
	//ui.plotWidget_1->stopAcqTimer();
	//关闭定时器
	//killTimer(m_timerId);


	/****测试线程获取示波器数据****/
	readCellThread->setGoOn(false);//停止真读循环，线程进入默认状态
	/****测试线程获取示波器数据****/
}
/**
* @brief 新建画布
*/
void ViewWidget::addNewPlot()
{
	

	int m = ui.gridLayout->count();
	PlotWidget* plotWidget_0 = new PlotWidget(ui.scrollAreaWidgetContents);
	plotWidget_0->setObjectName(QStringLiteral("plotWidget_1"));
	plotWidget_0->setCursor(QCursor(Qt::ArrowCursor));

	ui.gridLayout->addWidget(plotWidget_0);
	//QWidget* widget = plotWidgetList.last();
	int row;
	int column;
	int rowSpan;
	int columnSpan;
	ui.gridLayout->getItemPosition(2, &row, &column, &rowSpan, &columnSpan);
	plotWidgetList.append(plotWidget_0);


	//统计线程
	QObject::connect(readCellThread, SIGNAL(cellReadySignal(bool)), &plotWidget_0->staticsThread, SLOT(staticsCellData(bool)));
	clearPlotWidget();
	relayoutPlotWidget();

}
/**
* @brief 删除画布
*/
void ViewWidget::delPlot()
{
	//删除选中的画布
	for (int i = 0; i < plotWidgetList.size(); i++)
	{
		if (focusPlotWidget == plotWidgetList.at(i))
		{

			ui.gridLayout->removeWidget(focusPlotWidget);
			plotWidgetList.takeAt(i);
			delete focusPlotWidget;//删除
			focusPlotWidget = 0;//选中的为空

		}
	}


	
	clearPlotWidget();//清空所有画布
	relayoutPlotWidget();//重新布局画布
}

void ViewWidget::mouseMoveEvent(QMouseEvent * e)
{
	//int hvalue = ui.scrollArea->horizontalScrollBar()->value();
	//int vvalue = ui.scrollArea->verticalScrollBar()->value();
	//QPoint topLeft = ui.scrollArea->viewport()->rect().topLeft();

	//ui.scrollArea->viewport()->move(topLeft.x() - hvalue, topLeft.y() - vvalue);
}


void ViewWidget::mousePressEvent(QMouseEvent * event)
{

	for (int i = 0; i < plotWidgetList.size(); i++)
	{
		if (plotWidgetList.at(i) == focusWidget())

		{
			focusPlotWidget = focusWidget();//当期plot控件
			return;
		}
	}
	focusPlotWidget = 0;//否则为空
}

/**
* @brief 清空所有画布
*/
void ViewWidget::clearPlotWidget()
{
	//清空所有画布
	for (int i = 0; i < plotWidgetList.size(); i++)
	{
		ui.gridLayout->removeWidget(plotWidgetList.at(i));
	}
}
/**
* @brief 重新布局画布
*/
void ViewWidget::relayoutPlotWidget()
{
	//重新布局画布
	for (int i = 0, row = 0, column = 0; i < plotWidgetList.size(); i++)
	{
		if (column == 2)
		{
			column = 0;
			row++;
		}
		ui.gridLayout->addWidget(plotWidgetList.at(i), row, column, 1, 1);
		column++;

	}
}
void ViewWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	if (event->timerId() == m_timerId)
	{
		
	}
}
/**
* @brief 打开文件
*/
void ViewWidget::openExpFileSlot()
{
	QString file = "20140618_14.fcm";
	QDir dir1;
	QString absolutePath1 = dir1.absolutePath();
	QString canonicalPath1 = dir1.canonicalPath();
	QFileDialog *fd = new QFileDialog(this, tr("选择实验数据文件"), "../MatLabData", "");
	fd->setFileMode(QFileDialog::ExistingFile);
	fd->setViewMode(QFileDialog::Detail);
	QStringList nameFilters;
	nameFilters << "matlab files (*.fcm *.FCM *.matlab *.MATLAB)"
		<< "USB files (*.usb *.USB)"
		<< "FCS files (*.fcs *.FCS)";

	fd->setNameFilters(nameFilters);//设置文件类型过滤器
	QStringList fileNamesList;
	if (fd->exec()==QDialog::Accepted) // 取消则是：QDialog::Rejected
	{
		fileNamesList = fd->selectedFiles();
	}
	else{
		return;
	}
	QString fileName = fileNamesList.at(0).toLocal8Bit().constData();
	QDir dir = fd->directory();
	QString absolutePath = dir.absolutePath();
	QString canonicalPath = dir.canonicalPath();
	
	





	

	readCellThread->setGoOn(false);//停止采集
	readCellThread->setFilePath(fileName);//传递文件名
	QString nameFilter = fd->selectedNameFilter();
	if (nameFilter == "USB files (*.usb *.USB)")
		readCellThread->setOperate(ReadCellThread::Read_USB_FILE);//开始读取USB格式本地文件
	else if (nameFilter == "matlab files (*.fcm *.FCM *.matlab *.MATLAB)")
		readCellThread->setOperate(ReadCellThread::Read_MatLab_FILE);//开始读取MatLab格式本地文件
	else if (nameFilter == "FCS files (*.fcs *.FCS)")
		readCellThread->setOperate(ReadCellThread::Read_FCS_FILE);//开始读取FCS格式本地文件

	delete fd;
	//emit openExpSignal(file,true);//不用发信号
}
/**
* @brief 保存文件
*/
void ViewWidget::saveExpFileSlot()
{
	QFileDialog *fd = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
	fd->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
	fd->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
	fd->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
	fd->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
	//还有另一种形式QFileDialog::List，这个只是把文件的文件名以列表的形式显示出来
	fd->setGeometry(10, 30, 300, 200);//设置文件对话框的显示位置
	fd->setDirectory("../USBData");
	QStringList nameFilters;
	nameFilters << "USB files (*.usb *.USB)"
		<< "matlab files (*.fcm *.FCM *.matlab *.MATLAB)"
		<< "FCS files (*.fcs *.FCS)";
	fd->setNameFilters(nameFilters);//设置文件类型过滤器

	QStringList fileNamesList;
	if (fd->exec() == QDialog::Accepted) {
		fileNamesList = fd->selectedFiles();
		}


	QString fileName = fileNamesList.at(0).toLocal8Bit().constData();
	//QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
	//	"../USBData",
	//	tr("USB files (*.usb *.USB)"));

	QStringList list = fileName.split(".");
	QString fileType;
	if (list.last() == "usb" || list.last() == "USB")
		fileType = "usb";
	else if (list.last() == "fcs" || list.last() == "FCS")
		fileType = "fcs";
	else if (list.last() == "matlab" || list.last() == "MATLAB" || list.last() == "fcm" || list.last() == "FCM")
		fileType = "fcm";
	emit saveExpFileToPlotwigetSignal(fileName,fileType);


	delete fd;
}

