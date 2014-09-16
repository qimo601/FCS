/**
* 项    目:  FCS软件
* 文件名称:  BllSettings.h
* 文件路径： DataCenter/BllSettings.h
* 摘    要:  配置文件业务类
* 作    者： 刘兆邦
* 日    期： 2014年05月08日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef BLLSETTINGS_H
#define BLLSETTINGS_H

#include <QObject>

class BllSettings : public QObject
{
	Q_OBJECT

public:
	BllSettings(QObject *parent);
	~BllSettings();

private:
	
};

#endif // BLLSETTINGS_H
