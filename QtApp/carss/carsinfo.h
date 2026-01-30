#ifndef CARSINFO_H
#define CARSINFO_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "environment.h"
namespace Ui {
class Carsinfo;
}

class Carsinfo : public QDialog
{
    Q_OBJECT

public:
    explicit Carsinfo(QWidget *parent = nullptr);
    ~Carsinfo();

    void setModel(const QString &newModel);

    void setBranch(const QString &newBranch);

    void setid(const QString &newid);

private:
    Ui::Carsinfo *ui;
    QString model;
    QString branch;
    QString id;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;

private slots:
    void btnMyDataClicked();
    void MyDataSlot();

};

#endif // CARSINFO_H
