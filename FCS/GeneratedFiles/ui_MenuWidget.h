/********************************************************************************
** Form generated from reading UI file 'MenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QAction *newExpAction;
    QAction *openExpAction;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileBtn;
    QPushButton *expBtn;
    QPushButton *settingBtn;
    QPushButton *helpBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QStringLiteral("MenuWidget"));
        MenuWidget->resize(618, 22);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MenuWidget->sizePolicy().hasHeightForWidth());
        MenuWidget->setSizePolicy(sizePolicy);
        MenuWidget->setMaximumSize(QSize(16777215, 22));
        MenuWidget->setStyleSheet(QStringLiteral(""));
        newExpAction = new QAction(MenuWidget);
        newExpAction->setObjectName(QStringLiteral("newExpAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/Big.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        newExpAction->setIcon(icon);
        openExpAction = new QAction(MenuWidget);
        openExpAction->setObjectName(QStringLiteral("openExpAction"));
        verticalLayout = new QVBoxLayout(MenuWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(MenuWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        fileBtn = new QPushButton(frame);
        fileBtn->setObjectName(QStringLiteral("fileBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileBtn->sizePolicy().hasHeightForWidth());
        fileBtn->setSizePolicy(sizePolicy1);
        fileBtn->setMaximumSize(QSize(60, 20));
        fileBtn->setStyleSheet(QStringLiteral(""));
        fileBtn->setFlat(false);

        horizontalLayout->addWidget(fileBtn);

        expBtn = new QPushButton(frame);
        expBtn->setObjectName(QStringLiteral("expBtn"));
        sizePolicy1.setHeightForWidth(expBtn->sizePolicy().hasHeightForWidth());
        expBtn->setSizePolicy(sizePolicy1);
        expBtn->setMaximumSize(QSize(100, 20));
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        expBtn->setPalette(palette);
        expBtn->setFocusPolicy(Qt::StrongFocus);
        expBtn->setAutoFillBackground(false);
        expBtn->setStyleSheet(QStringLiteral(""));
        expBtn->setFlat(false);

        horizontalLayout->addWidget(expBtn);

        settingBtn = new QPushButton(frame);
        settingBtn->setObjectName(QStringLiteral("settingBtn"));
        sizePolicy1.setHeightForWidth(settingBtn->sizePolicy().hasHeightForWidth());
        settingBtn->setSizePolicy(sizePolicy1);
        settingBtn->setMaximumSize(QSize(60, 20));
        settingBtn->setStyleSheet(QStringLiteral(""));
        settingBtn->setFlat(false);

        horizontalLayout->addWidget(settingBtn);

        helpBtn = new QPushButton(frame);
        helpBtn->setObjectName(QStringLiteral("helpBtn"));
        sizePolicy1.setHeightForWidth(helpBtn->sizePolicy().hasHeightForWidth());
        helpBtn->setSizePolicy(sizePolicy1);
        helpBtn->setMaximumSize(QSize(60, 20));
        helpBtn->setStyleSheet(QStringLiteral(""));
        helpBtn->setFlat(false);

        horizontalLayout->addWidget(helpBtn);

        horizontalSpacer = new QSpacerItem(203, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QApplication::translate("MenuWidget", "MenuWidget", 0));
        newExpAction->setText(QApplication::translate("MenuWidget", "\346\226\260\345\273\272\345\256\236\351\252\214", 0));
#ifndef QT_NO_TOOLTIP
        newExpAction->setToolTip(QApplication::translate("MenuWidget", "\346\226\260\345\273\272\345\256\236\351\252\214", 0));
#endif // QT_NO_TOOLTIP
        openExpAction->setText(QApplication::translate("MenuWidget", "\346\211\223\345\274\200\345\256\236\351\252\214", 0));
#ifndef QT_NO_TOOLTIP
        openExpAction->setToolTip(QApplication::translate("MenuWidget", "\346\211\223\345\274\200\345\256\236\351\252\214", 0));
#endif // QT_NO_TOOLTIP
        fileBtn->setText(QApplication::translate("MenuWidget", "\346\226\207\344\273\266", 0));
        expBtn->setText(QApplication::translate("MenuWidget", "\345\256\236\351\252\214", 0));
        settingBtn->setText(QApplication::translate("MenuWidget", "\350\256\276\347\275\256", 0));
        helpBtn->setText(QApplication::translate("MenuWidget", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
