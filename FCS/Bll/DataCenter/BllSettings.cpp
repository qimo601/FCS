#include "BllSettings.h"
#include <QCoreApplication>
BllSettings::BllSettings(QObject *parent)
	: QObject(parent)
{
	init();

	//QString value = read("bolg", "game").toString();
	//QString value1 = read("Game").toString();
}

BllSettings::~BllSettings()
{

}

QSettings* BllSettings::s_settings = 0;

/**
* @brief 初始化配置文件
*/
void BllSettings::init()
{
	QString dir = QCoreApplication::applicationDirPath();
	if (s_settings == 0)
	{
		//exe运行的当前目录
		s_settings = new QSettings(QString("%1/config.ini").arg(dir), QSettings::IniFormat);
	}
	
}

/**
* @brief 更新配置
* @param prefix 组名
* @param key 关键字
* @param value 参数值
*/
void BllSettings::update(QString prefix,QString key,QVariant value)
{
	s_settings->beginGroup(prefix);
	s_settings->setValue(key, value);
	s_settings->endGroup();
}
/**
* @brief 读取配置
* @param prefix 组名
* @param key 关键字
*/
QVariant BllSettings::read(QString prefix, QString key)
{
	QVariant var = s_settings->value(QString("%1/%2").arg(prefix).arg(key),"-1");
	return var;
}
/**
* @brief 读取配置
* @param 直接读取关键字的参数
*/
QVariant BllSettings::read(QString key)
{
	QVariant var = s_settings->value(key);
	return var;
}

/**
* @brief 卸载全局配置
*/
void BllSettings::uninstall()
{
	if (s_settings != 0)
	{
		delete s_settings;
	}
}