/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

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

class Ui_DeleteWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QTableWidget *TasksViewer;
    QLabel *isDeleted_text;
    QHBoxLayout *buttonLayout;
    QPushButton *pushButton_toHomePage;
    QPushButton *pushButton_deleteTask;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName("DeleteWindow");
        DeleteWindow->resize(800, 600);
        centralwidget = new QWidget(DeleteWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(headerLabel);

        TasksViewer = new QTableWidget(centralwidget);
        if (TasksViewer->columnCount() < 3)
            TasksViewer->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TasksViewer->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TasksViewer->setObjectName("TasksViewer");
        TasksViewer->setColumnCount(3);

        mainLayout->addWidget(TasksViewer);

        isDeleted_text = new QLabel(centralwidget);
        isDeleted_text->setObjectName("isDeleted_text");

        mainLayout->addWidget(isDeleted_text);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        pushButton_toHomePage = new QPushButton(centralwidget);
        pushButton_toHomePage->setObjectName("pushButton_toHomePage");
        pushButton_toHomePage->setMinimumSize(QSize(200, 50));

        buttonLayout->addWidget(pushButton_toHomePage);

        pushButton_deleteTask = new QPushButton(centralwidget);
        pushButton_deleteTask->setObjectName("pushButton_deleteTask");
        pushButton_deleteTask->setMinimumSize(QSize(200, 50));

        buttonLayout->addWidget(pushButton_deleteTask);


        mainLayout->addLayout(buttonLayout);

        DeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeleteWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DeleteWindow);
        statusbar->setObjectName("statusbar");
        DeleteWindow->setStatusBar(statusbar);

        retranslateUi(DeleteWindow);

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("DeleteWindow", "font-size: 16pt; font-weight: bold;", nullptr));
        headerLabel->setText(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TasksViewer->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DeleteWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TasksViewer->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DeleteWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TasksViewer->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DeleteWindow", "\320\224\320\260\321\202\320\260", nullptr));
        isDeleted_text->setText(QString());
        pushButton_toHomePage->setStyleSheet(QCoreApplication::translate("DeleteWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushButton_toHomePage->setText(QCoreApplication::translate("DeleteWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        pushButton_deleteTask->setStyleSheet(QCoreApplication::translate("DeleteWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushButton_deleteTask->setText(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
