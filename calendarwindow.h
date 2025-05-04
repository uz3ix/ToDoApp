#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QMainWindow>

namespace Ui {
class CalendarWindow;
}

class CalendarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = nullptr);
    ~CalendarWindow();

public slots:
    void highlightTaskDates();

private slots:
    void on_pushButton_toHomePage_clicked();
    void connectToDB();

    void onDateClicked(const QDate &date);

private:
    Ui::CalendarWindow *ui;
};

#endif // CALENDARWINDOW_H
