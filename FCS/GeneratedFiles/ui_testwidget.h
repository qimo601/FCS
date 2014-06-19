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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <Ui/Library/BarChartWidget.h>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QAction *actionC;
    QAction *actionF;
    QAction *actionD;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    BarChartWidget *widget;
    QPushButton *pushButton1234;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QStringLiteral("TestWidget"));
        TestWidget->resize(1221, 876);
        TestWidget->setAutoFillBackground(false);
        TestWidget->setStyleSheet(QStringLiteral(""));
        actionC = new QAction(TestWidget);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionF = new QAction(TestWidget);
        actionF->setObjectName(QStringLiteral("actionF"));
        actionD = new QAction(TestWidget);
        actionD->setObjectName(QStringLiteral("actionD"));
        scrollArea = new QScrollArea(TestWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-70, 110, 1121, 821));
        scrollArea->setFocusPolicy(Qt::ClickFocus);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1119, 819));
        scrollAreaWidgetContents->setFocusPolicy(Qt::NoFocus);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new BarChartWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton1234 = new QPushButton(TestWidget);
        pushButton1234->setObjectName(QStringLiteral("pushButton1234"));
        pushButton1234->setGeometry(QRect(290, 20, 75, 23));
        label = new QLabel(TestWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 70, 54, 12));
        toolButton = new QToolButton(TestWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(510, 30, 201, 61));

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0));
        actionC->setText(QApplication::translate("TestWidget", "C", 0));
        actionF->setText(QApplication::translate("TestWidget", "F", 0));
        actionD->setText(QApplication::translate("TestWidget", "D", 0));
        pushButton1234->setText(QApplication::translate("TestWidget", "PushButton", 0));
        label->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        toolButton->setText(QApplication::translate("TestWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
