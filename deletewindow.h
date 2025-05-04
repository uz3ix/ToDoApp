#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

signals:
    void taskDeleted();


public slots:
    void createTasksViewerD();

private slots:
    void connectToDB();
    void on_pushButton_deleteTask_clicked();

    void on_pushButton_toHomePage_clicked();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
