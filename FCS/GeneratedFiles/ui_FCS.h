/********************************************************************************
** Form generated from reading UI file 'FCS.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCS_H
#define UI_FCS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCSClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FCSClass)
    {
        if (FCSClass->objectName().isEmpty())
            FCSClass->setObjectName(QStringLiteral("FCSClass"));
        FCSClass->resize(1000, 650);
        centralWidget = new QWidget(FCSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FCSClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FCSClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 23));
        FCSClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FCSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FCSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FCSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FCSClass->setStatusBar(statusBar);

        retranslateUi(FCSClass);

        QMetaObject::connectSlotsByName(FCSClass);
    } // setupUi

    void retranslateUi(QMainWindow *FCSClass)
    {
        FCSClass->setWindowTitle(QApplication::translate("FCSClass", "FCS", 0));
    } // retranslateUi

};

namespace Ui {
    class FCSClass: public Ui_FCSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCS_H
