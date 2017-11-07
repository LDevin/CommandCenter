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
