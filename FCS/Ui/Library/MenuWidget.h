/**
* ��    Ŀ:  FCS���
* �ļ�����:   MenuWidget.h
* �ļ�·����  Ui/Libary/MenuWidget.h
* ժ    Ҫ:  �˵�����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��03��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "ui_MenuWidget.h"

class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = 0);
	~MenuWidget();
public slots:
	/**
	* @brief ��ʵ���ļ�
	*/
	void openExpFile();
signals:
	void openExpFileSignal();//��ʵ���ļ��ź�
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::MenuWidget ui;
};

#endif // MENUWIDGET_H
