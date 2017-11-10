#include "hsftestdialog.h"
#include "ui_hsftestdialog.h"
#include"qdebug.h"
#include"slave.h"

HsfTestDialog::HsfTestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HsfTestDialog)
{
    ui->setupUi(this);
}

HsfTestDialog::~HsfTestDialog()
{
    delete ui;
}

void HsfTestDialog::on_infoID_clicked()
{
   qDebug()<<"get-infoID-click";
   QByteArray ret;
   Link::Slave::slave()->getInfoDetailById(tr("92262a4e-cf96-4093-a77a-373e6b256284"), "articleId:22 ", ret);
   qDebug() << "ret " << ret;
}
