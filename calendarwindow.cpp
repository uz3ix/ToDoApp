#include "calendarwindow.h"
#include "ui_calendarwindow.h"
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QSqlError>
#include <QTextCharFormat>
#include <QDebug>


CalendarWindow::CalendarWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalendarWindow)
{
    ui->setupUi(this);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    ui->TasksOnDateTable->setHidden(true);
    connectToDB();
    highlightTaskDates();
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &CalendarWindow::onDateClicked);

}

CalendarWindow::~CalendarWindow()
{
    delete ui;
}


// CONNECT TO DB

void CalendarWindow::connectToDB(){
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection", false);
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("tasks.db");
    }
}


// GO TO HOMEPAGE

void CalendarWindow::on_pushButton_toHomePage_clicked()
{
    if (auto mw = qobject_cast<MainWindow*>(parent())) {
        mw->setGeometry(this->geometry());
        hide();
        mw->show();
    }
}


// HIGHLIGHTING TASKS WITH COLOR

void CalendarWindow::highlightTaskDates() {
    // 1. Полностью сбросить форматирование ВСЕХ дат в календаре
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    // 2. Формат для выделения дат с задачами
    QTextCharFormat taskDateFormat;
    taskDateFormat.setForeground(Qt::white);
    taskDateFormat.setBackground(Qt::red);
    taskDateFormat.setFontWeight(QFont::Bold);

    // 3. Получаем список дат, для которых есть задачи
    QSqlQuery query("SELECT DISTINCT date FROM tasks WHERE has_time = 1");
    QSet<QDate> datesWithTasks;

    while (query.next()) {
        QString dateStr = query.value(0).toString();
        QDateTime temp = QDateTime::fromString(dateStr, "dd-MM-yyyy HH:mm");
        QDate date = temp.date();

        if (date.isValid()) {
            datesWithTasks.insert(date);
        }
    }

    // 4. Применяем форматирование только для дат, где есть задачи
    foreach (const QDate &date, datesWithTasks) {
        ui->calendarWidget->setDateTextFormat(date, taskDateFormat);
    }
}





// SHOW TASK IN DATE

void CalendarWindow::onDateClicked(const QDate &date) {
    ui->TasksOnDateTable->setHidden(false);
    ui->TasksOnDateTable->clearContents();
    ui->TasksOnDateTable->setRowCount(0);

    QStringList headers = {"Название", "Описание", "Время", "Статус"};
    ui->TasksOnDateTable->setColumnCount(4);
    ui->TasksOnDateTable->setHorizontalHeaderLabels(headers);

    QString dateStr = date.toString("dd-MM-yyyy");

    QSqlQuery query;
    query.prepare("SELECT name, description, date, is_completed FROM tasks WHERE has_time = 1 AND date LIKE :date || '%'");
    query.bindValue(":date", dateStr);

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            QString name = query.value(0).toString();
            QString description = query.value(1).toString();
            QString fullDate = query.value(2).toString();
            bool isCompleted = query.value(3).toInt();

            QString time = QDateTime::fromString(fullDate, "dd-MM-yyyy HH:mm").time().toString("HH:mm");
            QString status = isCompleted ? "Выполнена" : "Не выполнена";

            ui->TasksOnDateTable->insertRow(row);
            ui->TasksOnDateTable->setItem(row, 0, new QTableWidgetItem(name));
            ui->TasksOnDateTable->setItem(row, 1, new QTableWidgetItem(description.isEmpty() ? "-" : description));
            ui->TasksOnDateTable->setItem(row, 2, new QTableWidgetItem(time));
            ui->TasksOnDateTable->setItem(row, 3, new QTableWidgetItem(status));
            row++;
        }

        if (row == 0) {
            ui->TasksOnDateTable->setRowCount(1);
            ui->TasksOnDateTable->setSpan(0, 0, 1, 4);

            QTableWidgetItem *item = new QTableWidgetItem("Нет задач на этот день.");
            item->setTextAlignment(Qt::AlignCenter);
            ui->TasksOnDateTable->setItem(0, 0, item);
        }
    } else {
        qDebug() << "Ошибка запроса: " << query.lastError().text();
    }

    ui->TasksOnDateTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
