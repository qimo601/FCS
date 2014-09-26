/**
* 项    目:  FCS软件
* 文件名称:   PlotConfig.h
* 文件路径：  Ui/Libary/PlotConfig.h
* 摘    要:  画布，属性窗口
* 作    者： 刘兆邦
* 日    期： 2014年05月23日
* Copyright (c) 2014-2015, 中科院苏州医工所医学影像室电子组.All rights reserved.
* Version v1.0
*/
#ifndef PlotConfig_H
#define PlotConfig_H

#include <QWidget>
#include <QPropertyAnimation>
#include "ui_PlotConfig.h"
#include "bll/DataCenter/BllSettings.h"
class PlotConfig : public QWidget
{
	Q_OBJECT
public:
	PlotConfig(QWidget *parent = 0);
	~PlotConfig();
public slots:
	void on_colorBtnProperty_clicked();
	void on_fileNameBtnProperty_clicked();
	void on_midMarkBtnProperty_clicked();
	/**
	* @brief 初始通道1颜色
	*/
	void on_colorBtn_1_clicked();
	/**
	* @brief 给PushButton着色
	*/
	void setColorBtn(QPushButton* btn);
	/**
	* @brief 给颜色PushButton着色
	*/
	void setColorBtn(QPushButton* btn, QString name);
	/**
	* @brief 初始通道2颜色
	*/
	void on_colorBtn_2_clicked();
	/**
	* @brief 初始通道3颜色
	*/
	void on_colorBtn_3_clicked();
	/**
	* @brief 初始通道4颜色
	*/
	void on_colorBtn_4_clicked();
	/**
	* @brief 初始通道5颜色
	*/
	void on_colorBtn_5_clicked();
	/**
	* @brief 初始通道6颜色
	*/
	void on_colorBtn_6_clicked();
	/**
	* @brief 初始通道7颜色
	*/
	void on_colorBtn_7_clicked();
	/**
	* @brief 初始通道8颜色
	*/
	void on_colorBtn_8_clicked();
	/**
	* @brief 初始通道颜色默认参数
	*/
	void initPassageColorSettings(QList<QString>& colorNameList, QList<int>& wideSpinList);
	/**
	* @brief 更新通道颜色默认参数
	*/
	void updatePassageColorSettings();
	/**
	* @brief 确认
	*/
	void on_okBtnProperty_clicked();
	/**
	* @brief 取消
	*/
	void on_cancleBtnPropety_clicked();

	/**
	* @brief 初始示波器参数
	*/
	void initOscPlotSettings(QList<QString>& colorNameList, QList<int>& coordinateSpinList);
	/**
	* @brief 更新示波器参数
	*/
	void updateOscPlotSettings();
	/**
	* @brief 初始画布背景颜色
	*/
	void on_plotColorBtn_clicked();
	/**
	* @brief 画布背景默认颜色
	*/
	void on_defaultCheckBox_toggled(bool enable);
signals:
	void oscParamChanged();
	void oscPlotChanged();
protected:
	void paintEvent(QPaintEvent *);

private:
	Ui::PlotConfig ui;
	QPropertyAnimation* animation;
	QPropertyAnimation* animation1;
	//配置业务
	BllSettings bllSettings;
};

#endif // PlotConfig_H
