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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertyWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxPropertyWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *colorBtnProperty;
    QPushButton *fileNameBtnProperty;
    QPushButton *midMarkBtnProperty;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidgetProperty;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *passageGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_2;
    QPushButton *colorBtn_1;
    QLabel *label;
    QPushButton *colorBtn_2;
    QLabel *label_3;
    QPushButton *colorBtn_3;
    QLabel *label_4;
    QPushButton *colorBtn_4;
    QLabel *label_5;
    QPushButton *colorBtn_5;
    QLabel *label_6;
    QPushButton *colorBtn_6;
    QLabel *label_7;
    QPushButton *colorBtn_7;
    QLabel *label_8;
    QPushButton *colorBtn_8;
    QSpacerItem *horizontalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *passageGroupBox_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *passageGroupBox_3;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QSpinBox *spinBox;
    QLabel *label_11;
    QSpinBox *spinBox_2;
    QGroupBox *rightGroupBoxProperty;
    QVBoxLayout *verticalLayout_2;
    QPushButton *okBtnProperty;
    QPushButton *cancleBtnPropety;
    QSpacerItem *verticalSpacer_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *PropertyWidget)
    {
        if (PropertyWidget->objectName().isEmpty())
            PropertyWidget->setObjectName(QStringLiteral("PropertyWidget"));
        PropertyWidget->setWindowModality(Qt::WindowModal);
        PropertyWidget->resize(530, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PropertyWidget->sizePolicy().hasHeightForWidth());
        PropertyWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PropertyWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBoxPropertyWidget = new QGroupBox(PropertyWidget);
        groupBoxPropertyWidget->setObjectName(QStringLiteral("groupBoxPropertyWidget"));
        verticalLayout = new QVBoxLayout(groupBoxPropertyWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        colorBtnProperty = new QPushButton(groupBoxPropertyWidget);
        buttonGroup = new QButtonGroup(PropertyWidget);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(colorBtnProperty);
        colorBtnProperty->setObjectName(QStringLiteral("colorBtnProperty"));
        colorBtnProperty->setCheckable(true);
        colorBtnProperty->setChecked(true);
        colorBtnProperty->setFlat(true);

        verticalLayout->addWidget(colorBtnProperty);

        fileNameBtnProperty = new QPushButton(groupBoxPropertyWidget);
        buttonGroup->addButton(fileNameBtnProperty);
        fileNameBtnProperty->setObjectName(QStringLiteral("fileNameBtnProperty"));
        fileNameBtnProperty->setCheckable(true);
        fileNameBtnProperty->setFlat(true);

        verticalLayout->addWidget(fileNameBtnProperty);

        midMarkBtnProperty = new QPushButton(groupBoxPropertyWidget);
        buttonGroup->addButton(midMarkBtnProperty);
        midMarkBtnProperty->setObjectName(QStringLiteral("midMarkBtnProperty"));
        midMarkBtnProperty->setCheckable(true);
        midMarkBtnProperty->setFlat(true);

        verticalLayout->addWidget(midMarkBtnProperty);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBoxPropertyWidget);

        stackedWidgetProperty = new QStackedWidget(PropertyWidget);
        stackedWidgetProperty->setObjectName(QStringLiteral("stackedWidgetProperty"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        passageGroupBox = new QGroupBox(page);
        passageGroupBox->setObjectName(QStringLiteral("passageGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(passageGroupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 9, -1, -1);
        frame = new QFrame(passageGroupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        colorBtn_1 = new QPushButton(frame);
        colorBtn_1->setObjectName(QStringLiteral("colorBtn_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorBtn_1->sizePolicy().hasHeightForWidth());
        colorBtn_1->setSizePolicy(sizePolicy1);
        colorBtn_1->setMinimumSize(QSize(0, 0));
        colorBtn_1->setMaximumSize(QSize(30, 30));
        colorBtn_1->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_1->setFlat(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, colorBtn_1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        colorBtn_2 = new QPushButton(frame);
        colorBtn_2->setObjectName(QStringLiteral("colorBtn_2"));
        sizePolicy1.setHeightForWidth(colorBtn_2->sizePolicy().hasHeightForWidth());
        colorBtn_2->setSizePolicy(sizePolicy1);
        colorBtn_2->setMinimumSize(QSize(0, 0));
        colorBtn_2->setMaximumSize(QSize(30, 30));
        colorBtn_2->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_2->setFlat(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, colorBtn_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        colorBtn_3 = new QPushButton(frame);
        colorBtn_3->setObjectName(QStringLiteral("colorBtn_3"));
        sizePolicy1.setHeightForWidth(colorBtn_3->sizePolicy().hasHeightForWidth());
        colorBtn_3->setSizePolicy(sizePolicy1);
        colorBtn_3->setMinimumSize(QSize(0, 0));
        colorBtn_3->setMaximumSize(QSize(30, 30));
        colorBtn_3->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_3->setFlat(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, colorBtn_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        colorBtn_4 = new QPushButton(frame);
        colorBtn_4->setObjectName(QStringLiteral("colorBtn_4"));
        sizePolicy1.setHeightForWidth(colorBtn_4->sizePolicy().hasHeightForWidth());
        colorBtn_4->setSizePolicy(sizePolicy1);
        colorBtn_4->setMinimumSize(QSize(0, 0));
        colorBtn_4->setMaximumSize(QSize(30, 30));
        colorBtn_4->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_4->setFlat(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, colorBtn_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        colorBtn_5 = new QPushButton(frame);
        colorBtn_5->setObjectName(QStringLiteral("colorBtn_5"));
        sizePolicy1.setHeightForWidth(colorBtn_5->sizePolicy().hasHeightForWidth());
        colorBtn_5->setSizePolicy(sizePolicy1);
        colorBtn_5->setMinimumSize(QSize(0, 0));
        colorBtn_5->setMaximumSize(QSize(30, 30));
        colorBtn_5->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_5->setFlat(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, colorBtn_5);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        colorBtn_6 = new QPushButton(frame);
        colorBtn_6->setObjectName(QStringLiteral("colorBtn_6"));
        sizePolicy1.setHeightForWidth(colorBtn_6->sizePolicy().hasHeightForWidth());
        colorBtn_6->setSizePolicy(sizePolicy1);
        colorBtn_6->setMinimumSize(QSize(0, 0));
        colorBtn_6->setMaximumSize(QSize(30, 30));
        colorBtn_6->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_6->setFlat(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, colorBtn_6);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        colorBtn_7 = new QPushButton(frame);
        colorBtn_7->setObjectName(QStringLiteral("colorBtn_7"));
        sizePolicy1.setHeightForWidth(colorBtn_7->sizePolicy().hasHeightForWidth());
        colorBtn_7->setSizePolicy(sizePolicy1);
        colorBtn_7->setMinimumSize(QSize(0, 0));
        colorBtn_7->setMaximumSize(QSize(30, 30));
        colorBtn_7->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_7->setFlat(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, colorBtn_7);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        colorBtn_8 = new QPushButton(frame);
        colorBtn_8->setObjectName(QStringLiteral("colorBtn_8"));
        sizePolicy1.setHeightForWidth(colorBtn_8->sizePolicy().hasHeightForWidth());
        colorBtn_8->setSizePolicy(sizePolicy1);
        colorBtn_8->setMinimumSize(QSize(0, 0));
        colorBtn_8->setMaximumSize(QSize(30, 30));
        colorBtn_8->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_8->setFlat(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, colorBtn_8);


        horizontalLayout_2->addWidget(frame);

        horizontalSpacer = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(passageGroupBox);

        stackedWidgetProperty->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        passageGroupBox_2 = new QGroupBox(page_2);
        passageGroupBox_2->setObjectName(QStringLiteral("passageGroupBox_2"));
        layoutWidget = new QWidget(passageGroupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 189, 22));
        formLayout_3 = new QFormLayout(layoutWidget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout_5->addWidget(passageGroupBox_2);

        stackedWidgetProperty->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        passageGroupBox_3 = new QGroupBox(page_3);
        passageGroupBox_3->setObjectName(QStringLiteral("passageGroupBox_3"));
        layoutWidget1 = new QWidget(passageGroupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 161, 81));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        spinBox = new QSpinBox(layoutWidget1);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        spinBox_2 = new QSpinBox(layoutWidget1);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_2);


        verticalLayout_4->addWidget(passageGroupBox_3);

        stackedWidgetProperty->addWidget(page_3);

        horizontalLayout->addWidget(stackedWidgetProperty);

        rightGroupBoxProperty = new QGroupBox(PropertyWidget);
        rightGroupBoxProperty->setObjectName(QStringLiteral("rightGroupBoxProperty"));
        verticalLayout_2 = new QVBoxLayout(rightGroupBoxProperty);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        okBtnProperty = new QPushButton(rightGroupBoxProperty);
        okBtnProperty->setObjectName(QStringLiteral("okBtnProperty"));

        verticalLayout_2->addWidget(okBtnProperty);

        cancleBtnPropety = new QPushButton(rightGroupBoxProperty);
        cancleBtnPropety->setObjectName(QStringLiteral("cancleBtnPropety"));

        verticalLayout_2->addWidget(cancleBtnPropety);

        verticalSpacer_2 = new QSpacerItem(20, 201, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(rightGroupBoxProperty);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(colorBtn_2);
        label->setBuddy(colorBtn_2);
        label_3->setBuddy(colorBtn_2);
        label_4->setBuddy(colorBtn_2);
        label_5->setBuddy(colorBtn_2);
        label_6->setBuddy(colorBtn_2);
        label_7->setBuddy(colorBtn_2);
        label_8->setBuddy(colorBtn_2);
#endif // QT_NO_SHORTCUT

        retranslateUi(PropertyWidget);

        stackedWidgetProperty->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *PropertyWidget)
    {
        PropertyWidget->setWindowTitle(QApplication::translate("PropertyWidget", "PropertyWidget", 0));
        groupBoxPropertyWidget->setTitle(QString());
        colorBtnProperty->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\223\351\242\234\350\211\262", 0));
        fileNameBtnProperty->setText(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\221\275\345\220\215", 0));
        midMarkBtnProperty->setText(QApplication::translate("PropertyWidget", "\344\270\255\351\227\264\347\272\277\344\275\215\347\275\256", 0));
        passageGroupBox->setTitle(QApplication::translate("PropertyWidget", "\351\200\232\351\201\223\351\242\234\350\211\262\351\205\215\347\275\256", 0));
        label_2->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2231", 0));
        colorBtn_1->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2232", 0));
        colorBtn_2->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_3->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2233", 0));
        colorBtn_3->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_4->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2234", 0));
        colorBtn_4->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_5->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2235", 0));
        colorBtn_5->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_6->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2236", 0));
        colorBtn_6->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_7->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2237", 0));
        colorBtn_7->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_8->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2238", 0));
        colorBtn_8->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        passageGroupBox_2->setTitle(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\221\275\345\220\215\346\240\274\345\274\217", 0));
        label_9->setText(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\220\215\357\274\232", 0));
        passageGroupBox_3->setTitle(QApplication::translate("PropertyWidget", "\344\270\255\351\227\264\347\272\277\350\256\276\347\275\256", 0));
        label_10->setText(QApplication::translate("PropertyWidget", "X\350\275\264\344\270\255\351\227\264\347\272\277\357\274\232", 0));
        label_11->setText(QApplication::translate("PropertyWidget", "Y\350\275\264\344\270\255\351\227\264\347\272\277\357\274\232", 0));
        rightGroupBoxProperty->setTitle(QString());
        okBtnProperty->setText(QApplication::translate("PropertyWidget", "\347\241\256\345\256\232", 0));
        cancleBtnPropety->setText(QApplication::translate("PropertyWidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class PropertyWidget: public Ui_PropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYWIDGET_H
