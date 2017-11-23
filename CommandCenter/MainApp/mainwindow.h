﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "slave.h"
#include <QDebug>

#include "hsftestdialog.h"
#include "zktestdialog.h"
#include "xktestdialog.h"
#include "../Db/dbmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();
//----- check-controller------
    void get_formID_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

//    void dbslots() {

//        DbManager *db = (DbManager*)sender();
//        qDebug()<<"hahhahaha dbmanger " << db->queryData().size();
//        qDebug()<<QThread::currentThreadId();
//        db->deleteLater();
//        db = Q_NULLPTR;
//    }

private:
    Ui::MainWindow *ui;


    HsfTestDialog *hsfDlg;
    ZkTestDialog *zkDlg;
    XkTestDialog *xkDlg;
};

#endif // MAINWINDOW_H
