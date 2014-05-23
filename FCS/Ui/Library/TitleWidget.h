/**
* 项    目:  FCS软件
* 文件名称:   TitleWidget.h
* 文件路径：  Ui/Library/TitleWidget.h
* 摘    要:  标题栏类
* 作    者： 刘兆邦
* 日    期： 2014年04月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/

#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QVBoxLayout>
#include "PushButton.h"
#include "ToolButton.h"
#include "MainMenu.h"

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
	void translateLanguage();

signals:

	void showSkin();
    void showMin();
	void showMainMenu();
	void closeWidget();
	void turnPage(int current_page);

public slots:

	void turnPage(QString current_page);

private:

    QPoint press_point;//鼠标按下去的点
    bool is_move;

	QLabel *version_title; //标题
	PushButton *medal_button; //勋章墙
    PushButton *skin_button; //换肤
    PushButton *main_menu_button; //主菜单
    PushButton *min_button; //最小化
    PushButton *feedback_button; //反馈意见
    PushButton *close_button; //关闭

	QLabel *safe_360_label;  //360安全卫士
	QLabel *safe_label;  //360安全卫士

	QList<ToolButton *> button_list;
};

#endif // TITLEWIDGET_H
