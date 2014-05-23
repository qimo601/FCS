/********************************************************************************
** Form generated from reading UI file 'MTitleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTITLEWIDGET_H
#define UI_MTITLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "Ui/Library/pushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MTitleWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *titlePicLbl;
    QLabel *TitleTextLbl;
    QSpacerItem *horizontalSpacer;
    PushButton *minBtn;
    PushButton *maxBtn;
    PushButton *closeBtn;

    void setupUi(QWidget *MTitleWidget)
    {
        if (MTitleWidget->objectName().isEmpty())
            MTitleWidget->setObjectName(QStringLiteral("MTitleWidget"));
        MTitleWidget->resize(704, 23);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MTitleWidget->sizePolicy().hasHeightForWidth());
        MTitleWidget->setSizePolicy(sizePolicy);
        MTitleWidget->setMaximumSize(QSize(16777215, 23));
        horizontalLayout = new QHBoxLayout(MTitleWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titlePicLbl = new QLabel(MTitleWidget);
        titlePicLbl->setObjectName(QStringLiteral("titlePicLbl"));
        titlePicLbl->setPixmap(QPixmap(QString::fromUtf8(":/MainWindow/Resources/Images/sibet.png")));

        horizontalLayout->addWidget(titlePicLbl);

        TitleTextLbl = new QLabel(MTitleWidget);
        TitleTextLbl->setObjectName(QStringLiteral("TitleTextLbl"));

        horizontalLayout->addWidget(TitleTextLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minBtn = new PushButton(MTitleWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setFlat(true);

        horizontalLayout->addWidget(minBtn);

        maxBtn = new PushButton(MTitleWidget);
        maxBtn->setObjectName(QStringLiteral("maxBtn"));
        maxBtn->setFlat(true);

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new PushButton(MTitleWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setFlat(true);

        horizontalLayout->addWidget(closeBtn);


        retranslateUi(MTitleWidget);

        QMetaObject::connectSlotsByName(MTitleWidget);
    } // setupUi

    void retranslateUi(QWidget *MTitleWidget)
    {
        MTitleWidget->setWindowTitle(QApplication::translate("MTitleWidget", "MTitleWidget", 0));
        titlePicLbl->setText(QString());
        TitleTextLbl->setText(QApplication::translate("MTitleWidget", "\346\265\201\345\274\217\347\273\206\350\203\236\344\273\252\350\275\257\344\273\266", 0));
        minBtn->setText(QApplication::translate("MTitleWidget", "\347\274\251\345\260\217", 0));
        maxBtn->setText(QApplication::translate("MTitleWidget", "\346\224\276\345\244\247", 0));
        closeBtn->setText(QApplication::translate("MTitleWidget", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class MTitleWidget: public Ui_MTitleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTITLEWIDGET_H
