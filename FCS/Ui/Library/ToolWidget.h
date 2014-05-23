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
	* @brief 示波器采集窗口
	*/
	void on_acqBtn_clicked();
	/**
	* @brief 数据分析与报告窗口
	*/
	void on_analyBtn_clicked();
	/**
	* @brief 文件浏览器窗口
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
	
	QPixmap acqPixmap;//采集界面图片
	QPixmap analyPixmap;//数据分析与报告界面图片
};

#endif // TOOLWIDGET_H
