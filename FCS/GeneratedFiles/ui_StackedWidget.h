/********************************************************************************
** Form generated from reading UI file 'StackedWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKEDWIDGET_H
#define UI_STACKEDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Ui/Library/ViewWidget.h>
#include "ui/Library/ReportWidget.h"

QT_BEGIN_NAMESPACE

class Ui_StackedWidget
{
public:
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout_2;
    QDockWidget *statusDockWidget;
    QWidget *statusDockWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *usbBtn;
    QToolButton *lockBtn;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_10;
    QTextBrowser *textBrowser;
    QDockWidget *controlDockWidget;
    QWidget *controlDockWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QSpinBox *fluidSpin;
    QPushButton *setFluidBtn;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QSpinBox *sampleSpin;
    QPushButton *setSampleBtn;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *midRadioButton;
    QRadioButton *hightRadioButton;
    QRadioButton *lowRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *passageComboBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *strengthSpin;
    QPushButton *setLaserBtn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QSpinBox *triggerSpin;
    QPushButton *setTriggerBtn;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *voltageSpin;
    QPushButton *setChannelBiasBtn;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QFrame *rightFrame;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *viewStackedWidget;
    QWidget *dataAnalyPage;
    QVBoxLayout *verticalLayout_4;
    QWidget *toolBtnWidget;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    ViewWidget *widget;
    ReportWidget *reportWidget;
    QFrame *bottomFrame;
    QPushButton *pushButton;
    QPushButton *startAcquisitionBtn;
    QCheckBox *saveCheckBox;
    QPushButton *stopAcquisitionBtn;
    QCheckBox *checkBox_2;
    QSpinBox *spinBox_4;
    QCheckBox *checkBox_3;
    QSpinBox *spinBox_5;
    QCheckBox *checkBox_4;
    QSpinBox *spinBox_6;
    QButtonGroup *buttonGroup;

    void setupUi(QStackedWidget *StackedWidget)
    {
        if (StackedWidget->objectName().isEmpty())
            StackedWidget->setObjectName(QStringLiteral("StackedWidget"));
        StackedWidget->resize(1150, 915);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 20, 6, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftFrame = new QFrame(page);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(leftFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        statusDockWidget = new QDockWidget(leftFrame);
        statusDockWidget->setObjectName(QStringLiteral("statusDockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusDockWidget->sizePolicy().hasHeightForWidth());
        statusDockWidget->setSizePolicy(sizePolicy);
        statusDockWidget->setMinimumSize(QSize(250, 180));
        statusDockWidget->setMaximumSize(QSize(250, 180));
        statusDockWidget->setStyleSheet(QStringLiteral(""));
        statusDockWidgetContents = new QWidget();
        statusDockWidgetContents->setObjectName(QStringLiteral("statusDockWidgetContents"));
        verticalLayout_7 = new QVBoxLayout(statusDockWidgetContents);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        usbBtn = new QToolButton(statusDockWidgetContents);
        usbBtn->setObjectName(QStringLiteral("usbBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/usb_disconnected.png"), QSize(), QIcon::Normal, QIcon::Off);
        usbBtn->setIcon(icon);
        usbBtn->setIconSize(QSize(64, 32));

        horizontalLayout_9->addWidget(usbBtn);

        lockBtn = new QToolButton(statusDockWidgetContents);
        lockBtn->setObjectName(QStringLiteral("lockBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockBtn->setIcon(icon1);
        lockBtn->setIconSize(QSize(128, 32));

        horizontalLayout_9->addWidget(lockBtn);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(statusDockWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_10);

        textBrowser = new QTextBrowser(statusDockWidgetContents);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMaximumSize(QSize(228, 41));
        textBrowser->setFrameShape(QFrame::Box);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setLineWidth(1);
        textBrowser->setLineWrapMode(QTextEdit::WidgetWidth);

        verticalLayout_7->addWidget(textBrowser);

        statusDockWidget->setWidget(statusDockWidgetContents);

        verticalLayout_2->addWidget(statusDockWidget);

        controlDockWidget = new QDockWidget(leftFrame);
        controlDockWidget->setObjectName(QStringLiteral("controlDockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(controlDockWidget->sizePolicy().hasHeightForWidth());
        controlDockWidget->setSizePolicy(sizePolicy2);
        controlDockWidget->setMinimumSize(QSize(250, 320));
        controlDockWidget->setMaximumSize(QSize(250, 524287));
        controlDockWidget->setStyleSheet(QStringLiteral(""));
        controlDockWidgetContents = new QWidget();
        controlDockWidgetContents->setObjectName(QStringLiteral("controlDockWidgetContents"));
        controlDockWidgetContents->setStyleSheet(QStringLiteral(""));
        verticalLayout_6 = new QVBoxLayout(controlDockWidgetContents);
        verticalLayout_6->setSpacing(7);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, 0);
        label_11 = new QLabel(controlDockWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(81, 16));
        label_11->setMaximumSize(QSize(81, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        label_11->setFont(font);
        label_11->setStyleSheet(QStringLiteral(""));

        horizontalLayout_8->addWidget(label_11);

        fluidSpin = new QSpinBox(controlDockWidgetContents);
        fluidSpin->setObjectName(QStringLiteral("fluidSpin"));
        fluidSpin->setMinimumSize(QSize(59, 23));
        fluidSpin->setMaximumSize(QSize(59, 23));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        fluidSpin->setFont(font1);
        fluidSpin->setMaximum(4095);

        horizontalLayout_8->addWidget(fluidSpin);

        setFluidBtn = new QPushButton(controlDockWidgetContents);
        setFluidBtn->setObjectName(QStringLiteral("setFluidBtn"));
        setFluidBtn->setMinimumSize(QSize(40, 23));
        setFluidBtn->setMaximumSize(QSize(40, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        setFluidBtn->setIcon(icon2);

        horizontalLayout_8->addWidget(setFluidBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_8);

        line_2 = new QFrame(controlDockWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setStyleSheet(QStringLiteral(""));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(controlDockWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMinimumSize(QSize(81, 16));
        label_8->setMaximumSize(QSize(81, 16));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral(""));

        horizontalLayout_5->addWidget(label_8);

        sampleSpin = new QSpinBox(controlDockWidgetContents);
        sampleSpin->setObjectName(QStringLiteral("sampleSpin"));
        sampleSpin->setMinimumSize(QSize(59, 23));
        sampleSpin->setMaximumSize(QSize(59, 23));
        sampleSpin->setFont(font1);
        sampleSpin->setMaximum(4095);

        horizontalLayout_5->addWidget(sampleSpin);

        setSampleBtn = new QPushButton(controlDockWidgetContents);
        setSampleBtn->setObjectName(QStringLiteral("setSampleBtn"));
        setSampleBtn->setMinimumSize(QSize(40, 23));
        setSampleBtn->setMaximumSize(QSize(40, 23));
        setSampleBtn->setIcon(icon2);

        horizontalLayout_5->addWidget(setSampleBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        midRadioButton = new QRadioButton(controlDockWidgetContents);
        buttonGroup = new QButtonGroup(StackedWidget);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(midRadioButton);
        midRadioButton->setObjectName(QStringLiteral("midRadioButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        midRadioButton->setFont(font2);

        verticalLayout_5->addWidget(midRadioButton);

        hightRadioButton = new QRadioButton(controlDockWidgetContents);
        buttonGroup->addButton(hightRadioButton);
        hightRadioButton->setObjectName(QStringLiteral("hightRadioButton"));
        hightRadioButton->setFont(font2);

        verticalLayout_5->addWidget(hightRadioButton);

        lowRadioButton = new QRadioButton(controlDockWidgetContents);
        buttonGroup->addButton(lowRadioButton);
        lowRadioButton->setObjectName(QStringLiteral("lowRadioButton"));
        lowRadioButton->setFont(font2);

        verticalLayout_5->addWidget(lowRadioButton);


        horizontalLayout_7->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_7);

        line = new QFrame(controlDockWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(controlDockWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMinimumSize(QSize(81, 16));
        label_7->setMaximumSize(QSize(81, 16));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral(""));

        horizontalLayout_6->addWidget(label_7);

        passageComboBox = new QComboBox(controlDockWidgetContents);
        passageComboBox->setObjectName(QStringLiteral("passageComboBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(59);
        sizePolicy4.setVerticalStretch(18);
        sizePolicy4.setHeightForWidth(passageComboBox->sizePolicy().hasHeightForWidth());
        passageComboBox->setSizePolicy(sizePolicy4);
        passageComboBox->setMinimumSize(QSize(59, 23));
        passageComboBox->setMaximumSize(QSize(59, 23));
        passageComboBox->setFont(font2);

        horizontalLayout_6->addWidget(passageComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(controlDockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(81, 16));
        label->setMaximumSize(QSize(81, 16));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label);

        strengthSpin = new QSpinBox(controlDockWidgetContents);
        strengthSpin->setObjectName(QStringLiteral("strengthSpin"));
        strengthSpin->setMinimumSize(QSize(59, 23));
        strengthSpin->setMaximumSize(QSize(59, 23));
        strengthSpin->setFont(font1);

        horizontalLayout_2->addWidget(strengthSpin);

        setLaserBtn = new QPushButton(controlDockWidgetContents);
        setLaserBtn->setObjectName(QStringLiteral("setLaserBtn"));
        setLaserBtn->setMinimumSize(QSize(40, 23));
        setLaserBtn->setMaximumSize(QSize(40, 23));
        setLaserBtn->setIcon(icon2);

        horizontalLayout_2->addWidget(setLaserBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(controlDockWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(81, 16));
        label_9->setMaximumSize(QSize(81, 16));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_9);

        triggerSpin = new QSpinBox(controlDockWidgetContents);
        triggerSpin->setObjectName(QStringLiteral("triggerSpin"));
        triggerSpin->setMinimumSize(QSize(59, 23));
        triggerSpin->setMaximumSize(QSize(59, 23));
        triggerSpin->setFont(font1);
        triggerSpin->setMaximum(65536);

        horizontalLayout_4->addWidget(triggerSpin);

        setTriggerBtn = new QPushButton(controlDockWidgetContents);
        setTriggerBtn->setObjectName(QStringLiteral("setTriggerBtn"));
        setTriggerBtn->setMinimumSize(QSize(40, 23));
        setTriggerBtn->setMaximumSize(QSize(40, 23));
        setTriggerBtn->setIcon(icon2);

        horizontalLayout_4->addWidget(setTriggerBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(controlDockWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(81, 16));
        label_6->setMaximumSize(QSize(81, 16));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(label_6);

        voltageSpin = new QSpinBox(controlDockWidgetContents);
        voltageSpin->setObjectName(QStringLiteral("voltageSpin"));
        voltageSpin->setMinimumSize(QSize(59, 23));
        voltageSpin->setMaximumSize(QSize(59, 23));
        voltageSpin->setFont(font1);

        horizontalLayout_3->addWidget(voltageSpin);

        setChannelBiasBtn = new QPushButton(controlDockWidgetContents);
        setChannelBiasBtn->setObjectName(QStringLiteral("setChannelBiasBtn"));
        setChannelBiasBtn->setMinimumSize(QSize(40, 23));
        setChannelBiasBtn->setMaximumSize(QSize(40, 23));
        setChannelBiasBtn->setIcon(icon2);

        horizontalLayout_3->addWidget(setChannelBiasBtn);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_3);

        controlDockWidget->setWidget(controlDockWidgetContents);

        verticalLayout_2->addWidget(controlDockWidget);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(leftFrame);

        rightFrame = new QFrame(page);
        rightFrame->setObjectName(QStringLiteral("rightFrame"));
        rightFrame->setStyleSheet(QStringLiteral(""));
        rightFrame->setFrameShape(QFrame::StyledPanel);
        rightFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(rightFrame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        viewStackedWidget = new QStackedWidget(rightFrame);
        viewStackedWidget->setObjectName(QStringLiteral("viewStackedWidget"));
        viewStackedWidget->setStyleSheet(QStringLiteral(""));
        dataAnalyPage = new QWidget();
        dataAnalyPage->setObjectName(QStringLiteral("dataAnalyPage"));
        verticalLayout_4 = new QVBoxLayout(dataAnalyPage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        toolBtnWidget = new QWidget(dataAnalyPage);
        toolBtnWidget->setObjectName(QStringLiteral("toolBtnWidget"));
        toolBtnWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 201, 157);"));
        horizontalLayout_11 = new QHBoxLayout(toolBtnWidget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        pushButton_2 = new QPushButton(toolBtnWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_11->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(toolBtnWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_11->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(toolBtnWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_11->addWidget(pushButton_4);

        horizontalLayout_11->setStretch(0, 15);

        verticalLayout_4->addWidget(toolBtnWidget);

        widget = new ViewWidget(dataAnalyPage);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_4->addWidget(widget);

        reportWidget = new ReportWidget(dataAnalyPage);
        reportWidget->setObjectName(QStringLiteral("reportWidget"));

        verticalLayout_4->addWidget(reportWidget);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 20);
        verticalLayout_4->setStretch(2, 4);
        viewStackedWidget->addWidget(dataAnalyPage);

        verticalLayout_3->addWidget(viewStackedWidget);


        horizontalLayout->addWidget(rightFrame);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        bottomFrame = new QFrame(page);
        bottomFrame->setObjectName(QStringLiteral("bottomFrame"));
        bottomFrame->setEnabled(true);
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(bottomFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 20, 91, 41));
        startAcquisitionBtn = new QPushButton(bottomFrame);
        startAcquisitionBtn->setObjectName(QStringLiteral("startAcquisitionBtn"));
        startAcquisitionBtn->setGeometry(QRect(380, 20, 91, 41));
        startAcquisitionBtn->setIcon(icon2);
        saveCheckBox = new QCheckBox(bottomFrame);
        saveCheckBox->setObjectName(QStringLiteral("saveCheckBox"));
        saveCheckBox->setGeometry(QRect(480, 40, 71, 16));
        stopAcquisitionBtn = new QPushButton(bottomFrame);
        stopAcquisitionBtn->setObjectName(QStringLiteral("stopAcquisitionBtn"));
        stopAcquisitionBtn->setGeometry(QRect(740, 20, 91, 41));
        checkBox_2 = new QCheckBox(bottomFrame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(880, 10, 41, 16));
        spinBox_4 = new QSpinBox(bottomFrame);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(930, 0, 71, 22));
        checkBox_3 = new QCheckBox(bottomFrame);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(880, 70, 51, 16));
        spinBox_5 = new QSpinBox(bottomFrame);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(930, 60, 71, 22));
        checkBox_4 = new QCheckBox(bottomFrame);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(880, 40, 41, 16));
        spinBox_6 = new QSpinBox(bottomFrame);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setGeometry(QRect(930, 30, 71, 22));

        verticalLayout->addWidget(bottomFrame);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);
        StackedWidget->addWidget(page);
#ifndef QT_NO_SHORTCUT
        label_11->setBuddy(strengthSpin);
        label->setBuddy(strengthSpin);
        label_9->setBuddy(triggerSpin);
        label_6->setBuddy(voltageSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi(StackedWidget);

        viewStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StackedWidget);
    } // setupUi

    void retranslateUi(QStackedWidget *StackedWidget)
    {
        StackedWidget->setWindowTitle(QApplication::translate("StackedWidget", "StackedWidget", 0));
        statusDockWidget->setWindowTitle(QApplication::translate("StackedWidget", "\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        usbBtn->setText(QApplication::translate("StackedWidget", "...", 0));
        lockBtn->setText(QApplication::translate("StackedWidget", "...", 0));
        label_10->setText(QApplication::translate("StackedWidget", "\350\277\220\350\241\214\347\212\266\346\200\201\357\274\232", 0));
        controlDockWidget->setWindowTitle(QApplication::translate("StackedWidget", "\346\216\247\345\210\266\351\235\242\346\235\277", 0));
        label_11->setText(QApplication::translate("StackedWidget", "\351\236\230\346\266\262\357\274\232", 0));
        setFluidBtn->setText(QApplication::translate("StackedWidget", "\350\256\276\347\275\256", 0));
        label_8->setText(QApplication::translate("StackedWidget", "\346\240\267\345\223\201\346\265\201\351\200\237\357\274\232", 0));
        setSampleBtn->setText(QApplication::translate("StackedWidget", "\350\256\276\347\275\256", 0));
        midRadioButton->setText(QApplication::translate("StackedWidget", "\344\270\255", 0));
        hightRadioButton->setText(QApplication::translate("StackedWidget", "\351\253\230", 0));
        lowRadioButton->setText(QApplication::translate("StackedWidget", "\344\275\216", 0));
        label_7->setText(QApplication::translate("StackedWidget", "\351\207\207\351\233\206\351\200\232\351\201\223\350\256\276\347\275\256\357\274\232", 0));
        label->setText(QApplication::translate("StackedWidget", "\346\277\200\345\205\211\345\274\272\345\272\246\357\274\232", 0));
        setLaserBtn->setText(QApplication::translate("StackedWidget", "\350\256\276\347\275\256", 0));
        label_9->setText(QApplication::translate("StackedWidget", "\350\247\246\345\217\221\345\200\274\357\274\232", 0));
        setTriggerBtn->setText(QApplication::translate("StackedWidget", "\350\256\276\347\275\256", 0));
        label_6->setText(QApplication::translate("StackedWidget", "\351\200\232\351\201\223\345\201\217\345\216\213\357\274\232", 0));
        setChannelBiasBtn->setText(QApplication::translate("StackedWidget", "\350\256\276\347\275\256", 0));
        pushButton_2->setText(QApplication::translate("StackedWidget", "\346\226\260\345\273\272\347\224\273\345\270\203", 0));
        pushButton_3->setText(QApplication::translate("StackedWidget", "\345\210\240\351\231\244\347\224\273\345\270\203", 0));
        pushButton_4->setText(QApplication::translate("StackedWidget", "\344\277\235\345\255\230", 0));
        pushButton->setText(QApplication::translate("StackedWidget", "\350\275\275\345\205\245\345\217\202\346\225\260", 0));
        startAcquisitionBtn->setText(QApplication::translate("StackedWidget", "\345\274\200\345\247\213\351\207\207\351\233\206", 0));
        saveCheckBox->setText(QApplication::translate("StackedWidget", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
        stopAcquisitionBtn->setText(QApplication::translate("StackedWidget", "\345\201\234\346\255\242", 0));
        checkBox_2->setText(QApplication::translate("StackedWidget", "\346\227\266\351\227\264", 0));
        checkBox_3->setText(QApplication::translate("StackedWidget", "\346\225\260\351\207\217", 0));
        checkBox_4->setText(QApplication::translate("StackedWidget", "\346\265\201\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class StackedWidget: public Ui_StackedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKEDWIDGET_H
