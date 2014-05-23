#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "ui_MenuWidget.h"

class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = 0);
	~MenuWidget();
protected:
	void paintEvent(QPaintEvent *);
private:
	Ui::MenuWidget ui;
};

#endif // MENUWIDGET_H
