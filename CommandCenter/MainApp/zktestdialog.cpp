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
    Link::Slave::slave()->getBuildDevList("string", "string", 0, 0, ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
