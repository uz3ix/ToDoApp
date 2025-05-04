#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DeleteWindow::DeleteWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
    connectToDB();
    createTasksViewerD();
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}


// CONNECT TO DB

void DeleteWindow::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");


    }
}


// CREATE TASKSVIEWER

void DeleteWindow::createTasksViewerD(){
    ui->TasksViewer->clearContents();
    ui->TasksViewer->setRowCount(0);
    ui->TasksViewer->setColumnCount(4);
    QStringList headers = {"Название", "Описание", "Дата", "ID"};
    ui->TasksViewer->setHorizontalHeaderLabels(headers);
    ui->TasksViewer->setColumnHidden(3, true);
    ui->TasksViewer->setWordWrap(true);
    QSqlQuery query("SELECT id, name, description, date, has_time FROM tasks ORDER BY has_time ASC, date ASC");

    int row = 0;
    QString lastGroup = "";

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString description = query.value(2).toString();
        QString date = query.value(3).toString();
        int hasTime = query.value(4).toInt();

        QString currentGroup = hasTime == 1 ? "ЗАДАЧИ НА: " + date.left(10) : "БЕЗ ДАТЫ";

        if (currentGroup != lastGroup) {
            ui->TasksViewer->insertRow(row);
            QTableWidgetItem *groupItem = new QTableWidgetItem(currentGroup);
            groupItem->setFlags(Qt::ItemIsEnabled);
            groupItem->setBackground(Qt::lightGray);
            groupItem->setTextAlignment(Qt::AlignCenter);

            QFont boldFont;
            boldFont.setBold(true);
            groupItem->setFont(boldFont);

            ui->TasksViewer->setSpan(row, 0, 1, 3);
            ui->TasksViewer->setItem(row, 0, groupItem);
            row++;

            lastGroup = currentGroup;
        }

        ui->TasksViewer->insertRow(row);
        ui->TasksViewer->setItem(row, 0, new QTableWidgetItem(name));
        ui->TasksViewer->setItem(row, 1, new QTableWidgetItem(description=="" ? "_" : description));
        ui->TasksViewer->setItem(row, 2, new QTableWidgetItem(hasTime == 1 ? date : "_"));
        ui->TasksViewer->setItem(row, 3, new QTableWidgetItem(QString::number(id)));
        row++;
    }

    ui->TasksViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->TasksViewer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TasksViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


// DELETE TASK

void DeleteWindow::on_pushButton_deleteTask_clicked()
{
    int rowSelected = ui->TasksViewer->currentRow();
    if (rowSelected == -1) {
        ui->isDeleted_text->setText("Вы не выбрали задачу!");
        return;
    }

    if (!ui->TasksViewer->item(rowSelected, 3)) {
        ui->isDeleted_text->setText("Выбрана группа задач, а не конкретная задача!");
        return;
    }

    QString idTask = ui->TasksViewer->item(rowSelected, 3)->text();

    QSqlQuery query;
    if (!query.prepare("DELETE FROM tasks WHERE id = :id")) {
        qDebug() << "Prepare error:" << query.lastError().text();
        return;
    }
    query.bindValue(":id", idTask);

    if (!query.exec()) {
        ui->isDeleted_text->setText("Ошибка при удалении: " + query.lastError().text());
        qDebug() << "Delete error:" << query.lastError().text();
    } else {
        ui->isDeleted_text->setText("Задача успешно удалена!");
        ui->TasksViewer->removeRow(rowSelected);

        int headerRow = rowSelected - 1;
        if (headerRow >= 0 && !ui->TasksViewer->item(headerRow, 3)) {
            bool hasOtherTasks = false;
            for (int row = headerRow + 1; row < ui->TasksViewer->rowCount(); row++) {
                if (!ui->TasksViewer->item(row, 3)) break;
                hasOtherTasks = true;
                break;
            }
            if (!hasOtherTasks) {
                ui->TasksViewer->removeRow(headerRow);
            }
        }

        emit taskDeleted();
    }
}


// GO TO HOMEPAGE

void DeleteWindow::on_pushButton_toHomePage_clicked()
{

    auto mw = qobject_cast<MainWindow*>(parent());
    mw->setGeometry(this->geometry());
    hide();
    mw->show();
    ui->isDeleted_text->clear();

}

