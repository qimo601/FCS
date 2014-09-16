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
	* @brief ���ü���ǿ��
	*/
	void on_setLaserBtn_clicked();
	/**
	* @brief ������Һ
	*/
	void on_setFluidBtn_clicked();
	/**
	* @brief ������Ʒ��
	*/
	void on_setSampleBtn_clicked();
	/**
	* @brief ����ͨ��ƫѹ
	*/
	void on_setChannelBiasBtn_clicked();
	/**
	* @brief ���ô���ֵ
	*/
	void on_setTriggerBtn_clicked();
	/**
	* @brief ������Ʒ����-�е�
	*/
	void on_midRadioButton_clicked();
	/**
	* @brief ������Ʒ����-�ߵ�
	*/
	void on_hightRadioButton_clicked();
	/**
	* @brief ������Ʒ����-�͵�
	*/
	void on_lowRadioButton_clicked();

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *event);
private:
	Ui::ParamWidget ui;

	BllControl* bllControl;//�ɼ�����ҵ����
};

#endif // PARAMWIDGET_H
