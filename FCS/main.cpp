
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
#include "Ui/Report/ReportTree.h"
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

	/*ReportTree reportTree;
	reportTree.show();*/
	//toolWidget.resetGeometry(30);
// 	//主窗口
// 	OscWidget oscWidget;
// 	oscWidget.show();

	
	/*double n1 =  4000000;
	double n11 = 6000000;
	double n12= 7000000;
	double n2 = 10;
	double m;
	m = qLn(n1)/qLn(10);
	double t = qPow(10,m);
	m = qLn(n11) / qLn(10);
	t = qPow(10, m);
	m = qLn(n12) / qLn(10);
	t = qPow(10, m);
	

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
	memcpy(&c, da++, 1);*/

	//ceshi
	/*TestWidget testWidget;
	testWidget.show();*/

	/*ICellStaticData* iCellStaticData = ICellStaticData::getInstance();

	iCellStaticData->insert(0,44,33,22);*/


	QList<QList<double>> list1;
	QList<double> list;
	list.append(3);
	list.append(4);
	list.append(2);/*
	list.append(5.4);
	list.append(34.3);
	list.append(3222);
	list.append(2.3);*/
	list1.append(list);
	QList<QList<double>> list2;
	list2 = list1;
	QList<QList<double>> list3;
	QList<double> list31;
	list31.append(1);
	list31.append(2);
	list31.append(5);
	list3.append(list31);
	list2 = list3;
	//qSort(list2.at(0).begin(), list2.at(0).end());
	return a.exec();
}
