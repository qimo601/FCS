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
	void on_colorBtnProperty_clicked();
	void on_fileNameBtnProperty_clicked();
	void on_midMarkBtnProperty_clicked();
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::PropertyWidget ui;
	QPropertyAnimation* animation;
	QPropertyAnimation* animation1;
};

#endif // PROPERTYWIDGET_H
