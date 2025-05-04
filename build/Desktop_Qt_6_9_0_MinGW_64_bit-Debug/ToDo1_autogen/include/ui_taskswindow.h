/********************************************************************************
** Form generated from reading UI file 'taskswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSWINDOW_H
#define UI_TASKSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QTableWidget *TasksViewer;
    QLabel *isSelected;
    QHBoxLayout *buttonLayout;
    QPushButton *pushButton_toHomePage;
    QPushButton *pushButton_TaskComplete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TasksWindow)
    {
        if (TasksWindow->objectName().isEmpty())
            TasksWindow->setObjectName("TasksWindow");
        TasksWindow->resize(800, 600);
        centralwidget = new QWidget(TasksWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(headerLabel);

        TasksViewer = new QTableWidget(centralwidget);
        if (TasksViewer->columnCount() < 4)
            TasksViewer->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TasksViewer->setObjectName("TasksViewer");
        TasksViewer->setColumnCount(4);

        mainLayout->addWidget(TasksViewer);

        isSelected = new QLabel(centralwidget);
        isSelected->setObjectName("isSelected");

        mainLayout->addWidget(isSelected);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        pushButton_toHomePage = new QPushButton(centralwidget);
        pushButton_toHomePage->setObjectName("pushButton_toHomePage");
        pushButton_toHomePage->setMinimumSize(QSize(200, 50));

        buttonLayout->addWidget(pushButton_toHomePage);

        pushButton_TaskComplete = new QPushButton(centralwidget);
        pushButton_TaskComplete->setObjectName("pushButton_TaskComplete");
        pushButton_TaskComplete->setMinimumSize(QSize(200, 50));

        buttonLayout->addWidget(pushButton_TaskComplete);


        mainLayout->addLayout(buttonLayout);

        TasksWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TasksWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TasksWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TasksWindow);
        statusbar->setObjectName("statusbar");
        TasksWindow->setStatusBar(statusbar);

        retranslateUi(TasksWindow);

        QMetaObject::connectSlotsByName(TasksWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TasksWindow)
    {
        TasksWindow->setWindowTitle(QCoreApplication::translate("TasksWindow", "\320\222\321\201\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("TasksWindow", "font-size: 16pt; font-weight: bold;", nullptr));
        headerLabel->setText(QCoreApplication::translate("TasksWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\320\264\320\260\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TasksViewer->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TasksWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TasksViewer->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TasksWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TasksViewer->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TasksWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TasksViewer->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TasksWindow", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201", nullptr));
        isSelected->setText(QString());
        pushButton_toHomePage->setStyleSheet(QCoreApplication::translate("TasksWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushButton_toHomePage->setText(QCoreApplication::translate("TasksWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        pushButton_TaskComplete->setStyleSheet(QCoreApplication::translate("TasksWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushButton_TaskComplete->setText(QCoreApplication::translate("TasksWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TasksWindow: public Ui_TasksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSWINDOW_H
