#include "xktestdialog.h"
#include "ui_xktestdialog.h"

XkTestDialog::XkTestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XkTestDialog)
{
    ui->setupUi(this);
}

XkTestDialog::~XkTestDialog()
{
    delete ui;
}
