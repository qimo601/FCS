/**
* ��    Ŀ:  FCS���
* �ļ�����:  AnalysisWidget.h
* �ļ�·���� Ui/Libarary/AnalysisWidget.h
* ժ    Ҫ:  ���ݷ����뱨�洰��
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��28��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef ANALYSISWIDGET_H
#define ANALYSISWIDGET_H

#include <QWidget>
#include <QPainter>
#include "ui_AnalysisWidget.h"

class AnalysisWidget : public QWidget
{
	Q_OBJECT

public:
	AnalysisWidget(QWidget *parent = 0);
	~AnalysisWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::AnalysisWidget ui;
};

#endif // ANALYSISWIDGET_H
