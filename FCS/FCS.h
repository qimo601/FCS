#ifndef FCS_H
#define FCS_H

#include <QtWidgets/QMainWindow>
#include "ui_FCS.h"

class FCS : public QMainWindow
{
	Q_OBJECT

public:
	FCS(QWidget *parent = 0);
	~FCS();

private:
	Ui::FCSClass ui;
};

#endif // FCS_H
