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
#include <QtWidgets/QCheckBox>
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
    QWidget *passageColorPage;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *passageGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *colorBtn_1;
    QLabel *label_3;
    QSpinBox *wideSpinBox_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *colorBtn_2;
    QLabel *label_5;
    QSpinBox *wideSpinBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QPushButton *colorBtn_3;
    QLabel *label_7;
    QSpinBox *wideSpinBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QPushButton *colorBtn_4;
    QLabel *label_12;
    QSpinBox *wideSpinBox_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QPushButton *colorBtn_5;
    QLabel *label_14;
    QSpinBox *wideSpinBox_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QPushButton *colorBtn_6;
    QLabel *label_16;
    QSpinBox *wideSpinBox_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QPushButton *colorBtn_7;
    QLabel *label_18;
    QSpinBox *wideSpinBox_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_19;
    QPushButton *colorBtn_8;
    QLabel *label_20;
    QSpinBox *wideSpinBox_8;
    QSpacerItem *horizontalSpacer;
    QWidget *fileNamePage;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *passageGroupBox_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QWidget *midLinePage;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *passageGroupBox_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QSpinBox *xLeftSpinBox;
    QLabel *label;
    QSpinBox *xRightSpinBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QSpinBox *yDownSpinBox;
    QLabel *label_21;
    QSpinBox *yTopSpinBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_22;
    QPushButton *plotColorBtn;
    QCheckBox *defaultCheckBox;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_23;
    QSpinBox *xStepSizeSpinBox;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_24;
    QSpinBox *yStepSizeSpinBox;
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
        PropertyWidget->resize(530, 312);
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
        passageColorPage = new QWidget();
        passageColorPage->setObjectName(QStringLiteral("passageColorPage"));
        verticalLayout_3 = new QVBoxLayout(passageColorPage);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        passageGroupBox = new QGroupBox(passageColorPage);
        passageGroupBox->setObjectName(QStringLiteral("passageGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(passageGroupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame = new QFrame(passageGroupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(39, 23));

        horizontalLayout_3->addWidget(label_2);

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

        horizontalLayout_3->addWidget(colorBtn_1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(20, 23));

        horizontalLayout_3->addWidget(label_3);

        wideSpinBox_1 = new QSpinBox(frame);
        wideSpinBox_1->setObjectName(QStringLiteral("wideSpinBox_1"));
        wideSpinBox_1->setMaximumSize(QSize(40, 20));
        wideSpinBox_1->setSingleStep(1);
        wideSpinBox_1->setValue(2);

        horizontalLayout_3->addWidget(wideSpinBox_1);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(39, 23));

        horizontalLayout_4->addWidget(label_4);

        colorBtn_2 = new QPushButton(frame);
        colorBtn_2->setObjectName(QStringLiteral("colorBtn_2"));
        sizePolicy1.setHeightForWidth(colorBtn_2->sizePolicy().hasHeightForWidth());
        colorBtn_2->setSizePolicy(sizePolicy1);
        colorBtn_2->setMinimumSize(QSize(0, 0));
        colorBtn_2->setMaximumSize(QSize(30, 30));
        colorBtn_2->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_2->setFlat(true);

        horizontalLayout_4->addWidget(colorBtn_2);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(20, 23));

        horizontalLayout_4->addWidget(label_5);

        wideSpinBox_2 = new QSpinBox(frame);
        wideSpinBox_2->setObjectName(QStringLiteral("wideSpinBox_2"));
        wideSpinBox_2->setMaximumSize(QSize(40, 20));
        wideSpinBox_2->setSingleStep(1);
        wideSpinBox_2->setValue(2);

        horizontalLayout_4->addWidget(wideSpinBox_2);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(39, 23));

        horizontalLayout_5->addWidget(label_6);

        colorBtn_3 = new QPushButton(frame);
        colorBtn_3->setObjectName(QStringLiteral("colorBtn_3"));
        sizePolicy1.setHeightForWidth(colorBtn_3->sizePolicy().hasHeightForWidth());
        colorBtn_3->setSizePolicy(sizePolicy1);
        colorBtn_3->setMinimumSize(QSize(0, 0));
        colorBtn_3->setMaximumSize(QSize(30, 30));
        colorBtn_3->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_3->setFlat(true);

        horizontalLayout_5->addWidget(colorBtn_3);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(20, 23));

        horizontalLayout_5->addWidget(label_7);

        wideSpinBox_3 = new QSpinBox(frame);
        wideSpinBox_3->setObjectName(QStringLiteral("wideSpinBox_3"));
        wideSpinBox_3->setMaximumSize(QSize(40, 20));
        wideSpinBox_3->setSingleStep(1);
        wideSpinBox_3->setValue(2);

        horizontalLayout_5->addWidget(wideSpinBox_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(39, 23));

        horizontalLayout_6->addWidget(label_8);

        colorBtn_4 = new QPushButton(frame);
        colorBtn_4->setObjectName(QStringLiteral("colorBtn_4"));
        sizePolicy1.setHeightForWidth(colorBtn_4->sizePolicy().hasHeightForWidth());
        colorBtn_4->setSizePolicy(sizePolicy1);
        colorBtn_4->setMinimumSize(QSize(0, 0));
        colorBtn_4->setMaximumSize(QSize(30, 30));
        colorBtn_4->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_4->setFlat(true);

        horizontalLayout_6->addWidget(colorBtn_4);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(20, 23));

        horizontalLayout_6->addWidget(label_12);

        wideSpinBox_4 = new QSpinBox(frame);
        wideSpinBox_4->setObjectName(QStringLiteral("wideSpinBox_4"));
        wideSpinBox_4->setMaximumSize(QSize(40, 20));
        wideSpinBox_4->setSingleStep(1);
        wideSpinBox_4->setValue(2);

        horizontalLayout_6->addWidget(wideSpinBox_4);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(39, 23));

        horizontalLayout_7->addWidget(label_13);

        colorBtn_5 = new QPushButton(frame);
        colorBtn_5->setObjectName(QStringLiteral("colorBtn_5"));
        sizePolicy1.setHeightForWidth(colorBtn_5->sizePolicy().hasHeightForWidth());
        colorBtn_5->setSizePolicy(sizePolicy1);
        colorBtn_5->setMinimumSize(QSize(0, 0));
        colorBtn_5->setMaximumSize(QSize(30, 30));
        colorBtn_5->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_5->setFlat(true);

        horizontalLayout_7->addWidget(colorBtn_5);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(20, 23));

        horizontalLayout_7->addWidget(label_14);

        wideSpinBox_5 = new QSpinBox(frame);
        wideSpinBox_5->setObjectName(QStringLiteral("wideSpinBox_5"));
        wideSpinBox_5->setMaximumSize(QSize(40, 20));
        wideSpinBox_5->setSingleStep(1);
        wideSpinBox_5->setValue(2);

        horizontalLayout_7->addWidget(wideSpinBox_5);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(39, 23));

        horizontalLayout_8->addWidget(label_15);

        colorBtn_6 = new QPushButton(frame);
        colorBtn_6->setObjectName(QStringLiteral("colorBtn_6"));
        sizePolicy1.setHeightForWidth(colorBtn_6->sizePolicy().hasHeightForWidth());
        colorBtn_6->setSizePolicy(sizePolicy1);
        colorBtn_6->setMinimumSize(QSize(0, 0));
        colorBtn_6->setMaximumSize(QSize(30, 30));
        colorBtn_6->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_6->setFlat(true);

        horizontalLayout_8->addWidget(colorBtn_6);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(20, 23));

        horizontalLayout_8->addWidget(label_16);

        wideSpinBox_6 = new QSpinBox(frame);
        wideSpinBox_6->setObjectName(QStringLiteral("wideSpinBox_6"));
        wideSpinBox_6->setMaximumSize(QSize(40, 20));
        wideSpinBox_6->setSingleStep(1);
        wideSpinBox_6->setValue(2);

        horizontalLayout_8->addWidget(wideSpinBox_6);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(39, 23));

        horizontalLayout_9->addWidget(label_17);

        colorBtn_7 = new QPushButton(frame);
        colorBtn_7->setObjectName(QStringLiteral("colorBtn_7"));
        sizePolicy1.setHeightForWidth(colorBtn_7->sizePolicy().hasHeightForWidth());
        colorBtn_7->setSizePolicy(sizePolicy1);
        colorBtn_7->setMinimumSize(QSize(0, 0));
        colorBtn_7->setMaximumSize(QSize(30, 30));
        colorBtn_7->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_7->setFlat(true);

        horizontalLayout_9->addWidget(colorBtn_7);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(20, 23));

        horizontalLayout_9->addWidget(label_18);

        wideSpinBox_7 = new QSpinBox(frame);
        wideSpinBox_7->setObjectName(QStringLiteral("wideSpinBox_7"));
        wideSpinBox_7->setMaximumSize(QSize(40, 20));
        wideSpinBox_7->setSingleStep(1);
        wideSpinBox_7->setValue(2);

        horizontalLayout_9->addWidget(wideSpinBox_7);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(39, 23));

        horizontalLayout_10->addWidget(label_19);

        colorBtn_8 = new QPushButton(frame);
        colorBtn_8->setObjectName(QStringLiteral("colorBtn_8"));
        sizePolicy1.setHeightForWidth(colorBtn_8->sizePolicy().hasHeightForWidth());
        colorBtn_8->setSizePolicy(sizePolicy1);
        colorBtn_8->setMinimumSize(QSize(0, 0));
        colorBtn_8->setMaximumSize(QSize(30, 30));
        colorBtn_8->setCursor(QCursor(Qt::PointingHandCursor));
        colorBtn_8->setFlat(true);

        horizontalLayout_10->addWidget(colorBtn_8);

        label_20 = new QLabel(frame);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(20, 23));

        horizontalLayout_10->addWidget(label_20);

        wideSpinBox_8 = new QSpinBox(frame);
        wideSpinBox_8->setObjectName(QStringLiteral("wideSpinBox_8"));
        wideSpinBox_8->setMaximumSize(QSize(40, 20));
        wideSpinBox_8->setSingleStep(1);
        wideSpinBox_8->setValue(2);

        horizontalLayout_10->addWidget(wideSpinBox_8);


        verticalLayout_6->addLayout(horizontalLayout_10);


        horizontalLayout_2->addWidget(frame);

        horizontalSpacer = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(passageGroupBox);

        stackedWidgetProperty->addWidget(passageColorPage);
        fileNamePage = new QWidget();
        fileNamePage->setObjectName(QStringLiteral("fileNamePage"));
        verticalLayout_5 = new QVBoxLayout(fileNamePage);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        passageGroupBox_2 = new QGroupBox(fileNamePage);
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

        stackedWidgetProperty->addWidget(fileNamePage);
        midLinePage = new QWidget();
        midLinePage->setObjectName(QStringLiteral("midLinePage"));
        verticalLayout_4 = new QVBoxLayout(midLinePage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        passageGroupBox_3 = new QGroupBox(midLinePage);
        passageGroupBox_3->setObjectName(QStringLiteral("passageGroupBox_3"));
        layoutWidget1 = new QWidget(passageGroupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 30, 250, 22));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        xLeftSpinBox = new QSpinBox(layoutWidget1);
        xLeftSpinBox->setObjectName(QStringLiteral("xLeftSpinBox"));
        xLeftSpinBox->setMinimum(-100000);
        xLeftSpinBox->setMaximum(100000);

        horizontalLayout_11->addWidget(xLeftSpinBox);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_11->addWidget(label);

        xRightSpinBox = new QSpinBox(layoutWidget1);
        xRightSpinBox->setObjectName(QStringLiteral("xRightSpinBox"));
        xRightSpinBox->setMinimum(-100000);
        xRightSpinBox->setMaximum(100000);
        xRightSpinBox->setValue(100000);

        horizontalLayout_11->addWidget(xRightSpinBox);

        layoutWidget2 = new QWidget(passageGroupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 100, 250, 22));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_12->addWidget(label_11);

        yDownSpinBox = new QSpinBox(layoutWidget2);
        yDownSpinBox->setObjectName(QStringLiteral("yDownSpinBox"));
        yDownSpinBox->setMinimum(-100000);
        yDownSpinBox->setMaximum(100000);

        horizontalLayout_12->addWidget(yDownSpinBox);

        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_12->addWidget(label_21);

        yTopSpinBox = new QSpinBox(layoutWidget2);
        yTopSpinBox->setObjectName(QStringLiteral("yTopSpinBox"));
        yTopSpinBox->setMinimum(-100000);
        yTopSpinBox->setMaximum(100000);
        yTopSpinBox->setValue(100000);

        horizontalLayout_12->addWidget(yTopSpinBox);

        layoutWidget3 = new QWidget(passageGroupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 180, 175, 25));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_13->addWidget(label_22);

        plotColorBtn = new QPushButton(layoutWidget3);
        plotColorBtn->setObjectName(QStringLiteral("plotColorBtn"));
        sizePolicy1.setHeightForWidth(plotColorBtn->sizePolicy().hasHeightForWidth());
        plotColorBtn->setSizePolicy(sizePolicy1);
        plotColorBtn->setMinimumSize(QSize(0, 0));
        plotColorBtn->setMaximumSize(QSize(30, 30));
        plotColorBtn->setCursor(QCursor(Qt::PointingHandCursor));
        plotColorBtn->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #00316E, stop:1  #0057AE);"));
        plotColorBtn->setFlat(true);

        horizontalLayout_13->addWidget(plotColorBtn);

        defaultCheckBox = new QCheckBox(layoutWidget3);
        defaultCheckBox->setObjectName(QStringLiteral("defaultCheckBox"));
        defaultCheckBox->setChecked(true);

        horizontalLayout_13->addWidget(defaultCheckBox);

        layoutWidget4 = new QWidget(passageGroupBox_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 60, 156, 22));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget4);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_14->addWidget(label_23);

        xStepSizeSpinBox = new QSpinBox(layoutWidget4);
        xStepSizeSpinBox->setObjectName(QStringLiteral("xStepSizeSpinBox"));
        xStepSizeSpinBox->setMinimum(-100000);
        xStepSizeSpinBox->setMaximum(100000);
        xStepSizeSpinBox->setValue(40);

        horizontalLayout_14->addWidget(xStepSizeSpinBox);

        layoutWidget5 = new QWidget(passageGroupBox_3);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 130, 156, 22));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget5);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_15->addWidget(label_24);

        yStepSizeSpinBox = new QSpinBox(layoutWidget5);
        yStepSizeSpinBox->setObjectName(QStringLiteral("yStepSizeSpinBox"));
        yStepSizeSpinBox->setMinimum(-100000);
        yStepSizeSpinBox->setMaximum(100000);
        yStepSizeSpinBox->setValue(400);

        horizontalLayout_15->addWidget(yStepSizeSpinBox);


        verticalLayout_4->addWidget(passageGroupBox_3);

        stackedWidgetProperty->addWidget(midLinePage);

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


        retranslateUi(PropertyWidget);

        stackedWidgetProperty->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *PropertyWidget)
    {
        PropertyWidget->setWindowTitle(QApplication::translate("PropertyWidget", "\345\261\236\346\200\247\350\256\276\347\275\256", 0));
        groupBoxPropertyWidget->setTitle(QString());
        colorBtnProperty->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\223\351\242\234\350\211\262", 0));
        fileNameBtnProperty->setText(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\221\275\345\220\215", 0));
        midMarkBtnProperty->setText(QApplication::translate("PropertyWidget", "\347\224\273\345\270\203", 0));
        passageGroupBox->setTitle(QApplication::translate("PropertyWidget", "\351\200\232\351\201\223\351\242\234\350\211\262\351\205\215\347\275\256", 0));
        label_2->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2231\357\274\232", 0));
        colorBtn_1->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_3->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_1->setSuffix(QString());
        wideSpinBox_1->setPrefix(QString());
        label_4->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2232\357\274\232", 0));
        colorBtn_2->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_5->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_2->setSuffix(QString());
        wideSpinBox_2->setPrefix(QString());
        label_6->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2233\357\274\232", 0));
        colorBtn_3->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_7->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_3->setSuffix(QString());
        wideSpinBox_3->setPrefix(QString());
        label_8->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2234\357\274\232", 0));
        colorBtn_4->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_12->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_4->setSuffix(QString());
        wideSpinBox_4->setPrefix(QString());
        label_13->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2235\357\274\232", 0));
        colorBtn_5->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_14->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_5->setSuffix(QString());
        wideSpinBox_5->setPrefix(QString());
        label_15->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2236\357\274\232", 0));
        colorBtn_6->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_16->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_6->setSuffix(QString());
        wideSpinBox_6->setPrefix(QString());
        label_17->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2237\357\274\232", 0));
        colorBtn_7->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_18->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_7->setSuffix(QString());
        wideSpinBox_7->setPrefix(QString());
        label_19->setText(QApplication::translate("PropertyWidget", "\351\200\232\351\201\2238\357\274\232", 0));
        colorBtn_8->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        label_20->setText(QApplication::translate("PropertyWidget", "\347\262\227\357\274\232", 0));
        wideSpinBox_8->setSuffix(QString());
        wideSpinBox_8->setPrefix(QString());
        passageGroupBox_2->setTitle(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\221\275\345\220\215\346\240\274\345\274\217", 0));
        label_9->setText(QApplication::translate("PropertyWidget", "\346\226\207\344\273\266\345\220\215\357\274\232", 0));
        passageGroupBox_3->setTitle(QApplication::translate("PropertyWidget", "\344\270\255\351\227\264\347\272\277\350\256\276\347\275\256", 0));
        label_10->setText(QApplication::translate("PropertyWidget", "X\350\275\264\345\235\220\346\240\207\350\214\203\345\233\264\357\274\232", 0));
        label->setText(QApplication::translate("PropertyWidget", "\350\207\263", 0));
        label_11->setText(QApplication::translate("PropertyWidget", "Y\350\275\264\345\235\220\346\240\207\350\214\203\345\233\264\357\274\232", 0));
        label_21->setText(QApplication::translate("PropertyWidget", "\350\207\263", 0));
        label_22->setText(QApplication::translate("PropertyWidget", "\347\224\273\345\270\203\350\203\214\346\231\257\357\274\232", 0));
        plotColorBtn->setText(QApplication::translate("PropertyWidget", "\351\242\234\350\211\262", 0));
        defaultCheckBox->setText(QApplication::translate("PropertyWidget", "\351\273\230\350\256\244", 0));
        label_23->setText(QApplication::translate("PropertyWidget", "X\350\275\264\345\235\220\346\240\207\351\227\264\350\267\235\357\274\232", 0));
        label_24->setText(QApplication::translate("PropertyWidget", "X\350\275\264\345\235\220\346\240\207\351\227\264\350\267\235\357\274\232", 0));
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
