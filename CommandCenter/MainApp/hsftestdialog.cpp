#include "hsftestdialog.h"
#include "ui_hsftestdialog.h"
#include"qdebug.h"
#include"slave.h"


#define ACCESSTOKEN "b8cdecb2-6f9a-481a-8436-adbf828cd8ad"

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
    QString jsonStr=QString("?pageNum=%1").arg(1);
    Link::Slave::slave()->getInfoList(tr(ACCESSTOKEN), jsonStr, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_infoListID_clicked()
{
    qDebug()<<"on_infoListID_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoListClassifyID1(tr(ACCESSTOKEN), 1, "", ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_morebyid_clicked()
{
    qDebug()<<"on_morebyid_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoListMoreByID(tr(ACCESSTOKEN),2,1,"", ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_updateLikeTimes_clicked()
{
    qDebug()<<"on_updateLikeTimes_clicked";
    QByteArray ret;
    Link::Slave::slave()->updateInfoLikeTimes(tr(ACCESSTOKEN),2,1, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_commentList_clicked()
{
    qDebug()<<"on_commentList_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoCommentList(tr(ACCESSTOKEN), 2, 1, 1, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_childlevel_clicked()
{
    qDebug()<<"on_commentList_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfochildLevel(tr(ACCESSTOKEN), 2, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_firstLevel_clicked()
{
    qDebug()<<"on_commentList_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoFirstLevel(tr(ACCESSTOKEN), ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_infoNavigation_clicked()
{
    qDebug()<<"on_commentList_clicked";
    QByteArray ret;
    Link::Slave::slave()->getInfoNavigation(tr(ACCESSTOKEN), 2, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_addComments_clicked()
{
    qDebug()<<"on_addComments_clicked";
    QByteArray ret;
    Link::Slave::slave()->addInfoComments(tr(ACCESSTOKEN), 0,"stirngssss ", 0, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_delComments_clicked()
{
    qDebug()<<"on_delComments_clicked";
    QByteArray ret;
    Link::Slave::slave()->delInfoComments(tr(ACCESSTOKEN), 3, ret);
    qDebug() << "ret " << ret;
}

void HsfTestDialog::on_updateReadTimes_clicked()
{
    qDebug()<<"on_updateReadTimes_clicked";
    QByteArray ret;
    Link::Slave::slave()->updateInfoReadTimes(tr(ACCESSTOKEN),2,1, ret);
    qDebug() << "ret "<<ret <<QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void HsfTestDialog::on_addCheck_clicked()
{
    qDebug()<<"on_addCheck_clicked";
    QByteArray ret;
    QString jsonStr=QString("{\"itemSet\":\"\",\"pageNum\":1,\"pageSize\" :5,\"startRow\": 0, \"description\": \"test \",\"id\": \"11\","
                            " \"recordID\": \"\",\"itemID\":\"\", \"itemName\":\"\",\"relatedID\":\"\",\"dangerType\":\"1\",\"checkUserID\":\"1\"} ");
    Link::Slave::slave()->getFireCheckItem(tr(ACCESSTOKEN), jsonStr, ret);
    qDebug() << "ret "<<ret <<QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void HsfTestDialog::on_getCheckContentName_clicked()
{
    qDebug()<<"on_addCheck_clicked";
    QByteArray ret;
    Link::Slave::slave()->getFireCheckForm(tr(ACCESSTOKEN), 1, "aa","", "", "", "", ret);
    qDebug() << "ret "<<ret <<QJsonDocument::fromJson(ret).object()["msg"].toString();
}
