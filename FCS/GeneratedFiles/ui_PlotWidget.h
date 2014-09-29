/********************************************************************************
** Form generated from reading UI file 'PlotWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWIDGET_H
#define UI_PLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *cellToolFrame;
    QVBoxLayout *verticalLayout_2;
    QToolButton *zoomerBtn;
    QToolButton *pannerBtn;
    QToolButton *maximizedBtn;
    QToolButton *normalBtn;
    QToolButton *crossBtn;
    QToolButton *viewTrueValueBtn_2;
    QToolButton *rectBtn;
    QToolButton *parallelLineBtn;
    QToolButton *ellipseBtn;
    QToolButton *polygonBtn;
    QToolButton *testUpBtn;
    QToolButton *testDownBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QFrame *cellXFrame;
    QHBoxLayout *horizontalLayout;
    QToolButton *propertyBtn;
    QComboBox *passageYCombox;
    QComboBox *dataUnitYCombox;
    QCheckBox *gridCheckBox;
    QCheckBox *logCheckBox;
    QCheckBox *scatterCheckBox;
    QCheckBox *barChatStaticsCheckBox;
    QSpacerItem *horizontalSpacer;
    QFrame *cellPlotFrame;
    QSpacerItem *verticalSpacer_3;
    QFrame *cellYFrame;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QComboBox *dataUnitXCombox;
    QComboBox *passageXCombox;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *PlotWidget)
    {
        if (PlotWidget->objectName().isEmpty())
            PlotWidget->setObjectName(QStringLiteral("PlotWidget"));
        PlotWidget->resize(502, 446);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlotWidget->sizePolicy().hasHeightForWidth());
        PlotWidget->setSizePolicy(sizePolicy);
        PlotWidget->setMinimumSize(QSize(502, 446));
        PlotWidget->setMaximumSize(QSize(502, 446));
        PlotWidget->setFocusPolicy(Qt::StrongFocus);
        PlotWidget->setAcceptDrops(false);
        horizontalLayout_2 = new QHBoxLayout(PlotWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 5, 0, 5);
        cellToolFrame = new QFrame(PlotWidget);
        cellToolFrame->setObjectName(QStringLiteral("cellToolFrame"));
        cellToolFrame->setFocusPolicy(Qt::NoFocus);
        cellToolFrame->setStyleSheet(QStringLiteral(""));
        cellToolFrame->setFrameShape(QFrame::StyledPanel);
        cellToolFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(cellToolFrame);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        zoomerBtn = new QToolButton(cellToolFrame);
        zoomerBtn->setObjectName(QStringLiteral("zoomerBtn"));
        zoomerBtn->setMinimumSize(QSize(32, 32));
        zoomerBtn->setMaximumSize(QSize(32, 32));
        zoomerBtn->setCheckable(true);

        verticalLayout_2->addWidget(zoomerBtn);

        pannerBtn = new QToolButton(cellToolFrame);
        pannerBtn->setObjectName(QStringLiteral("pannerBtn"));
        pannerBtn->setMinimumSize(QSize(32, 32));
        pannerBtn->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/MoveBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pannerBtn->setIcon(icon);
        pannerBtn->setCheckable(true);
        pannerBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(pannerBtn);

        maximizedBtn = new QToolButton(cellToolFrame);
        maximizedBtn->setObjectName(QStringLiteral("maximizedBtn"));
        maximizedBtn->setMinimumSize(QSize(32, 32));
        maximizedBtn->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/MaxBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        maximizedBtn->setIcon(icon1);
        maximizedBtn->setCheckable(false);
        maximizedBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(maximizedBtn);

        normalBtn = new QToolButton(cellToolFrame);
        normalBtn->setObjectName(QStringLiteral("normalBtn"));
        normalBtn->setMinimumSize(QSize(32, 32));
        normalBtn->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/MinBTn.png"), QSize(), QIcon::Normal, QIcon::Off);
        normalBtn->setIcon(icon2);
        normalBtn->setCheckable(false);
        normalBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(normalBtn);

        crossBtn = new QToolButton(cellToolFrame);
        crossBtn->setObjectName(QStringLiteral("crossBtn"));
        crossBtn->setMinimumSize(QSize(32, 32));
        crossBtn->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/crossBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        crossBtn->setIcon(icon3);
        crossBtn->setIconSize(QSize(20, 20));
        crossBtn->setCheckable(true);
        crossBtn->setChecked(false);
        crossBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(crossBtn);

        viewTrueValueBtn_2 = new QToolButton(cellToolFrame);
        viewTrueValueBtn_2->setObjectName(QStringLiteral("viewTrueValueBtn_2"));
        viewTrueValueBtn_2->setMinimumSize(QSize(32, 32));
        viewTrueValueBtn_2->setMaximumSize(QSize(32, 32));
        viewTrueValueBtn_2->setCheckable(true);
        viewTrueValueBtn_2->setChecked(false);

        verticalLayout_2->addWidget(viewTrueValueBtn_2);

        rectBtn = new QToolButton(cellToolFrame);
        rectBtn->setObjectName(QStringLiteral("rectBtn"));
        rectBtn->setMinimumSize(QSize(32, 32));
        rectBtn->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/Rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectBtn->setIcon(icon4);
        rectBtn->setIconSize(QSize(20, 20));
        rectBtn->setCheckable(true);
        rectBtn->setChecked(false);
        rectBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(rectBtn);

        parallelLineBtn = new QToolButton(cellToolFrame);
        parallelLineBtn->setObjectName(QStringLiteral("parallelLineBtn"));
        parallelLineBtn->setMinimumSize(QSize(32, 32));
        parallelLineBtn->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/Parallel.png"), QSize(), QIcon::Normal, QIcon::Off);
        parallelLineBtn->setIcon(icon5);
        parallelLineBtn->setIconSize(QSize(20, 20));
        parallelLineBtn->setCheckable(true);
        parallelLineBtn->setChecked(false);
        parallelLineBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(parallelLineBtn);

        ellipseBtn = new QToolButton(cellToolFrame);
        ellipseBtn->setObjectName(QStringLiteral("ellipseBtn"));
        ellipseBtn->setMinimumSize(QSize(32, 32));
        ellipseBtn->setMaximumSize(QSize(32, 32));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/ellipseBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipseBtn->setIcon(icon6);
        ellipseBtn->setIconSize(QSize(20, 20));
        ellipseBtn->setCheckable(true);
        ellipseBtn->setChecked(false);
        ellipseBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(ellipseBtn);

        polygonBtn = new QToolButton(cellToolFrame);
        polygonBtn->setObjectName(QStringLiteral("polygonBtn"));
        polygonBtn->setMinimumSize(QSize(32, 32));
        polygonBtn->setMaximumSize(QSize(32, 32));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/PolygonBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        polygonBtn->setIcon(icon7);
        polygonBtn->setIconSize(QSize(20, 20));
        polygonBtn->setCheckable(true);
        polygonBtn->setChecked(false);
        polygonBtn->setAutoRaise(true);

        verticalLayout_2->addWidget(polygonBtn);

        testUpBtn = new QToolButton(cellToolFrame);
        testUpBtn->setObjectName(QStringLiteral("testUpBtn"));
        testUpBtn->setMinimumSize(QSize(32, 32));
        testUpBtn->setMaximumSize(QSize(32, 32));
        testUpBtn->setCheckable(true);
        testUpBtn->setChecked(false);

        verticalLayout_2->addWidget(testUpBtn);

        testDownBtn = new QToolButton(cellToolFrame);
        testDownBtn->setObjectName(QStringLiteral("testDownBtn"));
        testDownBtn->setMinimumSize(QSize(32, 32));
        testDownBtn->setMaximumSize(QSize(32, 32));
        testDownBtn->setCheckable(true);
        testDownBtn->setChecked(false);

        verticalLayout_2->addWidget(testDownBtn);

        verticalSpacer = new QSpacerItem(20, 339, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(cellToolFrame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cellXFrame = new QFrame(PlotWidget);
        cellXFrame->setObjectName(QStringLiteral("cellXFrame"));
        cellXFrame->setMaximumSize(QSize(16777215, 30));
        cellXFrame->setFocusPolicy(Qt::NoFocus);
        cellXFrame->setStyleSheet(QStringLiteral(""));
        cellXFrame->setFrameShape(QFrame::StyledPanel);
        cellXFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(cellXFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        propertyBtn = new QToolButton(cellXFrame);
        propertyBtn->setObjectName(QStringLiteral("propertyBtn"));
        propertyBtn->setMinimumSize(QSize(30, 30));
        propertyBtn->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        propertyBtn->setIcon(icon8);
        propertyBtn->setCheckable(true);
        propertyBtn->setAutoRaise(true);

        horizontalLayout->addWidget(propertyBtn);

        passageYCombox = new QComboBox(cellXFrame);
        passageYCombox->setObjectName(QStringLiteral("passageYCombox"));
        passageYCombox->setMinimumSize(QSize(55, 20));
        passageYCombox->setMaximumSize(QSize(69, 20));

        horizontalLayout->addWidget(passageYCombox);

        dataUnitYCombox = new QComboBox(cellXFrame);
        dataUnitYCombox->setObjectName(QStringLiteral("dataUnitYCombox"));
        dataUnitYCombox->setMinimumSize(QSize(55, 20));
        dataUnitYCombox->setMaximumSize(QSize(69, 20));

        horizontalLayout->addWidget(dataUnitYCombox);

        gridCheckBox = new QCheckBox(cellXFrame);
        gridCheckBox->setObjectName(QStringLiteral("gridCheckBox"));
        gridCheckBox->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/BGGrid.png"), QSize(), QIcon::Normal, QIcon::Off);
        gridCheckBox->setIcon(icon9);
        gridCheckBox->setChecked(true);
        gridCheckBox->setTristate(false);

        horizontalLayout->addWidget(gridCheckBox);

        logCheckBox = new QCheckBox(cellXFrame);
        logCheckBox->setObjectName(QStringLiteral("logCheckBox"));
        logCheckBox->setFocusPolicy(Qt::NoFocus);
        logCheckBox->setLayoutDirection(Qt::LeftToRight);
        logCheckBox->setAutoFillBackground(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/Log.png"), QSize(), QIcon::Normal, QIcon::Off);
        logCheckBox->setIcon(icon10);
        logCheckBox->setChecked(true);

        horizontalLayout->addWidget(logCheckBox);

        scatterCheckBox = new QCheckBox(cellXFrame);
        buttonGroup = new QButtonGroup(PlotWidget);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(scatterCheckBox);
        scatterCheckBox->setObjectName(QStringLiteral("scatterCheckBox"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/Scatter.png"), QSize(), QIcon::Normal, QIcon::Off);
        scatterCheckBox->setIcon(icon11);
        scatterCheckBox->setChecked(true);

        horizontalLayout->addWidget(scatterCheckBox);

        barChatStaticsCheckBox = new QCheckBox(cellXFrame);
        buttonGroup->addButton(barChatStaticsCheckBox);
        barChatStaticsCheckBox->setObjectName(QStringLiteral("barChatStaticsCheckBox"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/Histogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        barChatStaticsCheckBox->setIcon(icon12);

        horizontalLayout->addWidget(barChatStaticsCheckBox);

        horizontalSpacer = new QSpacerItem(493, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(cellXFrame);

        cellPlotFrame = new QFrame(PlotWidget);
        cellPlotFrame->setObjectName(QStringLiteral("cellPlotFrame"));
        sizePolicy.setHeightForWidth(cellPlotFrame->sizePolicy().hasHeightForWidth());
        cellPlotFrame->setSizePolicy(sizePolicy);
        cellPlotFrame->setFocusPolicy(Qt::NoFocus);
        cellPlotFrame->setFrameShape(QFrame::StyledPanel);
        cellPlotFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(cellPlotFrame);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        horizontalLayout_2->addLayout(verticalLayout);

        cellYFrame = new QFrame(PlotWidget);
        cellYFrame->setObjectName(QStringLiteral("cellYFrame"));
        cellYFrame->setMaximumSize(QSize(80, 16777215));
        cellYFrame->setFocusPolicy(Qt::NoFocus);
        cellYFrame->setStyleSheet(QStringLiteral(""));
        cellYFrame->setFrameShape(QFrame::StyledPanel);
        cellYFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(cellYFrame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 399, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        dataUnitXCombox = new QComboBox(cellYFrame);
        dataUnitXCombox->setObjectName(QStringLiteral("dataUnitXCombox"));
        dataUnitXCombox->setMinimumSize(QSize(55, 20));
        dataUnitXCombox->setMaximumSize(QSize(69, 20));

        verticalLayout_3->addWidget(dataUnitXCombox);

        passageXCombox = new QComboBox(cellYFrame);
        passageXCombox->setObjectName(QStringLiteral("passageXCombox"));
        passageXCombox->setMinimumSize(QSize(55, 20));
        passageXCombox->setMaximumSize(QSize(69, 20));

        verticalLayout_3->addWidget(passageXCombox);


        horizontalLayout_2->addWidget(cellYFrame);


        retranslateUi(PlotWidget);

        passageYCombox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PlotWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotWidget)
    {
        PlotWidget->setWindowTitle(QApplication::translate("PlotWidget", "All", 0));
        zoomerBtn->setText(QApplication::translate("PlotWidget", "\346\224\276\345\244\247/\347\274\251\345\260\217", 0));
#ifndef QT_NO_TOOLTIP
        pannerBtn->setToolTip(QApplication::translate("PlotWidget", "\345\271\263\347\247\273", 0));
#endif // QT_NO_TOOLTIP
        pannerBtn->setText(QApplication::translate("PlotWidget", "\345\271\263\347\247\273", 0));
#ifndef QT_NO_TOOLTIP
        maximizedBtn->setToolTip(QApplication::translate("PlotWidget", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        maximizedBtn->setText(QApplication::translate("PlotWidget", "\346\234\200\345\244\247\345\214\226", 0));
#ifndef QT_NO_TOOLTIP
        normalBtn->setToolTip(QApplication::translate("PlotWidget", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        normalBtn->setText(QApplication::translate("PlotWidget", "\350\277\230\345\216\237", 0));
#ifndef QT_NO_TOOLTIP
        crossBtn->setToolTip(QApplication::translate("PlotWidget", "\345\215\201\345\255\227\347\272\277", 0));
#endif // QT_NO_TOOLTIP
        crossBtn->setText(QApplication::translate("PlotWidget", "\345\215\201\345\255\227\347\272\277", 0));
        viewTrueValueBtn_2->setText(QApplication::translate("PlotWidget", "\345\215\201\345\255\227\347\272\2772", 0));
#ifndef QT_NO_TOOLTIP
        rectBtn->setToolTip(QApplication::translate("PlotWidget", "\347\237\251\345\275\242\350\256\276\351\227\250", 0));
#endif // QT_NO_TOOLTIP
        rectBtn->setText(QApplication::translate("PlotWidget", "\347\237\251\345\275\242", 0));
#ifndef QT_NO_TOOLTIP
        parallelLineBtn->setToolTip(QApplication::translate("PlotWidget", "\345\271\263\350\241\214\347\272\277\350\256\276\351\227\250", 0));
#endif // QT_NO_TOOLTIP
        parallelLineBtn->setText(QApplication::translate("PlotWidget", "\345\271\263\350\241\214\347\272\277", 0));
#ifndef QT_NO_TOOLTIP
        ellipseBtn->setToolTip(QApplication::translate("PlotWidget", "\346\244\255\345\234\206\350\256\276\351\227\250", 0));
#endif // QT_NO_TOOLTIP
        ellipseBtn->setText(QApplication::translate("PlotWidget", "\346\244\255\345\234\206", 0));
        polygonBtn->setText(QApplication::translate("PlotWidget", "\345\244\232\350\276\271\345\275\242", 0));
        testUpBtn->setText(QApplication::translate("PlotWidget", "+", 0));
        testDownBtn->setText(QApplication::translate("PlotWidget", "-", 0));
        propertyBtn->setText(QApplication::translate("PlotWidget", "...", 0));
#ifndef QT_NO_TOOLTIP
        passageYCombox->setToolTip(QApplication::translate("PlotWidget", "\351\200\232\351\201\223", 0));
#endif // QT_NO_TOOLTIP
        passageYCombox->setCurrentText(QString());
#ifndef QT_NO_TOOLTIP
        dataUnitYCombox->setToolTip(QApplication::translate("PlotWidget", "\346\225\260\346\215\256\345\215\225\345\205\203\347\261\273\345\236\213", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        gridCheckBox->setToolTip(QApplication::translate("PlotWidget", "\350\203\214\346\231\257\346\226\271\346\240\274\347\272\277", 0));
#endif // QT_NO_TOOLTIP
        gridCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        logCheckBox->setToolTip(QApplication::translate("PlotWidget", "LOG(10)", 0));
#endif // QT_NO_TOOLTIP
        logCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        scatterCheckBox->setToolTip(QApplication::translate("PlotWidget", "\346\225\243\347\202\271\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        scatterCheckBox->setText(QString());
#ifndef QT_NO_TOOLTIP
        barChatStaticsCheckBox->setToolTip(QApplication::translate("PlotWidget", "\347\233\264\346\226\271\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        barChatStaticsCheckBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlotWidget: public Ui_PlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWIDGET_H
