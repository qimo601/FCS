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
	/**
	* @brief 设置散点图画布参数菜单
	*/
	void on_scatterBtnProperty_clicked();

	/**
	* @brief 设置直方图画布参数菜单
	*/
	void on_barChartBtnProperty_clicked();
	/**
	* @brief 设置画布参数菜单
	*/
	void on_plotBtnProperty_clicked();
	/**
	* @brief 初始直方图颜色
	*/
	void on_barChatColorBtn_clicked();
	/**
	* @brief 给PushButton着色
	*/
	void setColorBtn(QPushButton* btn);
	/**
	* @brief 给颜色PushButton着色
	*/
	void setColorBtn(QPushButton* btn, QString name);
	/**
	* @brief 初始散点图颜色
	*/
	void on_scatterColorBtn_clicked();
	/**
	* @brief 初始画布颜色
	*/
	void on_plotColorBtn_clicked();
	/**
	* @brief 初始散点图颜色默认参数
	*/
	void initScatterPlotSettings(QMap<QString, QVariant>& valueMap);
	/**
	* @brief 更新散点图画布默认参数
	*/
	void updateScatterPlotSettings();
	/**
	* @brief 初始直方图Plot默认参数
	* @param valueMap
	*/
	void initBarChartPlotSettings(QMap<QString, QVariant>& valueMap);
	/**
	* @brief 更新直方图画布默认参数
	*/
	void updateBarChartPlotSettings();
	/**
	* @brief 初始Plot默认参数
	* @param valueMap
	*/
	void initPlotSettings(QMap<QString, QVariant>& valueMap);
	/**
	* @brief 更新画布默认参数
	*/
	void updatePlotSettings();
	/**
	* @brief 确认
	*/
	void on_okBtnProperty_clicked();
	/**
	* @brief 取消
	*/
	void on_cancleBtnPropety_clicked();

	/**
	* @brief  散点图x轴坐标范围自动变化
	*/
	void on_xAutoCheckBox_toggled(bool enable);
	/**
	* @brief  散点图y轴坐标范围自动变化
	*/
	void on_yAutoCheckBox_toggled(bool enable);
	/**
	* @brief  散点图线条颜色粗细设置
	*/
	void on_scatterDefaultCheckBox_toggled(bool enable);
	/**
	* @brief  直方图x轴坐标范围自动变化
	*/
	void on_xAutoCheckBox_2_toggled(bool enable);
	/**
	* @brief  直方图y轴坐标范围自动变化
	*/
	void on_yAutoCheckBox_2_toggled(bool enable);

	/**
	* @brief  直方图线条颜色粗细设置
	*/
	void on_barChartDefaultCheckBox_toggled(bool enable);
	
	/**
	* @brief  画布颜色设置
	*/
	void on_defaultCheckBox_toggled(bool enable);
signals:
	void scatterPlotConfigChange(QMap<QString, QVariant>);//散点图参数变更
	void barchartPlotConfigChange(QMap<QString, QVariant>);//直方图参数变更
	void plotConfigChange(QMap<QString, QVariant>);
	void plotConfigClosed();//关闭事件
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
