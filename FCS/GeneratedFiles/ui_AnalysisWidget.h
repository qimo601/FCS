/********************************************************************************
** Form generated from reading UI file 'AnalysisWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISWIDGET_H
#define UI_ANALYSISWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalysisWidget
{
public:

    void setupUi(QWidget *AnalysisWidget)
    {
        if (AnalysisWidget->objectName().isEmpty())
            AnalysisWidget->setObjectName(QStringLiteral("AnalysisWidget"));
        AnalysisWidget->resize(400, 300);

        retranslateUi(AnalysisWidget);

        QMetaObject::connectSlotsByName(AnalysisWidget);
    } // setupUi

    void retranslateUi(QWidget *AnalysisWidget)
    {
        AnalysisWidget->setWindowTitle(QApplication::translate("AnalysisWidget", "AnalysisWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalysisWidget: public Ui_AnalysisWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISWIDGET_H
