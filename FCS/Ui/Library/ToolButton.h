/**
* 项    目:  FCS软件
* 文件名称:   ToolButton.h
* 文件路径：  Ui/Library/ToolButton.h
* 摘    要:  工具栏类
* 作    者： 刘兆邦
* 日    期： 2014年04月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef TOOlBUTTON_H
#define TOOlBUTTON_H

#include <QToolButton>
#include <QMouseEvent>
#include <QPainter>

class ToolButton : public QToolButton
{

public:

	explicit ToolButton(QString pic_name, QWidget *parent = 0);
	~ToolButton();
	void setMousePress(bool mouse_press);

protected:

	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	void painterInfo(int top_color, int middle_color, int bottom_color);

public:

	bool mouse_over; //鼠标是否移过
	bool mouse_press; //鼠标是否按下
};

#endif //TOOlBUTTON_H
