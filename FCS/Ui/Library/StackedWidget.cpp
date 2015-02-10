#include "StackedWidget.h"

#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
#include <qwt_plot_renderer.h>
#include <QTextStream>
#include <QTextDocument>
#include <QPrinter>
#include <QTextBlock>
#include <QPdfWriter>
#include <QFileDialog>
#include <QMessageBox>
StackedWidget::StackedWidget(QWidget *parent)
	: QStackedWidget(parent)
{
	ui.setupUi(this);
	
	init();//初始化
	connect(this, SIGNAL(newExpSignal()), ui.celllViewWidget, SLOT(newExpSlot()));//新建实验
	connect(this, SIGNAL(openExpFileSignal()), ui.celllViewWidget, SLOT(openExpFileSlot()));//打开实验文件
	connect(this, SIGNAL(saveExpFileSignal()), ui.celllViewWidget, SLOT(saveExpFileSlot()));//保存实验文件
	
	//设置删除画布按钮状态
	connect(ui.celllViewWidget, SIGNAL(haveFocusPlotWidgetSignal(bool)), this, SLOT(setDelPlotActSlot(bool)));
	//设置报告按钮状态
	connect(ui.celllViewWidget, SIGNAL(reportTreeWidgetClose()), this, SLOT(setCloseReportActSlot()));//保存实验文件

	//报告
	connect(ui.reportBtn, SIGNAL(toggled(bool)), this, SLOT(showReport(bool)));


	//刷新频率参数设置
	connect(ui.freqLineEdit, SIGNAL(m_keyPressed()), this, SLOT(setFreqLineEditKeyPressed()));//回车事件确定刷新频率的值
	connect(ui.freqLineEdit, SIGNAL(m_doubleClicked(LineEdit*)), this, SLOT(setFreqLineEditDoubleClicked()));//双击事件，更改值
	setFreqLineEditKeyPressed();//初始化一下控件状态和界面参数
	//清空频率参数设置
	connect(ui.clearLineEdit, SIGNAL(m_keyPressed()), this, SLOT(setClearLineEditKeyPressed()));//回车事件确定清空频率的值
	connect(ui.clearLineEdit, SIGNAL(m_doubleClicked(LineEdit*)), this, SLOT(setClearLineEditDoubleClicked()));//双击事件，更改值
	setClearLineEditKeyPressed();//初始化一下控件状态和界面参数

	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));

	//测试用-先隐藏报告界面
	//ui.reportWidget->setVisible(false);
	//连上USB
	ui.usbBtn->setChecked(true);
	//默认停止按钮不可用
	ui.stopAcquisitionBtn->setEnabled(false);

	//细胞个数
	m_timerEvents = new QTimer(this);
	m_cellEvents = 0;
	connect(m_timerEvents, SIGNAL(timeout()), this, SLOT(updateEvents()));


	//流量测试，暂时不实现
	ui.flowSpinBox->setEnabled(false);
	ui.flowCheckBox->setEnabled(false);
	//初始化进入数据分析界面
	dataAnalyHandle();
	//oscHandle();

}

StackedWidget::~StackedWidget()
{
	delete oscWidgetPage;
}
//静态变量：设门数组
QList<GateStorage> StackedWidget::gatingDataList;
void StackedWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
/**
* @brief 初始化
*/
void StackedWidget::init()
{
	m_menu = 0;

	//将示波器窗口加入显示队列
	oscWidgetPage = new OscWidget();
	ui.viewStackedWidget->addWidget(oscWidgetPage);

	

	//初始化采集控制业务
	bllControl = new BllControl();
	//connect(oscWidgetPage, SIGNAL(startOscAcq()), this, SLOT(sendCmd()));

	//开始采集和停止采集
	connect(ui.startAcquisitionBtn, SIGNAL(clicked()), ui.celllViewWidget, SLOT(startAcqSlot()));
	connect(ui.stopAcquisitionBtn, SIGNAL(clicked()), ui.celllViewWidget, SLOT(stopAcqSlot()));



	createActions();//创建Action
	createToolBars();//创建工具栏

	createTreeFileDir();//创建文件管理目录

	
}
/**
* @brief 示波器显示处理槽函数
*/
void StackedWidget::oscHandle()
{
	ui.viewStackedWidget->setCurrentWidget(oscWidgetPage);

	//leftFrame切换到数据采集
	ui.leftStackedWidget->setCurrentIndex(0);
	ui.bottomFrame->setVisible(false);//采集功能显示
	//ui.bottomFrame->setEnabled(true);//屏蔽正常采集功能

	ui.statusDockWidget->setVisible(true);//状态面板显示
	ui.controlDockWidget->setVisible(true);//控制面板显示
	ui.fileBrowserDockWidget->setVisible(false);//文件面板隐藏

}
/**
* @brief 数据分析与报告处理
*/
void StackedWidget::dataAnalyHandle()
{
	
	ui.viewStackedWidget->setCurrentWidget(ui.dataAnalyPage);
	//leftFrame切换到文件浏览
	ui.leftStackedWidget->setCurrentIndex(1);
	ui.bottomFrame->setVisible(false);//隐藏采集功能
	//ui.bottomFrame->setEnabled(true);//屏蔽正常采集功能
	ui.statusDockWidget->setVisible(false);//隐藏状态面板
	ui.controlDockWidget->setVisible(false);//隐藏控制面板
	ui.fileBrowserDockWidget->setVisible(true);//显示文件面板
}
/**
* @brief 细胞数据采集
*/
void StackedWidget::acqHandle()
{
	
	ui.viewStackedWidget->setCurrentWidget(ui.dataAnalyPage);

	//leftFrame切换到数据采集
	ui.leftStackedWidget->setCurrentIndex(0);
	//ui.bottomFrame->setEnabled(true);//开启正常采集功能
	ui.bottomFrame->setVisible(true);//显示采集功能
	ui.statusDockWidget->setVisible(true);//显示状态面板
	ui.controlDockWidget->setVisible(true);//显示控制面板
	
	ui.fileBrowserDockWidget->setVisible(false);//隐藏文件面板
}

/**
* @brief 测试下发命令
*/
void StackedWidget::on_loadCmdBtn_clicked()
{
	//开始采集命令
	VoCmd voCmd;
	voCmd.setCmd(8);
	//voCmd.setCmd(5);
	voCmd.setLength(2);
	bllControl->sendCmd(voCmd);

}

/**
* @brief 打开/关闭USB设备
*/
void StackedWidget::on_usbBtn_toggled(bool toggled)
{
	if (toggled)
	{
		bllControl->initUSBControl();
		ui.usbBtn->setIcon(QIcon(":/MainWindow/Resources/Images/MainWindow/usb_connected.png"));
	}

	else
	{
		bllControl->closeUSBControl();
		ui.usbBtn->setIcon(QIcon(":/MainWindow/Resources/Images/MainWindow/usb_disconnected.png"));
	}
}

/**
* @brief 下发命令
*/
void StackedWidget::sendCmd()
{
	//开始采集命令
	VoCmd voCmd;
	voCmd.setCmd(8);
	voCmd.setLength(0);
	bllControl->sendCmd(voCmd);
}
/**
* @brief 下发开始采集命令
*/
void StackedWidget::on_startAcquisitionBtn_clicked()
{
	//如果USB打开，可以启动采集
	if (ui.usbBtn->isChecked())
	{
		//初始化USB控制-启动监听线程
		//bllControl->initUSBControl();
		//初始化环形缓冲区大小
		//Global::initCCycleBuffer(Gobal_CircleBuffer_Size);
		//清空全局缓冲区
		Global::S_CCycleBuffer->clearBuffer();
		bllDataCenter.clearAllEvents();//清空细胞数据-20150206 防止计数出错
		//开始采集命令
		VoCmd voCmd;
		voCmd.setCmd(5);
		voCmd.setLength(0);
		/************USB驱动不能读空，所以每次停止采集，就停止读取了**********************/
		bllControl->startListening();//先开启监听
		bllControl->sendCmd(voCmd);//再开始采集
		/************************************************************************/
		ui.startAcquisitionBtn->setEnabled(false);
		ui.stopAcquisitionBtn->setEnabled(true);
		//开始计时
		if (ui.timeCheckBox->isChecked())
		{
			m_timer->start(1000);//1s一次
		}

		//开始计数
		if (ui.eventsCheckBox->isChecked())
		{
			m_timerEvents->start(10);//1s一次
		}
		//禁止继续设置停止条件
		ui.timeCheckBox->setEnabled(false);
		ui.eventsCheckBox->setEnabled(false);
		//ui.flowCheckBox->setEnabled(false);

	}
	else
		return;

	

}
/**
* @brief 下发停止采集命令
*/
void StackedWidget::on_stopAcquisitionBtn_clicked()
{
	//如果已经开启，才可以停
	if (!ui.startAcquisitionBtn->isEnabled())
	{
		//停止采集命令
		VoCmd voCmd;
		voCmd.setCmd(6);
		voCmd.setLength(0);

		/**********防止USB驱动读空，一直挂起，关闭不了驱动*****************/
		bllControl->stopListening();//先停止监听，
		bllControl->sendCmd(voCmd);//再停止下位机送数据


		//bool result = bllControl->resetDevice();//重置一下USB，清空USB缓存，关闭USB再打开
		//if (!result)
		//{
		//	int ret = QMessageBox::warning(this, tr("警告"),
		//		QString("停止采集后，无法重置USB！"),
		//		QMessageBox::Ok,
		//		QMessageBox::Ok);
		//}
		/**********防止USB驱动读空，一直挂起，关闭不了驱动*****************/


		ui.startAcquisitionBtn->setEnabled(true);
		ui.stopAcquisitionBtn->setEnabled(false);

		//关闭文件
		ui.saveCheckBox->setChecked(false);//通过该属性判断文件关闭否
		//ui.saveCheckBox->click();

		//停止计时
		if (ui.timeCheckBox->isChecked())
		{
			ui.timeCheckBox->setChecked(false);
			ui.timeSpinBox->setEnabled(true);
			m_timer->stop();

		}
		//停止计数
		if (ui.eventsCheckBox->isChecked())
		{
			ui.eventsCheckBox->setChecked(false);
			ui.eventsSpinBox->setEnabled(true);
			m_timerEvents->stop();

		}
		//关闭USB
		//bllControl->closeUSBControl();

		//允许继续设置停止条件
		ui.timeCheckBox->setEnabled(true);
		ui.eventsCheckBox->setEnabled(true);
		//ui.flowCheckBox->setEnabled(true);
	}
	else
		return;

}
/**
* @brief 新建plot
*/
void StackedWidget::on_newPlotBtn_clicked()
{
	ui.celllViewWidget->addNewPlotFromUi();//界面按钮新添加空白窗口
}
/**
* @brief 删除plot
*/
void StackedWidget::on_delPlotBtn_clicked()
{
	ui.celllViewWidget->delPlot();
}
/**
* @brief 新建实验
*/
void StackedWidget::newExpSlot()
{
	emit newExpSignal();
}
/**
* @brief 打开实验文件
*/
void StackedWidget::openExpFileSlot()
{
	emit openExpFileSignal();
}

/**
* @brief 保存实验文件
*/
void StackedWidget::saveExpFileSlot()
{
	emit saveExpFileSignal();
}
/**
* @brief 保存细胞数据
*/
void StackedWidget::on_saveCheckBox_toggled(bool checked)
{
	//若是控制处选择保存
	if (ui.saveCheckBox->isChecked())
	{
		//细胞USB格式原始数据
		ReadCellThread::fileName = QString("OriFile_%1.usb").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd--HH-mm-ss"));
		
		QString appDir = QCoreApplication::applicationDirPath();
		QDir dir(appDir);
		if (!dir.exists())
			dir.mkdir(appDir);
		ReadCellThread::fileName = appDir + "/" + ReadCellThread::fileName;
		ReadCellThread::projectFile = fopen(ReadCellThread::fileName.toLocal8Bit().data(), "ab+");
		ReadCellThread::saveTag = true;
	}
	else
	{
		ReadCellThread::saveTag = false;
		if (ReadCellThread::projectFile != 0)//如果文件打开状态，关闭文件
		{//关闭文件
			if (fclose(ReadCellThread::projectFile) != 0)
				qDebug() << "【StackedWidget】关闭文件失败，文件名：" << ReadCellThread::fileName;
			else
			{
				ReadCellThread::projectFile = 0;
			}
		}
	}
}

/**
* @brief 时间计时
*/
void StackedWidget::on_timeCheckBox_toggled(bool checked)
{
	if (checked)
	{
		m_timeCount = ui.timeSpinBox->value();
		ui.timeSpinBox->setEnabled(false);
	}
	else
	{
		ui.timeSpinBox->setEnabled(true);
	}
}

/**
* @brief 更新时间
*/
void StackedWidget::updateTime()
{
	
	m_timeCount--;
	ui.timeLCD->display(m_timeCount);
	if (m_timeCount <= 0)
	{
		ui.stopAcquisitionBtn->click();
		m_timeCount = 0;//计时清0
	}
}



/**
* @brief 细胞计数
*/
void StackedWidget::on_eventsCheckBox_toggled(bool checked)
{
	if (checked)
	{
		m_cellEvents = ui.eventsSpinBox->value();
		ui.eventsSpinBox->setEnabled(false);
	}
	else
	{
		ui.eventsSpinBox->setEnabled(true);
	}
}
/**
* @brief 更新细胞个数
*/
void StackedWidget::updateEvents()
{
	//细胞数目
	m_cellEvents = (qint32)bllDataCenter.getAllEvents();
	ui.eventsLCD->display(m_cellEvents);
	//如果超过上限，停止采集
	if (m_cellEvents >= ui.eventsSpinBox->value())
	{
		ui.stopAcquisitionBtn->click();
		m_cellEvents = 0;//计数清0
	}

}

/**
* @brief 流量统计
*/
void StackedWidget::on_flowCheckBox_clicked()
{
}
/**
* @brief 报告按钮
*/
void StackedWidget::showReport(bool on)
{
	ui.celllViewWidget->showReport(on);
}
/**
* @brief 导出PDF
*/
void StackedWidget::exportPDF()
{
	ui.celllViewWidget->savePdfSlot();
}
/**
* @brief 方格布局
*/
void StackedWidget::gridLayoutSlot()
{
	ui.celllViewWidget->relayoutPlotWidget();
}
/**
* @brief 荧光补偿
*/
void StackedWidget::showCompensationWidget(bool on)
{
	ui.celllViewWidget->openCompensationWindow(on);
}
/**
* @brief 设门着色
*/
void StackedWidget::putGateColorSlot(bool on)
{
	ui.celllViewWidget->putGateColor();
}

/**
* @brief 菜单Action
*/
void StackedWidget::createActions()
{
	//隐藏旧的按钮
	ui.newPlotBtn->setVisible(false);
	ui.delPlotBtn->setVisible(false);
	ui.savePlotBtn->setVisible(false);
	ui.reportBtn->setVisible(false);

	m_newExpAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/newExpoBtn.png"), tr("&新建实验"), this);
	m_newExpAct->setShortcut(QKeySequence(tr("Ctrl+E")));
	m_newExpAct->setStatusTip(tr("新建实验"));
	connect(m_newExpAct, SIGNAL(triggered()), ui.celllViewWidget, SLOT(newExpSlot()));


	m_newPlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/newPlot.png"), tr("&新建一个画布"), this);
	m_newPlotAct->setShortcut(QKeySequence(tr("Ctrl+N")));
	m_newPlotAct->setStatusTip(tr("新建一个画布"));
	connect(m_newPlotAct, SIGNAL(triggered()), this, SLOT(on_newPlotBtn_clicked()));

	m_delPlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/delPlot.png"), tr("&删除一个已有的画布"), this);
	m_delPlotAct->setShortcut(QKeySequence(tr("Ctrl+D")));
	m_delPlotAct->setStatusTip(tr("删除一个已有的画布"));
	connect(m_delPlotAct, SIGNAL(triggered()), this, SLOT(on_delPlotBtn_clicked()));

	m_savePlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/savePlot.png"), tr("&保存当前画布"), this);
	m_delPlotAct->setShortcut(QKeySequence(tr("Ctrl+S")));
	m_delPlotAct->setStatusTip(tr("保存当前画布"));
	connect(m_savePlotAct, SIGNAL(triggered()), this, SLOT(saveExpFileSlot()));


	m_reportAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/Report.png"), tr("&显示/隐藏设门报告"), this);
	m_reportAct->setShortcut(QKeySequence(tr("Ctrl+R")));
	m_reportAct->setStatusTip(tr("显示/隐藏设门报告"));
	m_reportAct->setCheckable(true);//设置该按钮可选择
	connect(m_reportAct, SIGNAL(toggled(bool)), this, SLOT(showReport(bool)));


	m_pdfAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/PdfBtn.png"), tr("&导出PDF"), this);
	m_pdfAct->setShortcut(QKeySequence(tr("Ctrl+P")));
	m_pdfAct->setStatusTip(tr("导出PDF"));
	connect(m_pdfAct, SIGNAL(triggered()), this, SLOT(exportPDF()));

	m_gridLayoutAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/gridLayout.png"), tr("&方格布局"), this);
	m_gridLayoutAct->setShortcut(QKeySequence(tr("Ctrl+G")));
	m_gridLayoutAct->setStatusTip(tr("方格布局"));
	connect(m_gridLayoutAct, SIGNAL(triggered()), this, SLOT(gridLayoutSlot()));



	m_compensationAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/Compensation.png"), tr("&荧光补偿"), this);
	m_compensationAct->setShortcut(QKeySequence(tr("Ctrl+B")));
	m_compensationAct->setStatusTip(tr("荧光补偿"));
	m_compensationAct->setCheckable(true);//设置该按钮可选择
	connect(m_compensationAct, SIGNAL(toggled(bool)), this, SLOT(showCompensationWidget(bool)));


	m_putColorAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/PutColor.png"), tr("&设门着色"), this);
	m_putColorAct->setShortcut(QKeySequence(tr("Ctrl+P")));
	m_putColorAct->setStatusTip(tr("设门着色"));
	m_putColorAct->setCheckable(true);//设置该按钮可选择
	connect(m_putColorAct, SIGNAL(toggled(bool)), this, SLOT(putGateColorSlot(bool)));
	//窗口设门事件，激活这个着色按钮
	connect(ui.celllViewWidget, SIGNAL(putColorSignal()), m_putColorAct, SLOT(toggle()));

	m_delPlotAct->setEnabled(false);
	//copyAct->setEnabled(false);
	//connect(textEdit, SIGNAL(copyAvailable(bool)),
	//	cutAct, SLOT(setEnabled(bool)));
	//connect(textEdit, SIGNAL(copyAvailable(bool)),
	//	copyAct, SLOT(setEnabled(bool)));
}
/**
* @brief 创建菜单
*/
void StackedWidget::createMenus()
{
	//fileMenu = menuBar()->addMenu(tr("&File"));
	//fileMenu->addAction(newAct);
	////! [28]
	//fileMenu->addAction(openAct);
	////! [28]
	//fileMenu->addAction(saveAct);
	////! [26]
	//fileMenu->addAction(saveAsAct);
	//fileMenu->addSeparator();
	//fileMenu->addAction(exitAct);

	//editMenu = menuBar()->addMenu(tr("&Edit"));
	//editMenu->addAction(cutAct);
	//editMenu->addAction(copyAct);
	//editMenu->addAction(pasteAct);

	//menuBar()->addSeparator();

	//helpMenu = menuBar()->addMenu(tr("&Help"));
	//helpMenu->addAction(aboutAct);
	//helpMenu->addAction(aboutQtAct);
}
/**
* @brief 创建工具栏
*/
void StackedWidget::createToolBars()
{
	m_fileToolBar = new QToolBar(tr("File"), ui.toolBtnWidget);
	m_fileToolBar->addAction(m_newExpAct);
	m_fileToolBar->addAction(m_newPlotAct);
	m_fileToolBar->addAction(m_delPlotAct);
	m_fileToolBar->addAction(m_savePlotAct);
	m_fileToolBar->addSeparator();
	m_fileToolBar->addAction(m_reportAct);
	m_fileToolBar->addAction(m_pdfAct);
	m_fileToolBar->addAction(m_gridLayoutAct);
	m_fileToolBar->addAction(m_compensationAct);
	m_fileToolBar->addAction(m_putColorAct);
	ui.horizontalLayout_11->addWidget(m_fileToolBar);



	/*QToolBar* editToolBar = new QToolBar(tr("Edit"), ui.toolBtnWidget);
	
	editToolBar->addAction(reportAct);
	ui.horizontalLayout_11->addWidget(editToolBar);*/
}
/**
* @brief 设置删除画布按钮状态
*/
void StackedWidget::setDelPlotActSlot(bool focus)
{
	if (focus)
		m_delPlotAct->setEnabled(true);
	else
		m_delPlotAct->setEnabled(false);
}
/**
* @brief创建文件管理目录
*/
void StackedWidget::createTreeFileDir()
{
	m_currentMatLabPath = QCoreApplication::applicationDirPath();

	QString currentMatLabPath = m_currentMatLabPath+"/MatLabData";
	model = new QFileSystemModel(this);//文件数据源
	model->setRootPath(currentMatLabPath);//数据源的根目录
	treeView = new QTreeView(ui.fileWidget);//设置view的显示空间
	treeView->setModel(model);//设置view的数据源
	treeView->setRootIndex(model->index(currentMatLabPath));//设置显示的第一层根目录

	treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	
	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
	treeView->setSizePolicy(sizePolicy);
	//treeView->setMinimumSize(QSize(640, 480));

	treeView->setAlternatingRowColors(true);//颜色交替
	treeView->setSelectionBehavior(QAbstractItemView::SelectRows);//选择行
	treeView->setSelectionMode(QAbstractItemView::SingleSelection);//选择单个
	treeView->setContextMenuPolicy(Qt::CustomContextMenu);//设置右键菜单类型
	connect(treeView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onCustomContextMenuRequested(const QPoint&)));

	QVBoxLayout* verticalLayout_10 = new QVBoxLayout(ui.fileWidget);//给这文件布局一下
	verticalLayout_10->setSpacing(6);
	verticalLayout_10->setContentsMargins(11, 11, 11, 11);
	verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));

	verticalLayout_10->addWidget(treeView);
//	treeView->setAnimated(false);
//	treeView->setIndentation(20);
//	treeView->setSortingEnabled(true);
//
//	treeView->setWindowTitle(QObject::tr("Dir View"));
//	treeView->resize(640, 480);
}
/**
* @brief 右键菜单
*/
void StackedWidget::onCustomContextMenuRequested(const QPoint& pos)
{
	if (m_menu)//保证同时只存在一个menu，及时释放内存  
	{
		delete m_menu;
		m_menu = 0;
	}
	QModelIndex index = treeView->currentIndex();
	QModelIndex parent = index.parent();
	QModelIndex indexCurrent = model->index(index.row(), 0, parent);
	m_fileName = model->data(indexCurrent).toString();
	m_fileName = model->rootPath() +"/"+m_fileName;

	
	m_menu = new QMenu(treeView);

	QAction *openAction = m_menu->addAction(QIcon(":/MainWindow/Resources/Images/MainWindow/Check_Black.png"),"打开");
	connect(openAction, SIGNAL(triggered(bool)),this, SLOT(oepnExpFileFromRight(bool)));
	m_menu->exec(QCursor::pos());//在当前鼠标位置显示 
}
/**
* @brief 右键菜单
*/
void StackedWidget::oepnExpFileFromRight(bool enable)
{
	QDir dir;
	if (!dir.exists(m_fileName))
	{
		int ret = QMessageBox::warning(this, tr("警告"),
			QString("无法打开该文件，磁盘中，找不到该文件。\n文件路径：%1").arg(m_fileName),
			QMessageBox::Ok,
			QMessageBox::Ok);
		return;
	}
	ui.celllViewWidget->openExpFileFromRightSlot(m_fileName);
}
/**
* @brief 打开文件目录
*/
void StackedWidget::on_openFileBtn_clicked()
{
	QDir dir1;
	QString absolutePath1 = dir1.absolutePath();
	QString canonicalPath1 = dir1.canonicalPath();

	QString appDir = QCoreApplication::applicationDirPath();
	dir1.setCurrent(appDir+"/MatLabData");
	QFileDialog *fd = new QFileDialog(this, tr("选择实验数据文件"), appDir + "/MatLabData", "");
	fd->setFileMode(QFileDialog::Directory);
	fd->setViewMode(QFileDialog::Detail);
	//QStringList nameFilters;
	//nameFilters << "matlab files (*.fcm *.FCM *.matlab *.MATLAB)"
	//	<< "USB files (*.usb *.USB)"
	//	<< "FCS files (*.fcs *.FCS)";

	//fd->setNameFilters(nameFilters);//设置文件类型过滤器
	QStringList fileNamesList;
	if (fd->exec() == QDialog::Accepted) // 取消则是：QDialog::Rejected
	{
		fileNamesList = fd->selectedFiles();
	}
	else{
		return;
	}
	QString fileName = fileNamesList.at(0).toLocal8Bit().constData();//用户选择的文件路径
	QDir dir = fd->directory();
	QString absolutePath = dir.absolutePath();
	QString canonicalPath = dir.canonicalPath();
	//m_currentMatLabPath = appDir + "/MatLabData";
	m_currentMatLabPath = fileName;//实际文件路径
	model->setRootPath(m_currentMatLabPath);

	treeView->setModel(model);//设置view的数据源
	treeView->setRootIndex(model->index(m_currentMatLabPath));//设置显示的第一层根目录

	treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
	treeView->setSizePolicy(sizePolicy);
	//treeView->setMinimumSize(QSize(640, 480));

}
/**
* @brief 设置报告按钮状态
*/
void StackedWidget::setCloseReportActSlot()
{
	m_reportAct->setChecked(false);
}
/**
* @brief 回车事件确定刷新频率的值
*/
void StackedWidget::setFreqLineEditKeyPressed()
{
	ui.freqLineEdit->setReadOnly(true);
	ui.freqLineEdit->setStyleSheet(" #freqLineEdit{\
								   	background-color: #a3a3a3; \
										color: #6b6b6b; \
											}");

	//设置细胞刷新频率
	int freq = ui.freqLineEdit->text().toInt();
	if (freq>0)
		bllDataCenter.setFreq(freq);
	ui.freqLabel->setText(QString("刷新频率:%1个/次").arg(freq*8));
}
/**
* @brief 双击事件，更改值
*/
void StackedWidget::setFreqLineEditDoubleClicked()
{
	ui.freqLineEdit->setReadOnly(false);
	ui.freqLineEdit->setStyleSheet("");
	ui.freqLineEdit->setFocus();
}
/**
* @brief 回车事件确定清空频率的值
*/
void StackedWidget::setClearLineEditKeyPressed()
{
	ui.clearLineEdit->setReadOnly(true);
	ui.clearLineEdit->setStyleSheet(" #clearLineEdit{\
										background-color: #a3a3a3; \
											color: #6b6b6b; \
										}");

	//设置细胞刷新频率
	int clear = ui.clearLineEdit->text().toInt();
	if (clear > 0)
		bllDataCenter.setClear(clear);
	ui.clearLabel->setText(QString("清空频率:%1个/次").arg(clear * 8));
}
/**
* @brief 双击事件，更改值
*/
void StackedWidget::setClearLineEditDoubleClicked()
{
	ui.clearLineEdit->setReadOnly(false);
	ui.clearLineEdit->setStyleSheet("");
	ui.clearLineEdit->setFocus();
}

