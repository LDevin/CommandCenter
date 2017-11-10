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

    Link::Slave::slave()->getBuildDevList(tr("f4087b3d-7602-46d9-8270-8b49cdbfec07"), body, ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
