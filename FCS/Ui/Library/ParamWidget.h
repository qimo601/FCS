#ifndef PARAMWIDGET_H
#define PARAMWIDGET_H

#include <QWidget>
#include "ui_ParamWidget.h"
#include "Bll/Control/BllControl.h"
class ParamWidget : public QWidget
{
	Q_OBJECT

public:
	ParamWidget(QWidget *parent = 0);
	~ParamWidget();
public slots:
	/**
	* @brief 设置激光强度
	*/
	void on_setLaserBtn_clicked();
	/**
	* @brief 设置鞘液
	*/
	void on_setFluidBtn_clicked();
	/**
	* @brief 设置样品流
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
	* @brief 设置样品流速-中档
	*/
	void on_midRadioButton_clicked();
	/**
	* @brief 设置样品流速-高档
	*/
	void on_hightRadioButton_clicked();
	/**
	* @brief 设置样品流速-低档
	*/
	void on_lowRadioButton_clicked();

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *event);
private:
	Ui::ParamWidget ui;

	BllControl* bllControl;//采集控制业务类
};

#endif // PARAMWIDGET_H
