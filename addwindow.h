#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

signals:
    void taskAdded();

private slots:
    void on_pushBut_HomePage_clicked();
    void connectToDB();
    void on_pushBut_creatTask_clicked();

private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
