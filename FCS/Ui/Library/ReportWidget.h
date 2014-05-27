#ifndef REPORTWIDGET_H
#define REPORTWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_ReportWidget.h"

class ReportWidget : public QWidget
{
	Q_OBJECT

public:
	ReportWidget(QWidget *parent = 0);
	~ReportWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::ReportWidget ui;
};

#endif // REPORTWIDGET_H
