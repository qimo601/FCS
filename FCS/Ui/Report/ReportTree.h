#ifndef REPORTTREE_H
#define REPORTTREE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "ui_ReportTree.h"
#include "Include/Global.h"
class ReportTree : public QWidget
{
	Q_OBJECT

public:
	ReportTree(QWidget *parent = 0);
	~ReportTree();
public slots:

	/**
	* @brief 初始化报表数据
	*/
	void initReportData();


protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
signals:

private:
	Ui::ReportTree ui;

	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键
};

#endif // REPORTTREE_H
