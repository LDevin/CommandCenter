#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "slave.h"
#include <QDebug>

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

private:
    Ui::MainWindow *ui;

    void handle(QObject *obj) {

        QObject *ojj = obj;

       qDebug()<<"HHEHH "<<ojj;
       qDebug()<<"dddd "<<obj;

        delete ojj, obj;
        ojj = NULL;
        obj = NULL;


        if (obj == NULL) {
            qDebug()<<"pppp";
        } else {
            qDebug()<<"vvvvvvvvvv";
        }

        qDebug()<<"HHEHH "<<ojj;
        qDebug()<<"dddd "<<obj;

       // delete obj;
       // obj = NULL;
    }
};

#endif // MAINWINDOW_H
