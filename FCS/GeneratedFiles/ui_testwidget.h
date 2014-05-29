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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QAction *actionC;
    QAction *actionF;
    QAction *actionD;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QPushButton *pushButton123;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QTableView *tableView;
    QListView *listView;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGroupBox *groupBox_2;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QPushButton *pushButton_7;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QVBoxLayout *verticalLayout;
    QTableView *tableView_3;
    QWidget *subwindow_2;
    QVBoxLayout *verticalLayout_2;
    QCommandLinkButton *commandLinkButton;
    QListView *listView_2;
    QWidget *subwindow_3;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QStringLiteral("TestWidget"));
        TestWidget->resize(1221, 876);
        TestWidget->setStyleSheet(QStringLiteral(""));
        actionC = new QAction(TestWidget);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionF = new QAction(TestWidget);
        actionF->setObjectName(QStringLiteral("actionF"));
        actionD = new QAction(TestWidget);
        actionD->setObjectName(QStringLiteral("actionD"));
        mainToolBar = new QToolBar(TestWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 12));
        statusBar = new QStatusBar(TestWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 18));
        pushButton123 = new QPushButton(TestWidget);
        pushButton123->setObjectName(QStringLiteral("pushButton123"));
        pushButton123->setGeometry(QRect(0, 40, 75, 23));
        scrollArea = new QScrollArea(TestWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-290, -50, 791, 791));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(400, 400));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgb(234, 237, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 800, 800));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(800, 800));
        pushButton = new QPushButton(scrollAreaWidgetContents_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 650, 131, 61));
        groupBox = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 490, 120, 80));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));
        tableView = new QTableView(scrollAreaWidgetContents_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(500, 120, 256, 192));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));
        listView = new QListView(scrollAreaWidgetContents_3);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(510, 370, 256, 192));
        listView->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));
        dockWidget = new QDockWidget(scrollAreaWidgetContents_3);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setGeometry(QRect(40, 380, 120, 80));
        dockWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 89, 125);"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 480, 120, 80));
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));
        dockWidget_2 = new QDockWidget(scrollAreaWidgetContents_3);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setGeometry(QRect(190, 380, 120, 80));
        dockWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 89, 125);"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        dockWidget_2->setWidget(dockWidgetContents_2);
        pushButton_7 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(370, 510, 101, 81));
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        mdiArea = new QMdiArea(TestWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(780, 120, 841, 651));
        mdiArea->setTabsClosable(false);
        subwindow = new QWidget();
        subwindow->setObjectName(QStringLiteral("subwindow"));
        verticalLayout = new QVBoxLayout(subwindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_3 = new QTableView(subwindow);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));

        verticalLayout->addWidget(tableView_3);

        mdiArea->addSubWindow(subwindow);
        subwindow_2 = new QWidget();
        subwindow_2->setObjectName(QStringLiteral("subwindow_2"));
        verticalLayout_2 = new QVBoxLayout(subwindow_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        commandLinkButton = new QCommandLinkButton(subwindow_2);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));

        verticalLayout_2->addWidget(commandLinkButton);

        listView_2 = new QListView(subwindow_2);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        verticalLayout_2->addWidget(listView_2);

        mdiArea->addSubWindow(subwindow_2);
        subwindow_3 = new QWidget();
        subwindow_3->setObjectName(QStringLiteral("subwindow_3"));
        verticalLayout_3 = new QVBoxLayout(subwindow_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView_2 = new QTableView(subwindow_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));

        verticalLayout_3->addWidget(tableView_2);

        pushButton_2 = new QPushButton(subwindow_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        mdiArea->addSubWindow(subwindow_3);
        pushButton_3 = new QPushButton(TestWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 90, 241, 221));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(55, 131, 189, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_4 = new QPushButton(TestWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(610, 380, 161, 81));
        pushButton_5 = new QPushButton(TestWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 550, 91, 31));
        pushButton_5->setStyleSheet(QStringLiteral(""));
        pushButton_6 = new QPushButton(TestWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(560, 690, 101, 51));

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0));
        actionC->setText(QApplication::translate("TestWidget", "C", 0));
        actionF->setText(QApplication::translate("TestWidget", "F", 0));
        actionD->setText(QApplication::translate("TestWidget", "D", 0));
        pushButton123->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton->setText(QApplication::translate("TestWidget", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("TestWidget", "GroupBox", 0));
        groupBox_2->setTitle(QApplication::translate("TestWidget", "GroupBox", 0));
        pushButton_7->setText(QApplication::translate("TestWidget", "PushButton", 0));
        subwindow->setWindowTitle(QApplication::translate("TestWidget", "\345\255\220\347\252\227\345\217\243", 0));
        subwindow_2->setWindowTitle(QApplication::translate("TestWidget", "\345\255\220\347\252\227\345\217\243", 0));
        commandLinkButton->setText(QApplication::translate("TestWidget", "CommandLinkButton", 0));
        subwindow_3->setWindowTitle(QApplication::translate("TestWidget", "\345\255\220\347\252\227\345\217\243", 0));
        pushButton_2->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("TestWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
