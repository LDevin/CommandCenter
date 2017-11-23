#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->fromID,SIGNAL(clicked(bool)),this,SLOT(get_formID_clicked()));

    QString msg;
    DbManager::manager()->executeQuery("SELECT * FROM `T_BUILDING`", QJsonArray(), msg);
    LOG("MSG: " + msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getUserInfo(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getDatalinelist(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildBasicDetailById(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 555, ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_5_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildByName(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "fsadf", ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_6_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->addResEnforce(tr("92262a4e-cf96-4093-a77a-373e6b256284"), "dfdsafdsf",ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_7_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getOauthToken("admin", "admin", "client",ret);
    qDebug() << "ret " << ret;
}

//----------get--form id------
void MainWindow::get_formID_clicked(){
    qDebug()<<"get formid click";
}

void MainWindow::on_pushButton_8_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResEnforceDetail(tr("d7fb4aae-439d-45d6-9f9b-0d07f2180e7d"), 895,ret);
    qDebug() << tr("ret 执法队伍详情 ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_9_clicked()
{
    //胡胜飞
    hsfDlg = new HsfTestDialog(this);
    hsfDlg->show();
}



void MainWindow::on_pushButton_10_clicked()
{
    //张坤
    zkDlg = new ZkTestDialog(this);
    zkDlg->show();
}



void MainWindow::on_pushButton_11_clicked()
{
    //辛奎
    xkDlg = new XkTestDialog(this);
    xkDlg->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    //统计分析执法伍
    QByteArray ret;
    Link::Slave::slave()->getResEnforceDeviceView(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 895,ret);
    qDebug() << tr("ret fdfd ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_13_clicked()
{
    //执法队伍列表
    QByteArray ret;
    Link::Slave::slave()->getResEnforceList(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "dfd", 1, 1,ret);
    qDebug() << tr("ret zzzzzz ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_14_clicked()
{
    //新增执法人员
    QByteArray ret;
    Link::Slave::slave()->addResEnforcePerson(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 454, "{}",ret);
    qDebug() << tr("ret fffff ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_15_clicked()
{
    //查询执法人员详情
    QByteArray ret;
    Link::Slave::slave()->getResEnforcePersonDetail(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 454, 236,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_16_clicked()
{
    //获取执法队伍人员信息列表
    QByteArray ret;
    Link::Slave::slave()->getResEnforcePersonList(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 454, "236", 1,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_17_clicked()
{
    //修改执法队伍
    QByteArray ret;
    Link::Slave::slave()->updateResEnforce(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_18_clicked()
{
    //新增灭火器
    QByteArray ret;
    Link::Slave::slave()->addResExtinguisher(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_19_clicked()
{
    //灭火器详情
    QByteArray ret;
    Link::Slave::slave()->getResExtinguisherDetail(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 456,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_20_clicked()
{
    //灭火器列表
    QByteArray ret;
    Link::Slave::slave()->getResExtinguisherList(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "", -1, -1, "", "", 2, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_21_clicked()
{
    //修改灭火器
    QByteArray ret;
    Link::Slave::slave()->updateResExtinguisher(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_22_clicked()
{
    //b000481f-fdd6-4877-bbcf-ec5586227008
    QByteArray ret;//tttt
    Link::Slave::slave()->getResFirePlugDeviceView(tr("b000481f-fdd6-4877-bbcf-ec5586227008"), 456, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();

}

void MainWindow::on_pushButton_23_clicked()
{
    //b000481f-fdd6-4877-bbcf-ec5586227008
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugDevMac(tr("b000481f-fdd6-4877-bbcf-ec5586227008"), 456, ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}
