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

private:
    Ui::ZkTestDialog *ui;
};

#endif // ZKTESTDIALOG_H
