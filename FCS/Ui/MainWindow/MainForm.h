/**
* 项    目:  FCS软件
* 文件名称:  MainForm.h
* 文件路径： Ui/MainForm.h
* 摘    要: 主窗口
* 作    者： 刘兆邦
* 日    期： 2014年04月02日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	* @brief   初始化
	*
	* @author  Liuzhaobang
	* @date    2014-5-15
	*/
	void init();
public slots:
	void showMaxOrNormal();
	void showMin();
signals:
	void openExpFileSignal();//打开实验文件
	void saveExpFileSignal();//保存实验文件
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::MainForm ui;
	MTitleWidget* titleWidget;///标题栏
	WidgetStatus widgetStatus;
};

#endif // MAINFORM_H
