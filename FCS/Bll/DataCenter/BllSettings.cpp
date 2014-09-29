#include "BllSettings.h"
#include <QCoreApplication>
#include<QDir>
#include<QMessageBox>
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
	QString dirPath = QCoreApplication::applicationDirPath();
	if (s_settings == 0)
	{
		QDir dir;
		if (!dir.exists(QString("%1/config.ini").arg(dirPath)))
		{
			QMessageBox msgBox;
			msgBox.setText("找不到参数配置文件：config.ini.");
			msgBox.setInformativeText("没有参数配置文件，界面参数可能是不理想参数，请拷贝config.ini文件至exe的目录。");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.setIcon(QMessageBox::Critical);
			int ret = msgBox.exec();
		}
		//exe运行的当前目录
		s_settings = new QSettings(QString("%1/config.ini").arg(dirPath), QSettings::IniFormat);
		
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