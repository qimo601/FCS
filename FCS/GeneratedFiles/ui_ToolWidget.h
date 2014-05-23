/********************************************************************************
** Form generated from reading UI file 'ToolWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWIDGET_H
#define UI_TOOLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileBrowserBtn;
    QPushButton *acqBtn;
    QPushButton *analyBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ToolWidget)
    {
        if (ToolWidget->objectName().isEmpty())
            ToolWidget->setObjectName(QStringLiteral("ToolWidget"));
        ToolWidget->resize(802, 50);
        ToolWidget->setMinimumSize(QSize(0, 50));
        ToolWidget->setMaximumSize(QSize(16777215, 50));
        ToolWidget->setStyleSheet(QStringLiteral("background-color: rgb(131, 131, 131);"));
        verticalLayout = new QVBoxLayout(ToolWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fileBrowserBtn = new QPushButton(ToolWidget);
        fileBrowserBtn->setObjectName(QStringLiteral("fileBrowserBtn"));
        fileBrowserBtn->setMinimumSize(QSize(75, 30));
        fileBrowserBtn->setMaximumSize(QSize(75, 30));

        horizontalLayout->addWidget(fileBrowserBtn);

        acqBtn = new QPushButton(ToolWidget);
        acqBtn->setObjectName(QStringLiteral("acqBtn"));
        acqBtn->setMinimumSize(QSize(110, 30));
        acqBtn->setMaximumSize(QSize(110, 30));

        horizontalLayout->addWidget(acqBtn);

        analyBtn = new QPushButton(ToolWidget);
        analyBtn->setObjectName(QStringLiteral("analyBtn"));
        analyBtn->setEnabled(true);
        analyBtn->setMinimumSize(QSize(110, 30));
        analyBtn->setMaximumSize(QSize(110, 30));
        analyBtn->setLayoutDirection(Qt::LeftToRight);
        analyBtn->setAutoFillBackground(false);
        analyBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(analyBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ToolWidget);

        QMetaObject::connectSlotsByName(ToolWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolWidget)
    {
        ToolWidget->setWindowTitle(QApplication::translate("ToolWidget", "ToolWidget", 0));
        fileBrowserBtn->setText(QApplication::translate("ToolWidget", "\346\226\207\344\273\266\346\265\217\350\247\210\345\231\250", 0));
        acqBtn->setText(QApplication::translate("ToolWidget", "\347\244\272\346\263\242\345\231\250\351\207\207\351\233\206", 0));
        analyBtn->setText(QApplication::translate("ToolWidget", "\346\225\260\346\215\256\345\210\206\346\236\220\344\270\216\347\273\237\350\256\241", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolWidget: public Ui_ToolWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWIDGET_H
