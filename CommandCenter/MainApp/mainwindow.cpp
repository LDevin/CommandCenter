#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getUserInfo(tr("c341cbe3-95d0-442c-95a0-3a61e224d21c"), ret);
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
    QByteArray ret;
    Link::Slave::slave()->getDatalinelist(tr("c341cbe3-95d0-442c-95a0-3a61e224d21c"), ret);
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
