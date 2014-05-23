/**
* 项    目:  FCS软件
* 文件名称:   MainMenu.h
* 文件路径：  Ui/Library/MainMenu.h
* 摘    要:  菜单类
* 作    者： 刘兆邦
* 日    期： 2014年04月18日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMenu>
#include <QDesktopServices>
#include <QUrl>
#include "common.h"

class MainMenu : public QMenu
{
	Q_OBJECT

public:

	explicit MainMenu(QWidget *parent = 0);
	void translateActions();

signals:

	void showSettingDialog();
	void showNewCharacter();
	void showAboutUs();

private slots:

	void showPage();

private:
	
	void createActions();

private:

	QAction *action_setting; //设置
	QAction *action_new_character; //新版特性
	QAction *action_check_update; //检查更新
	QAction *action_change_company; //切换为企业版
	QAction *action_help_online; //在线帮助
	QAction *action_platform_help; //论坛求助
	QAction *action_login_home; //360网站
	QAction *action_protect; //隐私保护
	QAction *action_about_us; //关于我们

};

#endif //MAINMENU_H
