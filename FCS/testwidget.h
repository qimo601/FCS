#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "ui_testwidget.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include "Ui/Library/PropertyWidget.h"
#include <QPoint>
#include <QPropertyAnimation>
class TestWidget : public QWidget
{
	Q_OBJECT

public:
	TestWidget(QWidget *parent = 0);
	~TestWidget();
public slots:

	void on_pushButton123_clicked();
protected:
	virtual void resizeEvent(QResizeEvent * event);
	virtual void mouseMoveEvent(QMouseEvent* event);
private:
	Ui::TestWidget ui;
	QPoint mouseEventPos;
	QPoint mouseEventGlobalPos;
	QPoint cursorPos;
	QPoint mapToGlobalpos;
	PropertyWidget* propertyWidget;
	//属性窗口出现动画
	QPropertyAnimation* showPropertyAnimation;

};

#endif // TESTWIDGET_H
