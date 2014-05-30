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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QAction *actionC;
    QAction *actionF;
    QAction *actionD;
    QPushButton *pushButton123;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;
    QListView *listView;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;

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
        pushButton123 = new QPushButton(TestWidget);
        pushButton123->setObjectName(QStringLiteral("pushButton123"));
        pushButton123->setGeometry(QRect(9, 844, 75, 23));
        scrollArea = new QScrollArea(TestWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(9, 9, 432, 400));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(400, 400));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, -28, 1000, 1000));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(1000, 1000));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(scrollAreaWidgetContents_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(scrollAreaWidgetContents_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        listView = new QListView(scrollAreaWidgetContents_3);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));

        verticalLayout->addWidget(listView);

        dockWidget_2 = new QDockWidget(scrollAreaWidgetContents_3);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 89, 125);"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        dockWidget_2->setWidget(dockWidgetContents_2);

        verticalLayout->addWidget(dockWidget_2);

        dockWidget = new QDockWidget(scrollAreaWidgetContents_3);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 89, 125);"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);

        verticalLayout->addWidget(dockWidget);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));

        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 87);"));

        verticalLayout->addWidget(groupBox);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

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
        groupBox_2->setTitle(QApplication::translate("TestWidget", "GroupBox", 0));
        groupBox->setTitle(QApplication::translate("TestWidget", "GroupBox", 0));
        pushButton_7->setText(QApplication::translate("TestWidget", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("TestWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
