#include "taskswindow.h"
#include "ui_taskswindow.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

TasksWindow::TasksWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::TasksWindow)
{
    ui->setupUi(this);
    connectToDB();
    createTasksViewer();
}

TasksWindow::~TasksWindow()
{
    delete ui;
}


// CONNECT TO DB

void TasksWindow::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");
    }
}


// GO TO HOMEPAGE

void TasksWindow::on_pushButton_toHomePage_clicked(){
    ui->isSelected->clear();
    if (auto mw = qobject_cast<MainWindow*>(parent())) {
        mw->setGeometry(this->geometry());
        hide();
        mw->show();
    }
}


// CREATE TASKSVIEWER

void TasksWindow::createTasksViewer(){
    ui->TasksViewer->clearContents();
    ui->TasksViewer->setRowCount(0);
    ui->TasksViewer->setColumnCount(5);
    QStringList headers = {"Название", "Описание", "Дата", "ID", "Прогресс"};
    ui->TasksViewer->setHorizontalHeaderLabels(headers);
    ui->TasksViewer->setColumnHidden(3, true);

    QSqlQuery query("SELECT id, name, description, date, has_time, is_completed FROM tasks ORDER BY has_time ASC, date ASC");

    int row = 0;
    QString lastGroup = "";

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString description = query.value(2).toString();
        QString date = query.value(3).toString();
        int hasTime = query.value(4).toInt();
        int isCompleted = query.value(5).toInt();

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

            ui->TasksViewer->setSpan(row, 0, 1, 5);
            ui->TasksViewer->setItem(row, 0, groupItem);
            row++;

            lastGroup = currentGroup;
        }
        ui->TasksViewer->insertRow(row);

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        nameItem->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        nameItem->setData(Qt::TextWordWrap, true);
        ui->TasksViewer->setItem(row, 0, nameItem);

        QTableWidgetItem *descItem = new QTableWidgetItem(description.isEmpty() ? "_" : description);
        descItem->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        descItem->setData(Qt::TextWordWrap, true);
        ui->TasksViewer->setItem(row, 1, descItem);


        ui->TasksViewer->setItem(row, 2, new QTableWidgetItem(hasTime == 1 ? date : "_"));
        ui->TasksViewer->setItem(row, 3, new QTableWidgetItem(QString::number(id)));
        ui->TasksViewer->setItem(row, 4, new QTableWidgetItem(isCompleted == 1 ? "Выполнена" : "Не выполнена"));

        row++;
    }

    ui->TasksViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->TasksViewer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TasksViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->TasksViewer->setWordWrap(true);
    ui->TasksViewer->resizeRowsToContents();
}



// CHANGE TO COMPLETE

void TasksWindow::on_pushButton_TaskComplete_clicked(){
    int rowSelected = ui->TasksViewer->currentRow();

    if (ui->TasksViewer->item(rowSelected, 4)->text() == "Выполнена"){
        ui->isSelected->setText("Уже выполнена!");
        return;
    }
    if (rowSelected == -1){
        ui->isSelected->setText("Вы не выбрали задачу!");
        return;
    }

    QString idTask = ui->TasksViewer->item(rowSelected, 3)->text();

    QSqlQuery query;
    query.prepare("UPDATE tasks SET is_completed = 1 WHERE id = :id");
    query.bindValue(":id", idTask);

    if (!query.exec()) {
        ui->isSelected->setText("Ошибка при обновлении статуса!");
    } else {
        ui->isSelected->setText("Задача помечена как выполненная!");
        emit taskComleted();
        ui->TasksViewer->item(rowSelected, 4)->setText("Выполнена");
    }
}


