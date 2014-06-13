#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ViewWidget.h"
#include "PlotWidget.h"
class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget *parent = 0);
	~ViewWidget();
public slots:
	/**
	* @brief 开始采集
	*/
	void startAcqSlot();
	/**
	* @brief 结束采集
	*/
	void stopAcqSlot();
protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseMoveEvent(QMouseEvent * e);
private:
	Ui::ViewWidget ui;
	//PlotWidget* plotWidget;
};

#endif // VIEWWIDGET_H
