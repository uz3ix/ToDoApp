#include "tasknotification.h"
#include "ui_tasknotification.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QMenu>
#include <QAction>
#include <QTimer>

TaskNotification::TaskNotification(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TaskNotification)
{
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_ShowWithoutActivating);
    ui->setupUi(this);
}

TaskNotification::~TaskNotification()
{
    delete ui;
}

void TaskNotification::showTask(QString name, QString desc, QDateTime time){
    ui->InfoTask_label->setWordWrap(true);
    ui->InfoTask_label->setTextFormat(Qt::RichText);
    if (desc == ""){
        ui->InfoTask_label->setText("Время выполнить задачу!<br>"
                                    "Название:" + name + "<br>");
    }else{
        ui->InfoTask_label->setText("Время выполнить задачу!<br>"
                                    "Название:" + name + "<br>"
                                     "Описание:" + desc);
    }
}
