/**
* 项    目:  FCS软件
* 文件名称:   DropShadowWidget.h
* 文件路径：  Ui/Library/DropShadowWidget.h
* 摘    要:  主窗口父类
* 作    者： 刘兆邦
* 日    期： 2014年04月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef DROPSHADOWWIDGET_H
#define DROPSHADOWWIDGET_H

#include <QDialog>
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

class DropShadowWidget : public QWidget
{
	Q_OBJECT

public:

	explicit DropShadowWidget(QWidget *parent = 0);
	~DropShadowWidget();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:

	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键

};

#endif //DROPSHADOWWIDGET_H