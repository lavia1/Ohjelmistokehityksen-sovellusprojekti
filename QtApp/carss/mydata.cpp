#include "mydata.h"
#include "ui_mydata.h"

MyData::MyData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyData)
{
    ui->setupUi(this);
}

MyData::~MyData()
{
    delete ui;
}
