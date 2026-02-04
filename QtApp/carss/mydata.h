#ifndef MYDATA_H
#define MYDATA_H

#include <QDialog>

namespace Ui {
class MyData;
}

class MyData : public QDialog
{
    Q_OBJECT

public:
    explicit MyData(QWidget *parent = nullptr);
    ~MyData();

private:
    Ui::MyData *ui;
};

#endif // MYDATA_H
