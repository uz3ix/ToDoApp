#include "addwindow.h"
#include "ui_addwindow.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


AddWindow::AddWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDate(QDate::currentDate());
    connectToDB();
}

AddWindow::~AddWindow()
{
    delete ui;
}


// CONNECT TO DB

void AddWindow::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");
    }
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Ошибка открытия БД:" << db.lastError().text();
        } else {
            qDebug() << "База данных открыта";
        }
    }
}


// RETURN TO HOMEPAGE

void AddWindow::on_pushBut_HomePage_clicked()
{
    ui->inputNameTask->clear();
    ui->inputDescribeTask->clear();
    ui->errorLabel->clear();
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->isDateTask->setChecked(false);

    if (auto mw = qobject_cast<MainWindow*>(parent())) {
        mw->setGeometry(this->geometry());
        hide();
        mw->show();
    }
}


// CREATE TASKS

void AddWindow::on_pushBut_creatTask_clicked()
{
    if (ui->inputNameTask->text().trimmed().isEmpty()){
        ui->errorLabel->setText("Вы не ввели название задачи!");
        return;
    }
    QSqlQuery insertQuery;

    QString nameTask = ui->inputNameTask->text();
    QString describeTask = ui->inputDescribeTask->toPlainText();

    insertQuery.prepare("INSERT INTO tasks (name, description, date, has_time) "
                        "VALUES (:name, :description, :date, :has_time)");
    insertQuery.bindValue(":name", nameTask);
    insertQuery.bindValue(":description", describeTask);
    if (ui->isDateTask->isChecked()){
        QString dateTask = ui->dateTimeEdit->dateTime().toString("dd-MM-yyyy HH:mm");
        insertQuery.bindValue(":date", dateTask);
        insertQuery.bindValue(":has_time", 1);
    }
    insertQuery.exec();

    emit taskAdded();
    ui->inputNameTask->clear();
    ui->inputDescribeTask->clear();
    ui->errorLabel->clear();
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->isDateTask->setChecked(false);

    if (auto mw = qobject_cast<MainWindow*>(parent())) {
        mw->setGeometry(this->geometry());
        hide();
        mw->show();
    }
}



