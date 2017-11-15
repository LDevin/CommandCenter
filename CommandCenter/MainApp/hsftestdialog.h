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

private slots:
    void on_infoID_clicked();

    void on_infoID_S_clicked();

    void on_infoList_clicked();

    void on_infoListID_clicked();

    void on_morebyid_clicked();

    void on_updateLikeTimes_clicked();

    void on_commentList_clicked();

    void on_childlevel_clicked();

    void on_firstLevel_clicked();

    void on_infoNavigation_clicked();

    void on_addComments_clicked();

    void on_delComments_clicked();

private:
    Ui::HsfTestDialog *ui;
};

#endif // HSFTESTDIALOG_H
