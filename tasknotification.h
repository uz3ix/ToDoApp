#ifndef TASKNOTIFICATION_H
#define TASKNOTIFICATION_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class TaskNotification;
}

class TaskNotification : public QWidget
{
    Q_OBJECT

public:
    explicit TaskNotification(QWidget *parent = nullptr);
    ~TaskNotification();

public slots:
    void showTask(QString name, QString desc, QDateTime time);

private:
    Ui::TaskNotification *ui;
};

#endif // TASKNOTIFICATION_H
