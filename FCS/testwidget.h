#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "ui_testwidget.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPoint>
class TestWidget : public QWidget
{
	Q_OBJECT

public:
	TestWidget(QWidget *parent = 0);
	~TestWidget();
public slots:

	void on_pushButton_clicked();
protected:
	virtual void resizeEvent(QResizeEvent * event);
	virtual void mouseMoveEvent(QMouseEvent* event);
private:
	Ui::TestWidget ui;
	QPoint mouseEventPos;
	QPoint mouseEventGlobalPos;
	QPoint cursorPos;
	QPoint mapToGlobalpos;
};

#endif // TESTWIDGET_H
