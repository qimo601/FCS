﻿#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "ui_testwidget.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include "Ui/Library/PropertyWidget.h"
#include <QPoint>
#include <QPropertyAnimation>
#include <QPaintEvent>
class TestWidget : public QWidget
{
	Q_OBJECT

public:
	TestWidget(QWidget *parent = 0);
	~TestWidget();
public slots:

	void on_pushButton1234_clicked();
protected:
	virtual void resizeEvent(QResizeEvent * event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void paintEvent(QPaintEvent *);
private:
	Ui::TestWidget ui;

};

#endif // TESTWIDGET_H
