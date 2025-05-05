/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topButtonsLayout;
    QSpacerItem *horizontalSpacer_top;
    QPushButton *pushButton_help;
    QLabel *nearestTask_label;
    QVBoxLayout *vboxLayout;
    QLabel *nearestTaskName_label;
    QLabel *nearestTaskDescription_label;
    QLabel *nearestTaskDate_label;
    QHBoxLayout *buttonsLayout;
    QPushButton *pushBut_addWindow;
    QPushButton *pushButton_Tasks;
    QPushButton *pushButton_todeleteWindow;
    QHBoxLayout *hboxLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_toStatisticWindow;
    QPushButton *pushButton_toCalendarWindow;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        topButtonsLayout = new QHBoxLayout();
        topButtonsLayout->setObjectName("topButtonsLayout");
        horizontalSpacer_top = new QSpacerItem(40, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topButtonsLayout->addItem(horizontalSpacer_top);

        pushButton_help = new QPushButton(centralwidget);
        pushButton_help->setObjectName("pushButton_help");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_help->sizePolicy().hasHeightForWidth());
        pushButton_help->setSizePolicy(sizePolicy);
        pushButton_help->setMinimumSize(QSize(100, 30));
        pushButton_help->setMaximumSize(QSize(100, 30));
        pushButton_help->setStyleSheet(QString::fromUtf8("font-size: 10pt; padding: 2px;"));

        topButtonsLayout->addWidget(pushButton_help);


        verticalLayout->addLayout(topButtonsLayout);

        nearestTask_label = new QLabel(centralwidget);
        nearestTask_label->setObjectName("nearestTask_label");
        nearestTask_label->setMinimumSize(QSize(0, 100));
        nearestTask_label->setMaximumSize(QSize(16777215, 100));
        nearestTask_label->setStyleSheet(QString::fromUtf8("font-size: 16pt; font-weight: bold;"));
        nearestTask_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(nearestTask_label);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        nearestTaskName_label = new QLabel(centralwidget);
        nearestTaskName_label->setObjectName("nearestTaskName_label");
        QFont font;
        font.setPointSize(12);
        nearestTaskName_label->setFont(font);
        nearestTaskName_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout->addWidget(nearestTaskName_label);

        nearestTaskDescription_label = new QLabel(centralwidget);
        nearestTaskDescription_label->setObjectName("nearestTaskDescription_label");
        nearestTaskDescription_label->setFont(font);
        nearestTaskDescription_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout->addWidget(nearestTaskDescription_label);

        nearestTaskDate_label = new QLabel(centralwidget);
        nearestTaskDate_label->setObjectName("nearestTaskDate_label");
        nearestTaskDate_label->setFont(font);
        nearestTaskDate_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vboxLayout->addWidget(nearestTaskDate_label);


        verticalLayout->addLayout(vboxLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        pushBut_addWindow = new QPushButton(centralwidget);
        pushBut_addWindow->setObjectName("pushBut_addWindow");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushBut_addWindow->sizePolicy().hasHeightForWidth());
        pushBut_addWindow->setSizePolicy(sizePolicy1);
        pushBut_addWindow->setMinimumSize(QSize(200, 50));
        pushBut_addWindow->setStyleSheet(QString::fromUtf8("font-size: 14pt; padding: 10px;"));

        buttonsLayout->addWidget(pushBut_addWindow);

        pushButton_Tasks = new QPushButton(centralwidget);
        pushButton_Tasks->setObjectName("pushButton_Tasks");
        sizePolicy1.setHeightForWidth(pushButton_Tasks->sizePolicy().hasHeightForWidth());
        pushButton_Tasks->setSizePolicy(sizePolicy1);
        pushButton_Tasks->setMinimumSize(QSize(200, 50));
        pushButton_Tasks->setStyleSheet(QString::fromUtf8("font-size: 14pt; padding: 10px;"));

        buttonsLayout->addWidget(pushButton_Tasks);

        pushButton_todeleteWindow = new QPushButton(centralwidget);
        pushButton_todeleteWindow->setObjectName("pushButton_todeleteWindow");
        sizePolicy1.setHeightForWidth(pushButton_todeleteWindow->sizePolicy().hasHeightForWidth());
        pushButton_todeleteWindow->setSizePolicy(sizePolicy1);
        pushButton_todeleteWindow->setMinimumSize(QSize(200, 50));
        pushButton_todeleteWindow->setStyleSheet(QString::fromUtf8("font-size: 14pt; padding: 10px;"));

        buttonsLayout->addWidget(pushButton_todeleteWindow);

        buttonsLayout->setStretch(0, 1);
        buttonsLayout->setStretch(2, 1);

        verticalLayout->addLayout(buttonsLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        pushButton_toStatisticWindow = new QPushButton(centralwidget);
        pushButton_toStatisticWindow->setObjectName("pushButton_toStatisticWindow");
        sizePolicy1.setHeightForWidth(pushButton_toStatisticWindow->sizePolicy().hasHeightForWidth());
        pushButton_toStatisticWindow->setSizePolicy(sizePolicy1);
        pushButton_toStatisticWindow->setMinimumSize(QSize(200, 50));
        pushButton_toStatisticWindow->setStyleSheet(QString::fromUtf8("font-size: 14pt; padding: 10px;"));

        hboxLayout->addWidget(pushButton_toStatisticWindow);

        pushButton_toCalendarWindow = new QPushButton(centralwidget);
        pushButton_toCalendarWindow->setObjectName("pushButton_toCalendarWindow");
        sizePolicy1.setHeightForWidth(pushButton_toCalendarWindow->sizePolicy().hasHeightForWidth());
        pushButton_toCalendarWindow->setSizePolicy(sizePolicy1);
        pushButton_toCalendarWindow->setMinimumSize(QSize(200, 50));
        pushButton_toCalendarWindow->setStyleSheet(QString::fromUtf8("font-size: 14pt; padding: 10px;"));

        hboxLayout->addWidget(pushButton_toCalendarWindow);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(hboxLayout);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\260\320\275\320\270\321\200\320\276\320\262\321\211\320\270\320\272 \320\267\320\260\320\264\320\260\321\207", nullptr));
        pushButton_help->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        nearestTask_label->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\270\320\266\320\260\320\271\321\210\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260:", nullptr));
        nearestTaskName_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        nearestTaskDescription_label->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        nearestTaskDate_label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        pushBut_addWindow->setText(QCoreApplication::translate("MainWindow", "\342\236\225 \320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_Tasks->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 \320\227\320\260\320\264\320\260\321\207\320\270", nullptr));
        pushButton_todeleteWindow->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221 \320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        pushButton_toStatisticWindow->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 \320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        pushButton_toCalendarWindow->setText(QCoreApplication::translate("MainWindow", "\360\237\223\205 \320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
