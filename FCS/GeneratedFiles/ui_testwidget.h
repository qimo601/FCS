/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QAction *actionC;
    QAction *actionF;
    QAction *actionD;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QwtPlot *qwtPlot;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuA;
    QMenu *menuB;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QStringLiteral("TestWidget"));
        TestWidget->resize(727, 507);
        actionC = new QAction(TestWidget);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionF = new QAction(TestWidget);
        actionF->setObjectName(QStringLiteral("actionF"));
        actionD = new QAction(TestWidget);
        actionD->setObjectName(QStringLiteral("actionD"));
        centralWidget = new QWidget(TestWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(9, 213, 75, 23));
        qwtPlot = new QwtPlot(centralWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setGeometry(QRect(90, 9, 261, 232));
        qwtPlot->setCursor(QCursor(Qt::SizeAllCursor));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(562, 213, 75, 23));
        pushButton_2->setStyleSheet(QLatin1String("\n"
"background-color: qlineargradient(spread:pad, x1:0.511, y1:1, x2:0.511364, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(85, 170, 127);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(643, 213, 75, 23));
        TestWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 23));
        menuA = new QMenu(menuBar);
        menuA->setObjectName(QStringLiteral("menuA"));
        menuB = new QMenu(menuBar);
        menuB->setObjectName(QStringLiteral("menuB"));
        TestWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestWidget->setStatusBar(statusBar);

        menuBar->addAction(menuA->menuAction());
        menuBar->addAction(menuB->menuAction());
        menuA->addAction(actionC);
        menuA->addAction(actionF);
        menuB->addAction(actionD);

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QMainWindow *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0));
        actionC->setText(QApplication::translate("TestWidget", "C", 0));
        actionF->setText(QApplication::translate("TestWidget", "F", 0));
        actionD->setText(QApplication::translate("TestWidget", "D", 0));
        pushButton->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("TestWidget", "PushButton", 0));
        menuA->setTitle(QApplication::translate("TestWidget", "A", 0));
        menuB->setTitle(QApplication::translate("TestWidget", "B", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
