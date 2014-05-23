#ifndef MTOOLBUTTON_H
#define MTOOLBUTTON_H

#include <QToolButton>
#include "ui_MToolButton.h"
#include <QMouseEvent>
class MToolButton : public QToolButton
{
	Q_OBJECT

public:
	MToolButton(QWidget *parent = 0);
	~MToolButton();
	//…Ë÷√Õº±Í
	void setIcon(QIcon);
protected:
	virtual void mouseMoveEvent(QMouseEvent *event);
private:
	Ui::MToolButton ui;
};

#endif // MTOOLBUTTON_H
