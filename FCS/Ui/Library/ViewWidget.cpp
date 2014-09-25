﻿#include "ViewWidget.h"
#include <QScrollBar>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
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
	readCellThread->quit();//线程离开exec循环
}
/**
* @brief 初始化
*/
void ViewWidget::init()
{
	//初始化当前焦点plot
	focusPlotWidget = 0;
	m_timerId = 0;//初始化
	this->setFocusPolicy(Qt::StrongFocus);


	
	//循环读取缓冲区
	connect(this, SIGNAL(startReadCellDataFromCircleBuffer()), readCellThread, SLOT(startReadCellDataFromCircleBuffer()));
	//读取本地文件--已经没用了
	connect(this, SIGNAL(openExpSignal(QString, bool)), readCellThread, SLOT(getCellDataFromFile(QString, bool)));
	/****线程读取细胞数据****/

	//初始化当前gridlayout中的plot数组
	plotWidgetList.append(ui.plotWidget_1);
	plotWidgetList.append(ui.plotWidget_2);
	plotWidgetList.append(ui.plotWidget_3);
	plotWidgetList.append(ui.plotWidget_4);
	//初始化全局有效细胞数据的plot窗口
	m_plotWidgetList.append(ui.plotWidget_1);
	m_plotWidgetList.append(ui.plotWidget_2);



	/****plotWidget_1配置****/
	//还原窗口
	connect(ui.plotWidget_1, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//新添加设门窗口
	connect(ui.plotWidget_1, SIGNAL(addGateSignal(QWidget*)), this, SLOT(addGateSlot(QWidget*)));
	//plotWidget_1统计线程
	connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_1->staticsThread, SLOT(staticsCellData(bool)));
	//plotWidget_1保存文件信号
	connect(this, SIGNAL(saveExpFileToPlotwigetSignal(QString, QString)), ui.plotWidget_1, SLOT(saveExpFileSlot(QString, QString)));


	/****plotWidget_2配置****/
	//统计线程直方图统计，这个速度有点卡
	connect(readCellThread, SIGNAL(cellReadySignal(bool)), &ui.plotWidget_2->staticsThread, SLOT(staticsCellData(bool)));
	//还原窗口
	connect(ui.plotWidget_2, SIGNAL(normalPlot()), this, SLOT(relayoutPlotWidget()));
	//新添加设门窗口
	connect(ui.plotWidget_2, SIGNAL(addGateSignal(QWidget*)), this, SLOT(addGateSlot(QWidget*)));


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
	//配置第一个plot用来实时显示散点图
	ui.plotWidget_1->setScatterMode(true);
	ui.plotWidget_1->setTitle("All1");
	//配置第二个直方图用来实时显示直方图
	ui.plotWidget_2->setBarStatisticsMode(true);
	ui.plotWidget_2->setTitle("All2");
	//先隐藏画布3和画布4，用来实时显示其他类型图
	ui.plotWidget_3->setVisible(false);
	ui.plotWidget_4->setVisible(false);
}

//全局所有画布数组
QList<QWidget*> ViewWidget::m_plotWidgetList;
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
	addNewPlot(widget);
}
/**
* @brief 新建画布-会实时统计
*/
void ViewWidget::addNewPlot(PlotWidget* widget)
{
	

	int m = ui.gridLayout->count();
	PlotWidget* plotWidget_0 = 0;
	//如果新增设门指定窗口
	if (widget != 0)
	{
		plotWidget_0 = widget;
		plotWidget_0->setParent(ui.scrollAreaWidgetContents);
	}
	//新增空白窗口
	else
	{
		plotWidget_0 = new PlotWidget(ui.scrollAreaWidgetContents);
		plotWidget_0->setTitle("空数据");

	}

	plotWidget_0->setObjectName(QStringLiteral("plotWidget_0"));
	plotWidget_0->setCursor(QCursor(Qt::ArrowCursor));

	ui.gridLayout->addWidget(plotWidget_0);
	//QWidget* widget = plotWidgetList.last();
	int row;
	int column;
	int rowSpan;
	int columnSpan;
	ui.gridLayout->getItemPosition(2, &row, &column, &rowSpan, &columnSpan);

	plotWidgetList.append(plotWidget_0);//gridlayout中的所有数组
	m_plotWidgetList.append(widget);//全局数组添加该窗口

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
		//在全局有效细胞数据中删除选中的画布
		for (int i = 0; i < m_plotWidgetList.size(); i++)
		{
			if (focusPlotWidget == m_plotWidgetList.at(i))
			{

				plotWidget = (PlotWidget*)m_plotWidgetList.takeAt(i);

			}
		}



		//在grid中删除选中的画布
		for (int i = 0; i < plotWidgetList.size(); i++)
		{
			if (focusPlotWidget == plotWidgetList.at(i))
			{

				ui.gridLayout->removeWidget(focusPlotWidget);
				plotWidgetList.takeAt(i);
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

	for (int i = 0; i < plotWidgetList.size(); i++)
	{
		if (plotWidgetList.at(i) == focusWidget())

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
* @brief 新建实验
*/
void ViewWidget::newExpSlot()
{
	uninstall();
	//clearPlotWidget();


	////第一第二窗口清空数据
	//plotWidgetList.append(ui.plotWidget_3);
	//plotWidgetList.append(ui.plotWidget_4);
	////初始化全局有效细胞数据的plot窗口
	//m_plotWidgetList.append(ui.plotWidget_1);
	//m_plotWidgetList.append(ui.plotWidget_2)
}
/**
* @brief 注销界面，清空所有数据
*/
void ViewWidget::uninstall()
{
	PlotWidget* plotWidget = 0;
	//全局plotwidget，清空除了第一个和第二个的画布
	for (int i = 2; i < m_plotWidgetList.size(); /*i++*/)
	{
		m_plotWidgetList.removeLast();
	}
	//布局中，清除画布控件
	for (int i = 2; i < plotWidgetList.size(); /*i++*/)
	{
		plotWidget = (PlotWidget*)plotWidgetList.takeLast();
		delete plotWidget;
	}
	//置第一个画布的设门控件为空
	plotWidget = (PlotWidget*)m_plotWidgetList.at(0);
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
	plotWidget = (PlotWidget*)m_plotWidgetList.at(1);
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
}
/**
* @brief 显示指定的设门窗口
*/
void ViewWidget::viewGateSlot(QString gateName)
{
	PlotWidget* rootPlotWidget = (PlotWidget* )m_plotWidgetList.at(0);//散点图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			addNewPlot(plotWidget);//加入界面布局
			plotWidget->show();
			plotWidget->setFocus(Qt::MouseFocusReason);
			return;
		}
		else
		{
			PlotWidget* plotWidget = findGate(gate, gateName);
			if (plotWidget != 0)
			{
				addNewPlot(plotWidget);//加入界面布局
				plotWidget->show();
				plotWidget->setFocus(Qt::MouseFocusReason);
			}

		}

	}
	//散点图的设门若是没搜到，继续搜直方图设门
	rootPlotWidget = (PlotWidget*)m_plotWidgetList.at(1);//直方图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			addNewPlot(plotWidget);//加入界面布局
			plotWidget->show();
			plotWidget->setFocus(Qt::MouseFocusReason);
			return;
		}
		else
		{
			PlotWidget* plotWidget = findGate(gate, gateName);
			if (plotWidget != 0)
			{
				addNewPlot(plotWidget);//加入界面布局
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
	for (int i = 0; i < plotWidget->m_gateStorageList.size(); i++)
	{
		//最新gate
		gate = plotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget

			return plotWidget;
		}
		else
		{
			//递归查询子设门
			findGate(gate,gateName);
		}
	}
	//没查到返回0
	return 0;
	
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
	PlotWidget* rootPlotWidget = (PlotWidget*)m_plotWidgetList.at(0);//散点图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{

		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			focusPlotWidget = plotWidget;//指定聚焦的画布窗口
			delPlot();//关闭窗口
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
	rootPlotWidget = (PlotWidget*)m_plotWidgetList.at(1);//直方图根节点窗口
	for (int i = 0; i < rootPlotWidget->m_gateStorageList.size(); i++)
	{
		GateStorage* gate = rootPlotWidget->m_gateStorageList.at(i);
		if (gate->getGateName() == gateName)
		{
			PlotWidget* plotWidget = (PlotWidget*)gate->getPlotWidget();//获得当前设门的widget
			focusPlotWidget = plotWidget;//指定聚焦的画布窗口
			delPlot();//关闭窗口
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
