#include "mainwindow.h"
#include "ui_mainwindow.h"



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
    Link::Slave::slave()->getUserInfo(tr("5555"));

//    QObject *ob2;
//    ob2 = obj;

//    delete ob2;
//    ob2 = NULL;

//    if (obj) {
//        qDebug()<<"ddfdfdfvvvvvvvvvd";
//    } else {
//        qDebug()<<"hfdsfhdkf";
//    }
}
