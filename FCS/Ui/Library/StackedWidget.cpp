#include "StackedWidget.h"

#include "Vo/VoCmd.h"
#include "Vo/VoLaser.h"
#include "Vo/VoFluid.h"
#include "Vo/VoSample.h"
#include "Vo/VoChannelBias.h"
#include "Vo/VoTrigger.h"
StackedWidget::StackedWidget(QWidget *parent)
	: QStackedWidget(parent)
{
	ui.setupUi(this);
	
	init();//初始化
	connect(this, SIGNAL(openExpFileSignal()), ui.celllViewWidget, SLOT(openExpFileSlot()));//打开实验文件
	connect(this, SIGNAL(saveExpFileSignal()), ui.celllViewWidget, SLOT(saveExpFileSlot()));//保存实验文件
	//报告
	connect(ui.reportBtn, SIGNAL(toggled(bool)), this, SLOT(showReport(bool)));
	//测试用-先隐藏报告界面
	//ui.reportWidget->setVisible(false);
}

StackedWidget::~StackedWidget()
{
	delete oscWidgetPage;
}
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
	//将示波器窗口加入显示队列
	oscWidgetPage = new OscWidget();
	ui.viewStackedWidget->addWidget(oscWidgetPage);

	//初始化通道默认数值
	ui.passageComboBox->addItem("通道1", (int)1);
	ui.passageComboBox->addItem("通道2", (int)2);
	ui.passageComboBox->addItem("通道3", (int)3);
	ui.passageComboBox->addItem("通道4", (int)4);
	ui.passageComboBox->addItem("通道5", (int)5);
	ui.passageComboBox->addItem("通道6", (int)6);
	ui.passageComboBox->addItem("通道7", (int)7);
	ui.passageComboBox->addItem("通道8", (int)8);
	ui.passageComboBox->setCurrentIndex(2);//默认通道3

	//默认中等速度
	ui.midRadioButton->setChecked(true);
	ui.midRadioButton->clicked();

	//初始化采集控制业务
	bllControl = new BllControl();
	//connect(oscWidgetPage, SIGNAL(startOscAcq()), this, SLOT(sendCmd()));

	//开始采集和停止采集
	connect(ui.startAcquisitionBtn, SIGNAL(clicked()), ui.celllViewWidget, SLOT(startAcqSlot()));
	connect(ui.stopAcquisitionBtn, SIGNAL(clicked()), ui.celllViewWidget, SLOT(stopAcqSlot()));



	createActions();//创建Action
	createToolBars();//创建工具栏
	
}
/**
* @brief 示波器显示处理槽函数
*/
void StackedWidget::oscHandle()
{
	ui.viewStackedWidget->setCurrentWidget(oscWidgetPage);
	ui.bottomFrame->setEnabled(false);//屏蔽正常采集功能


}
/**
* @brief 数据分析与报告处理
*/
void StackedWidget::dataAnalyHandle()
{
	ui.viewStackedWidget->setCurrentWidget(ui.dataAnalyPage);
	ui.bottomFrame->setEnabled(true);//开启正常采集功能

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
* @brief 设置激光强度
*/
void StackedWidget::on_setLaserBtn_clicked()
{
	int passage = ui.passageComboBox->currentData().toInt();
	int strength = ui.strengthSpin->value();
	VoLaser vo;
	vo.setCmd(1);
	vo.setLength(2);
	vo.setPassage(passage);
	vo.setStrength(strength);
	bllControl->setLaser(vo);
}
/**
* @brief 设置鞘液
*/
void StackedWidget::on_setFluidBtn_clicked()
{
	int velocity = ui.fluidSpin->value();
	VoFluid vo;
	vo.setCmd(2);
	vo.setLength(2);
	vo.setVelocity(velocity);
	bllControl->setFluid(vo);
}
/**
* @brief 设置样品流
*/
void StackedWidget::on_setSampleBtn_clicked()
{
	int velocity = ui.sampleSpin->value();
	VoSample vo;
	vo.setCmd(3);
	vo.setLength(2);
	vo.setVelocity(velocity);
	bllControl->setSample(vo);
}
/**
* @brief 设置通道偏压
*/
void StackedWidget::on_setChannelBiasBtn_clicked()
{
	int passage = ui.passageComboBox->currentData().toInt();
	int voltage = ui.voltageSpin->value();
	VoChannelBias vo;
	vo.setCmd(4);
	vo.setLength(2);
	vo.setChannel(passage);
	vo.setVoltage(voltage);
	bllControl->setChannelBias(vo);

}

/**
* @brief 设置触发值
*/
void StackedWidget::on_setTriggerBtn_clicked()
{
	int trigger = ui.triggerSpin->value();
	int passage = ui.passageComboBox->currentData().toInt();
	VoTrigger vo;
	vo.setCmd(7);
	vo.setLength(4);
	vo.setChannel1(0);//暂时不支持
	vo.setChannel2(passage);
	vo.setTriggerValue(trigger);
	bllControl->setTrigger(vo);
}
/**
* @brief 打开USB设备
*/
void StackedWidget::on_openUsbBtn_clicked()
{
	bllControl->openUSBControl();
}
/**
* @brief 关闭USB设备
*/
void StackedWidget::on_closeUsbBtn_clicked()
{

	bllControl->closeUSBControl();
}
/**
* @brief 设置样品流速-中档
*/
void StackedWidget::on_midRadioButton_clicked()
{
	ui.sampleSpin->setValue(800);
}

/**
* @brief 设置样品流速-高档
*/
void StackedWidget::on_hightRadioButton_clicked()
{

	ui.sampleSpin->setValue(3000);
}

/**
* @brief 设置样品流速-低档
*/
void StackedWidget::on_lowRadioButton_clicked()
{

	ui.sampleSpin->setValue(100);
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
	//停止采集命令
	VoCmd voCmd;
	voCmd.setCmd(5);
	voCmd.setLength(0);
	bllControl->sendCmd(voCmd);
	ui.startAcquisitionBtn->setEnabled(false);
	ui.stopAcquisitionBtn->setEnabled(true);
}
/**
* @brief 下发停止采集命令
*/
void StackedWidget::on_stopAcquisitionBtn_clicked()
{
	//停止采集命令
	VoCmd voCmd;
	voCmd.setCmd(6);
	voCmd.setLength(0);
	bllControl->sendCmd(voCmd);

	ui.startAcquisitionBtn->setEnabled(true);
	ui.stopAcquisitionBtn->setEnabled(false);

	//关闭文件
	ui.saveCheckBox->setChecked(false);
	on_saveCheckBox_clicked();
}
/**
* @brief 新建plot
*/
void StackedWidget::on_newPlotBtn_clicked()
{
	ui.celllViewWidget->addNewPlot();
}
/**
* @brief 删除plot
*/
void StackedWidget::on_delPlotBtn_clicked()
{
	ui.celllViewWidget->delPlot();
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
void StackedWidget::on_saveCheckBox_clicked()
{
	//若是控制处选择保存
	if (ui.saveCheckBox->isChecked())
	{
		//细胞USB格式原始数据
		ReadCellThread::fileName = QString("OriFile_%1.usb").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd--HH-mm-ss"));
		QDir dir("../USBData");
		
		QString absolutePath = dir.absolutePath();
		if (!dir.exists())
			dir.mkdir(absolutePath);
		ReadCellThread::fileName = absolutePath +"/"+ ReadCellThread::fileName;
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
* @brief 报告按钮
*/
void StackedWidget::showReport(bool on)
{
	ui.celllViewWidget->showReport(on);
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

	newPlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/newPlot.png"), tr("&新建一个画布"), this);
	newPlotAct->setShortcut(QKeySequence(tr("Ctrl+N")));
	newPlotAct->setStatusTip(tr("新建一个画布"));
	connect(newPlotAct, SIGNAL(triggered()), this, SLOT(on_newPlotBtn_clicked()));

	delPlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/delPlot.png"), tr("&删除一个已有的画布"), this);
	delPlotAct->setShortcut(QKeySequence(tr("Ctrl+D")));
	delPlotAct->setStatusTip(tr("删除一个已有的画布"));
	connect(delPlotAct, SIGNAL(triggered()), this, SLOT(on_delPlotBtn_clicked()));

	savePlotAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/savePlot.png"), tr("&保存当前画布"), this);
	delPlotAct->setShortcut(QKeySequence(tr("Ctrl+S")));
	delPlotAct->setStatusTip(tr("保存当前画布"));
	connect(delPlotAct, SIGNAL(triggered()), this, SLOT(saveExpFileSlot()));


	reportAct = new QAction(QIcon(":/MainWindow/Resources/Images/MainWindow/Report.png"), tr("&显示/隐藏设门报告"), this);
	reportAct->setShortcut(QKeySequence(tr("Ctrl+R")));
	reportAct->setStatusTip(tr("显示/隐藏设门报告"));
	reportAct->setCheckable(true);//设置该按钮可选择
	connect(reportAct, SIGNAL(toggled(bool)), this, SLOT(showReport(bool)));

	delPlotAct->setEnabled(false);
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
	fileToolBar = new QToolBar(tr("File"), ui.toolBtnWidget);
	fileToolBar->addAction(newPlotAct);
	fileToolBar->addAction(delPlotAct);
	fileToolBar->addAction(savePlotAct);
	fileToolBar->addSeparator();
	fileToolBar->addAction(reportAct);
	ui.horizontalLayout_11->addWidget(fileToolBar);



	/*QToolBar* editToolBar = new QToolBar(tr("Edit"), ui.toolBtnWidget);
	
	editToolBar->addAction(reportAct);
	ui.horizontalLayout_11->addWidget(editToolBar);*/
}