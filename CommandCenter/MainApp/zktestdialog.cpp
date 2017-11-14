#include "zktestdialog.h"
#include "ui_zktestdialog.h"

ZkTestDialog::ZkTestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZkTestDialog)
{
    ui->setupUi(this);
}

ZkTestDialog::~ZkTestDialog()
{
    delete ui;
}

void ZkTestDialog::on_pushButton_clicked()
{
    QByteArray ret;


    QJsonObject p;
    p.insert("isExcpetion", "0");
    p.insert("name", "");
    p.insert("pageNum", 1);
    p.insert("selectID", 235);
    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getBuildDevList(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_detail_clicked()
{
    QByteArray ret;

    Link::Slave::slave()->getDevDetail(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), "743-b10e-01e8a14d6366", ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_BuildView_clicked()
{
    QByteArray ret;


    QString body= QString("dataLineID=hhh&relatedID=hhh&name=hhhhj&type=1&pageNum=1&lat=22.4555&lng=114.5555");
    Link::Slave::slave()->getBuildView(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_deviceview_clicked()
{
    QByteArray ret;

    QJsonObject p;
    p.insert("buidingID", 0);
    p.insert("itemType", "string");
    p.insert("lineID", 0);
    p.insert("selectID", 0);
    p.insert("selectType", "string");
    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getDevView(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_devType_clicked()
{
    QByteArray ret;

    Link::Slave::slave()->getDevType(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), "743-b10e-01e8a14d6366", ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_directDev_clicked()
{
    QByteArray ret;

    QJsonObject p;
    p.insert("lat", "string");
    p.insert("pageNum", 0);
    p.insert("lineID", 0);
    p.insert("queryName","string");
    p.insert("relatedID", 0);
    p.insert("type", "string");

    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getDirectDev(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
