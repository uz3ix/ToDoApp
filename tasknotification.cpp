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
    // QColor bgColor = palette().window().color();

//     // Устанавливаем критически важные атрибуты
//     setAttribute(Qt::WA_StyledBackground, true);
//     setAttribute(Qt::WA_TranslucentBackground, false);
//     setAutoFillBackground(true);

//     // Явно задаем стиль с border
//     setStyleSheet(QString(R"(
//     TaskNotification {
//         background-color: %1;
//         border: 2px solid white;
//         border-radius: 8px;
//         padding: 12px;
//     }
//     QLabel {
//         color: %2;
//         background: transparent;
//         font-size: 20px;  /* Размер текста */
//         font-weight: 500;  /* Жирность */
//     }
// )").arg(bgColor.name())
//                       .arg(bgColor.lightness() > 128 ? "black" : "white"));

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
