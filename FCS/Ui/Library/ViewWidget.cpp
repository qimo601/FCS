#include "ViewWidget.h"
#include <QScrollBar>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include <QPrinter>
#include <QTextBlock>
#include <QPdfWriter>
#include <QFileDialog>
#include <QDateTime>
ViewWidget::ViewWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	/*plotWidget = new PlotWidget(ui.scrollAreaWidgetContents);
	ui.gridLayout->addWidget(plotWidget, 1, 0, 1, 1);*/

	//barChartWidget = new BarChartWidget(ui.scrollAreaWidgetContents);
	/****线程读取细胞数据****/
	readCellThread = new ReadCellThread();//从全局缓冲区读取细胞数据线程
	readCellThread->start();//细胞数据线程读取
	
	init();//初始化
	
}

ViewWidget::~ViewWidget()
{
	readCellThread->setGoOn(false);//退出环形缓冲区真循环
	readCellThread->setReadCellThreadTag(false);//退出线程大循环
	readCellThread->quit();//线程离开exec循环
	if (readCellThread->isRunning())
	{
		readCellThread->wait();
	}
}
/**
* @brief 初始化
*/
void ViewWidget::init()
{
	//荧光补偿窗口
	m_compensationSettingsWidget = new CompensationSettings(this);
	m_compensationSettingsWidget->setVisible(false);

	//初始化当前焦点plot
	focusPlotWidget = 0;
	m_timerId = 0;//初始化
	this->setFocusPolicy(Qt::StrongFocus);
	//PDF窗口，方便保存上次路径
	m_fdPDF = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。

	
	//循环读取缓冲区
	connect(this, SIGNAL(startReadCellDataFromCircleBuffer()), readCellThread, SLOT(startReadCellDataFromCircleBuffer()));
	//读取本地文件--已经没用了
	connect(this, SIGNAL(openExpSignal(QString, bool)), readCellThread, SLOT(getCellDataFromFile(QString, bool)));
	/****线程读取细胞数据****/

	//初始化当前gridlayout中的plot数组
	m_gridPlotWidgetList.append(ui.plotWidget_1);
	m_gridPlotWidgetList.append(ui.plotWidget_2);
	//m_gridPlotWidgetList.append(ui.plotWidget_3);
	//m_gridPlotWidgetList.append(ui.plotWidget_4);
	//初始化全局有效细胞数据的plot窗口
	s_plotWidgetList.append(ui.plotWidget_1);
	s_plotWidgetList.append(ui.plotWidget_2);



	/****plotWidget_1配置****/
	//还原窗口
	connect(ui.plotWidget_1, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//新添加设门窗口
	connect(ui.plotWidget_1, SIGNAL(addGateSignal(QWidget*)), this, SLOT(addGateSlot(QWidget*)));
	//plotWidget_1统计线程
	connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_1->staticsThread, SLOT(staticsCellData(bool)));
	//plotWidget_1保存文件信号
	connect(this, SIGNAL(saveExpFileToPlotwigetSignal(QString, QString)), ui.plotWidget_1, SLOT(saveExpFileSlot(QString, QString)));

	//通知荧光补偿窗口
	connect(m_compensationSettingsWidget, SIGNAL(compensation(int, int, double)), ui.plotWidget_1, SLOT(compensationSlot(int, int, double)));

	/****plotWidget_2配置****/
	//统计线程直方图统计，这个速度有点卡
	connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_2->staticsThread, SLOT(staticsCellData(bool)));
	//还原窗口
	connect(ui.plotWidget_2, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//新添加设门窗口
	connect(ui.plotWidget_2, SIGNAL(addGateSignal(QWidget*)), this, SLOT(addGateSlot(QWidget*)));
	//通知荧光补偿窗口
	connect(m_compensationSettingsWidget, SIGNAL(compensation(int, int, double)), ui.plotWidget_2, SLOT(compensationSlot(int, int, double)));


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
	connect(reportTree, SIGNAL(viewGateWidget(QString)),this,SLOT(viewGateSlot(QString)));//显示设门窗口
	connect(reportTree, SIGNAL(willClose()), this, SLOT(closeReportSlot()));//关闭报告窗口
	connect(reportTree, SIGNAL(delGateWidget(QString)), this, SLOT(delGateSlot(QString)));//删除设门对应的窗口
	//connect(reportTree, SIGNAL(delGateWidget(QString)), this, SLOT(delGateSlot(QString)));//删除设门对应的窗口
	
	//初始化新实验名
	initExperimentName();
	
	//配置第一个plot用来实时显示散点图
	ui.plotWidget_1->setScatterMode(true);
	ui.plotWidget_1->setTitle("All-1");
	ui.plotWidget_1->setExperimentName(s_experimentName);//设置实验名
	ui.plotWidget_1->setCellEvents(0);//设置细胞数据
	
	//配置第二个直方图用来实时显示直方图
	ui.plotWidget_2->setBarStatisticsMode(true);
	ui.plotWidget_2->setTitle("All-2");
	ui.plotWidget_2->setExperimentName(s_experimentName);//设置实验名
	ui.plotWidget_2->setCellEvents(0);//设置细胞数据
	//先隐藏画布3和画布4，用来实时显示其他类型图
	//ui.plotWidget_3->setVisible(false);
	//ui.plotWidget_4->setVisible(false);

	
}

//全局所有画布数组
QList<QWidget*> ViewWidget::s_plotWidgetList;
//在gridLayout中的画布
QList<QWidget*> ViewWidget::m_gridPlotWidgetList;
//实验名
QString ViewWidget::s_experimentName;
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
	readCellThread->setGoOn(false);//停止真读循环，线程进入默认状态继续循环等待
	/****测试线程获取示波器数据****/
}
/**
* @brief 新建画布-新建按钮
*/
void ViewWidget::addNewPlotFromUi()
{
	addNewPlot();
}
/**
* @brief 新建画布-新加设门
*/
void ViewWidget::addNewPlotFromGate(PlotWidget* widget)
{
	addNewPlot(widget,true);//新增设门窗口
}
/**
* @brief 新建画布-会实时统计
*/
void ViewWidget::addNewPlot(PlotWidget* widget,bool addNew)
{
	

	int m = ui.gridLayout->count();
	PlotWidget* plotWidget_0 = 0;
	//如果新增设门指定窗口
	if (widget != 0)
	{
		plotWidget_0 = widget;
		plotWidget_0->setParent(ui.scrollAreaWidgetContents);

		//如果需要新增加，比如是设门
		if (addNew)
		{
			s_plotWidgetList.append(plotWidget_0);//全局数组添加该窗口
			//若只是查找指定的窗口，就不需要添加至全局数组，重复了。
			m_gridPlotWidgetList.append(plotWidget_0);//gridlayout中的所有数组
		}
		//若只是查找，判断一下窗口是否在里面，没有则加上
		if (!m_gridPlotWidgetList.contains(plotWidget_0))
			//若只是查找指定的窗口，就不需要添加至全局数组，重复了。
			m_gridPlotWidgetList.append(plotWidget_0);//gridlayout中的所有数组
		

	}
	//新增空白窗口
	else
	{
		plotWidget_0 = new PlotWidget(ui.scrollAreaWidgetContents);
		plotWidget_0->setTitle("空数据");

		m_gridPlotWidgetList.append(plotWidget_0);//gridlayout中的所有数组
		s_plotWidgetList.append(widget);//全局数组添加该窗口
	}

	plotWidget_0->setObjectName(QStringLiteral("plotWidget_0"));
	plotWidget_0->setCursor(QCursor(Qt::ArrowCursor));

	ui.gridLayout->addWidget(plotWidget_0);
	//QWidget* widget = m_gridPlotWidgetList.last();
	int row;
	int column;
	int rowSpan;
	int columnSpan;
	ui.gridLayout->getItemPosition(2, &row, &column, &rowSpan, &columnSpan);

	

	//统计线程-暂时不支持新建画布更新数据：2014-8-10
	//QObject::connect(readCellThread, SIGNAL(cellReadySignal(bool)), &plotWidget_0->staticsThread, SLOT(staticsCellData(bool)));
	//还原窗口
	connect(plotWidget_0, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//新添加设门窗口
	connect(plotWidget_0, SIGNAL(addGateSignal(QWidget*)), this, SLOT(addGateSlot(QWidget*)));

	clearPlotWidget();
	relayoutPlotWidget();

}

/**
* @brief 删除画布
*/
void ViewWidget::delPlot()
{

	/*QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setWindowTitle(tr("警告！"));
	msgBox.setText(tr("警告，您确定删除当前选中的画布吗？"));
	QPushButton *Button1 = msgBox.addButton(tr("确定"), QMessageBox::AcceptRole);
	QPushButton *Button2 = msgBox.addButton(tr("取消"), QMessageBox::RejectRole);
	msgBox.exec();

	if (msgBox.clickedButton() == Button1)
	{
		*/
	PlotWidget * plotWidget = 0;
		////在全局有效细胞数据中删除选中的画布
		//for (int i = 0; i < s_plotWidgetList.size(); i++)
		//{
		//	if (focusPlotWidget == s_plotWidgetList.at(i))
		//	{

		//		plotWidget = (PlotWidget*)s_plotWidgetList.takeAt(i);

		//	}
		//}



		//在grid中删除选中的画布
		for (int i = 0; i < m_gridPlotWidgetList.size(); i++)
		{
			if (focusPlotWidget == m_gridPlotWidgetList.at(i))
			{

				ui.gridLayout->removeWidget(focusPlotWidget);
				m_gridPlotWidgetList.takeAt(i);
				focusPlotWidget->setVisible(false);//隐藏即可
				PlotWidget* w = (PlotWidget*)focusPlotWidget;
				if (w->getTitle()=="空数据")
					delete w;//不应该删除，只需要从界面屏蔽即可，只有删除设门的时候，才能顺便删掉该窗口
				focusPlotWidget = 0;//选中的为空

			}
		}
		

	
		clearPlotWidget();//清空所有画布
		relayoutPlotWidget();//重新布局画布
	//}

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

	for (int i = 0; i < m_gridPlotWidgetList.size(); i++)
	{
		if (m_gridPlotWidgetList.at(i) == focusWidget())

		{
			focusPlotWidget = focusWidget();//当期plot控件
			//如果不是是根画图，允许删除
			if (i!=0&&i!=1)
				emit haveFocusPlotWidgetSignal(true);
			//否则不允许
			else
			{
				emit haveFocusPlotWidgetSignal(false);
			}
			return;
		}
	}
	focusPlotWidget = 0;//否则为空
	emit haveFocusPlotWidgetSignal(false);
}

/**
* @brief 清空所有画布
*/
void ViewWidget::clearPlotWidget()
{
	//清空所有画布
	for (int i = 0; i < m_gridPlotWidgetList.size(); i++)
	{
		ui.gridLayout->removeWidget(m_gridPlotWidgetList.at(i));
	}
}
/**
* @brief 重新布局画布
*/
void ViewWidget::relayoutPlotWidget()
{
	//重新布局画布
	for (int i = 0, row = 0, column = 0; i < m_gridPlotWidgetList.size(); i++)
	{
		if (column == 3)
		{
			column = 0;
			row++;
		}
		//恢复原尺寸，防止当最大化窗口的时候，缩放策略发生改变。
		QWidget* plotWidget = m_gridPlotWidgetList.at(i);
		//设置还原后窗口伸展策略
		QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
		plotWidget->setSizePolicy(sizePolicy);
		plotWidget->setMinimumSize(QSize(425, 434));
		plotWidget->setMaximumSize(QSize(425, 434));
		plotWidget->setFocusPolicy(Qt::StrongFocus);
		plotWidget->setAcceptDrops(false);
		
		ui.gridLayout->addWidget(plotWidget, row, column, 1, 1);
		column++;

	}
}
/**
* @brief 打开荧光补偿窗口
*/
void ViewWidget::openCompensationWindow(bool on)
{
	if (on)
		m_compensationSettingsWidget->show();
	else
		m_compensationSettingsWidget->hide();
}

void ViewWidget::timerEvent(QTimerEvent *event)
{
	//每个10ms更新一次
	if (event->timerId() == m_timerId)
	{
		
	}
}
/**
* @brief 新建实验
*/
void ViewWidget::newExpSlot()
{
	uninstall();
	//clearPlotWidget();


	////第一第二窗口清空数据
	//m_gridPlotWidgetList.append(ui.plotWidget_3);
	//m_gridPlotWidgetList.append(ui.plotWidget_4);
	////初始化全局有效细胞数据的plot窗口
	//s_plotWidgetList.append(ui.plotWidget_1);
	//s_plotWidgetList.append(ui.plotWidget_2)
}
/**
* @brief 注销界面，清空所有数据
*/
void ViewWidget::uninstall()
{
	PlotWidget* plotWidget = 0;
	//全局plotwidget，清空除了第一个和第二个的画布
	for (int i = 2; i < s_plotWidgetList.size(); /*i++*/)
	{
		s_plotWidgetList.removeLast();
	}
	initExperimentName();//重新初始化实验名
	ui.plotWidget_1->setExperimentName(s_experimentName);//设置实验名
	ui.plotWidget_1->setCellEvents(0);//设置细胞数据
	ui.plotWidget_1->unistall();//卸载该窗口，包括置所有设门为空状态

	ui.plotWidget_2->setExperimentName(s_experimentName);//设置实验名
	ui.plotWidget_2->setCellEvents(0);//设置细胞数据
	ui.plotWidget_2->unistall();//卸载该窗口，包括置所有设门为空状态
	

	//布局中，清除画布控件
	for (int i = 2; i < m_gridPlotWidgetList.size(); /*i++*/)
	{
		plotWidget = (PlotWidget*)m_gridPlotWidgetList.takeLast();
		delete plotWidget;
	}
	//置第一个画布的设门控件为空
	plotWidget = (PlotWidget*)s_plotWidgetList.at(0);
	if (plotWidget->d_rectPicker != 0)
	{
		delete plotWidget->d_rectPicker;
		plotWidget->d_rectPicker = 0;
	}
	if (plotWidget->d_parallelLinePicker_1 != 0)
	{
		delete plotWidget->d_parallelLinePicker_1;
		plotWidget->d_parallelLinePicker_1 = 0;
	}
	if (plotWidget->d_parallelLinePicker_2 != 0)
	{
		delete plotWidget->d_parallelLinePicker_2;
		plotWidget->d_parallelLinePicker_2 = 0;
	}
	plotWidget->parallelLineList.clear();
	if (plotWidget->d_crossPicker_1 != 0)
	{
		delete plotWidget->d_crossPicker_1;
		plotWidget->d_crossPicker_1 = 0;
	}
	if (plotWidget->d_crossPicker_2 != 0)
	{
		delete plotWidget->d_crossPicker_2;
		plotWidget->d_crossPicker_2 = 0;
	}
	plotWidget->crossPickerList.clear();
	if (plotWidget->d_ellipsePicker != 0)
	{
		delete plotWidget->d_ellipsePicker;
		plotWidget->d_ellipsePicker = 0;
	}
	if (plotWidget->d_polygonPicker != 0)
	{
		delete plotWidget->d_ellipsePicker;
		plotWidget->d_polygonPicker = 0;
	}
	//清除第一个窗口的设门窗口关系
	plotWidget->m_gateStorageList.clear();
	//清空画布数据，重新画图
	plotWidget->clearPlotSamples();
	
	//置第二个画布的设门控件为空
	plotWidget = (PlotWidget*)s_plotWidgetList.at(1);
	if (plotWidget->d_rectPicker != 0)
	{
		delete plotWidget->d_rectPicker;
		plotWidget->d_rectPicker = 0;
	}
	if (plotWidget->d_parallelLinePicker_1 != 0)
	{
		delete plotWidget->d_parallelLinePicker_1;
		plotWidget->d_parallelLinePicker_1 = 0;
	}
	if (plotWidget->d_parallelLinePicker_2 != 0)
	{
		delete plotWidget->d_parallelLinePicker_2;
		plotWidget->d_parallelLinePicker_2 = 0;
	}
	plotWidget->parallelLineList.clear();
	if (plotWidget->d_crossPicker_1 != 0)
	{
		delete plotWidget->d_crossPicker_1;
		plotWidget->d_crossPicker_1 = 0;
	}
	if (plotWidget->d_crossPicker_2 != 0)
	{
		delete plotWidget->d_crossPicker_2;
		plotWidget->d_crossPicker_2 = 0;
	}
	plotWidget->crossPickerList.clear();
	if (plotWidget->d_ellipsePicker != 0)
	{
		delete plotWidget->d_ellipsePicker;
		plotWidget->d_ellipsePicker = 0;
	}
	if (plotWidget->d_polygonPicker != 0)
	{
		delete plotWidget->d_ellipsePicker;
		plotWidget->d_polygonPicker = 0;
	}
	//清除第一个窗口的设门窗口关系
	plotWidget->m_gateStorageList.clear();
	//清空画布数据，重新画图
	plotWidget->clearPlotSamples();
	

	reportTree->updateReport();//更新报告界面
}
/**
* @brief 打开文件
*/
void ViewWidget::openExpFileSlot()
{
	QString file = "20140618_14.fcm";
	QString appDir = QCoreApplication::applicationDirPath();
	QDir dir1;
	QString absolutePath1 = dir1.absolutePath();
	QString canonicalPath1 = dir1.canonicalPath();
	dir1.setCurrent(appDir);
	QFileDialog *fd = new QFileDialog(this, tr("选择实验数据文件"), appDir+"/MatLabData", "");
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
* @brief 右键打开文件
*/
void ViewWidget::openExpFileFromRightSlot(QString fileName)
{
	readCellThread->setGoOn(false);//停止采集
	readCellThread->setFilePath(fileName);//传递文件名
	QStringList fileList = fileName.split(".");
	
	QString nameFilter = fileList.last();
	if (nameFilter == "usb"||nameFilter=="USB)")
		readCellThread->setOperate(ReadCellThread::Read_USB_FILE);//开始读取USB格式本地文件
	else if (nameFilter == "fcm" || nameFilter == "FCM" || nameFilter == "matlab" || nameFilter == "MATLAB")
		readCellThread->setOperate(ReadCellThread::Read_MatLab_FILE);//开始读取MatLab格式本地文件
	else if (nameFilter == "fcs" || nameFilter == "FCS")
		readCellThread->setOperate(ReadCellThread::Read_FCS_FILE);//开始读取FCS格式本地文件
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

	QString appDir = QCoreApplication::applicationDirPath();
	fd->setDirectory(appDir+"/MatLabData");
	QStringList nameFilters;
	nameFilters << "matlab files (*.fcm *.FCM *.matlab *.MATLAB)"
		<< "FCS files (*.fcs *.FCS)";
	/*nameFilters << "USB files (*.usb *.USB)"
		<< "matlab files (*.fcm *.FCM *.matlab *.MATLAB)"
		<< "FCS files (*.fcs *.FCS)";*/
	fd->setNameFilters(nameFilters);//设置文件类型过滤器

	QStringList fileNamesList;
	if (fd->exec() == QDialog::Accepted) // 取消则是：QDialog::Rejected
	{
		fileNamesList = fd->selectedFiles();
	}
	else{
		return;
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
/**
* @brief 新增加设门窗口槽函数
*/
void ViewWidget::addGateSlot(QWidget* widget)
{
	
	addNewPlotFromGate((PlotWidget*)widget);//界面布局上新添加该窗口
	reportTree->updateReport();//更新报告界面
	emit putColorSignal();//请求激活主界面着色按钮
}
/**
* @brief 显示指定的设门窗口
*/
void ViewWidget::viewGateSlot(QString gateName)
{
	PlotWidget* rootPlotWidget = (PlotWidget* )s_plotWidgetList.at(0);//散点图根节点窗口
	if (gateName == "All1")
	{
		addNewPlot(rootPlotWidget,false);//根目录加入界面布局
		rootPlotWidget->show();
		rootPlotWidget->setFocus(Qt::MouseFocusReason);
	}
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			addNewPlot(plotWidget, false);//加入界面布局
			plotWidget->show();
			plotWidget->setFocus(Qt::MouseFocusReason);
			return;
		}
		else
		{
			PlotWidget* plotWidget = findGate(gate, gateName);
			if (plotWidget != 0)
			{
				addNewPlot(plotWidget, false);//加入界面布局
				plotWidget->show();
				plotWidget->setFocus(Qt::MouseFocusReason);
			}

		}

	}
	//散点图的设门若是没搜到，继续搜直方图设门
	rootPlotWidget = (PlotWidget*)s_plotWidgetList.at(1);//直方图根节点窗口
	if (gateName == "All2")
	{
		addNewPlot(rootPlotWidget, false);//根目录加入界面布局
		rootPlotWidget->show();
		rootPlotWidget->setFocus(Qt::MouseFocusReason);
	}
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			addNewPlot(plotWidget, false);//加入界面布局
			plotWidget->show();
			plotWidget->setFocus(Qt::MouseFocusReason);
			return;
		}
		else
		{
			PlotWidget* plotWidget = findGate(gate, gateName);
			if (plotWidget != 0)
			{
				addNewPlot(plotWidget, false);//加入界面布局
				plotWidget->show();
				plotWidget->setFocus(Qt::MouseFocusReason);
			}
		}
	}


}

/**
* @brief 递归查找设门窗口
* @param GateStorage* gate 输入-输出参数
* @param QString gateName 输入参数
*/
PlotWidget* ViewWidget::findGate(GateStorage* gate, QString gateName)
{
	//遍历当前设门下面的所有设门
	PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();

	//欲找到的窗口
	PlotWidget* findPlotWidget = 0;
	for (int i = 0; i < plotWidget->m_gateStorageList.size(); i++)
	{
		//最新gate
		gate = plotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			findPlotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget

			return findPlotWidget;
		}
		else
		{
			//递归查询子设门
			findPlotWidget = findGate(gate, gateName);
			if (findPlotWidget != 0)
				return findPlotWidget;
		}
	}
	//没查到返回0
	return findPlotWidget;
	
}
/**
* @brief 关闭报告窗口槽函数
*/
void ViewWidget::closeReportSlot()
{
	emit reportTreeWidgetClose();
}
/**
* @brief 删除画布对应的窗口
*/
void ViewWidget::delGateSlot(QString gateName)
{
	PlotWidget* rootPlotWidget = (PlotWidget*)s_plotWidgetList.at(0);//散点图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{

		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			focusPlotWidget = plotWidget;//指定聚焦的画布窗口
			delPlot();//关闭窗口


			//在全局有效细胞数据中删除选中的画布
			s_plotWidgetList.removeOne(focusPlotWidget);
			delete plotWidget;//删除窗口，只有一次。
			plotWidget = 0;


			PlotWidget* parentWidget = (PlotWidget*)gate->getParentWidget();
			parentWidget->m_gateStorageList.removeOne(gate);//将父类窗口中的对应设门剔除
			delete gate;

			reportTree->updateReport();
			return;
		}
		else
		{
			//获得最新plotwidget和gate指针
			PlotWidget* plotWidget = findGate(gate, gateName);
			//递归查询到
			if (plotWidget != 0)
			{
				focusPlotWidget = plotWidget;//指定聚焦的画布窗口
				delPlot();//关闭窗口
				//在全局有效细胞数据中删除选中的画布
				s_plotWidgetList.removeOne(focusPlotWidget);
				delete plotWidget;//删除窗口，只有一次。
				plotWidget = 0;


				PlotWidget* parentWidget = (PlotWidget*)gate->getParentWidget();
				parentWidget->m_gateStorageList.removeOne(gate);//将父类窗口中的对应设门剔除
				delete gate;
				return;
				reportTree->updateReport();
			}
		}

	}
	//散点图的设门若是没搜到，继续搜直方图设门
	rootPlotWidget = (PlotWidget*)s_plotWidgetList.at(1);//直方图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			focusPlotWidget = plotWidget;//指定聚焦的画布窗口
			delPlot();//关闭窗口
			//在全局有效细胞数据中删除选中的画布
			s_plotWidgetList.removeOne(focusPlotWidget);
			delete plotWidget;//删除窗口，只有一次。
			plotWidget = 0;


			PlotWidget* parentWidget = (PlotWidget*)gate->getParentWidget();
			parentWidget->m_gateStorageList.removeOne(gate);//将父类窗口中的对应设门剔除
			delete gate;

			reportTree->updateReport();
			return;
		}
		else
		{
			//获得最新plotwidget和gate指针
			PlotWidget* plotWidget = findGate(gate, gateName);
			//递归查询到
			if (plotWidget != 0)
			{
				focusPlotWidget = plotWidget;//指定聚焦的画布窗口
				delPlot();//关闭窗口
				//在全局有效细胞数据中删除选中的画布
				s_plotWidgetList.removeOne(focusPlotWidget);
				delete plotWidget;//删除窗口，只有一次。
				plotWidget = 0;


				PlotWidget* parentWidget = (PlotWidget*)gate->getParentWidget();
				parentWidget->m_gateStorageList.removeOne(gate);//将父类窗口中的对应设门剔除
				delete gate;

				reportTree->updateReport();
				return;
			}

		}
	}

	
}

/**
* @brief 导出PDF文档
*/
void ViewWidget::savePdfSlot()
{
	QString appDir = QCoreApplication::applicationDirPath();
	
	if (m_fdPDF == 0)
		m_fdPDF = new QFileDialog(this);
	QDir currentDir = m_fdPDF->directory();
	QString m_pdfSavePath = currentDir.absolutePath();
	m_fdPDF->setWindowTitle(tr("保存为"));//设置文件保存对话框的标题
	m_fdPDF->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
	m_fdPDF->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
	m_fdPDF->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
	//还有另一种形式QFileDialog::List，这个只是把文件的文件名以列表的形式显示出来
	m_fdPDF->setGeometry(10, 30, 300, 200);//设置文件对话框的显示位置

	if (m_pdfSavePath!="")
		m_fdPDF->setDirectory(m_pdfSavePath);
	else
	{
		m_fdPDF->setDirectory(appDir+"/USBData");
	}


	QStringList nameFilters;
	nameFilters << "PDF files (*.pdf *.PDF)";
	m_fdPDF->setNameFilters(nameFilters);//设置文件类型过滤器

	QStringList fileNamesList;
	if (m_fdPDF->exec() == QDialog::Accepted) // 取消则是：QDialog::Rejected
	{
		fileNamesList = m_fdPDF->selectedFiles();
	}
	else{
		return;
	}


	QString fileName = fileNamesList.at(0).toLocal8Bit().constData();

	//图片生成pdf
	QPrinter printer(QPrinter::HighResolution);
	printer.setPageSize(QPrinter::A4);  //设置纸张大小为A4
	printer.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
	printer.setOutputFileName(fileName);   //设置输出路径

	QPainter painter;
	QBrush brush(QColor("#000000"), Qt::SolidPattern);//颜色黑色，实体线
	painter.setBrush(brush);
	//黑体普通画笔
	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	pen.setBrush(brush);
	pen.setColor(QColor("#000000"));
	painter.setPen(pen);
	painter.setFont(QFont("Times", 10, QFont::Bold));//字体大小

	QPoint pointTemp(0, 200);//文字行距

	if (!painter.begin(&printer))// 打开文件失败
	{
		qWarning("打开文件失败，文件是否已经被占用？或者是否有写权限？");
	}
	//QRect rect = painterPixmap.viewport();//绘图的视图窗口尺寸
	//int multiple = rect.width() / pixmap.width();
	
	//将gridlayout中的画布都绘制在pdf上，排除最后第三个和第四个隐藏控件

	QPoint pointPainter(0,0);//绘画当前点
	painter.resetTransform();//恢复比例
	painter.setFont(QFont("Times", 20, QFont::Bold));//字体大小
	pointPainter.setX(pointPainter.x()*5+3000);
	pointPainter.setY(pointPainter.y()*5+100);
	painter.drawText(pointPainter, s_experimentName);
	pointPainter = pointPainter + pointTemp;

	painter.setFont(QFont("Times", 10, QFont::Light));//字体大小
	painter.scale(5, 5); //将图像(所有要画的东西)在pdf上放大5倍
	pointPainter.setX(pointPainter.x() / 5);
	pointPainter.setY(pointPainter.y() / 5);
	for (int i = 0; i < m_gridPlotWidgetList.size(); i++)
	{
		PlotWidget* plotWidget = (PlotWidget*) m_gridPlotWidgetList.at(i);
		QPixmap pixmap = QPixmap::grabWidget(plotWidget, plotWidget->rect());  //获取界面的图片
		pointPainter.setX(50 + i % 3 * 600);//每行三个图，每个图间距600，页边左起50
		pointPainter.setY(150+ i / 3 * 500);//每行三个图，页边上距50
		painter.drawPixmap(pointPainter.x(), pointPainter.y(), pixmap);  //画图
		
	}
	//焦点下移一个画布高度+10
	pointPainter.setX(50);
	pointPainter.setY(pointPainter.y()+500 + 10);

	//设置直线画笔颜色
	QPen pen1;
	pen1.setStyle(Qt::SolidLine);
	pen1.setWidth(5);
	pen1.setBrush(brush);
	pen1.setColor(QColor("#CFCFCF"));
	painter.setPen(pen1);
	//绘画一根直线
	painter.drawLine(pointPainter, pointPainter+QPoint(1500, 0));

	//下移50个像素
	pointPainter = pointPainter+QPoint(0,50);
	//绘画文字

	
	QString experiementName = QString("Experiment Name: %1").arg(s_experimentName);
	QString specimenName =    QString("Specimen Name:   Specimen_001");
	QString tubeName =        QString("Tube Name:       eight2013");
	QString recordDate =      QString("Record Date:     Dec 12,2013 10:08:50 AM");
	QString op =              QString("$OP:             Administrator");
	QString guid =            QString("GUID:            244042b1-914d-4c84-a86f-59dc04ceecc9");
	
	painter.resetTransform();//恢复坐标比例,当前坐标也得扩大5倍
	pointPainter.setX(pointPainter.x()* 5);
	pointPainter.setY(pointPainter.y()*5);
	
	painter.setPen(pen);//黑笔
	
	painter.drawText(pointPainter, experiementName);
	pointPainter = pointPainter + pointTemp;
	painter.drawText(pointPainter, specimenName);
	pointPainter = pointPainter + pointTemp;
	painter.drawText(pointPainter, tubeName);
	pointPainter = pointPainter + pointTemp;
	painter.drawText(pointPainter, recordDate);
	pointPainter = pointPainter + pointTemp;
	painter.drawText(pointPainter, op);
	pointPainter = pointPainter + pointTemp;
	painter.drawText(pointPainter, guid);
	pointPainter = pointPainter + pointTemp;



	painter.scale(10, 10); //将图像(所有要画的东西)在pdf上放大5倍
	pointPainter.setX(pointPainter.x() / 10);//当前绘图坐标缩小5倍，才能保证间距
	pointPainter.setY(pointPainter.y() / 10);

	QTreeWidget* treeWidgetPdf = reportTree->getTreeWidgetPdf();
	QPixmap pixmap1 = QPixmap::grabWidget(treeWidgetPdf, treeWidgetPdf->contentsRect());  //获取界面的图片
	painter.drawPixmap(pointPainter.x(), pointPainter.y(), pixmap1);  //画图
	painter.end();

	

}
/**
* @brief 初始化新实验名
*/
void ViewWidget::initExperimentName()
{
	s_experimentName = QString("[Experiment %1]").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
}
/**
* @brief 进行设门着色
*/
void ViewWidget::putGateColor()
{
	//手动更新两个根节点的设门着色
	ui.plotWidget_1->updateGateColorSample(ui.plotWidget_1);
	ui.plotWidget_2->updateGateColorSample(ui.plotWidget_2);

}