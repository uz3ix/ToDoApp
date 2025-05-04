/********************************************************************************
** Form generated from reading UI file 'calendarwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARWINDOW_H
#define UI_CALENDARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QCalendarWidget *calendarWidget;
    QTableWidget *TasksOnDateTable;
    QHBoxLayout *buttonLayout;
    QSpacerItem *hSpacer;
    QPushButton *pushButton_toHomePage;
    QSpacerItem *hSpacer2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalendarWindow)
    {
        if (CalendarWindow->objectName().isEmpty())
            CalendarWindow->setObjectName("CalendarWindow");
        CalendarWindow->resize(800, 600);
        centralwidget = new QWidget(CalendarWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(headerLabel);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");

        mainLayout->addWidget(calendarWidget);

        TasksOnDateTable = new QTableWidget(centralwidget);
        if (TasksOnDateTable->columnCount() < 4)
            TasksOnDateTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TasksOnDateTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TasksOnDateTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TasksOnDateTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TasksOnDateTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TasksOnDateTable->setObjectName("TasksOnDateTable");
        TasksOnDateTable->setColumnCount(4);

        mainLayout->addWidget(TasksOnDateTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        hSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(hSpacer);

        pushButton_toHomePage = new QPushButton(centralwidget);
        pushButton_toHomePage->setObjectName("pushButton_toHomePage");
        pushButton_toHomePage->setMinimumSize(QSize(200, 50));

        buttonLayout->addWidget(pushButton_toHomePage);

        hSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(hSpacer2);


        mainLayout->addLayout(buttonLayout);

        CalendarWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalendarWindow);
        menubar->setObjectName("menubar");
        CalendarWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalendarWindow);
        statusbar->setObjectName("statusbar");
        CalendarWindow->setStatusBar(statusbar);

        retranslateUi(CalendarWindow);

        QMetaObject::connectSlotsByName(CalendarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarWindow)
    {
        CalendarWindow->setWindowTitle(QCoreApplication::translate("CalendarWindow", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214 \320\267\320\260\320\264\320\260\321\207", nullptr));
        headerLabel->setText(QCoreApplication::translate("CalendarWindow", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("CalendarWindow", "font-size: 16pt; font-weight: bold;", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TasksOnDateTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CalendarWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TasksOnDateTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CalendarWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TasksOnDateTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CalendarWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TasksOnDateTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CalendarWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        pushButton_toHomePage->setText(QCoreApplication::translate("CalendarWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        pushButton_toHomePage->setStyleSheet(QCoreApplication::translate("CalendarWindow", "font-size: 14pt; padding: 10px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarWindow: public Ui_CalendarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARWINDOW_H
