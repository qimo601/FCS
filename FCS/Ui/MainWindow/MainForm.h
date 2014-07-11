/**
* ��    Ŀ:  FCS���
* �ļ�����:  MainForm.h
* �ļ�·���� Ui/MainForm.h
* ժ    Ҫ: ������
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��04��02��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ui_MainForm.h"
#include "Ui/Library/DropShadowWidget.h"
#include "Ui/Library/MTitleWidget.h"
#include "Ui/Library/common.h"
#include "Include/Global.h"
class MainForm : public DropShadowWidget
{
	Q_OBJECT

public:
	MainForm(QWidget *parent = 0);
	~MainForm();

	void resetGeometry(int x);


	/** 
	* @brief   ��ʼ��
	*
	* @author  Liuzhaobang
	* @date    2014-5-15
	*/
	void init();
public slots:
	void showMaxOrNormal();
	void showMin();
signals:
	void openExpFileSignal();//��ʵ���ļ�
	void saveExpFileSignal();//����ʵ���ļ�
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::MainForm ui;
	MTitleWidget* titleWidget;///������
	WidgetStatus widgetStatus;
};

#endif // MAINFORM_H
