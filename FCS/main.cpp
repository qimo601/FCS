
#include "FCS.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "Include/Global.h"
#include "USB/USBThread.h"
#include <QTranslator>
#include "Ui/MainWindow/MainForm.h"
#include "Ui/Library/OscWidget.h"
#include "testwidget.h"
#include <string>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)  
#if defined(_MSC_VER) && (_MSC_VER < 1600)  
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
#else  
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
#endif  
#endif 

	Global global;
	MainForm mainForm;
	//mainForm.show();
	mainForm.showMaximized();
	//mainForm.resetGeometry(30);
// 	MTitleWidget titleWidget;
// 	titleWidget.show();

	//toolWidget.resetGeometry(30);
// 	//主窗口
// 	OscWidget oscWidget;
// 	oscWidget.show();

	//ceshi
	TestWidget testWidget;
	testWidget.show();
	return a.exec();
}
