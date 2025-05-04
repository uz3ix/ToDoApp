/********************************************************************************
** Form generated from reading UI file 'staticticsinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICTICSINFO_H
#define UI_STATICTICSINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaticticsInfo
{
public:
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QLabel *allTasks;
    QLabel *CompletedTasks;
    QLabel *NotcomletedTasks;

    void setupUi(QWidget *StaticticsInfo)
    {
        if (StaticticsInfo->objectName().isEmpty())
            StaticticsInfo->setObjectName("StaticticsInfo");
        StaticticsInfo->resize(291, 195);
        mainLayout = new QVBoxLayout(StaticticsInfo);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(StaticticsInfo);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(headerLabel);

        allTasks = new QLabel(StaticticsInfo);
        allTasks->setObjectName("allTasks");
        allTasks->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        mainLayout->addWidget(allTasks);

        CompletedTasks = new QLabel(StaticticsInfo);
        CompletedTasks->setObjectName("CompletedTasks");
        CompletedTasks->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        mainLayout->addWidget(CompletedTasks);

        NotcomletedTasks = new QLabel(StaticticsInfo);
        NotcomletedTasks->setObjectName("NotcomletedTasks");
        NotcomletedTasks->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        mainLayout->addWidget(NotcomletedTasks);


        retranslateUi(StaticticsInfo);

        QMetaObject::connectSlotsByName(StaticticsInfo);
    } // setupUi

    void retranslateUi(QWidget *StaticticsInfo)
    {
        StaticticsInfo->setWindowTitle(QCoreApplication::translate("StaticticsInfo", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\267\320\260\320\264\320\260\321\207", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("StaticticsInfo", "font-size: 16pt; font-weight: bold;", nullptr));
        headerLabel->setText(QCoreApplication::translate("StaticticsInfo", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        allTasks->setStyleSheet(QCoreApplication::translate("StaticticsInfo", "font-size: 14pt;", nullptr));
        allTasks->setText(QCoreApplication::translate("StaticticsInfo", "\320\222\321\201\320\265\320\263\320\276 \320\267\320\260\320\264\320\260\321\207: 0", nullptr));
        CompletedTasks->setStyleSheet(QCoreApplication::translate("StaticticsInfo", "font-size: 14pt;", nullptr));
        CompletedTasks->setText(QCoreApplication::translate("StaticticsInfo", "\320\222\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276: 0", nullptr));
        NotcomletedTasks->setStyleSheet(QCoreApplication::translate("StaticticsInfo", "font-size: 14pt;", nullptr));
        NotcomletedTasks->setText(QCoreApplication::translate("StaticticsInfo", "\320\235\320\265 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaticticsInfo: public Ui_StaticticsInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICTICSINFO_H
