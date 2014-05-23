/********************************************************************************
** Form generated from reading UI file 'WheelBox.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHEELBOX_H
#define UI_WHEELBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_wheel.h"

QT_BEGIN_NAMESPACE

class Ui_WheelBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLCDNumber *d_number;
    QwtWheel *d_wheel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *d_label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WheelBox)
    {
        if (WheelBox->objectName().isEmpty())
            WheelBox->setObjectName(QStringLiteral("WheelBox"));
        WheelBox->resize(117, 99);
        verticalLayout = new QVBoxLayout(WheelBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        d_number = new QLCDNumber(WheelBox);
        d_number->setObjectName(QStringLiteral("d_number"));
        d_number->setMaximumSize(QSize(71, 30));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        d_number->setFont(font);
        d_number->setFocusPolicy(Qt::WheelFocus);
        d_number->setAutoFillBackground(false);
        d_number->setStyleSheet(QLatin1String("background-color: rgb(6, 6, 6);\n"
"color: green;"));
        d_number->setMode(QLCDNumber::Dec);
        d_number->setSegmentStyle(QLCDNumber::Flat);
        d_number->setProperty("value", QVariant(100));

        horizontalLayout_4->addWidget(d_number);

        d_wheel = new QwtWheel(WheelBox);
        d_wheel->setObjectName(QStringLiteral("d_wheel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(d_wheel->sizePolicy().hasHeightForWidth());
        d_wheel->setSizePolicy(sizePolicy);
        d_wheel->setMaximumSize(QSize(21, 51));
        d_wheel->setLayoutDirection(Qt::LeftToRight);
        d_wheel->setOrientation(Qt::Vertical);
        d_wheel->setWheelWidth(20);

        horizontalLayout_4->addWidget(d_wheel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        d_label = new QLabel(WheelBox);
        d_label->setObjectName(QStringLiteral("d_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setBold(false);
        font1.setWeight(50);
        d_label->setFont(font1);

        horizontalLayout->addWidget(d_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WheelBox);

        QMetaObject::connectSlotsByName(WheelBox);
    } // setupUi

    void retranslateUi(QWidget *WheelBox)
    {
        WheelBox->setWindowTitle(QApplication::translate("WheelBox", "WheelBox", 0));
        d_label->setText(QApplication::translate("WheelBox", "X\350\275\264\350\260\203\350\212\202", 0));
    } // retranslateUi

};

namespace Ui {
    class WheelBox: public Ui_WheelBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHEELBOX_H
