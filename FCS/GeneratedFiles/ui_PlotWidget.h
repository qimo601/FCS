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
#include <QtWidgets/QPushButton>
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
    QToolButton *viewTrueValueBtn;
    QToolButton *viewTrueValueBtn_2;
    QToolButton *chooseBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QFrame *cellXFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
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
    QPushButton *pushButton_4;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *PlotWidget)
    {
        if (PlotWidget->objectName().isEmpty())
            PlotWidget->setObjectName(QStringLiteral("PlotWidget"));
        PlotWidget->resize(763, 642);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlotWidget->sizePolicy().hasHeightForWidth());
        PlotWidget->setSizePolicy(sizePolicy);
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
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, -1, 9, -1);
        zoomerBtn = new QToolButton(cellToolFrame);
        zoomerBtn->setObjectName(QStringLiteral("zoomerBtn"));
        zoomerBtn->setMinimumSize(QSize(70, 30));
        zoomerBtn->setMaximumSize(QSize(70, 30));
        zoomerBtn->setCheckable(true);

        verticalLayout_2->addWidget(zoomerBtn);

        pannerBtn = new QToolButton(cellToolFrame);
        pannerBtn->setObjectName(QStringLiteral("pannerBtn"));
        pannerBtn->setMinimumSize(QSize(70, 30));
        pannerBtn->setMaximumSize(QSize(70, 30));
        pannerBtn->setCheckable(true);

        verticalLayout_2->addWidget(pannerBtn);

        maximizedBtn = new QToolButton(cellToolFrame);
        maximizedBtn->setObjectName(QStringLiteral("maximizedBtn"));
        maximizedBtn->setMinimumSize(QSize(70, 30));
        maximizedBtn->setMaximumSize(QSize(70, 30));
        maximizedBtn->setCheckable(false);

        verticalLayout_2->addWidget(maximizedBtn);

        normalBtn = new QToolButton(cellToolFrame);
        normalBtn->setObjectName(QStringLiteral("normalBtn"));
        normalBtn->setMinimumSize(QSize(70, 30));
        normalBtn->setMaximumSize(QSize(70, 30));
        normalBtn->setCheckable(false);

        verticalLayout_2->addWidget(normalBtn);

        viewTrueValueBtn = new QToolButton(cellToolFrame);
        viewTrueValueBtn->setObjectName(QStringLiteral("viewTrueValueBtn"));
        viewTrueValueBtn->setMinimumSize(QSize(70, 30));
        viewTrueValueBtn->setMaximumSize(QSize(70, 30));
        viewTrueValueBtn->setCheckable(true);
        viewTrueValueBtn->setChecked(false);

        verticalLayout_2->addWidget(viewTrueValueBtn);

        viewTrueValueBtn_2 = new QToolButton(cellToolFrame);
        viewTrueValueBtn_2->setObjectName(QStringLiteral("viewTrueValueBtn_2"));
        viewTrueValueBtn_2->setMinimumSize(QSize(70, 30));
        viewTrueValueBtn_2->setMaximumSize(QSize(70, 30));
        viewTrueValueBtn_2->setCheckable(true);
        viewTrueValueBtn_2->setChecked(false);

        verticalLayout_2->addWidget(viewTrueValueBtn_2);

        chooseBtn = new QToolButton(cellToolFrame);
        chooseBtn->setObjectName(QStringLiteral("chooseBtn"));
        chooseBtn->setMinimumSize(QSize(70, 30));
        chooseBtn->setMaximumSize(QSize(70, 30));
        chooseBtn->setCheckable(true);
        chooseBtn->setChecked(false);

        verticalLayout_2->addWidget(chooseBtn);

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
        pushButton_3 = new QPushButton(cellXFrame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_3);

        passageYCombox = new QComboBox(cellXFrame);
        passageYCombox->setObjectName(QStringLiteral("passageYCombox"));

        horizontalLayout->addWidget(passageYCombox);

        dataUnitYCombox = new QComboBox(cellXFrame);
        dataUnitYCombox->setObjectName(QStringLiteral("dataUnitYCombox"));

        horizontalLayout->addWidget(dataUnitYCombox);

        gridCheckBox = new QCheckBox(cellXFrame);
        gridCheckBox->setObjectName(QStringLiteral("gridCheckBox"));
        gridCheckBox->setFocusPolicy(Qt::NoFocus);
        gridCheckBox->setChecked(true);

        horizontalLayout->addWidget(gridCheckBox);

        logCheckBox = new QCheckBox(cellXFrame);
        logCheckBox->setObjectName(QStringLiteral("logCheckBox"));
        logCheckBox->setFocusPolicy(Qt::NoFocus);
        logCheckBox->setChecked(false);

        horizontalLayout->addWidget(logCheckBox);

        scatterCheckBox = new QCheckBox(cellXFrame);
        buttonGroup = new QButtonGroup(PlotWidget);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(scatterCheckBox);
        scatterCheckBox->setObjectName(QStringLiteral("scatterCheckBox"));
        scatterCheckBox->setChecked(true);

        horizontalLayout->addWidget(scatterCheckBox);

        barChatStaticsCheckBox = new QCheckBox(cellXFrame);
        buttonGroup->addButton(barChatStaticsCheckBox);
        barChatStaticsCheckBox->setObjectName(QStringLiteral("barChatStaticsCheckBox"));

        horizontalLayout->addWidget(barChatStaticsCheckBox);

        horizontalSpacer = new QSpacerItem(493, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(cellXFrame);

        cellPlotFrame = new QFrame(PlotWidget);
        cellPlotFrame->setObjectName(QStringLiteral("cellPlotFrame"));
        sizePolicy.setHeightForWidth(cellPlotFrame->sizePolicy().hasHeightForWidth());
        cellPlotFrame->setSizePolicy(sizePolicy);
        cellPlotFrame->setMinimumSize(QSize(600, 600));
        cellPlotFrame->setFocusPolicy(Qt::NoFocus);
        cellPlotFrame->setFrameShape(QFrame::StyledPanel);
        cellPlotFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(cellPlotFrame);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

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

        verticalLayout_3->addWidget(dataUnitXCombox);

        passageXCombox = new QComboBox(cellYFrame);
        passageXCombox->setObjectName(QStringLiteral("passageXCombox"));

        verticalLayout_3->addWidget(passageXCombox);

        pushButton_4 = new QPushButton(cellYFrame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 30));
        pushButton_4->setMaximumSize(QSize(30, 30));
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_2->addWidget(cellYFrame);


        retranslateUi(PlotWidget);

        passageYCombox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PlotWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotWidget)
    {
        PlotWidget->setWindowTitle(QApplication::translate("PlotWidget", "PlotWidget", 0));
        zoomerBtn->setText(QApplication::translate("PlotWidget", "\346\224\276\345\244\247/\347\274\251\345\260\217", 0));
        pannerBtn->setText(QApplication::translate("PlotWidget", "\345\271\263\347\247\273", 0));
        maximizedBtn->setText(QApplication::translate("PlotWidget", "\346\234\200\345\244\247\345\214\226", 0));
        normalBtn->setText(QApplication::translate("PlotWidget", "\350\277\230\345\216\237", 0));
        viewTrueValueBtn->setText(QApplication::translate("PlotWidget", "\345\215\201\345\255\227\347\272\277", 0));
        viewTrueValueBtn_2->setText(QApplication::translate("PlotWidget", "\345\215\201\345\255\227\347\272\2772", 0));
        chooseBtn->setText(QApplication::translate("PlotWidget", "\347\247\273\345\212\250\346\265\213\350\257\225", 0));
        pushButton_3->setText(QApplication::translate("PlotWidget", "\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        passageYCombox->setToolTip(QApplication::translate("PlotWidget", "\351\200\232\351\201\223", 0));
#endif // QT_NO_TOOLTIP
        passageYCombox->setCurrentText(QString());
#ifndef QT_NO_TOOLTIP
        dataUnitYCombox->setToolTip(QApplication::translate("PlotWidget", "\346\225\260\346\215\256\345\215\225\345\205\203\347\261\273\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        gridCheckBox->setText(QApplication::translate("PlotWidget", "\350\203\214\346\231\257\346\226\271\346\240\274\347\272\277", 0));
        logCheckBox->setText(QApplication::translate("PlotWidget", "log(10)", 0));
        scatterCheckBox->setText(QApplication::translate("PlotWidget", "\346\225\243\347\202\271\345\233\276", 0));
        barChatStaticsCheckBox->setText(QApplication::translate("PlotWidget", "\347\233\264\346\226\271\345\233\276\347\273\237\350\256\241", 0));
        pushButton_4->setText(QApplication::translate("PlotWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotWidget: public Ui_PlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWIDGET_H
