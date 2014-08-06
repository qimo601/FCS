#include "ReportTree.h"
#include <QIcon>
ReportTree::ReportTree(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initReportData();//初始化数据
	
	//隐藏原标题栏
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	//设置透明-窗体标题栏和控件不透明,背景透明  
	//setAttribute(Qt::WA_TranslucentBackground);
	//初始化为未按下鼠标左键
	mouse_press = false;

	//窗口关闭按钮
	ui.closeBtn->setPicName(":/sysButton/Resources/Images/SysButton/close");
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(close()));
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
	QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui.treeWidget, itemStringlist);
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