#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ViewWidget.h"

class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(QWidget *parent = 0);
	~ViewWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::ViewWidget ui;
};

#endif // VIEWWIDGET_H
