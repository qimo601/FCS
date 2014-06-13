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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <Ui/Library/PlotWidget.h>
#include "qwt_plot.h"

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
    QWidget *widget_1;
    QwtPlot *qwtPlot;
    PlotWidget *plotwidget_45;
    QWidget *widget_4;
    QPushButton *pushButton_3;
    QWidget *widget_3;
    QPushButton *pushButton123;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_2;
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
        scrollArea->setGeometry(QRect(-70, 110, 691, 611));
        scrollArea->setFocusPolicy(Qt::ClickFocus);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 672, 690));
        scrollAreaWidgetContents->setFocusPolicy(Qt::NoFocus);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_1 = new QWidget(scrollAreaWidgetContents);
        widget_1->setObjectName(QStringLiteral("widget_1"));
        widget_1->setMinimumSize(QSize(200, 300));
        widget_1->setFocusPolicy(Qt::StrongFocus);
        widget_1->setStyleSheet(QStringLiteral("background-color: rgb(194, 203, 255);"));
        qwtPlot = new QwtPlot(widget_1);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setGeometry(QRect(30, 60, 231, 200));

        gridLayout->addWidget(widget_1, 0, 0, 2, 1);

        plotwidget_45 = new PlotWidget(scrollAreaWidgetContents);
        plotwidget_45->setObjectName(QStringLiteral("plotwidget_45"));
        plotwidget_45->setMinimumSize(QSize(200, 300));
        plotwidget_45->setFocusPolicy(Qt::StrongFocus);
        plotwidget_45->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(plotwidget_45, 0, 1, 1, 1);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(200, 300));
        widget_4->setFocusPolicy(Qt::StrongFocus);
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 99, 229);"));
        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 40, 75, 161));
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(142, 138, 255);"));

        gridLayout->addWidget(widget_4, 1, 1, 2, 1);

        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(200, 300));
        widget_3->setFocusPolicy(Qt::StrongFocus);
        widget_3->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 182, 99);"));

        gridLayout->addWidget(widget_3, 2, 0, 1, 1);

        pushButton123 = new QPushButton(scrollAreaWidgetContents);
        pushButton123->setObjectName(QStringLiteral("pushButton123"));
        pushButton123->setStyleSheet(QString::fromUtf8("font: 75 26pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(pushButton123, 3, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        graphicsView = new QGraphicsView(TestWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(640, 170, 571, 561));
        pushButton_2 = new QPushButton(TestWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 730, 211, 111));
        pushButton_2->setFocusPolicy(Qt::StrongFocus);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(142, 138, 255);"));
        pushButton1234 = new QPushButton(TestWidget);
        pushButton1234->setObjectName(QStringLiteral("pushButton1234"));
        pushButton1234->setGeometry(QRect(290, 20, 75, 23));
        label = new QLabel(TestWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 70, 54, 12));
        toolButton = new QToolButton(TestWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(510, 30, 201, 61));
        QWidget::setTabOrder(widget_3, widget_1);
        QWidget::setTabOrder(widget_1, plotwidget_45);
        QWidget::setTabOrder(plotwidget_45, pushButton123);

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0));
        actionC->setText(QApplication::translate("TestWidget", "C", 0));
        actionF->setText(QApplication::translate("TestWidget", "F", 0));
        actionD->setText(QApplication::translate("TestWidget", "D", 0));
        pushButton_3->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton123->setText(QApplication::translate("TestWidget", "\344\270\213\344\270\200\344\270\252\357\274\210\347\204\246\347\202\271\357\274\211", 0));
        pushButton_2->setText(QApplication::translate("TestWidget", "PushButton", 0));
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
