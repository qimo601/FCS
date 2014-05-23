/********************************************************************************
** Form generated from reading UI file 'MToolButton.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTOOLBUTTON_H
#define UI_MTOOLBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MToolButton
{
public:

    void setupUi(QWidget *MToolButton)
    {
        if (MToolButton->objectName().isEmpty())
            MToolButton->setObjectName(QStringLiteral("MToolButton"));
        MToolButton->resize(400, 300);

        retranslateUi(MToolButton);

        QMetaObject::connectSlotsByName(MToolButton);
    } // setupUi

    void retranslateUi(QWidget *MToolButton)
    {
        MToolButton->setWindowTitle(QApplication::translate("MToolButton", "MToolButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MToolButton: public Ui_MToolButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTOOLBUTTON_H
