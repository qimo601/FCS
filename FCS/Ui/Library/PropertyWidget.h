/**
* ��    Ŀ:  FCS���
* �ļ�����:   PropertyWidget.h
* �ļ�·����  Ui/Libary/PropertyWidget.h
* ժ    Ҫ:  ���Դ���
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��23��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
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
