#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>
#include "ui_ToolWidget.h"
#include <QPainter>
#include <QResizeEvent>
class ToolWidget : public QWidget
{
	Q_OBJECT

public:
	ToolWidget(QWidget *parent = 0);
	~ToolWidget();
	void resetGeometry(int x);
public slots:

	/**
	* @brief ʾ�����ɼ�����
	*/
	void on_acqBtn_clicked();
	/**
	* @brief ���ݷ����뱨�洰��
	*/
	void on_analyBtn_clicked();
	/**
	* @brief �ļ����������
	*/
	void on_fileBrowserBtn_clicked();
signals:
	void acqBtnClicked();
	void analyBtnClicked();
	void fileBrowserBtnClicked();

protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent * event);
private:
	Ui::ToolWidget ui;
	
	QPixmap acqPixmap;//�ɼ�����ͼƬ
	QPixmap analyPixmap;//���ݷ����뱨�����ͼƬ
};

#endif // TOOLWIDGET_H
