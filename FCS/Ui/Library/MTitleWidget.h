#ifndef MTITLEWIDGET_H
#define MTITLEWIDGET_H

#include <QWidget>
#include "ui_MTitleWidget.h"

class MTitleWidget : public QWidget
{
	Q_OBJECT

public:
	MTitleWidget(QWidget *parent = 0);
	~MTitleWidget();
protected:
	void paintEvent(QPaintEvent *);
signals:

	void minWidget();//最小化窗口
	void maxWidget();//最大化窗口
	void closeWidget();//关闭窗口
private:
	Ui::MTitleWidget ui;
};

#endif // MTITLEWIDGET_H
