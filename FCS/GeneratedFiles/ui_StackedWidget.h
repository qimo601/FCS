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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Ui/Library/ParamWidget.h>
#include <Ui/Library/ViewWidget.h>

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
    ParamWidget *controlDockWidget;
    QDockWidget *fileBrowserDockWidget;
    QWidget *fileBrowserDockWidgetContents;
    QVBoxLayout *verticalLayout_9;
    QWidget *fileWidget;
    QWidget *widget;
    QToolButton *openFileBtn;
    QSpacerItem *verticalSpacer;
    QFrame *rightFrame;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *viewStackedWidget;
    QWidget *dataAnalyPage;
    QVBoxLayout *verticalLayout_4;
    QWidget *toolBtnWidget;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_12;
    QToolButton *newPlotBtn;
    QPushButton *delPlotBtn;
    QPushButton *savePlotBtn;
    QPushButton *reportBtn;
    ViewWidget *celllViewWidget;
    QFrame *bottomFrame;
    QPushButton *startAcquisitionBtn;
    QCheckBox *saveCheckBox;
    QPushButton *stopAcquisitionBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *timeCheckBox;
    QSpinBox *timeSpinBox;
    QLCDNumber *timeLCD;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *eventsCheckBox;
    QSpinBox *eventsSpinBox;
    QLCDNumber *eventsLCD;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *flowCheckBox;
    QSpinBox *flowSpinBox;
    QLCDNumber *flowLCD;
    QButtonGroup *buttonGroup;

    void setupUi(QStackedWidget *StackedWidget)
    {
        if (StackedWidget->objectName().isEmpty())
            StackedWidget->setObjectName(QStringLiteral("StackedWidget"));
        StackedWidget->resize(1150, 700);
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
        usbBtn->setCheckable(true);
        usbBtn->setChecked(false);
        usbBtn->setAutoRaise(true);

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

        controlDockWidget = new ParamWidget(leftFrame);
        controlDockWidget->setObjectName(QStringLiteral("controlDockWidget"));

        verticalLayout_2->addWidget(controlDockWidget);

        fileBrowserDockWidget = new QDockWidget(leftFrame);
        fileBrowserDockWidget->setObjectName(QStringLiteral("fileBrowserDockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileBrowserDockWidget->sizePolicy().hasHeightForWidth());
        fileBrowserDockWidget->setSizePolicy(sizePolicy2);
        fileBrowserDockWidget->setMinimumSize(QSize(250, 320));
        fileBrowserDockWidget->setMaximumSize(QSize(250, 524287));
        fileBrowserDockWidget->setStyleSheet(QStringLiteral(""));
        fileBrowserDockWidgetContents = new QWidget();
        fileBrowserDockWidgetContents->setObjectName(QStringLiteral("fileBrowserDockWidgetContents"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(fileBrowserDockWidgetContents->sizePolicy().hasHeightForWidth());
        fileBrowserDockWidgetContents->setSizePolicy(sizePolicy3);
        fileBrowserDockWidgetContents->setStyleSheet(QStringLiteral(""));
        verticalLayout_9 = new QVBoxLayout(fileBrowserDockWidgetContents);
        verticalLayout_9->setSpacing(7);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        fileWidget = new QWidget(fileBrowserDockWidgetContents);
        fileWidget->setObjectName(QStringLiteral("fileWidget"));
        sizePolicy3.setHeightForWidth(fileWidget->sizePolicy().hasHeightForWidth());
        fileWidget->setSizePolicy(sizePolicy3);
        fileWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_9->addWidget(fileWidget);

        widget = new QWidget(fileBrowserDockWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        openFileBtn = new QToolButton(widget);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));
        openFileBtn->setGeometry(QRect(80, 0, 80, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/NewExpBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFileBtn->setIcon(icon2);
        openFileBtn->setIconSize(QSize(32, 32));
        openFileBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        openFileBtn->setAutoRaise(true);

        verticalLayout_9->addWidget(widget);

        verticalLayout_9->setStretch(0, 5);
        verticalLayout_9->setStretch(1, 1);
        fileBrowserDockWidget->setWidget(fileBrowserDockWidgetContents);

        verticalLayout_2->addWidget(fileBrowserDockWidget);

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
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolBtnWidget = new QWidget(dataAnalyPage);
        toolBtnWidget->setObjectName(QStringLiteral("toolBtnWidget"));
        toolBtnWidget->setMaximumSize(QSize(16777215, 30));
        toolBtnWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_11 = new QHBoxLayout(toolBtnWidget);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        newPlotBtn = new QToolButton(toolBtnWidget);
        newPlotBtn->setObjectName(QStringLiteral("newPlotBtn"));
        newPlotBtn->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/newPlot.png"), QSize(), QIcon::Normal, QIcon::Off);
        newPlotBtn->setIcon(icon3);
        newPlotBtn->setIconSize(QSize(32, 32));

        horizontalLayout_11->addWidget(newPlotBtn);

        delPlotBtn = new QPushButton(toolBtnWidget);
        delPlotBtn->setObjectName(QStringLiteral("delPlotBtn"));
        delPlotBtn->setMaximumSize(QSize(32, 32));

        horizontalLayout_11->addWidget(delPlotBtn);

        savePlotBtn = new QPushButton(toolBtnWidget);
        savePlotBtn->setObjectName(QStringLiteral("savePlotBtn"));
        savePlotBtn->setMaximumSize(QSize(32, 32));

        horizontalLayout_11->addWidget(savePlotBtn);

        reportBtn = new QPushButton(toolBtnWidget);
        reportBtn->setObjectName(QStringLiteral("reportBtn"));
        reportBtn->setMaximumSize(QSize(32, 32));
        reportBtn->setCheckable(true);

        horizontalLayout_11->addWidget(reportBtn);

        horizontalLayout_11->setStretch(0, 15);

        verticalLayout_4->addWidget(toolBtnWidget);

        celllViewWidget = new ViewWidget(dataAnalyPage);
        celllViewWidget->setObjectName(QStringLiteral("celllViewWidget"));
        sizePolicy2.setHeightForWidth(celllViewWidget->sizePolicy().hasHeightForWidth());
        celllViewWidget->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(celllViewWidget);

        verticalLayout_4->setStretch(0, 10);
        verticalLayout_4->setStretch(1, 1);
        viewStackedWidget->addWidget(dataAnalyPage);

        verticalLayout_3->addWidget(viewStackedWidget);


        horizontalLayout->addWidget(rightFrame);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        bottomFrame = new QFrame(page);
        bottomFrame->setObjectName(QStringLiteral("bottomFrame"));
        bottomFrame->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(bottomFrame->sizePolicy().hasHeightForWidth());
        bottomFrame->setSizePolicy(sizePolicy4);
        bottomFrame->setMinimumSize(QSize(0, 116));
        bottomFrame->setMaximumSize(QSize(16777215, 116));
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        startAcquisitionBtn = new QPushButton(bottomFrame);
        startAcquisitionBtn->setObjectName(QStringLiteral("startAcquisitionBtn"));
        startAcquisitionBtn->setGeometry(QRect(380, 20, 91, 41));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        startAcquisitionBtn->setIcon(icon4);
        saveCheckBox = new QCheckBox(bottomFrame);
        saveCheckBox->setObjectName(QStringLiteral("saveCheckBox"));
        saveCheckBox->setGeometry(QRect(480, 40, 101, 16));
        stopAcquisitionBtn = new QPushButton(bottomFrame);
        stopAcquisitionBtn->setObjectName(QStringLiteral("stopAcquisitionBtn"));
        stopAcquisitionBtn->setGeometry(QRect(740, 20, 91, 41));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopAcquisitionBtn->setIcon(icon5);
        layoutWidget = new QWidget(bottomFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(870, 0, 211, 89));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        timeCheckBox = new QCheckBox(layoutWidget);
        timeCheckBox->setObjectName(QStringLiteral("timeCheckBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(timeCheckBox->sizePolicy().hasHeightForWidth());
        timeCheckBox->setSizePolicy(sizePolicy5);
        timeCheckBox->setMinimumSize(QSize(60, 16));
        timeCheckBox->setMaximumSize(QSize(60, 16));

        horizontalLayout_14->addWidget(timeCheckBox);

        timeSpinBox = new QSpinBox(layoutWidget);
        timeSpinBox->setObjectName(QStringLiteral("timeSpinBox"));
        sizePolicy5.setHeightForWidth(timeSpinBox->sizePolicy().hasHeightForWidth());
        timeSpinBox->setSizePolicy(sizePolicy5);
        timeSpinBox->setMinimumSize(QSize(71, 22));
        timeSpinBox->setMaximumSize(QSize(71, 22));
        timeSpinBox->setMaximum(3600);
        timeSpinBox->setValue(60);

        horizontalLayout_14->addWidget(timeSpinBox);

        timeLCD = new QLCDNumber(layoutWidget);
        timeLCD->setObjectName(QStringLiteral("timeLCD"));
        timeLCD->setMaximumSize(QSize(64, 23));
        timeLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"color: rgb(62, 166, 30);"));

        horizontalLayout_14->addWidget(timeLCD);


        verticalLayout_8->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        eventsCheckBox = new QCheckBox(layoutWidget);
        eventsCheckBox->setObjectName(QStringLiteral("eventsCheckBox"));
        sizePolicy5.setHeightForWidth(eventsCheckBox->sizePolicy().hasHeightForWidth());
        eventsCheckBox->setSizePolicy(sizePolicy5);
        eventsCheckBox->setMinimumSize(QSize(60, 16));
        eventsCheckBox->setMaximumSize(QSize(60, 16));

        horizontalLayout_13->addWidget(eventsCheckBox);

        eventsSpinBox = new QSpinBox(layoutWidget);
        eventsSpinBox->setObjectName(QStringLiteral("eventsSpinBox"));
        sizePolicy5.setHeightForWidth(eventsSpinBox->sizePolicy().hasHeightForWidth());
        eventsSpinBox->setSizePolicy(sizePolicy5);
        eventsSpinBox->setMinimumSize(QSize(71, 22));
        eventsSpinBox->setMaximumSize(QSize(71, 22));
        eventsSpinBox->setMaximum(50000);
        eventsSpinBox->setValue(10000);

        horizontalLayout_13->addWidget(eventsSpinBox);

        eventsLCD = new QLCDNumber(layoutWidget);
        eventsLCD->setObjectName(QStringLiteral("eventsLCD"));
        eventsLCD->setMaximumSize(QSize(64, 23));
        eventsLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"color: rgb(62, 166, 30);"));

        horizontalLayout_13->addWidget(eventsLCD);


        verticalLayout_8->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        flowCheckBox = new QCheckBox(layoutWidget);
        flowCheckBox->setObjectName(QStringLiteral("flowCheckBox"));
        sizePolicy5.setHeightForWidth(flowCheckBox->sizePolicy().hasHeightForWidth());
        flowCheckBox->setSizePolicy(sizePolicy5);
        flowCheckBox->setMinimumSize(QSize(60, 16));
        flowCheckBox->setMaximumSize(QSize(60, 16));

        horizontalLayout_15->addWidget(flowCheckBox);

        flowSpinBox = new QSpinBox(layoutWidget);
        flowSpinBox->setObjectName(QStringLiteral("flowSpinBox"));
        sizePolicy5.setHeightForWidth(flowSpinBox->sizePolicy().hasHeightForWidth());
        flowSpinBox->setSizePolicy(sizePolicy5);
        flowSpinBox->setMinimumSize(QSize(71, 22));
        flowSpinBox->setMaximumSize(QSize(71, 22));
        flowSpinBox->setMaximum(1000);
        flowSpinBox->setValue(5);

        horizontalLayout_15->addWidget(flowSpinBox);

        flowLCD = new QLCDNumber(layoutWidget);
        flowLCD->setObjectName(QStringLiteral("flowLCD"));
        flowLCD->setMaximumSize(QSize(64, 23));
        flowLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"color: rgb(62, 166, 30);"));

        horizontalLayout_15->addWidget(flowLCD);


        verticalLayout_8->addLayout(horizontalLayout_15);


        verticalLayout->addWidget(bottomFrame);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 3);
        StackedWidget->addWidget(page);

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
        fileBrowserDockWidget->setWindowTitle(QApplication::translate("StackedWidget", "\345\256\236\351\252\214\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        openFileBtn->setToolTip(QApplication::translate("StackedWidget", "\346\211\223\345\274\200\345\256\236\351\252\214\347\233\256\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        openFileBtn->setText(QApplication::translate("StackedWidget", "\346\211\223\345\274\200\345\256\236\351\252\214\347\233\256\345\275\225", 0));
        newPlotBtn->setText(QApplication::translate("StackedWidget", "...", 0));
        delPlotBtn->setText(QApplication::translate("StackedWidget", "\345\210\240\351\231\244\347\224\273\345\270\203", 0));
        savePlotBtn->setText(QApplication::translate("StackedWidget", "\344\277\235\345\255\230", 0));
        reportBtn->setText(QApplication::translate("StackedWidget", "\346\212\245\345\221\212", 0));
        startAcquisitionBtn->setText(QApplication::translate("StackedWidget", "\345\274\200\345\247\213\351\207\207\351\233\206", 0));
        saveCheckBox->setText(QApplication::translate("StackedWidget", "\344\277\235\345\255\230", 0));
        stopAcquisitionBtn->setText(QApplication::translate("StackedWidget", "\345\201\234\346\255\242", 0));
        timeCheckBox->setText(QApplication::translate("StackedWidget", "\346\227\266\351\227\264", 0));
        timeSpinBox->setSuffix(QApplication::translate("StackedWidget", "s", 0));
        eventsCheckBox->setText(QApplication::translate("StackedWidget", "\346\225\260\351\207\217", 0));
        eventsSpinBox->setSuffix(QApplication::translate("StackedWidget", "\344\270\252", 0));
        flowCheckBox->setText(QApplication::translate("StackedWidget", "\346\265\201\351\207\217", 0));
        flowSpinBox->setSuffix(QApplication::translate("StackedWidget", "L", 0));
    } // retranslateUi

};

namespace Ui {
    class StackedWidget: public Ui_StackedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKEDWIDGET_H
