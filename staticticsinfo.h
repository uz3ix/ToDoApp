#ifndef STATICTICSINFO_H
#define STATICTICSINFO_H

#include <QWidget>

namespace Ui {
class StaticticsInfo;
}

class StaticticsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StaticticsInfo(QWidget *parent = nullptr);
    ~StaticticsInfo();

public slots:
    void viewCountTasks();
    int countAllTasks();
    int countCompletedTasks();

private slots:
    void connectToDB();




private:
    Ui::StaticticsInfo *ui;

};

#endif // STATICTICSINFO_H
