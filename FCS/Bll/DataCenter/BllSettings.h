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
#include <QSettings>
class BllSettings : public QObject
{
	Q_OBJECT

	static QSettings* s_settings;
public:
	BllSettings(QObject *parent=0);
	~BllSettings();
public slots:
	/**
	* @brief 初始化配置文件
	*/
	void init();
	/**
	* @brief 更新配置
	* @param prefix 组名
	* @param key 关键字
	* @param value 参数值
	*/
	void update(QString prefix, QString key, QVariant value);
	/**
	* @brief 读取配置
	*/
	QVariant read(QString prefix, QString key);
	/**
	* @brief 读取配置
	*/
	QVariant read(QString key);
	/**
	* @brief 卸载全局配置
	*/
	static void uninstall();

private:
	
};

#endif // BLLSETTINGS_H
