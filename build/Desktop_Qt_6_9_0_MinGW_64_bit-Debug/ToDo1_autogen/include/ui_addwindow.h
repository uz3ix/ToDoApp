/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *inputNameTask;
    QLabel *labelDesc;
    QPlainTextEdit *inputDescribeTask;
    QLabel *labelDateToggle;
    QCheckBox *isDateTask;
    QLabel *labelDate;
    QDateTimeEdit *dateTimeEdit;
    QLabel *errorLabel;
    QHBoxLayout *buttonsLayout;
    QPushButton *pushBut_HomePage;
    QPushButton *pushBut_creatTask;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName("AddWindow");
        AddWindow->resize(800, 600);
        centralwidget = new QWidget(AddWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(headerLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(centralwidget);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        inputNameTask = new QLineEdit(centralwidget);
        inputNameTask->setObjectName("inputNameTask");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, inputNameTask);

        labelDesc = new QLabel(centralwidget);
        labelDesc->setObjectName("labelDesc");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelDesc);

        inputDescribeTask = new QPlainTextEdit(centralwidget);
        inputDescribeTask->setObjectName("inputDescribeTask");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputDescribeTask->sizePolicy().hasHeightForWidth());
        inputDescribeTask->setSizePolicy(sizePolicy);
        inputDescribeTask->setMinimumSize(QSize(0, 60));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, inputDescribeTask);

        labelDateToggle = new QLabel(centralwidget);
        labelDateToggle->setObjectName("labelDateToggle");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDateToggle);

        isDateTask = new QCheckBox(centralwidget);
        isDateTask->setObjectName("isDateTask");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, isDateTask);

        labelDate = new QLabel(centralwidget);
        labelDate->setObjectName("labelDate");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelDate);

        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName("dateTimeEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, dateTimeEdit);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, errorLabel);


        mainLayout->addLayout(formLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        pushBut_HomePage = new QPushButton(centralwidget);
        pushBut_HomePage->setObjectName("pushBut_HomePage");
        pushBut_HomePage->setMinimumSize(QSize(200, 50));

        buttonsLayout->addWidget(pushBut_HomePage);

        pushBut_creatTask = new QPushButton(centralwidget);
        pushBut_creatTask->setObjectName("pushBut_creatTask");
        pushBut_creatTask->setMinimumSize(QSize(200, 50));

        buttonsLayout->addWidget(pushBut_creatTask);


        mainLayout->addLayout(buttonsLayout);

        AddWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AddWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddWindow);
        statusbar->setObjectName("statusbar");
        AddWindow->setStatusBar(statusbar);

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddWindow)
    {
        AddWindow->setWindowTitle(QCoreApplication::translate("AddWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("AddWindow", "font-size: 16pt; font-weight: bold;", nullptr));
        headerLabel->setText(QCoreApplication::translate("AddWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        labelName->setText(QCoreApplication::translate("AddWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        labelDesc->setText(QCoreApplication::translate("AddWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        labelDateToggle->setText(QCoreApplication::translate("AddWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\260\321\202\321\203:", nullptr));
        labelDate->setText(QCoreApplication::translate("AddWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        errorLabel->setStyleSheet(QCoreApplication::translate("AddWindow", "color: red;", nullptr));
        errorLabel->setText(QString());
        pushBut_HomePage->setStyleSheet(QCoreApplication::translate("AddWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushBut_HomePage->setText(QCoreApplication::translate("AddWindow", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        pushBut_creatTask->setStyleSheet(QCoreApplication::translate("AddWindow", "font-size: 14pt; padding: 10px;", nullptr));
        pushBut_creatTask->setText(QCoreApplication::translate("AddWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
