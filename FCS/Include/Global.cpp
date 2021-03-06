﻿#include "Global.h"
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include <QTranslator>
#include "Include/OscDataCenter.h"
#include "Bll/DataCenter/BllSettings.h"
#include "Bll/Control/BllControl.h"
Global::Global(QObject *parent)
	: QObject(parent)
{
	//初始化
	init();
}

Global::~Global()
{
	//全局卸载函数
	uninstall();
}


/**
* @brief 系统初始化
*/
void Global::init()
{
	//初始化样式表
	initQss();
	//初始化翻译
	//initLanguage();
	//初始化环形缓冲区大小
	initCCycleBuffer(Gobal_CircleBuffer_Size);
	//初始化示波器缓冲区结构
	for (int i = 0; i < 8; i++)//8个通道
	{
		QVector<double> vector;
		Global::oscYData.append(vector);
		
	}

}

CCycleBuffer* Global::S_CCycleBuffer = 0;


QVector<double> Global::oscXData;
QList<QVector<double>> Global::oscYData;

//细胞总数
qint32 Global::s_cellEvents = 0;

/**
* @brief qss初始化
*/
void Global::initQss()
{
	//全局qss先清空
	//QString ss = qApp->styleSheet();
	//qApp->setStyleSheet("");
	QDir dir;
	QString current = dir.currentPath();
	QFile file("Resources/StyleSheet.qss");
	if (!file.open(QFile::ReadOnly))
	{

		QMessageBox msgBox;
		msgBox.setText("程序出现错误.");
		msgBox.setInformativeText("系统初始化错误，qss文件无法打开，请确认Resources/StyleSheet.qss文件是否存在。\
								   出错程序:/Include/Global.cpp的initQss()函数");
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.setDefaultButton(QMessageBox::Ok);
		int ret = msgBox.exec();
	}
	QString styleSheet = file.readAll().data();
	//设定全局qss风格
	qApp->setStyleSheet(styleSheet);
}
/**
* @brief 初始化语言
*/
void Global::initLanguage()
{
	
	translator.load(QString(":/Qm/Resources/fcs_en.qm"));
	qApp->installTranslator(&translator);
}

/**
* @brief 初始化环形缓冲区
*/
bool Global::initCCycleBuffer(int size)
{
	//删除旧的缓冲区
	if (S_CCycleBuffer != 0)
	{
		delete S_CCycleBuffer;
		S_CCycleBuffer = 0;
	}
	//开辟新的缓存区
	S_CCycleBuffer = new CCycleBuffer(size);
	if (!S_CCycleBuffer)
		return false;
	else
		return true;
		
}

/**
* @brief 卸载
*/
bool Global::uninstall()
{
	//卸载配置
	BllSettings::uninstall();
	//首先关闭USB
	BllControl::closeUSBControl();
	//然后删除缓冲区
	if (S_CCycleBuffer != 0)
		delete S_CCycleBuffer;
	
	return true;
}

