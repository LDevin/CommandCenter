#include "hsftestdialog.h"
#include "ui_hsftestdialog.h"
#include"qdebug.h"
#include"slave.h"

#define ACCESSTOKEN "119dc22f-1280-4f15-87ca-98727a47efb5"

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
   Link::Slave::slave()->getInfoDetailById(tr(ACCESSTOKEN), 1, 11, ret);
   qDebug() << "ret " << ret;
}

void HsfTestDialog::on_infoID_S_clicked()
{
    qDebug()<<"on_infoID_S_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoExcellentRecommend(tr(ACCESSTOKEN), ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_infoList_clicked()
{
    qDebug()<<"on_infoList_clicked";
    QByteArray ret;
    //QString jsonStr=QString("{pageNum:%1, title:%2, classifyID1:%3, classifyID2:%4}").arg("1").arg("").arg("").arg("");
    QString jsonStr=QString("{pageNum:%1}").arg(1);
    Link::Slave::slave()->getInfolist(tr(ACCESSTOKEN), jsonStr, ret);
    qDebug() << "ret " << ret;
}
