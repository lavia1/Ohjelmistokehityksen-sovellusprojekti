#include "carsinfo.h"
#include "ui_carsinfo.h"

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
    ui->labelBranch->setText(id);
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
        if (!doc.isArray()) return;  // oletetaan että palvelin palauttaa JSON-arrayn

        QJsonArray carsArray = doc.array();

        // Tyhjennä nykyiset tiedot (jos käytät esimerkiksi QTableWidget tai QListWidget)
        ui->listCars->clear();

        for (const QJsonValue &value : carsArray) {
            QJsonObject obj = value.toObject();
            QString model = obj["model"].toString();
            QString branch = obj["branch"].toString();
            QString id = obj["id"].toString();

            QString displayText = id + ": " + model + " (" + branch + ")";
            ui->listCars->addItem(displayText); // listCars = QListWidget UI:ssa
        }

}
