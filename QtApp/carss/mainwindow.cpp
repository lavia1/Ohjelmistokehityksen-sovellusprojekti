#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::btnAddSlot);
    manager=new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnAddSlot(){
    QString url=environment::base_url()+"cars";
    QNetworkRequest request (url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject jObject;
    jObject.insert("model", ui->textModel->text());
    jObject.insert("branch", ui->textBranch->text());
    QJsonDocument jsonDoc(jObject);
    reply=manager->post(request, jsonDoc.toJson());
    connect(reply, &QNetworkReply::finished, this, &MainWindow::getCars);
}

void MainWindow::getCars()
{
    QByteArray responseData = reply->readAll();
        qDebug() << responseData;

        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        if(!doc.isObject()) return;

        QJsonObject obj = doc.object();
        QString newId = obj["id"].toString();

        Carsinfo *objCarsinfo = new Carsinfo(this);
        objCarsinfo->setid(newId);
        objCarsinfo->setModel(ui->textModel->text());
        objCarsinfo->setBranch(ui->textBranch->text());

        objCarsinfo->show();
}

