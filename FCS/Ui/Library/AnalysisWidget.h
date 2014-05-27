#ifndef ANALYSISWIDGET_H
#define ANALYSISWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_AnalysisWidget.h"

class AnalysisWidget : public QWidget
{
	Q_OBJECT

public:
	AnalysisWidget(QWidget *parent = 0);
	~AnalysisWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::AnalysisWidget ui;
};

#endif // ANALYSISWIDGET_H
