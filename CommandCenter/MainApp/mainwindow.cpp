#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->fromID,SIGNAL(clicked(bool)),this,SLOT(get_formID_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getUserInfo(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), ret);
    qDebug() << "ret " << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray ret;//c341cbe3-95d0-442c-95a0-3a61e224d21c
    Link::Slave::slave()->getDatalinelist(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildBasicDetailById(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 555, ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_5_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResBuildByName(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "fsadf", ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_6_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->addResEnforce(tr("92262a4e-cf96-4093-a77a-373e6b256284"), "dfdsafdsf",ret);
    qDebug() << "ret " << ret;
}

void MainWindow::on_pushButton_7_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getOauthToken("admin", "admin", "client",ret);
    qDebug() << "ret " << ret;
}

//----------get--form id------
void MainWindow::get_formID_clicked(){
    qDebug()<<"get formid click";
}

void MainWindow::on_pushButton_8_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResEnforceDetail(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 895,ret);
    qDebug() << tr("ret 执法队伍详情 ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_9_clicked()
{
    //胡胜飞
    hsfDlg = new HsfTestDialog(this);
    hsfDlg->show();
}



void MainWindow::on_pushButton_10_clicked()
{
    //张坤
    zkDlg = new ZkTestDialog(this);
    zkDlg->show();
}



void MainWindow::on_pushButton_11_clicked()
{
    //辛奎
    xkDlg = new XkTestDialog(this);
    xkDlg->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    //统计分析执法伍
    QByteArray ret;
    Link::Slave::slave()->getResEnforceDeviceView(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 895,ret);
    qDebug() << tr("ret fdfd ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_13_clicked()
{
    //执法队伍列表
    QByteArray ret;
    Link::Slave::slave()->getResEnforceList(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "dfd", 1, 1,ret);
    qDebug() << tr("ret zzzzzz ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_14_clicked()
{
    //新增执法人员
    QByteArray ret;
    Link::Slave::slave()->addResEnforcePerson(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 454, "{}",ret);
    qDebug() << tr("ret fffff ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_15_clicked()
{
    //查询执法人员详情
    QByteArray ret;
    Link::Slave::slave()->getResEnforcePersonDetail(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 454, 236,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_16_clicked()
{
    //获取执法队伍人员信息列表
    QByteArray ret;
    Link::Slave::slave()->getResEnforcePersonList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 454, "236", 1,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_17_clicked()
{
    //修改执法队伍
    QByteArray ret;
    Link::Slave::slave()->updateResEnforce(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_18_clicked()
{
    //新增灭火器
    QByteArray ret;
    Link::Slave::slave()->addResExtinguisher(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_19_clicked()
{
    //灭火器详情
    QByteArray ret;
    Link::Slave::slave()->getResExtinguisherDetail(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), 456,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_20_clicked()
{
    //灭火器列表
    QByteArray ret;
    Link::Slave::slave()->getResExtinguisherList(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "111", -1, -1, "222", "333", 2, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_21_clicked()
{
    //修改灭火器
    QByteArray ret;
    Link::Slave::slave()->updateResExtinguisher(tr("e2db273f-e23a-4727-8f70-1d23ac563be1"), "{}", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_22_clicked()
{
    //b000481f-fdd6-4877-bbcf-ec5586227008
    QByteArray ret;//tttt
    Link::Slave::slave()->getResFirePlugDeviceView(tr("b000481f-fdd6-4877-bbcf-ec5586227008"), 456, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();

}

void MainWindow::on_pushButton_23_clicked()
{
    //b000481f-fdd6-4877-bbcf-ec5586227008
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugDevMac(tr("b000481f-fdd6-4877-bbcf-ec5586227008"), 456, ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_24_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugUnconcern(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "",1, ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_25_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugConcernned(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "111","222",1, ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_26_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->updateResFirePlug(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "{}", ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_27_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->getResGetByKey(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "aaa", ret);
    qDebug() << tr("ret ttt ddt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_28_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->addResRecureCar(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 12345, "{}",ret);
    qDebug() << tr("ret fffff ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_29_clicked()
{
    //修改消防车辆
    QByteArray ret;
    Link::Slave::slave()->updateResRecureCar(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_30_clicked()
{
    QByteArray ret;
    Link::Slave::slave()->addResRescure(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "{}",ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << QJsonDocument::fromJson(ret).object()["msg"].toString();
}

void MainWindow::on_pushButton_31_clicked()
{
    //查询消防车辆详情
    QByteArray ret;
    Link::Slave::slave()->getResRescureCarDetail(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 455, 456,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_32_clicked()
{
    //查询消防车辆列表
    QByteArray ret;
    Link::Slave::slave()->getResRescureCarList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 111, 1,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_33_clicked()
{
    //查询救援队伍详情
    QByteArray ret;
    Link::Slave::slave()->getResRescureDetail(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 545,ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_34_clicked()
{
    //统计分析救援队伍
    QByteArray ret;
    Link::Slave::slave()->getResRescureDeviceview(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 123, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_35_clicked()
{
    //新增救援人员
    QByteArray ret;
    Link::Slave::slave()->addResRescurePerson(tr("cbc5a5c4-e49f-4c29-9cd5-2bd0e30d9502"), 111, "ssfdf", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_36_clicked()
{
    //查询救援人员详情
    QByteArray ret;
    Link::Slave::slave()->getResRescurePersonDetail(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 11, 22, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_37_clicked()
{
    //查询救援人员列表
    QByteArray ret;
    Link::Slave::slave()->getResRescurePersonList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 11, 1, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_38_clicked()
{
    //修改救援人员
    QByteArray ret;
    Link::Slave::slave()->updateResRecurePerson(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "sss", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_39_clicked()
{
    //修改救援队伍
    QByteArray ret;
    Link::Slave::slave()->updateResRecure(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "sss", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_40_clicked()
{
    //救援队伍列表
    QByteArray ret;
    Link::Slave::slave()->getResRescureList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "dfd", 1, 1, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_41_clicked()
{
    //新增消防水源
    QByteArray ret;
    Link::Slave::slave()->addResWater(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "dfd", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_42_clicked()
{
    //获取消防水源详情
    QByteArray ret;
    Link::Slave::slave()->getResWaterDetail(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 1000, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_43_clicked()
{
    //统计消防水源
    QByteArray ret;
    Link::Slave::slave()->getResWaterDeviceView(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), 456, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_44_clicked()
{
    //消防水源列表
    QByteArray ret;
    Link::Slave::slave()->getResWaterList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"), "123", 1, "bb", "cc", 4, 1, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_45_clicked()
{
    //修改消防水源信息
    QByteArray ret;
    Link::Slave::slave()->updateResWater(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"),"111", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_46_clicked()
{
    //获取父地域
    QByteArray ret;
    Link::Slave::slave()->getResZoneByParent(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"),1, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_47_clicked()
{
    //根据父地域获取子地域
    QByteArray ret;
    Link::Slave::slave()->getResFullZone(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"),"11", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_48_clicked()
{
    //室外水压关联的消火栓
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugDoconern(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"),1000,"11", ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}

void MainWindow::on_pushButton_49_clicked()
{
    //室外水压关联的消火栓
    QByteArray ret;
    Link::Slave::slave()->getResFirePlugList(tr("25d09553-0107-4105-9fbc-be65b00a3ba0"),"1000", 1, 1, 1, "222", 1, "11", "33", 8, ret);
    qDebug() << tr("ret tttt ").toLocal8Bit() << ret;
}
