#include "ViewWidget.h"
#include <QScrollBar>
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

	//初始化当前焦点plot
	focusPlotWidget = 0;

	this->setFocusPolicy(Qt::StrongFocus);

}

ViewWidget::~ViewWidget()
{

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

	ui.plotWidget_1->startAcqTimer();
}
/**
* @brief 结束采集
*/
void ViewWidget::stopAcqSlot()
{
	ui.plotWidget_1->stopAcqTimer();
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