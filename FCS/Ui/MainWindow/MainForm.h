#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ui_MainForm.h"
#include "Ui/Library/DropShadowWidget.h"
#include "Ui/Library/MTitleWidget.h"
#include "Ui/Library/common.h"
#include "Include/Global.h"
class MainForm : public DropShadowWidget
{
	Q_OBJECT

public:
	MainForm(QWidget *parent = 0);
	~MainForm();

	void resetGeometry(int x);


	/** 
	* @brief   初始化
	*
	* @author  Liuzhaobang
	* @date    2014-5-15
	*/
	void init();
public slots:
	void showMaxOrNormal();
	void showMin();

	

protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::MainForm ui;
	MTitleWidget* titleWidget;///标题栏
	WidgetStatus widgetStatus;
};

#endif // MAINFORM_H
