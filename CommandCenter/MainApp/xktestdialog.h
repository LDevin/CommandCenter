#ifndef XKTESTDIALOG_H
#define XKTESTDIALOG_H

#include <QDialog>

namespace Ui {
class XkTestDialog;
}

class XkTestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit XkTestDialog(QWidget *parent = 0);
    ~XkTestDialog();

private:
    Ui::XkTestDialog *ui;
};

#endif // XKTESTDIALOG_H
