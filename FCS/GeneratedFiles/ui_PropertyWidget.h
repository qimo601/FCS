/********************************************************************************
** Form generated from reading UI file 'PropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYWIDGET_H
#define UI_PROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertyWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton1;

    void setupUi(QWidget *PropertyWidget)
    {
        if (PropertyWidget->objectName().isEmpty())
            PropertyWidget->setObjectName(QStringLiteral("PropertyWidget"));
        PropertyWidget->setWindowModality(Qt::NonModal);
        PropertyWidget->resize(300, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PropertyWidget->sizePolicy().hasHeightForWidth());
        PropertyWidget->setSizePolicy(sizePolicy);
        PropertyWidget->setMinimumSize(QSize(300, 200));
        PropertyWidget->setMaximumSize(QSize(300, 200));
        PropertyWidget->setStyleSheet(QStringLiteral("background-color: rgb(62, 113, 255);"));
        pushButton = new QPushButton(PropertyWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 0, 0));
        pushButton1 = new QPushButton(PropertyWidget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(200, 10, 75, 23));

        retranslateUi(PropertyWidget);

        QMetaObject::connectSlotsByName(PropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *PropertyWidget)
    {
        PropertyWidget->setWindowTitle(QApplication::translate("PropertyWidget", "PropertyWidget", 0));
        pushButton->setText(QApplication::translate("PropertyWidget", "PushButton", 0));
        pushButton1->setText(QApplication::translate("PropertyWidget", "\345\274\200\345\247\213\350\277\220\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class PropertyWidget: public Ui_PropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYWIDGET_H
