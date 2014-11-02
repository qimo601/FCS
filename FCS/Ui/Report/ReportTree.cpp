#include "ReportTree.h"
#include "Ui/Library/ViewWidget.h"
#include <QMessageBox>
#include <QIcon>
ReportTree::ReportTree(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	rootItem0 = 0;//根节点
	currentItem0 = 0;//当前节点
	parentItem0 = 0;//父节点
	rootItem1 = 0;//根节点
	currentItem1 = 0;//当前节点
	parentItem1 = 0;//父节点
	initReportData();//初始化数据
	//隐藏原标题栏
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	//设置透明-窗体标题栏和控件不透明,背景透明  
	//setAttribute(Qt::WA_TranslucentBackground);
	//初始化为未按下鼠标左键
	mouse_press = false;
	//根节点的假设设门1
	gateStorageRoot1 = new GateStorage();
	//根节点的假设设门2
	gateStorageRoot2 = new GateStorage();

	//窗口关闭按钮
	ui.closeBtn->setPicName(":/sysButton/Resources/Images/SysButton/close");
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(close()));

	//显示设门的绘图按钮
	ui.plotBtn->setEnabled(false);
	ui.delGateBtn->setEnabled(false);
	connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(enablePlotBtn(QTreeWidgetItem*, int)));
	//内容窗口自适应
	ui.treeWidget->resizeColumnToContents(0);
	ui.treeWidget->resizeColumnToContents(1);
	ui.treeWidget->resizeColumnToContents(2);
	//初始化一下表
	updateReport();

	//读取报表显示参数
	QList<int> intList;
	//initReportSettings(intList);

}

ReportTree::~ReportTree()
{


}
/**
* @brief 初始化报表数据
*/
void ReportTree::initReportData()
{
	//隐藏某列，测试
	//ui.treeWidget->setColumnHidden(2, true);
	//ui.treeWidget->setColumnHidden(1, true);

	//初始化所有列标题

	m_stringListMap;
	QStringList passageSL;
	passageSL << "FSC" << "SSC" << "FL1" << "FL2" << "FL3" << "FL4" << "FL5" << "FL6";
	QStringList dataSL;
	dataSL << "H" << "A" << "W";

	//初始化不同通道不同参数的几个值
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			QStringList stringList4;
			stringList4 << passageSL.at(i) << dataSL.at(j) << "#Average";
			m_stringListMap.insert(4 + 3 * j + 3 * 3 * i, stringList4);
			QStringList stringList5;
			stringList5 << passageSL.at(i) << dataSL.at(j) << "#MidValue";
			m_stringListMap.insert(5 + 3 * j + 3 * 3 * i, stringList5);
			QStringList stringList6;
			stringList6 << passageSL.at(i) << dataSL.at(j) << "%CV";
			m_stringListMap.insert(6 + 3 * j + 3 * 3 * i, stringList6);
		}


	}

	//初始化前面几个值，并在QTreewidget上汇入，所有通道共用
	QTreeWidgetItem *treewidgetitem = ui.treeWidget->headerItem();
	treewidgetitem->setText(0, "Population");
	treewidgetitem->setText(1, "#Events");
	treewidgetitem->setText(2, "%Parent");
	treewidgetitem->setText(3, "%Total");
	for (int i = 0, j = 4; i < m_stringListMap.size(); i++, j++)
	{
		//"FSC-H\n#Events
		QStringList stringLt = m_stringListMap.value(j);
		treewidgetitem->setText(j, QString("%1-%2\n%3").arg(stringLt.at(0)).arg(stringLt.at(1)).arg(stringLt.at(2)));
	}

	////根节点的数据项
	//QStringList itemStringlist;
	//itemStringlist << "All EventS" <<"10000" << "100%" << "100%";
	//QTreeWidgetItem * rootItem = new QTreeWidgetItem(ui.treeWidget, itemStringlist);
	//QPixmap pixmap(10,10);//新建一个Pixmap图
	//pixmap.fill(QColor(Qt::black));//填充色
	//QIcon icon(pixmap);
	//rootItem->setIcon(0, icon);//设置图标

	////根节点的孩子节点1
	//QStringList leafStringList1;
	//leafStringList1 << "Gate1" << "8000"<<"80%"<<"80%";
	//QTreeWidgetItem *leafItem1 = new QTreeWidgetItem(rootItem, leafStringList1);
	//pixmap.fill(QColor(Qt::red));
	//leafItem1->setIcon(0, pixmap);
	////根节点的孩子节点2
	//QStringList leafStringList2;
	//leafStringList2 << "Gate2" << "4000" << "40%" << "40%";
	//QTreeWidgetItem *leafItem2 = new QTreeWidgetItem(rootItem, leafStringList2);
	//pixmap.fill(QColor(Qt::green));
	//leafItem2->setIcon(0, pixmap);
	////根节点的孩子节点3
	//QStringList leafStringList3;
	//leafStringList3 << "Gate3" << "2000" << "20%" << "20%";
	//QTreeWidgetItem *leafItem3 = new QTreeWidgetItem(rootItem, leafStringList3);
	//pixmap.fill(QColor(Qt::blue));
	//leafItem3->setIcon(0, pixmap);

	////节点3的孩子节点1_in_3
	//QStringList leafStringList1_In_3;
	//leafStringList1_In_3 << "Gate1_in_3" << "1000" << "50%" << "10%";
	//QTreeWidgetItem *leafItem1_in_3 = new QTreeWidgetItem(leafItem3, leafStringList1_In_3);
	//pixmap.fill(QColor(Qt::gray));
	//leafItem1_in_3->setIcon(0, pixmap);
	////给节点3添加孩子节点
	//leafItem3->addChild(leafItem1_in_3);


	////节点3的孩子节点2_in_3
	//QStringList leafStringList2_In_3;
	//leafStringList2_In_3 << "Gate2_in_3" << "500" << "40%" << "2%";
	//QTreeWidgetItem *leafItem2_in_3 = new QTreeWidgetItem(leafItem3, leafStringList2_In_3);
	//pixmap.fill(QColor(Qt::darkCyan));
	//leafItem2_in_3->setIcon(0, pixmap);
	//leafItem3->addChild(leafItem2_in_3);


	////给根节点添加孩子节点
	//rootItem->addChild(leafItem1);
	//rootItem->addChild(leafItem2);
	//rootItem->addChild(leafItem3);
}

void ReportTree::mousePressEvent(QMouseEvent *event)
{
	//只能是鼠标左键移动和改变大小
	if (event->button() == Qt::LeftButton)
	{
		if (event->y() > 33)//控制在标题栏内，才可以拖动窗口
		{
			event->ignore();
			return;
		}
		mouse_press = true;
	}

	//窗口移动距离
	move_point = event->globalPos() - pos();
}

void ReportTree::mouseReleaseEvent(QMouseEvent *)
{
	mouse_press = false;
}
void ReportTree::mouseMoveEvent(QMouseEvent *event)
{
	if (event->y() <= 33)//控制在标题栏内，才可以拖动窗口
	{
		setCursor(Qt::SizeAllCursor);
	}
	else
	{
		setCursor(Qt::ArrowCursor);
	}

	//移动窗口
	if (mouse_press)
	{
		QPoint move_pos = event->globalPos();
		move(move_pos - move_point);
	}
}
void ReportTree::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
/**
* @brief 刷新按钮
*/
void ReportTree::on_refreshBtn_clicked()
{
	updateReport();
}
/**
* @brief 更新报表显示参数
*/
void ReportTree::updatevisibleParams()
{
	//读取报表显示参数
	QList<int> notvisibleList;
	initReportSettings(notvisibleList);
	for (int i = 0; i < ui.treeWidget->columnCount(); i++)
	{
		//先恢复所有列参数显示
		ui.treeWidget->setColumnHidden(i,false);
	}
	for (int i = 0; i < notvisibleList.size(); i++)
	{
		//隐藏列参数
		ui.treeWidget->setColumnHidden(notvisibleList.at(i), true);
	}
}
/**
* @brief 刷新生成报告
*/
void ReportTree::updateReport()
{
	ui.treeWidget->clear();//清空所有旧的节点
	rootItem0 = 0;//根节点
	currentItem0 = 0;//当前节点
	parentItem0 = 0;//父节点
	rootItem1 = 0;//根节点
	currentItem1 = 0;//当前节点
	parentItem1 = 0;//父节点
	PlotWidget* plotWidget = 0;
	for (int i = 0; i < ViewWidget::s_plotWidgetList.size(); i++)
	{
		if ( i ==0)
		{
			plotWidget = (PlotWidget*)ViewWidget::s_plotWidgetList.at(i);
			getTreeReport(plotWidget,i);
		}

		else if (i == 1)
		{
			plotWidget = (PlotWidget*)ViewWidget::s_plotWidgetList.at(i);
			getTreeReport(plotWidget,i);
		}
	}
	
	expandTreeReport(rootItem0);
	expandTreeReport(rootItem1);
	//更新列显示参数
	updatevisibleParams();

}
/**
* @brief 展开所有节点
*/
void ReportTree::expandTreeReport(QTreeWidgetItem* rootItem)
{
	//ui.treeWidget->expandItem(rootItem0);
	//ui.treeWidget->expandItem(rootItem1);
	rootItem->setExpanded(true);
	for (int i = 0; i < rootItem->childCount(); i++)
	{
		QTreeWidgetItem* item = rootItem->child(i);
		expandTreeReport(item);
	}

}

/**
* @brief 获得窗口的所有设门报告
*/
void ReportTree::getTreeReport(PlotWidget* plotWidget,int i)
{
	//获取根目录
	getTreeRootReport(plotWidget, i);
	if (i == 0)
		getTreeChildReport(rootItem0, plotWidget, i);
	else if (i == 1)
		getTreeChildReport(rootItem1, plotWidget, i);

	
}
/**
* @brief 获得root报告
*/
void ReportTree::getTreeRootReport(PlotWidget* plotWidget,int i)
{
	GateStorage* gateStorageRoot = 0;
	//先计算根目录,假设根目录就是一个最大的设门,永远只有两个根目录
	
	if (i == 0)
		gateStorageRoot = gateStorageRoot1;
	else if (i==1)
		gateStorageRoot = gateStorageRoot2;

	gateStorageRoot->setGateName(plotWidget->getTitle());
	gateStorageRoot->setPlotWidget(plotWidget);
	double parentEvents = plotWidget->computerEvents();
	double totalEvents = bllDataCenter.getAllEvents();
	double events = plotWidget->computerEvents();
	gateStorageRoot->setEvents(events);

	double percentageParent = 0;
	if(parentEvents!=0)
		percentageParent = events / parentEvents;
	gateStorageRoot->setPercentageParent(percentageParent);
	double percentageTotal = 0;
	if (parentEvents != 0)
		percentageTotal = events / parentEvents;
	gateStorageRoot->setPercentageTotal(percentageTotal);
	QList<QList<double>> averageValueList;
	QList<QList<double>> midValueList;
	QList<QList<double>> cvValueList;
	
	/*******************************减少计算次数********************/
	//如果参数不为空，但值为0，也需要计算
	if (gateStorageRoot->getAverageValue().size() != 0)
	{
		//屏蔽这个if可以排除cv为NAN值，因为有些情况，没计算如下
		/*if (gateStorageRoot->getAverageValue().at(0).at(0) == 0)
		{*/
			//计算所有的值，平均值，中间值和CV值
			plotWidget->computerAverageValue(averageValueList, midValueList, cvValueList);

			gateStorageRoot->setAverageValue(averageValueList);
			gateStorageRoot->setMidValue(midValueList);
			gateStorageRoot->setCvValue(cvValueList);
		//}

	}
	//如果参数为空，需要计算
	else if(gateStorageRoot->getAverageValue().size() == 0)
	{
		//计算所有的值，平均值，中间值和CV值
		plotWidget->computerAverageValue(averageValueList, midValueList, cvValueList);

		gateStorageRoot->setAverageValue(averageValueList);
		gateStorageRoot->setMidValue(midValueList);
		gateStorageRoot->setCvValue(cvValueList);
	}

	if (i == 0)
		//插入根目录
		insertRootReport(rootItem0, gateStorageRoot);
	else if (i == 1)
		//插入根目录
		insertRootReport(rootItem1, gateStorageRoot);
}
/**
* @brief 获得Child报告-递归查询
*/
void ReportTree::getTreeChildReport(QTreeWidgetItem* currentItem, PlotWidget* parentPlotWidget, int i)
{
	
	//当前窗口所有设门
	for (int j = 0; j < parentPlotWidget->m_gateStorageList.size(); j++)
	{
		//轮训每个设门统计
		GateStorage* gateStorage = parentPlotWidget->m_gateStorageList.at(j);
		//每个设门对应的窗口
		PlotWidget* childPlotWidget = (PlotWidget*)gateStorage->getPlotWidget();
		double parentEvents = parentPlotWidget->computerEvents();
		double totalEvents = bllDataCenter.getAllEvents();
		double events = childPlotWidget->computerEvents();
		gateStorage->setEvents(events);

		double percentageParent = 0;
		if (parentEvents!=0)
			percentageParent = events / parentEvents;
		gateStorage->setPercentageParent(percentageParent);
		double percentageTotal = 0;
		if (totalEvents != 0)
			percentageTotal = events / totalEvents;
		gateStorage->setPercentageTotal(percentageTotal);

		QList<QList<double>> averageValueList;
		QList<QList<double>> midValueList;
		QList<QList<double>> cvValueList;


		/*******************************减少计算次数********************/
		//如果参数不为空，但值为0，也需要计算
		if (gateStorage->getAverageValue().size() != 0)
		{
			//屏蔽这个if可以排除cv为NAN值，因为有些情况，没计算如下
			/*if (gateStorage->getAverageValue().at(0).at(0) == 0)
			{*/
				//计算所有的值，平均值，中间值和CV值
				childPlotWidget->computerAverageValue(averageValueList, midValueList, cvValueList);

				gateStorage->setAverageValue(averageValueList);
				gateStorage->setMidValue(midValueList);
				gateStorage->setCvValue(cvValueList);
			//}

		}
		//如果参数为空，需要计算
		else if (gateStorage->getAverageValue().size() == 0)
		{
			//计算所有的值，平均值，中间值和CV值
			childPlotWidget->computerAverageValue(averageValueList, midValueList, cvValueList);

			gateStorage->setAverageValue(averageValueList);
			gateStorage->setMidValue(midValueList);
			gateStorage->setCvValue(cvValueList);
		}

		
		if (i == 0)

		{
			//获得父亲节点
			parentItem0 = currentItem;
			//插入孩子目录,获取当前节点
			insertChildReport(parentItem0, currentItem0, gateStorage);
			//查询新的节点的报告
			getTreeChildReport(currentItem0, childPlotWidget, i);
		}
		else if (i == 1)
		{
			//获得父亲节点
			parentItem1 = currentItem;
			//插入孩子目录,获取当前节点
			insertChildReport(parentItem1, currentItem1, gateStorage);
			//查询新的节点的报告
			getTreeChildReport(currentItem1, childPlotWidget, i);
		}

	}
	

	
}
/**
* @brief 添加根目录
*/
void ReportTree::insertRootReport(QTreeWidgetItem* &rootItem, GateStorage* gateStorage)
{
	//根节点的数据项
	QStringList itemStringlist;
	itemStringlist.append(gateStorage->getGateName());
	itemStringlist.append(QString::number(gateStorage->getEvents()));
	itemStringlist.append(QString::number(gateStorage->getPercentageParent()));
	itemStringlist.append(QString::number(gateStorage->getPercentageTotal()));
	//获取设门的计算参数
	QList<QList<double>> averageValueList = gateStorage->getAverageValue();
	QList<QList<double>> midValueList = gateStorage->getMidValue();
	QList<QList<double>> cvValueList = gateStorage->getCvValue();
	double averageValue = 0;
	double midValue = 0;
	double cvValue = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//如果平均值不为空
			if (averageValueList.at(i).at(j) != 0)
				averageValue = averageValueList.at(i).at(j);
			itemStringlist.append(QString::number(averageValue));
			//如果Mid值不为空
			if (midValueList.at(i).at(j) != 0)
				midValue = midValueList.at(i).at(j);
			itemStringlist.append(QString::number(midValue));
			//如果Cv值不为空
			if (cvValueList.at(i).at(j) != 0)
				cvValue = cvValueList.at(i).at(j);
			itemStringlist.append(QString("%1%").arg(cvValue * 100));
		}


	}
	//itemStringlist << gateStorage->getGateName() << QString::number(gateStorage->getEvents()) << QString::number(gateStorage->getPercentageParent()) << QString::number(gateStorage->getPercentageTotal()) << QString::number(gateStorage->getAverageValue()) << QString::number(gateStorage->getMidValue()) << QString::number(gateStorage->getCvValue());
	rootItem = new QTreeWidgetItem(ui.treeWidget, itemStringlist);
	QPixmap pixmap(10, 10);//新建一个Pixmap图
	pixmap.fill(QColor(Qt::black));//填充色
	QIcon icon(pixmap);
	rootItem->setIcon(0, icon);//设置图标
}
/**
* @brief 添加孩子目录
*/
void ReportTree::insertChildReport(QTreeWidgetItem* parentItem, QTreeWidgetItem* &currentItem, GateStorage* gateStorage)
{
	//根节点的孩子节点1
	QStringList leafStringList1;
	leafStringList1.append(gateStorage->getGateName());
	leafStringList1.append(QString::number(gateStorage->getEvents()));
	leafStringList1.append(QString::number(gateStorage->getPercentageParent()));
	leafStringList1.append(QString::number(gateStorage->getPercentageTotal()));


	//获取设门的计算参数
	QList<QList<double>> averageValueList = gateStorage->getAverageValue();
	QList<QList<double>> midValueList = gateStorage->getMidValue();
	QList<QList<double>> cvValueList = gateStorage->getCvValue();
	double averageValue = 0;
	double midValue = 0;
	double cvValue = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//如果平均值不为空
			if (averageValueList.at(i).at(j) != 0)
				averageValue = averageValueList.at(i).at(j);
			leafStringList1.append(QString::number(averageValue));
			//如果Mid值不为空
			if (midValueList.at(i).at(j) != 0)
				midValue = midValueList.at(i).at(j);
			leafStringList1.append(QString::number(midValue));
			//如果Cv值不为空
			if (cvValueList.at(i).at(j) != 0)
				cvValue = cvValueList.at(i).at(j);
			leafStringList1.append(QString("%1%").arg(cvValue * 100));
		}


	}
	//leafStringList1 << gateStorage->getGateName() << QString::number(gateStorage->getEvents()) << QString::number(gateStorage->getPercentageParent()) << QString::number(gateStorage->getPercentageTotal()) << QString::number(gateStorage->getAverageValue()) << QString::number(gateStorage->getMidValue()) << QString::number(gateStorage->getCvValue());
	
	currentItem = new QTreeWidgetItem(parentItem, leafStringList1);
	QPixmap pixmap(10, 10);//新建一个Pixmap图
	QColor color(qrand() % 255, qrand() % 255, qrand() % 255);
	pixmap.fill(color);
	currentItem->setIcon(0, pixmap);
}

/**
* @brief 显示设门对应的画布窗口
*/
void ReportTree::on_plotBtn_clicked()
{
	QTreeWidgetItem *treeItem = ui.treeWidget->currentItem();
	if (treeItem != 0)
	{

		QString gateName = treeItem->text(0);//获得当前tree节点第一个值，GateName
		emit viewGateWidget(gateName);
	}
}
/**
* @brief 删除该设门对应的窗口
*/
void ReportTree::on_delGateBtn_clicked()
{
	QTreeWidgetItem *treeItem = ui.treeWidget->currentItem();
	//根节点不可以删除
	if (treeItem == rootItem0 || treeItem == rootItem1)
	{
		int ret = QMessageBox::warning(this, tr("警告"),
			QString("不可以删除根节点！"),
			QMessageBox::Ok,
			QMessageBox::Ok);
		return;
	}

	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setWindowTitle(tr("警告！"));
	msgBox.setText(tr("警告，您确定删除当前选中的设门吗？"));
	QPushButton *Button1 = msgBox.addButton(tr("确定"), QMessageBox::AcceptRole);
	QPushButton *Button2 = msgBox.addButton(tr("取消"), QMessageBox::RejectRole);
	msgBox.exec();

	if (msgBox.clickedButton() == Button1)
	{
		if (treeItem != 0)
		{
			QString gateName = treeItem->text(0);//获得当前tree节点第一个值，GateName
			emit delGateWidget(gateName);
		}
	}
	
}
/**
* @brief 使能绘图按钮
*/
void ReportTree::enablePlotBtn(QTreeWidgetItem * item, int column)
{
	if (item != rootItem0&&item != rootItem1)

	{
		//根目录
		ui.delGateBtn->setEnabled(true);
	}
	else
	{
		ui.delGateBtn->setEnabled(false);
	}
	//可以显示画布
	ui.plotBtn->setEnabled(true);
}
/**
* @brief 关闭事件
*/
void ReportTree::closeEvent(QCloseEvent *event)
{
	ui.plotBtn->setEnabled(false);
	updateReport();
	event->accept();
	emit willClose();

	/*if (maybeSave()) {
		writeSettings();
		event->accept();
		}
		else {
		event->ignore();
		}*/
}
/**
* @brief 设置按钮
*/
void ReportTree::on_settingBtn_toggled(bool enable)
{
	if (enable)
	{
		ui.stackedWidget->setCurrentIndex(1);
		ui.refreshBtn->setEnabled(false);
		ui.plotBtn->setEnabled(false);
		ui.delGateBtn->setEnabled(false);
		ui.settingBtn->setText("返回");
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0);
		ui.refreshBtn->setEnabled(true);
		ui.plotBtn->setEnabled(false);
		ui.delGateBtn->setEnabled(false);
		ui.settingBtn->setText("设置");
	}
}

/**
* @brief 添加按钮
*/
void ReportTree::on_addBtn_clicked()
{
	QString passageCombox = ui.passageCombox->currentText();
	QString dataCombox = ui.dataCombox->currentText();
	QString valueCombox = ui.valueCombox->currentText();

	QTableWidgetItem* passageItem = new QTableWidgetItem(passageCombox);
	QTableWidgetItem* dataItem = new QTableWidgetItem(dataCombox);
	QTableWidgetItem* valueItem = new QTableWidgetItem(valueCombox);

	for (int i = 0; i < ui.tableWidget_2->rowCount(); i++)
	{
		QTableWidgetItem* passageItem1 = ui.tableWidget_2->item(i,0);
		QTableWidgetItem* dataItem1 = ui.tableWidget_2->item(i, 1);
		QTableWidgetItem* valueItem1 = ui.tableWidget_2->item(i, 2);
		if (passageItem1->text() == passageItem->text() && dataItem1->text() == dataItem->text() && valueItem1->text() == valueItem->text())
		{
			QMessageBox msgBox;
			msgBox.setText("已经存在该组参数.");
			msgBox.setInformativeText("参数已经存在，无需加入。");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.setIcon(QMessageBox::Critical);
			int ret = msgBox.exec();
			return;
		}

	}
	int m = ui.tableWidget_2->rowCount();
	ui.tableWidget_2->insertRow(m);
	ui.tableWidget_2->setItem(m, 0, passageItem);//m是从1开始，所以实际是m-1
	ui.tableWidget_2->setItem(m, 1, dataItem);
	ui.tableWidget_2->setItem(m, 2, valueItem);

	//更新显示列参数
	updateReportSettings();
}
/**
* @brief 删除按钮
*/
void ReportTree::on_delBtn_clicked()
{
	int index = ui.tableWidget_2->currentRow();

	if (index > 0)
		ui.tableWidget_2->removeRow(index);
	else
	{
		QMessageBox msgBox;
		msgBox.setText("请选择要删除的行。");
		msgBox.setInformativeText("未选中。");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		msgBox.setIcon(QMessageBox::Critical);
		int ret = msgBox.exec();
		return;
	}
	ui.tableWidget_2->update();
	//更新显示列参数
	updateReportSettings();
}


/**
* @brief 初始报告参数
* @param indexNotVisibleList 不需要显示的参数
*/
void ReportTree::initReportSettings(QList<int>& indexNotVisibleList)
{
	QStringList passageSL;
	passageSL << "FSC" << "SSC" << "FL1" << "FL2" << "FL3" << "FL4" << "FL5" << "FL6";
	QStringList dataSL;
	dataSL << "H" << "A" << "W";
	
	//清除所有参数，重新载入配置参数
	

	//清除所有参数，重新载入配置参数
	ui.tableWidget_2->clear();
	ui.tableWidget_2->clearContents();
	ui.tableWidget_2->setRowCount(0);
	ui.tableWidget_2->update();
	QTableWidgetItem *tablewidgetitem = new QTableWidgetItem("通道");
	ui.tableWidget_2->setHorizontalHeaderItem(0, tablewidgetitem);
	QTableWidgetItem *tablewidgetitem1 = new QTableWidgetItem("参数");
	ui.tableWidget_2->setHorizontalHeaderItem(1, tablewidgetitem1);
	QTableWidgetItem *tablewidgetitem2 = new QTableWidgetItem("值");
	ui.tableWidget_2->setHorizontalHeaderItem(2, tablewidgetitem2);
	//tablewidgetitem->setText("通道");
	//tablewidgetitem1->setText("参数");
	//tablewidgetitem2->setText("值");


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//读取存在的参数
			QString average = bllSettings.read("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("#Average")).toString();
			if (average == "0")//不要显示的参数
			{
				QStringList stringList;
				stringList<< passageSL.at(i) << dataSL.at(j) << "#Average";
				int index = m_stringListMap.key(stringList);
				indexNotVisibleList.append(index);//传递不可显示的序号
			}
			//"1"或者"-1"，表示都要显示的参数。"-1"是指没设置参数，读取为空
			else
			{
				QTableWidgetItem* passageItem = new QTableWidgetItem(passageSL.at(i));
				QTableWidgetItem* dataItem = new QTableWidgetItem(dataSL.at(j));
				QTableWidgetItem* valueItem = new QTableWidgetItem("#Average");

				int m = ui.tableWidget_2->rowCount();
				ui.tableWidget_2->insertRow(m);
				ui.tableWidget_2->setItem(m, 0, passageItem);//m是从1开始，所以实际是m-1
				ui.tableWidget_2->setItem(m, 1, dataItem);
				ui.tableWidget_2->setItem(m, 2, valueItem);
			}
			//读取存在的参数
			QString midValue = bllSettings.read("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("#MidValue")).toString();
			
			if (midValue == "0")
			{
				QStringList stringList;
				stringList << passageSL.at(i) << dataSL.at(j) << "#MidValue";
				int index = m_stringListMap.key(stringList);
				indexNotVisibleList.append(index);//传递不可显示的序号
			}
			//"1"或者"-1"，表示都要显示的参数。"-1"是指没设置参数，读取为空
			else
			{
				QTableWidgetItem* passageItem = new QTableWidgetItem(passageSL.at(i));
				QTableWidgetItem* dataItem = new QTableWidgetItem(dataSL.at(j));
				QTableWidgetItem* valueItem = new QTableWidgetItem("#MidValue");

				int m = ui.tableWidget_2->rowCount();
				ui.tableWidget_2->insertRow(m);
				ui.tableWidget_2->setItem(m, 0, passageItem);//m是从1开始，所以实际是m-1
				ui.tableWidget_2->setItem(m, 1, dataItem);
				ui.tableWidget_2->setItem(m, 2, valueItem);
			}
			//读取存在的参数
			QString cv =bllSettings.read("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("%CV")).toString();
			if (cv == "0")
			{
				QStringList stringList;
				stringList << passageSL.at(i) << dataSL.at(j) << "%CV";
				int index = m_stringListMap.key(stringList);
				indexNotVisibleList.append(index);//传递不可显示的序号
			}
			//"1"或者"-1"，表示都要显示的参数。"-1"是指没设置参数，读取为空
			else
			{
				QTableWidgetItem* passageItem = new QTableWidgetItem(passageSL.at(i));
				QTableWidgetItem* dataItem = new QTableWidgetItem(dataSL.at(j));
				QTableWidgetItem* valueItem = new QTableWidgetItem("%CV");

				int m = ui.tableWidget_2->rowCount();
				ui.tableWidget_2->insertRow(m);
				ui.tableWidget_2->setItem(m, 0, passageItem);//m是从1开始，所以实际是m-1
				ui.tableWidget_2->setItem(m, 1, dataItem);
				ui.tableWidget_2->setItem(m, 2, valueItem);
			}
		}


	}


}
/**
* @brief 更新报告参数
*/
void ReportTree::updateReportSettings()
{
	QStringList passageSL;
	passageSL << "FSC" << "SSC" << "FL1" << "FL2" << "FL3" << "FL4" << "FL5" << "FL6";
	QStringList dataSL;
	dataSL << "H" << "A" << "W";

	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//更新报告所有可显示参数为"0"
			bllSettings.update("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("#Average"), "0");
			bllSettings.update("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("#MidValue"), "0");
			bllSettings.update("ReportTree", QString("%1-%2\n%3").arg(passageSL.at(i)).arg(dataSL.at(j)).arg("%CV"), "0");
			
		}


	}
	int m = ui.tableWidget_2->rowCount();
	//更新最新参数，需要显示则为1
	for (int i = 0; i < ui.tableWidget_2->rowCount(); i++)
	{
		QTableWidgetItem* passageItem1 = ui.tableWidget_2->item(i, 0);
		QTableWidgetItem* dataItem1 = ui.tableWidget_2->item(i, 1);
		QTableWidgetItem* valueItem1 = ui.tableWidget_2->item(i, 2);
		//参数值为"1"，代表需要显示的项，read参数为"0"则表示不需要显示
		bllSettings.update("ReportTree", QString("%1-%2\n%3").arg(passageItem1->text()).arg(dataItem1->text()).arg(valueItem1->text()), "1");
	}

	//更新列显示参数
	updatevisibleParams();
	emit reportParamChanged();
}

/**
* @brief 返回可以打印的报表
*/
QTreeWidget* ReportTree::getTreeWidgetPdf()
{
	treeWidgetPdf = ui.treeWidget;
	return treeWidgetPdf;
}