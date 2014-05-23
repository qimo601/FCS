/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Ui/Library/MTitleWidget.h"
#include "Ui/Library/MenuWidget.h"
#include "Ui/Library/Stackedwidget.h"
#include "Ui/Library/ToolWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    MTitleWidget *titleWidget;
    MenuWidget *menuWidget;
    ToolWidget *toolWidget;
    QWidget *contentWidget;
    StackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QStringLiteral("MainForm"));
        MainForm->resize(998, 691);
        MainForm->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(MainForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(MainForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(frame);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        titleWidget = new MTitleWidget(mainWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(titleWidget);

        menuWidget = new MenuWidget(mainWidget);
        menuWidget->setObjectName(QStringLiteral("menuWidget"));

        verticalLayout->addWidget(menuWidget);

        toolWidget = new ToolWidget(mainWidget);
        toolWidget->setObjectName(QStringLiteral("toolWidget"));
        toolWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(toolWidget);

        contentWidget = new QWidget(mainWidget);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));

        verticalLayout->addWidget(contentWidget);

        stackedWidget = new StackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        titleWidget->raise();
        menuWidget->raise();
        contentWidget->raise();
        toolWidget->raise();
        stackedWidget->raise();

        verticalLayout_3->addWidget(mainWidget);


        horizontalLayout->addWidget(frame);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "MainForm", 0));
#ifndef QT_NO_TOOLTIP
        titleWidget->setToolTip(QApplication::translate("MainForm", "\346\240\207\351\242\230\346\240\217", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
