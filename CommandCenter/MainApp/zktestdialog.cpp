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

    Link::Slave::slave()->getBuildDevList(tr("ad54d649-7135-467a-a89a-1d682a108367"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_detail_clicked()
{
    QByteArray ret;

    Link::Slave::slave()->getDevDetail(tr("ad54d649-7135-467a-a89a-1d682a108367"), "743-b10e-01e8a14d6366", ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void ZkTestDialog::on_BuildView_clicked()
{
    QByteArray ret;


    QString body= QString("dataLineID=hhh&relatedID=hhh&name=hhhhj&type=1&pageNum=1&lat=22.4555&lng=114.5555");
    Link::Slave::slave()->getBuildView(tr("ad54d649-7135-467a-a89a-1d682a108367"), body, ret);

    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
