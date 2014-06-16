
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
#include "Include/ICellStaticData.h"
//在VC项目配置里C / C++ / Preprocessor / Preprocessor Definitions属性里面加入宏定义：QT_NO_DEBUG_OUTPUT
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
	qDebug() << "【ReadOscThread】step:";
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
	double n1 =  4000000;
	double n11 = 6000000;
	double n12= 7000000;
	double n2 = 10;
	double m;
	m = qLn(n1) / qLn(10);
	m = qLn(n11) / qLn(10);
	m = qLn(n12) / qLn(10);

	char data[512] = { "12345" };
	memset(data,0,5);
	char *mm1 = new char();
	memcpy(mm1, data, 5);
	char mm2[5];
	memcpy(mm2, mm1, 5);
	char* da = mm2;
	char c;
	memcpy(&c, da++, 1);
	memcpy(&c, da++, 1);
	memcpy(&c, da++, 1);

	//ceshi
	TestWidget testWidget;
	testWidget.show();

	/*ICellStaticData* iCellStaticData = ICellStaticData::getInstance();

	iCellStaticData->insert(0,44,33,22);*/

	return a.exec();
}
