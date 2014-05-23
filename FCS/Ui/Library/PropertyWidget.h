#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include "ui_PropertyWidget.h"

class PropertyWidget : public QWidget
{
	Q_OBJECT
public:
	PropertyWidget(QWidget *parent = 0);
	~PropertyWidget();
	public slots:
	void on_pushButton1_clicked();
private:
	Ui::PropertyWidget ui;
	QPropertyAnimation* animation;
	QPropertyAnimation* animation1;
};

#endif // PROPERTYWIDGET_H
