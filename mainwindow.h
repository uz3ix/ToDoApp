#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSystemTrayIcon>

#include "addwindow.h"
#include "deletewindow.h"
#include "taskswindow.h"
#include "staticticsinfo.h"
#include "calendarwindow.h"
#include "tasknotification.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void getNextTask();

private slots:
    void on_pushBut_addWindow_clicked();
    void on_pushButton_todeleteWindow_clicked();
    ;
    void connectToDB();
    void on_pushButton_toStatisticWindow_clicked();
    void on_pushButton_Tasks_clicked();
    void on_pushButton_toCalendarWindow_clicked();

    void checkTasks();
    void startCheckingTasks();

    void on_pushButton_help_clicked();

private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *quitAction;


    Ui::MainWindow *ui;
    AddWindow *addWindow;
    DeleteWindow *deleteWindow;
    TasksWindow *tasksWindow;
    StaticticsInfo *staticinfo;
    CalendarWindow *calendarwindow;
    TaskNotification *taskNotification;


    void createTrayIcon();
    void showNotification(QString message);  // Метод для уведомлений
};
#endif // MAINWINDOW_H
