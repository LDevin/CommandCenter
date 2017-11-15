#ifndef ZKTESTDIALOG_H
#define ZKTESTDIALOG_H

#include <QDialog>
#include "slave.h"

namespace Ui {
class ZkTestDialog;
}

class ZkTestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZkTestDialog(QWidget *parent = 0);
    ~ZkTestDialog();

private slots:
    void on_pushButton_clicked();

    void on_detail_clicked();

    void on_BuildView_clicked();

    void on_deviceview_clicked();

    void on_devType_clicked();

    void on_directDev_clicked();

    void on_entDevList_clicked();

    void on_dirEnt_clicked();

private:
    Ui::ZkTestDialog *ui;
};

#endif // ZKTESTDIALOG_H
