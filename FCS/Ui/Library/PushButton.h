/**
* 项    目:  FCS软件
* 文件名称:   PushButton.h
* 文件路径：  Ui/Library/PushButton.h
* 摘    要:  按钮类
* 作    者： 刘兆邦
* 日    期： 2014年04月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef SYSTEMBUTTON_H
#define SYSTEMBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class PushButton : public QPushButton
{
	Q_OBJECT

public:

	explicit PushButton(QWidget *parent = 0);
	~PushButton();
	void setPicName(QString pic_name);

protected:

	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *);
	virtual void mouseMoveEvent(QMouseEvent *event);
private:

	//枚举按钮的几种状态
	enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
	ButtonStatus status;
	QString pic_name;

	int btn_width; //按钮宽度
	int btn_height; //按钮高度
	bool mouse_press; //按钮左键是否按下
};

#endif //SYSTEMBUTTON_H

