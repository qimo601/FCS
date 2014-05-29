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
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::MenuWidget ui;
};

#endif // MENUWIDGET_H
