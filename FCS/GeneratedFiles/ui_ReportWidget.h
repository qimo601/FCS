/********************************************************************************
** Form generated from reading UI file 'ReportWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName(QStringLiteral("ReportWidget"));
        ReportWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ReportWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(ReportWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(5, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(5, 3, __qtablewidgetitem33);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ReportWidget);

        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QApplication::translate("ReportWidget", "ReportWidget", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ReportWidget", "\350\256\276\351\227\250ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ReportWidget", "\344\270\252\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ReportWidget", "\344\270\252\346\225\260\346\257\224", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ReportWidget", "CV", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("ReportWidget", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("ReportWidget", "2", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("ReportWidget", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("ReportWidget", "3", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("ReportWidget", "4", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("ReportWidget", "6", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("ReportWidget", "A", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("ReportWidget", "2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 3);
        ___qtablewidgetitem13->setText(QApplication::translate("ReportWidget", "3", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("ReportWidget", "BInA", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("ReportWidget", "4", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 2);
        ___qtablewidgetitem16->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 3);
        ___qtablewidgetitem17->setText(QApplication::translate("ReportWidget", "4", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(2, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("ReportWidget", "CInB", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("ReportWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 3);
        ___qtablewidgetitem21->setText(QApplication::translate("ReportWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(3, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("ReportWidget", "CInA", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(3, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("ReportWidget", "6", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 2);
        ___qtablewidgetitem24->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 3);
        ___qtablewidgetitem25->setText(QApplication::translate("ReportWidget", "5", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(4, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("ReportWidget", "DInB", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(4, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("ReportWidget", "6", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(4, 2);
        ___qtablewidgetitem28->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(4, 3);
        ___qtablewidgetitem29->setText(QApplication::translate("ReportWidget", "6", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(5, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("ReportWidget", "EInB", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(5, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("ReportWidget", "6", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(5, 2);
        ___qtablewidgetitem32->setText(QApplication::translate("ReportWidget", "10%", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(5, 3);
        ___qtablewidgetitem33->setText(QApplication::translate("ReportWidget", "6", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
