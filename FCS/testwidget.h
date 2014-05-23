#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QMainWindow>
#include "ui_testwidget.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPoint>
class TestWidget : public QMainWindow
{
	Q_OBJECT

public:
	TestWidget(QWidget *parent = 0);
	~TestWidget();
public slots:

	void on_pushButton_clicked();
protected:
	void resizeEvent(QResizeEvent * event);
	void mouseMoveEvent(QMouseEvent* event);
private:
	Ui::TestWidget ui;
	QPoint mouseEventPos;
	QPoint mouseEventGlobalPos;
	QPoint cursorPos;
	QPoint mapToGlobal
};

#endif // TESTWIDGET_H
