#ifndef HSFTESTDIALOG_H
#define HSFTESTDIALOG_H

#include <QDialog>

namespace Ui {
class HsfTestDialog;
}

class HsfTestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HsfTestDialog(QWidget *parent = 0);
    ~HsfTestDialog();

private:
    Ui::HsfTestDialog *ui;
};

#endif // HSFTESTDIALOG_H
