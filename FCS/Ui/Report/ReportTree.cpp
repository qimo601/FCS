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
	//initReportData();//初始化数据
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
}

ReportTree::~ReportTree()
{


}
/**
* @brief 初始化报表数据
*/
void ReportTree::initReportData()
{
	

	//根节点的数据项
	QStringList itemStringlist;
	itemStringlist << "All EventS" <<"10000" << "100%" << "100%";
	QTreeWidgetItem * rootItem = new QTreeWidgetItem(ui.treeWidget, itemStringlist);
	QPixmap pixmap(10,10);//新建一个Pixmap图
	pixmap.fill(QColor(Qt::black));//填充色
	QIcon icon(pixmap);
	rootItem->setIcon(0, icon);//设置图标

	//根节点的孩子节点1
	QStringList leafStringList1;
	leafStringList1 << "Gate1" << "8000"<<"80%"<<"80%";
	QTreeWidgetItem *leafItem1 = new QTreeWidgetItem(rootItem, leafStringList1);
	pixmap.fill(QColor(Qt::red));
	leafItem1->setIcon(0, pixmap);
	//根节点的孩子节点2
	QStringList leafStringList2;
	leafStringList2 << "Gate2" << "4000" << "40%" << "40%";
	QTreeWidgetItem *leafItem2 = new QTreeWidgetItem(rootItem, leafStringList2);
	pixmap.fill(QColor(Qt::green));
	leafItem2->setIcon(0, pixmap);
	//根节点的孩子节点3
	QStringList leafStringList3;
	leafStringList3 << "Gate3" << "2000" << "20%" << "20%";
	QTreeWidgetItem *leafItem3 = new QTreeWidgetItem(rootItem, leafStringList3);
	pixmap.fill(QColor(Qt::blue));
	leafItem3->setIcon(0, pixmap);

	//节点3的孩子节点1_in_3
	QStringList leafStringList1_In_3;
	leafStringList1_In_3 << "Gate1_in_3" << "1000" << "50%" << "10%";
	QTreeWidgetItem *leafItem1_in_3 = new QTreeWidgetItem(leafItem3, leafStringList1_In_3);
	pixmap.fill(QColor(Qt::gray));
	leafItem1_in_3->setIcon(0, pixmap);
	//给节点3添加孩子节点
	leafItem3->addChild(leafItem1_in_3);


	//节点3的孩子节点2_in_3
	QStringList leafStringList2_In_3;
	leafStringList2_In_3 << "Gate2_in_3" << "500" << "40%" << "2%";
	QTreeWidgetItem *leafItem2_in_3 = new QTreeWidgetItem(leafItem3, leafStringList2_In_3);
	pixmap.fill(QColor(Qt::darkCyan));
	leafItem2_in_3->setIcon(0, pixmap);
	leafItem3->addChild(leafItem2_in_3);


	//给根节点添加孩子节点
	rootItem->addChild(leafItem1);
	rootItem->addChild(leafItem2);
	rootItem->addChild(leafItem3);
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
	for (int i = 0; i < ViewWidget::m_plotWidgetList.size(); i++)
	{
		if ( i ==0)
		{
			plotWidget = (PlotWidget*)ViewWidget::m_plotWidgetList.at(i);
			getTreeReport(plotWidget,i);
		}

		else if (i == 1)
		{
			plotWidget = (PlotWidget*)ViewWidget::m_plotWidgetList.at(i);
			getTreeReport(plotWidget,i);
		}
	}
	
	expandTreeReport(rootItem0);
	expandTreeReport(rootItem1);

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
			if (gateStorage->getAverageValue().at(0).at(0) == 0)
			{
				//计算所有的值，平均值，中间值和CV值
				childPlotWidget->computerAverageValue(averageValueList, midValueList, cvValueList);

				gateStorage->setAverageValue(averageValueList);
				gateStorage->setMidValue(midValueList);
				gateStorage->setCvValue(cvValueList);
			}

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
	//如果平均值不为空
	if (averageValueList.at(0).at(0)!= 0)
		averageValue = averageValueList.at(0).at(0);
	itemStringlist.append(QString::number(averageValue));
	//如果Mid值不为空
	if (midValueList.at(0).at(0) != 0)
		midValue = midValueList.at(0).at(0);
	itemStringlist.append(QString::number(midValue));
	//如果Cv值不为空
	if (cvValueList.at(0).at(0) != 0)
		cvValue = cvValueList.at(0).at(0);
	itemStringlist.append(QString("%1%").arg(cvValue * 100));

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
	//如果平均值不为空
	if (averageValueList.at(0).at(0) != 0)
		averageValue = averageValueList.at(0).at(0);
	leafStringList1.append(QString::number(averageValue));
	//如果Mid值不为空
	if (midValueList.at(0).at(0) != 0)
		midValue = midValueList.at(0).at(0);
	leafStringList1.append(QString::number(midValue));
	//如果Cv值不为空
	if (cvValueList.at(0).at(0) != 0)
		cvValue = cvValueList.at(0).at(0);
	leafStringList1.append(QString("%1%").arg(cvValue*100));
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
		ui.plotBtn->setEnabled(true);
		ui.delGateBtn->setEnabled(true);
	}
	else
	{
		ui.plotBtn->setEnabled(false);
		ui.delGateBtn->setEnabled(false);
	}

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