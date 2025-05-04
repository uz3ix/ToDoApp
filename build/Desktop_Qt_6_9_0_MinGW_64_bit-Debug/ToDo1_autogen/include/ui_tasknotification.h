/********************************************************************************
** Form generated from reading UI file 'tasknotification.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKNOTIFICATION_H
#define UI_TASKNOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskNotification
{
public:
    QVBoxLayout *mainLayout;
    QLabel *InfoTask_label;

    void setupUi(QWidget *TaskNotification)
    {
        if (TaskNotification->objectName().isEmpty())
            TaskNotification->setObjectName("TaskNotification");
        TaskNotification->resize(400, 200);
        mainLayout = new QVBoxLayout(TaskNotification);
        mainLayout->setObjectName("mainLayout");
        InfoTask_label = new QLabel(TaskNotification);
        InfoTask_label->setObjectName("InfoTask_label");
        InfoTask_label->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(InfoTask_label);


        retranslateUi(TaskNotification);

        QMetaObject::connectSlotsByName(TaskNotification);
    } // setupUi

    void retranslateUi(QWidget *TaskNotification)
    {
        TaskNotification->setWindowTitle(QCoreApplication::translate("TaskNotification", "\320\235\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\320\265", nullptr));
        InfoTask_label->setText(QCoreApplication::translate("TaskNotification", "\320\242\320\265\320\272\321\201\321\202 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        InfoTask_label->setStyleSheet(QCoreApplication::translate("TaskNotification", "font-size: 14pt; padding: 20px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskNotification: public Ui_TaskNotification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKNOTIFICATION_H
