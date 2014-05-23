// 源代码编码必须是: UTF-8(BOM)  
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "USB/USBControl.h"
#include "Ui/Library/DropShadowWidget.h"
#include "Ui/Library/TitleWidget.h"
class MainWindow : public DropShadowWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	public slots:

	/**
	* @brief 打开USB设备
	*/
	void on_openUsbBtn_clicked();

	/**
	* @brief 关闭USB设备
	*/
	void on_closeUsbBtn_clicked();
	/**
	* @brief 测试下发命令
	*/
	void on_loadCmdBtn_clicked();
	/**
	* @brief 测试采集示波器数据
	*/
	void on_startOscBtn_clicked();
	/**
	* @brief 测试开始采集细胞数据
	*/
	void on_startAcqBtn_clicked();
	/**
	* @brief 设置激光
	*/
	void on_setLaserBtn_clicked();
	/**
	* @brief 设置鞘液
	*/
	void on_setFluidBtn_clicked();
	/**
	* @brief 设置样本流
	*/
	void on_setSampleBtn_clicked();
	/**
	* @brief 设置通道偏压
	*/
	void on_setChannelBiasBtn_clicked();
	/**
	* @brief 设置触发值
	*/
	void on_setTriggerBtn_clicked();
	/**
	* @brief 读取数据
	*/
	void on_readBtn_clicked();
signals:
	///开始示波器采集
	void startOscAcq();
	///开始采集
	void startacq();
private:
	Ui::MainWindow ui;
	USBControl* usbControl;
	///标题栏
	TitleWidget* titleWidget;
};

#endif // MAINWINDOW_H
