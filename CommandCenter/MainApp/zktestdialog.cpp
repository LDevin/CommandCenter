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

    Link::Slave::slave()->getBuildDevList(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_detail_clicked()
{
    QByteArray ret;

    Link::Slave::slave()->getDevDetail(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), 366, ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_BuildView_clicked()
{
    QByteArray ret;


    QString body= QString("dataLineID=hhh&relatedID=hhh&name=hhhhj&type=1&pageNum=1&lat=22.4555&lng=114.5555");
    Link::Slave::slave()->getBuildView(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), body, ret);

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

    Link::Slave::slave()->getDevView(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_devType_clicked()
{
    QByteArray ret;

    Link::Slave::slave()->getDevType(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), 366, ret);
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

    Link::Slave::slave()->getDirectDev(tr("c0280f11-3dcf-43f4-8c9b-6859e808d427"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_entDevList_clicked()
{
    QByteArray ret;

    QJsonObject p;
    p.insert("devTypeID", 0);
    p.insert("isExcpetion", "string");
    p.insert("pageNum", 0);
    p.insert("selectID", 0);
    p.insert("systemType", "string");


    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getEntDevList(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_dirEnt_clicked()
{
    QByteArray ret;

    QJsonObject p;

       p.insert("lat", "string");
       p.insert("lineID", 0);
       p.insert("lng","string");
       p.insert("pageNum", 0);
       p.insert("queryName", "string");
       p.insert("relatedID", 0);
       p.insert("type","string");

    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getDirectEnt(tr("aa28e8022-8ba0-40a7-b871-bdf76be83423"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_listActivByID_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getFireLstActByID(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"), 556,555, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_selTimeEndID_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getFireSelEndTimeByID(tr("a28e8022-8ba0-40a7-b871-bdf76be83423"),555, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_getLeaderView_clicked()
{
    QByteArray ret;

    QJsonObject p;

       p.insert("lat", "string");
       p.insert("lineID", 0);
       p.insert("lng","string");
       p.insert("pageNum", 0);
       p.insert("queryName", "string");
       p.insert("relatedID", 0);
       p.insert("type","string");


    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getLeaderView(tr("fe2618a6-146c-4c80-9bca-cd4903d92fed"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_getMonitorList_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getMonitorList(tr("fe2618a6-146c-4c80-9bca-cd4903d92fed"),555, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_getdevstatelist_clicked()
{
    QByteArray ret;

    QJsonObject p;

     p.insert("gatewayID", "string");
     p.insert("itemType", "string");
     p.insert("lat", "string");
     p.insert("lineID", 0);
     p.insert("lng", "string");
     p.insert("pageNum", 0);
     p.insert("selectID", 0);
     p.insert("selectName", "string");
     p.insert("selectType", "string");
     p.insert("state","string");
     p.insert("systemType", "string");

    QByteArray headerData = QJsonDocument(p).toJson();
    QString body;
    body.append(headerData);

    Link::Slave::slave()->getLeaderView(tr("5b12182d-2328-4a84-9a9b-951b388bac69"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_getStatushiList_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getStatushisList(tr("5b12182d-2328-4a84-9a9b-951b388bac69"), 555,1, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_getSystemTypeList_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getSystemTypeList(tr("5b12182d-2328-4a84-9a9b-951b388bac69"), ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
