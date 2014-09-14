/********************************************************************************
** Form generated from reading UI file 'OscWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSCWIDGET_H
#define UI_OSCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Ui/Library/WheelBox.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_OscWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QFrame *oscLeftFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *frame_5;
    QPushButton *startOscAcqBtn;
    QCheckBox *saveCheckBox;
    QPushButton *stopOscAcqBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QwtPlot *oscPlot;
    QFrame *toolFrame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *propertyBtn;
    QFrame *frame_6;
    WheelBox *xScalewheelBox;
    WheelBox *yScalewheelBox;
    QFrame *frame_7;
    WheelBox *xMarkwheelBox;
    WheelBox *yMarkwheelBox;
    QSpacerItem *verticalSpacer_3;
    QFrame *botFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *OscWidget)
    {
        if (OscWidget->objectName().isEmpty())
            OscWidget->setObjectName(QStringLiteral("OscWidget"));
        OscWidget->resize(907, 562);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OscWidget->sizePolicy().hasHeightForWidth());
        OscWidget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(OscWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        oscLeftFrame = new QFrame(OscWidget);
        oscLeftFrame->setObjectName(QStringLiteral("oscLeftFrame"));
        oscLeftFrame->setStyleSheet(QStringLiteral(""));
        oscLeftFrame->setFrameShape(QFrame::StyledPanel);
        oscLeftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(oscLeftFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(oscLeftFrame);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        frame_5 = new QFrame(oscLeftFrame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setStyleSheet(QStringLiteral("background-color: rgb(166, 68, 41);"));
        frame_5->setFrameShape(QFrame::HLine);
        frame_5->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_5);

        startOscAcqBtn = new QPushButton(oscLeftFrame);
        startOscAcqBtn->setObjectName(QStringLiteral("startOscAcqBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startOscAcqBtn->sizePolicy().hasHeightForWidth());
        startOscAcqBtn->setSizePolicy(sizePolicy1);
        startOscAcqBtn->setMinimumSize(QSize(80, 40));
        startOscAcqBtn->setMaximumSize(QSize(91, 51));
        startOscAcqBtn->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        startOscAcqBtn->setIcon(icon);
        startOscAcqBtn->setFlat(false);

        verticalLayout->addWidget(startOscAcqBtn);

        saveCheckBox = new QCheckBox(oscLeftFrame);
        saveCheckBox->setObjectName(QStringLiteral("saveCheckBox"));

        verticalLayout->addWidget(saveCheckBox);

        stopOscAcqBtn = new QPushButton(oscLeftFrame);
        stopOscAcqBtn->setObjectName(QStringLiteral("stopOscAcqBtn"));
        sizePolicy1.setHeightForWidth(stopOscAcqBtn->sizePolicy().hasHeightForWidth());
        stopOscAcqBtn->setSizePolicy(sizePolicy1);
        stopOscAcqBtn->setMinimumSize(QSize(80, 40));
        stopOscAcqBtn->setMaximumSize(QSize(91, 51));
        stopOscAcqBtn->setFocusPolicy(Qt::StrongFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopOscAcqBtn->setIcon(icon1);
        stopOscAcqBtn->setFlat(false);

        verticalLayout->addWidget(stopOscAcqBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addWidget(oscLeftFrame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(OscWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(553, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame);

        oscPlot = new QwtPlot(OscWidget);
        oscPlot->setObjectName(QStringLiteral("oscPlot"));

        verticalLayout_2->addWidget(oscPlot);


        horizontalLayout_5->addLayout(verticalLayout_2);

        toolFrame = new QFrame(OscWidget);
        toolFrame->setObjectName(QStringLiteral("toolFrame"));
        toolFrame->setStyleSheet(QStringLiteral(""));
        toolFrame->setFrameShape(QFrame::StyledPanel);
        toolFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(toolFrame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        propertyBtn = new QToolButton(toolFrame);
        propertyBtn->setObjectName(QStringLiteral("propertyBtn"));
        propertyBtn->setMinimumSize(QSize(20, 20));
        propertyBtn->setMaximumSize(QSize(20, 20));
        propertyBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        propertyBtn->setIcon(icon2);
        propertyBtn->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(propertyBtn);


        verticalLayout_3->addLayout(horizontalLayout_3);

        frame_6 = new QFrame(toolFrame);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setStyleSheet(QStringLiteral("background-color: rgb(166, 68, 41);"));
        frame_6->setFrameShape(QFrame::HLine);
        frame_6->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frame_6);

        xScalewheelBox = new WheelBox(toolFrame);
        xScalewheelBox->setObjectName(QStringLiteral("xScalewheelBox"));

        verticalLayout_3->addWidget(xScalewheelBox);

        yScalewheelBox = new WheelBox(toolFrame);
        yScalewheelBox->setObjectName(QStringLiteral("yScalewheelBox"));

        verticalLayout_3->addWidget(yScalewheelBox);

        frame_7 = new QFrame(toolFrame);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setStyleSheet(QStringLiteral("background-color: rgb(166, 68, 41);"));
        frame_7->setFrameShape(QFrame::HLine);
        frame_7->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frame_7);

        xMarkwheelBox = new WheelBox(toolFrame);
        xMarkwheelBox->setObjectName(QStringLiteral("xMarkwheelBox"));

        verticalLayout_3->addWidget(xMarkwheelBox);

        yMarkwheelBox = new WheelBox(toolFrame);
        yMarkwheelBox->setObjectName(QStringLiteral("yMarkwheelBox"));

        verticalLayout_3->addWidget(yMarkwheelBox);

        verticalSpacer_3 = new QSpacerItem(20, 444, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_5->addWidget(toolFrame);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_5);

        botFrame = new QFrame(OscWidget);
        botFrame->setObjectName(QStringLiteral("botFrame"));
        botFrame->setStyleSheet(QStringLiteral(""));
        botFrame->setFrameShape(QFrame::StyledPanel);
        botFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(botFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(688, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(botFrame);


        retranslateUi(OscWidget);

        QMetaObject::connectSlotsByName(OscWidget);
    } // setupUi

    void retranslateUi(QWidget *OscWidget)
    {
        OscWidget->setWindowTitle(QApplication::translate("OscWidget", "OscWidget", 0));
        label_3->setText(QApplication::translate("OscWidget", "\347\244\272\346\263\242\345\231\250\346\216\247\345\210\266", 0));
        startOscAcqBtn->setText(QApplication::translate("OscWidget", "\345\274\200\345\247\213", 0));
        saveCheckBox->setText(QApplication::translate("OscWidget", "\345\206\231\346\226\207\344\273\266", 0));
        stopOscAcqBtn->setText(QApplication::translate("OscWidget", "\345\201\234\346\255\242", 0));
        propertyBtn->setText(QApplication::translate("OscWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class OscWidget: public Ui_OscWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSCWIDGET_H
