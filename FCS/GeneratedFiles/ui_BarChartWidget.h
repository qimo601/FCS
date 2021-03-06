/********************************************************************************
** Form generated from reading UI file 'BarChartWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARCHARTWIDGET_H
#define UI_BARCHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BarChartWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *cellToolFrame;
    QVBoxLayout *verticalLayout_2;
    QToolButton *zoomerBtn;
    QToolButton *pannerBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QFrame *cellXFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QCheckBox *gridCheckBox;
    QSpacerItem *horizontalSpacer;
    QFrame *cellPlotFrame;
    QFrame *cellYFrame;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_4;

    void setupUi(QWidget *BarChartWidget)
    {
        if (BarChartWidget->objectName().isEmpty())
            BarChartWidget->setObjectName(QStringLiteral("BarChartWidget"));
        BarChartWidget->resize(730, 450);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BarChartWidget->sizePolicy().hasHeightForWidth());
        BarChartWidget->setSizePolicy(sizePolicy);
        BarChartWidget->setFocusPolicy(Qt::StrongFocus);
        BarChartWidget->setAcceptDrops(false);
        horizontalLayout_2 = new QHBoxLayout(BarChartWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 5, 0, 5);
        cellToolFrame = new QFrame(BarChartWidget);
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

        verticalSpacer = new QSpacerItem(20, 339, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(cellToolFrame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cellXFrame = new QFrame(BarChartWidget);
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

        gridCheckBox = new QCheckBox(cellXFrame);
        gridCheckBox->setObjectName(QStringLiteral("gridCheckBox"));
        gridCheckBox->setFocusPolicy(Qt::NoFocus);
        gridCheckBox->setChecked(true);

        horizontalLayout->addWidget(gridCheckBox);

        horizontalSpacer = new QSpacerItem(493, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(cellXFrame);

        cellPlotFrame = new QFrame(BarChartWidget);
        cellPlotFrame->setObjectName(QStringLiteral("cellPlotFrame"));
        sizePolicy.setHeightForWidth(cellPlotFrame->sizePolicy().hasHeightForWidth());
        cellPlotFrame->setSizePolicy(sizePolicy);
        cellPlotFrame->setFocusPolicy(Qt::NoFocus);
        cellPlotFrame->setFrameShape(QFrame::StyledPanel);
        cellPlotFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(cellPlotFrame);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        horizontalLayout_2->addLayout(verticalLayout);

        cellYFrame = new QFrame(BarChartWidget);
        cellYFrame->setObjectName(QStringLiteral("cellYFrame"));
        cellYFrame->setMaximumSize(QSize(30, 16777215));
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

        pushButton_4 = new QPushButton(cellYFrame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 30));
        pushButton_4->setMaximumSize(QSize(30, 30));
        pushButton_4->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_2->addWidget(cellYFrame);


        retranslateUi(BarChartWidget);

        QMetaObject::connectSlotsByName(BarChartWidget);
    } // setupUi

    void retranslateUi(QWidget *BarChartWidget)
    {
        BarChartWidget->setWindowTitle(QApplication::translate("BarChartWidget", "BarChartWidget", 0));
        zoomerBtn->setText(QApplication::translate("BarChartWidget", "\346\224\276\345\244\247/\347\274\251\345\260\217", 0));
        pannerBtn->setText(QApplication::translate("BarChartWidget", "\345\271\263\347\247\273", 0));
        pushButton_3->setText(QApplication::translate("BarChartWidget", "\350\256\276\347\275\256", 0));
        gridCheckBox->setText(QApplication::translate("BarChartWidget", "\350\203\214\346\231\257\346\226\271\346\240\274\347\272\277", 0));
        pushButton_4->setText(QApplication::translate("BarChartWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class BarChartWidget: public Ui_BarChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARCHARTWIDGET_H
