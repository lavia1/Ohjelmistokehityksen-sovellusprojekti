#include "carsinfo.h"
#include "ui_carsinfo.h"
#include <QDebug>

Carsinfo::Carsinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Carsinfo)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    connect(ui->btnMyData, &QPushButton::clicked, this, &Carsinfo::btnMyDataClicked);

}

Carsinfo::~Carsinfo()
{
    delete ui;
}

void Carsinfo::setModel(const QString &newModel)
{
    model = newModel;
    ui->labelModel->setText(model);
}

void Carsinfo::setBranch(const QString &newBranch)
{
    branch = newBranch;
    ui->labelBranch->setText(branch);
}

void Carsinfo::setid(const QString &newid)
{
    id = newid;
    ui->labelid->setText(id);
}

void Carsinfo::btnMyDataClicked()
{
    QString url=environment::base_url()+"cars";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &Carsinfo::MyDataSlot);
}

void Carsinfo::MyDataSlot()
{
    QByteArray responseData = reply->readAll();
        reply->deleteLater();

        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        if (!doc.isArray()) return;

        QJsonArray carsArray = doc.array();

        ui->listCars->clear();

        for (const QJsonValue &value : carsArray) {
            QJsonObject obj = value.toObject();
            QString model = obj["model"].toString();
            QString branch = obj["branch"].toString();
            QString id = obj["id"].toString();

            QString displayText = id + ": " + model + " (" + branch + ")";
            QListWidgetItem *item = new QListWidgetItem(displayText);
            item->setData(Qt::UserRole, id);   // ← id talteen oikein
            ui->listCars->addItem(item);
        }

}

void Carsinfo::on_btnDelete_clicked()
{
    qDebug() << "DELETE CLICKED";
    QListWidgetItem * item = ui->listCars->currentItem();
    if (!item) return;

    QString id = item->data(Qt::UserRole).toString();
    qDebug() << "Deleting id:" << id;

    QString url = environment::base_url()+"cars/" + id;
    QNetworkRequest request(url);

    reply = manager->deleteResource(request);
    connect(reply, &QNetworkReply::finished,
            this, &Carsinfo::deleteFinished);
}
void Carsinfo::deleteFinished()
{
    QByteArray response = reply->readAll();
       qDebug() << "DELETE response:" << response;
       qDebug() << "HTTP error:" << reply->error();

       reply->deleteLater();
       btnMyDataClicked(); // päivitä lista
}


