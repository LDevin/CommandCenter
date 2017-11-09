#include "zktestdialog.h"
#include "ui_zktestdialog.h"

ZkTestDialog::ZkTestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZkTestDialog)
{
    ui->setupUi(this);
}

ZkTestDialog::~ZkTestDialog()
{
    delete ui;
}
