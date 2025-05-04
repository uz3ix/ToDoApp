#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),addWindow(new AddWindow(this)),deleteWindow(new DeleteWindow(this)), tasksWindow(new TasksWindow(this))
    , staticinfo(new StaticticsInfo), calendarwindow(new CalendarWindow(this)), taskNotification(new TaskNotification(this))
{
    ui->setupUi(this);

    connect(addWindow, &AddWindow::taskAdded, tasksWindow, &TasksWindow::createTasksViewer);
    connect(addWindow, &AddWindow::taskAdded, deleteWindow, &DeleteWindow::createTasksViewerD);
    connect(deleteWindow, &DeleteWindow::taskDeleted, tasksWindow, &TasksWindow::createTasksViewer);
    connect(addWindow, &AddWindow::taskAdded, calendarwindow, &CalendarWindow::highlightTaskDates);
    connect(deleteWindow, &DeleteWindow::taskDeleted, calendarwindow, &CalendarWindow::highlightTaskDates);
    connect(deleteWindow, &DeleteWindow::taskDeleted, staticinfo, &StaticticsInfo::viewCountTasks);
    connect(addWindow, &AddWindow::taskAdded, staticinfo, &StaticticsInfo::viewCountTasks);
    connect(tasksWindow, &TasksWindow::taskComleted, staticinfo, &StaticticsInfo::viewCountTasks);
    connect(deleteWindow, &DeleteWindow::taskDeleted, this, &MainWindow::getNextTask);
    connect(addWindow, &AddWindow::taskAdded, this, &MainWindow::getNextTask);


    taskNotification->hide();
    connectToDB();
    getNextTask();
    startCheckingTasks();

}

MainWindow::~MainWindow()
{
    delete ui;
}


// CONNECT TO DB

void MainWindow::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");

    }
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");
        if (!db.open()) {
            qDebug() << "Ошибка при открытии БД в AddWindow:" << db.lastError().text();
        } else {
            qDebug() << "База данных открыта в AddWindow";
        }
    }

    db.setDatabaseName("tasks.db");

    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "name TEXT, "
                    "description TEXT, "
                    "date TEXT,"
                    "has_time INTEGER DEFAULT 0,"
                    "is_completed INTEGER DEFAULT 0)")) {
        
    }
}


// GO TO ADDWINDOW

void MainWindow::on_pushBut_addWindow_clicked()
{
    addWindow->setGeometry(this->geometry());
    hide();
    addWindow->show();
}


// GO TO DELETEWINDOW

void MainWindow::on_pushButton_todeleteWindow_clicked()
{
    deleteWindow->setGeometry(this->geometry());
    hide();
    deleteWindow->show();
}


// GET NEAREST TASK

void MainWindow::getNextTask(){


    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");

    QDateTime currentTime = QDateTime::currentDateTime();
    QString currentTimeStr = currentTime.toString("dd-MM-yyyy HH:mm");


    QSqlQuery query(db);
    query.prepare("SELECT id, name, description, date FROM tasks WHERE has_time = 1 AND date >= :currentTime ORDER BY date ASC LIMIT 1");
    query.bindValue(":currentTime", currentTimeStr);

    if (query.exec()) {
        if (query.next()) {
            QString name = query.value(1).toString();
            QString description = query.value(2).toString();
            QString date = query.value(3).toString();
            ui->nearestTaskDate_label->setHidden(false);
            ui->nearestTaskDescription_label->setHidden(false);
            ui->nearestTaskName_label->setHidden(false);
            ui->nearestTask_label->setText("Ближайшая задача");
            ui->nearestTaskName_label->setText("Название задачи: "+ name);
            if(description==""){
                ui->nearestTaskDescription_label->setHidden(true);
            }else{
                ui->nearestTaskDescription_label->setText("Описание задачи: "+ description);
            }
            ui->nearestTaskDate_label->setText("Дата: "+ date);


        } else {
            ui->nearestTask_label->setText("Нет ближайших задач!");
            ui->nearestTaskDate_label->setHidden(true);
            ui->nearestTaskDescription_label->setHidden(true);
            ui->nearestTaskName_label->setHidden(true);
        }
    }

}


// VIEW STATICTICS ABOUT TASKS

void MainWindow::on_pushButton_toStatisticWindow_clicked()
{
    staticinfo->show();
}


// GO TO ALL TASKS

void MainWindow::on_pushButton_Tasks_clicked()
{
    tasksWindow->setGeometry(this->geometry());
    hide();
    tasksWindow->show();
}


// GO TO CALENDAR

void MainWindow::on_pushButton_toCalendarWindow_clicked()
{
    calendarwindow->setGeometry(this->geometry());
    hide();
    calendarwindow->show();
}


// CHECK TIME TASKS

void MainWindow::checkTasks(){
    QDateTime currentTime = QDateTime::currentDateTime();
    QString currentTimeStr = currentTime.toString("dd-MM-yyyy HH:mm");

    QSqlQuery query;
    query.prepare("SELECT name, description, date FROM tasks WHERE has_time = 1 AND date = :date");
    query.bindValue(":date", currentTimeStr);

    QString name, desc;
    QDateTime time;

    if (query.exec()) {
        while (query.next()) {
            name = query.value(0).toString();
            desc = query.value(1).toString();
            time = query.value(2).toDateTime();

            taskNotification->show();

            if (taskNotification) {
                taskNotification->showTask(name, desc, time);

                QTimer::singleShot(20000, taskNotification, &TaskNotification::hide);
            }
        }
    }


}

void MainWindow::startCheckingTasks(){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkTasks);
    timer->start(60000);
}



void MainWindow::on_pushButton_help_clicked()
{
    QMessageBox::information(this, "Инструкция", "1.При добавлении задачи не забудьте написать название!\n"
"Без него нельзя создать задачу.\n"
"2.Уведомление о времени выполнения задачи может произойти не сразу как подойдет время, так как проверка происходит один раз в 60 секунд.\n"
"3.При удалении задачи и измении статуса на «Выполнено» убедитесь, что вы выбрали задачу, а не Дату, в противном случае программа вылетит.\n");
}

