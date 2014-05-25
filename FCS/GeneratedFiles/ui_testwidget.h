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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QAction *actionC;
    QAction *actionF;
    QAction *actionD;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *lblMouseEventPos;
    QFrame *frame;
    QPushButton *posBtn;
    QPushButton *pushButton_5;
    QLabel *mapToBl;
    QLabel *lblToGlobalPos;
    QLabel *label_2;
    QLabel *lblMouseEventGlobalPos;
    QLabel *lblCursorPos;
    QLabel *label_3;
    QLabel *lblPushBttonPos;
    QLabel *label_4;
    QLabel *lblToParentPos;
    QLabel *mapToBl_2;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QStringLiteral("TestWidget"));
        TestWidget->resize(1159, 583);
        actionC = new QAction(TestWidget);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionF = new QAction(TestWidget);
        actionF->setObjectName(QStringLiteral("actionF"));
        actionD = new QAction(TestWidget);
        actionD->setObjectName(QStringLiteral("actionD"));
        centralWidget = new QWidget(TestWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 1161, 491));
        centralWidget->setMouseTracking(true);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(195, 195, 195);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 70, 101, 61));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 280, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 280, 131, 41));
        label->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        lblMouseEventPos = new QLabel(centralWidget);
        lblMouseEventPos->setObjectName(QStringLiteral("lblMouseEventPos"));
        lblMouseEventPos->setGeometry(QRect(420, 280, 121, 41));
        lblMouseEventPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(50, 340, 211, 128));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(206, 162, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        posBtn = new QPushButton(frame);
        posBtn->setObjectName(QStringLiteral("posBtn"));
        posBtn->setGeometry(QRect(2, 2, 80, 50));
        posBtn->setMinimumSize(QSize(50, 50));
        posBtn->setMouseTracking(true);
        posBtn->setStyleSheet(QLatin1String("\n"
"background-color: qlineargradient(spread:pad, x1:0.511, y1:1, x2:0.511364, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(85, 170, 127);"));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(2, 52, 75, 50));
        pushButton_5->setMinimumSize(QSize(50, 50));
        mapToBl = new QLabel(centralWidget);
        mapToBl->setObjectName(QStringLiteral("mapToBl"));
        mapToBl->setGeometry(QRect(820, 230, 121, 41));
        mapToBl->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        lblToGlobalPos = new QLabel(centralWidget);
        lblToGlobalPos->setObjectName(QStringLiteral("lblToGlobalPos"));
        lblToGlobalPos->setGeometry(QRect(950, 230, 111, 41));
        lblToGlobalPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 100, 131, 41));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        lblMouseEventGlobalPos = new QLabel(centralWidget);
        lblMouseEventGlobalPos->setObjectName(QStringLiteral("lblMouseEventGlobalPos"));
        lblMouseEventGlobalPos->setGeometry(QRect(420, 100, 121, 41));
        lblMouseEventGlobalPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        lblCursorPos = new QLabel(centralWidget);
        lblCursorPos->setObjectName(QStringLiteral("lblCursorPos"));
        lblCursorPos->setGeometry(QRect(420, 170, 121, 41));
        lblCursorPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 170, 131, 41));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        lblPushBttonPos = new QLabel(centralWidget);
        lblPushBttonPos->setObjectName(QStringLiteral("lblPushBttonPos"));
        lblPushBttonPos->setGeometry(QRect(420, 230, 121, 41));
        lblPushBttonPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(270, 230, 141, 41));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        lblToParentPos = new QLabel(centralWidget);
        lblToParentPos->setObjectName(QStringLiteral("lblToParentPos"));
        lblToParentPos->setGeometry(QRect(690, 230, 111, 41));
        lblToParentPos->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 186);"));
        mapToBl_2 = new QLabel(centralWidget);
        mapToBl_2->setObjectName(QStringLiteral("mapToBl_2"));
        mapToBl_2->setGeometry(QRect(560, 230, 121, 41));
        mapToBl_2->setStyleSheet(QStringLiteral("background-color: rgb(178, 186, 255);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 110, 101, 31));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 243, 206);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 180, 101, 31));
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 243, 206);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(360, 340, 104, 126));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(toolButton_2);

        mainToolBar = new QToolBar(TestWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 12));
        statusBar = new QStatusBar(TestWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 18));

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0));
        actionC->setText(QApplication::translate("TestWidget", "C", 0));
        actionF->setText(QApplication::translate("TestWidget", "F", 0));
        actionD->setText(QApplication::translate("TestWidget", "D", 0));
        pushButton->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("TestWidget", "PushButton", 0));
        label->setText(QApplication::translate("TestWidget", "lblMouseEventPos:", 0));
        lblMouseEventPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        posBtn->setText(QApplication::translate("TestWidget", "\350\257\245\346\214\211\351\222\256\347\232\204\345\235\220\346\240\207", 0));
        pushButton_5->setText(QApplication::translate("TestWidget", "PushButton", 0));
        mapToBl->setText(QApplication::translate("TestWidget", "mapToGlobal():", 0));
        lblToGlobalPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        label_2->setText(QApplication::translate("TestWidget", "mouseEvent.globalPos()", 0));
        lblMouseEventGlobalPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        lblCursorPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        label_3->setText(QApplication::translate("TestWidget", "Qcursor::Pos()", 0));
        lblPushBttonPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        label_4->setText(QApplication::translate("TestWidget", "ui.pushButton->pos()", 0));
        lblToParentPos->setText(QApplication::translate("TestWidget", "TextLabel", 0));
        mapToBl_2->setText(QApplication::translate("TestWidget", "mapToParent():", 0));
        label_5->setText(QApplication::translate("TestWidget", "\346\230\276\347\244\272\345\231\250\345\205\250\345\261\200\345\235\220\346\240\207\357\274\232", 0));
        label_6->setText(QApplication::translate("TestWidget", "\346\230\276\347\244\272\345\231\250\345\205\250\345\261\200\345\235\220\346\240\207\357\274\232", 0));
        toolButton->setText(QApplication::translate("TestWidget", "...", 0));
        toolButton_2->setText(QApplication::translate("TestWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
