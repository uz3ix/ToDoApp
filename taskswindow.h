#ifndef TASKSWINDOW_H
#define TASKSWINDOW_H

#include <QMainWindow>

namespace Ui {
class TasksWindow;
}

class TasksWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TasksWindow(QWidget *parent = nullptr);
    ~TasksWindow();

public slots:
    void createTasksViewer();

signals:
    void taskComleted();

private slots:
    void on_pushButton_toHomePage_clicked();

    void connectToDB();

    void on_pushButton_TaskComplete_clicked();

private:
    Ui::TasksWindow *ui;
};

#endif // TASKSWINDOW_H
