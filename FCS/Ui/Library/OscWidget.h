#ifndef OSCWIDGET_H
#define OSCWIDGET_H

#include <QWidget>
#include "ui_OscWidget.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QTimer>
#include "Include/Global.h"
#include "Bll/DataCenter/BllDataCenter.h"
#include <qwt_legend.h>
#include <qwt_system_clock.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_marker.h>
#include <qwt_interval.h>
#include "Ui/Library/PropertyWidget.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QMouseEvent>
class OscWidget : public QWidget
{
	Q_OBJECT

public:
	OscWidget(QWidget *parent = 0);
	~OscWidget();
	/**
	* @brief ��ʼ��
	*/
	void init();
	/**
	* @brief ��ʼ��Plot
	*/
	void initPlot();
	/**
	* @brief ��ʼ��WheelBox
	*/
	void initWheelBox();

	/**
	* @brief ��ʼ�����Դ��ڼ��䶯��
	*/
	void initAnimation();
	/**
	* @brief ��ʾ���Դ���
	*/
	void showPropertyWidget();
	/**
	* @brief �ر����Դ���
	*/
	void closePropertyWidget();
	/**
	* @brief ����һ���ĸ�������ʾ
	*/
	void showCurve(QwtPlotItem *item, bool on);
public slots:

	/**
	* @brief ���»�ͼ����
	*/
	void updateOscPlot();
	/**
	* @brief ��ʼʾ�����ɼ�
	*/
	void on_startOscAcqBtn_clicked();
	/**
	* @brief ֹͣʾ�����ɼ�
	*/
	void on_stopOscAcqBtn_clicked();
	/**
	* @brief ������������ۺ���
	*/
	void legendChecked(const QVariant &itemInfo, bool on);

	/**
	* @brief ����X������
	*/
	void setXAxisScale(double interval);
	/**
	* @brief ����Y������
	*/
	void setYAxisScale(double interval);
	/**
	* @brief ����X���м���
	*/
	void setXMark(double mark_x);
	/**
	* @brief ����Y���м���
	*/
	void setYMark(double mark_y);
	/**
	* @brief ���ð�ť�������Դ���
	*/
	void on_propertyBtn_clicked();
	/**
	* @brief �������Դ��ڲ��ɼ�
	*/
	void setVisiblePropertyWidget();
protected:
	virtual void timerEvent(QTimerEvent *);
	virtual void mouseMoveEvent(QMouseEvent *event);
signals:
	void startOscAcq();
	void propertyClicked();
private:
	Ui::OscWidget ui;
	//��������ҵ����
	BllDataCenter bllDataCenter;
	
	//��ͼ��ʱ��
	QTimer *m_timer;
	//������
	int stepValue;
	//ʾ��������
	QwtPlotCurve* oscCurve;
	//���ߵ�����
	QwtLegend* legend;
	//ʾ�������� �б�
	QList<QwtPlotCurve*> m_curveList;
	//���ߵ����� �б�
	QList<QwtLegend*> m_legendList;
	//���������¼�
	QwtSystemClock m_clock;
	int m_timerId;

	//���û���
	QwtPlotCanvas* canvas;
	//�м�ʮ�ֱ��
	QwtPlotMarker* d_origin;
	//��������
	QwtPlotGrid* grid;

	//����X�����귶Χ�����ʱ��
	QwtInterval m_interval_x;
	//����Y�����귶Χ
	QwtInterval m_interval_y;
	//���ð�ťͼ��
	QPixmap settingPixmap;
	//�м���λ��
	QPoint m_markPos;

	//���Դ���
	PropertyWidget* propertyWidget;
	//���Դ��ڳ��ֶ���
	QPropertyAnimation* showPropertyAnimation;
	//���Դ��ڳ��ֶ���
	QPropertyAnimation* closePropertyAnimation;
	
	bool propertWidgetTag;
};

#endif // OSCWIDGET_H
