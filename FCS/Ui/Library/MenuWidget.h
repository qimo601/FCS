/**
* 项    目:  FCS软件
* 文件名称:   MenuWidget.h
* 文件路径：  Ui/Libary/MenuWidget.h
* 摘    要:  菜单窗口
* 作    者： 刘兆邦
* 日    期： 2014年04月03日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
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
	* @brief 新建实验
	*/
	void newExp();
	/**
	* @brief 打开实验文件
	*/
	void openExpFile();
	/**
	* @brief 保存实验文件
	*/
	void saveExpFile();
signals:
	void newExpSignal();//新建实验信号
	void openExpFileSignal();//打开实验文件信号
	void saveExpFileSignal();//保存实验文件信号
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::MenuWidget ui;
};

#endif // MENUWIDGET_H
