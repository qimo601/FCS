/**
* ��    Ŀ:  FCS���
* �ļ�����:   PlotWidget.h
* �ļ�·����  Ui/Libary/PlotWidget.h
* ժ    Ҫ:  ��ͼ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��29��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include "ui_PlotWidget.h"
class Plot;

class PlotWidget : public QWidget
{
	Q_OBJECT

public:
	PlotWidget(QWidget *parent = 0);
	~PlotWidget();

	/**
	* @brief ��������
	*/
	void setSamples(int samples);
	/**
	* @brief ���ֵ
	*/
	double randomValue();
private:
	Ui::PlotWidget ui;
	Plot *d_plot;
};

#endif // PLOTWIDGET_H
