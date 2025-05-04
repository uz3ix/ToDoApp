#include "staticticsinfo.h"
#include "ui_staticticsinfo.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StaticticsInfo::StaticticsInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StaticticsInfo)
{
    ui->setupUi(this);
    connectToDB();
    viewCountTasks();

}

StaticticsInfo::~StaticticsInfo()
{
    delete ui;
}


// CONNECT TO DB

void StaticticsInfo::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");
    }
}


int StaticticsInfo::countAllTasks(){
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM tasks");
    query.next();
    int allTasks = query.value(0).toInt();
    qDebug() << allTasks;
    return allTasks;
}


int StaticticsInfo::countCompletedTasks(){
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM tasks WHERE is_completed = 1");
    query.next();
    int completedTasks = query.value(0).toInt();
    qDebug() << completedTasks;
    return completedTasks;
}



void StaticticsInfo::viewCountTasks(){
    int allTasks = countAllTasks();

    if (allTasks == 0){
        ui->NotcomletedTasks->setHidden(true);
        ui->CompletedTasks->setHidden(true);
        ui->allTasks->setText("У вас нет задач");
        return;
    }
    int completedTasks = countCompletedTasks();
    int notCompleted = allTasks - completedTasks;
    ui->NotcomletedTasks->setHidden(false);
    ui->CompletedTasks->setHidden(false);

    ui->allTasks->setText(QString("Все задачи: %1").arg(allTasks));
    ui->CompletedTasks->setText(QString("Выполнено: %1").arg(completedTasks));
    ui->NotcomletedTasks->setText(QString("Не выполнено: %1").arg(notCompleted));
}
