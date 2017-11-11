#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->fromID,SIGNAL(clicked(bool)),this,SLOT(get_formID_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getUserInfo(tr(""), ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_2_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResEnforceDeviceView(666, ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getDatalinelist(tr(""), ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildBasicDetailById(tr("c341cbe3-95d0-442c-95a0-3a61e224d21c"), 555, ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_5_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildByName(tr("92262a4e-cf96-4093-a77a-373e6b256284"), "fsadf", ret);
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
