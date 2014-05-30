/**
* ��    Ŀ:  FCS���
* �ļ�����:   Plot.h
* �ļ�·����  Ui/Libary/Plot.h
* ժ    Ҫ:  �Զ����ͼ�ؼ�
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��29��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef PLOT_H
#define PLOT_H

#include <qwt_plot.h>

class QwtPlotCurve;
class QwtSymbol;
class Plot : public QwtPlot
{
	Q_OBJECT

public:
	Plot(QWidget *parent = 0);
	~Plot();
	void setSymbol(QwtSymbol *);
	void setSamples(const QVector<QPointF> &samples);
private:
	QwtPlotCurve *d_curve;
};

#endif // PLOT_H
