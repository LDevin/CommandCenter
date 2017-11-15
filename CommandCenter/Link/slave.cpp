#include "slave.h"
#include <windows.h>
#include <QEventLoop>
namespace Link {

QMutex mutex;

Slave* Slave::s_slave = Q_NULLPTR;

Slave* Slave::slave()
{
    mutex.lock();
    if ( Q_NULLPTR == s_slave ) {
        s_slave = new Slave();
    }
    mutex.unlock();

    return s_slave;
}

Slave::Slave()
{
    Tools::tools();
    setCallTimeOutMsg(Config::config()->httpOverTimeErrMsg());
}

Slave::~Slave()
{

}

void Slave::setCallTimeOutMsg(QString msg)
{
    _callTimeOutMsg = msg;
}

QString Slave::callTimeOutMsg() const
{
    return _callTimeOutMsg;
}

void Slave::slaveFinishedWork()
{
    QMutex mutex;
    mutex.lock();
    LinkInterface *link = (LinkInterface *)sender();

    emit slaveFetchLinkData(link->contentData());
    mutex.unlock();
}

/*****************link 配置*******************/
bool Slave::setLinkConfigurationData(LinkConfiguration *linkCfg,
                                     const QString &root,
                                     const QString &api, QByteArray &ret)
{
    if (!linkCfg) {
        return returnHttpOtherErrMsg("link instance is NULL!", LINK_INVOKE_CONFIG_NULL, ret);
    }

    HttpConfiguration *config = dynamic_cast<HttpConfiguration*>(linkCfg);
    Link::LinkDataBag linkDataBag = Link::Config::config()->dataBagMap()[root][api];

    if (linkDataBag.fullUrl.isEmpty() ) {
        config->deleteLater();
        return returnHttpOtherErrMsg("link url is empty!", LINK_URL_IS_EMPTY, ret);
    }

    if (linkDataBag.req < 1) {
        config->deleteLater();
        return returnHttpOtherErrMsg("HTTP 请求方式get 或者post 有问题!", LINK_HTTP_REQ_TYPE_ERR, ret);
    }

    if (linkDataBag.api.isEmpty()) {
        config->deleteLater();
        return returnHttpOtherErrMsg("http api的名字有误!", LINK_HTTP_API_NAME_ERR, ret);
    }

    config->setRequestUrl(QUrl(linkDataBag.fullUrl));
    config->setRequestType(static_cast<HttpConfiguration::RequestType>(linkDataBag.req));

    config->setTimeOutMsg(callTimeOutMsg());

    return RETURN_OK;
}

bool Slave::slaveStartLink(LinkInterface *link,
                           const QByteArray &headerData,
                           const QByteArray &requestData, QByteArray &ret)
{
    if ( !link ) {
        link = Q_NULLPTR;
        return returnHttpOtherErrMsg("link instance is NULL!", LINK_INVOKE_CONFIG_NULL, ret);
    }

    QEventLoop eventLoop;
    connect(link, &LinkInterface::finished, &eventLoop, &QEventLoop::quit);

    link->setRequestHeader(headerData);
    link->startRequest(requestData);

    eventLoop.exec();
    LOG("link data: " + link->contentData());

    ret = link->contentData();
    destroyLink(link);

    return RETURN_OK;
}

void Slave::setHttpApiOtherErrMsg(const QString &msg, int code, QByteArray &ret)
{
    if (Config::config()->httpApiOtherErrMsg().isEmpty()) {
        LOG("httpApiOtherErrMsg from tools.json file is empty!");
        return;
    }

    QJsonObject obj;
    if (!JsonHelper::toObject(Config::config()->httpApiOtherErrMsg(), obj)) {
        LOG("httpApiOtherErrMsg from tools.json file is empty!");
        return;
    }

    obj.insert("code", code);
    obj.insert("msg", msg);

    ret = QJsonDocument(obj).toJson();
    LOG(ret);
}

bool Slave::returnHttpOtherErrMsg(const QString &msg, int code, QByteArray &ret)
{
    setHttpApiOtherErrMsg(msg, code, ret);
    return RETURN_FALSE;
}

void Slave::destroyLink(LinkInterface *link)
{
    if ( link ) {
        link->deleteLater();
        delete link;
    }

    link = Q_NULLPTR;
    LOG((link ? "destroy link failed! " : "destroy link success!"))
}
/*****************link 配置*******************/


/***************各个接口******************/
bool Slave::getOauthToken(const QString &user, const QString &ps,
                          const QString &clientId, QByteArray &ret)
{
    if ( user.isEmpty() || ps.isEmpty() || clientId.isEmpty() ) {
        return returnHttpOtherErrMsg("参数为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_TOKEN, LINK_API_OAUTH_TOKEN, ret)) {
        return RETURN_FALSE;
    }

    config->setContentType(HttpConfiguration::XwwwType);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("userName", user);
    p.insert("password", ps);
    p.insert("clientId", clientId);

    QByteArray sendData = QJsonDocument(p).toJson();
    QString body = tr("userName=%1&password=%2&clientId=%3").arg(user).arg(ps).arg(clientId);
    return slaveStartLink(link, sendData, body.toLatin1(), ret);
}

bool Slave::getUserInfo(const QString &token, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg(tr("token为空").toLocal8Bit(), LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_USER, LINK_API_USERINFO, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray sendData;
    Tools::setLinkToken(token, sendData);

    return slaveStartLink(link, sendData, sendData, ret);
}

bool Slave::getDatalinelist(const QString &token, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_USER, LINK_API_DATALINE_LIST, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, QByteArray(), ret);
}

bool Slave::getResBuildBasicDetailById(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_BUILD_BASIC_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}

bool Slave::getResBuildByName(const QString &token, const QString &name, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_BUILD_SCH_BY_NAME, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, name.toLatin1(), ret);
}

bool Slave::addResEnforce(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_ADD, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getResEnforceDetail(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}


bool Slave::getResEnforceDeviceView(const QString &token, long supervisorID, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token为空", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_DEVICEVIEW, ret)) {
        return RETURN_FALSE;
    }

    config->setContentType(HttpConfiguration::XwwwType);

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    QString body = tr("supervisorID=%1").arg(supervisorID);
    return slaveStartLink(link, headerData, body.toLatin1(), ret);
}

bool Slave::getResEnforceList(const QString &token, const QString &name,
                              int type, int pageNum, QByteArray &ret)
{
    if ( token.isEmpty() || pageNum < 1) {
        return returnHttpOtherErrMsg("token为空 或页码错误", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_LIST, ret)) {
        return RETURN_FALSE;
    }

    config->setContentType(HttpConfiguration::XwwwType);

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    QString body = tr("pageNum=%1").arg(pageNum);
    if ( !name.isEmpty() ) {
        body.append(tr("&name=%1").arg(name));
    }

    if ( type > 0 ) {
        body.append(tr("&type=%1").arg(type));
    }

    return slaveStartLink(link, headerData, body.toLatin1(), ret);
}

bool Slave::addResEnforcePerson(const QString &token, long enforceId,
                                const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() || enforceId < 1) {
        return returnHttpOtherErrMsg("has null parameter", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_PERSON_ADD, ret)) {
        return RETURN_FALSE;
    }

    config->setRequestUrl(QUrl(config->urlToString() + "/" + tr("%1").arg(enforceId)));

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getResEnforcePersonList(const QString &token, long enforceId,
                                    const QString &name, int pageNum, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_PERSON_LIST, ret)) {
        return RETURN_FALSE;
    }

    QString urlData = tr("%1?%2").arg(enforceId).arg(pageNum);

    if ( !name.isEmpty() ) {
        urlData += "&" + name;
    }

    config->setRequestUrl(QUrl(config->urlToString() + urlData));

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, QByteArray(), ret);
}

bool Slave::getResEnforcePersonDetail(const QString &token, long enforceid,
                                      long personid, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_PERSON_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    config->setRequestUrl(QUrl(config->urlToString() + tr("%1/%2").arg(enforceid).arg(personid)));

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, QByteArray(), ret);
}

bool Slave::updateResEnforce(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_PERSON_UPDATE, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::addResExtinguisher(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_EXTINGUISHER_ADD, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getResExtinguisherDetail(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_EXTINGUISHER_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}

bool Slave::getResExtinguisherList(const QString &token, const QString &code, long relatedID,
                                   int type, const QString &startTime, const QString &endTime,
                                   int pageNum, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_EXTINGUISHER_LIST, ret)) {
        return RETURN_FALSE;
    }

    if ( pageNum < 1 )
        pageNum = 1;

    config->setRequestUrl(QUrl(config->urlToString() + tr("?pageNum=%1").arg(pageNum)));
    config->setContentType(HttpConfiguration::XwwwType);

    QString body = "";
    if ( !code.isEmpty() ) {
        body += "code=" + code;
    }

    if ( relatedID > 0) {
        body += ( body.isEmpty() ? tr("relatedID=%1").arg(relatedID) : tr("&relatedID=%1").arg(relatedID));
    }

    if ( type > 0) {
        body += ( body.isEmpty() ? tr("type=%1").arg(type) : tr("&type=%1").arg(type));
    }

    if ( !startTime.isEmpty()) {
        body += ( body.isEmpty() ? tr("startTime=%1").arg(startTime) : tr("&startTime=%1").arg(startTime));
    }

    if ( !endTime.isEmpty()) {
        body += ( body.isEmpty() ? tr("endTime=%1").arg(endTime) : tr("&endTime=%1").arg(endTime));
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, body.toLatin1(), ret);
}

bool Slave::updateResExtinguisher(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_EXTINGUISHER_UPDATE, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::addResFirePlug(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_FIREPLUG_ADD, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getResFirePlugDetail(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_FIREPLUG_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}

bool Slave::getResFirePlugDeviceView(const QString &token, long chargerID, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_FIREPLUG_DEVICEVIEW, ret)) {
        return RETURN_FALSE;
    }

    config->setContentType(HttpConfiguration::XwwwType);

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("{\"chargerID\":%1}").arg(chargerID).toLatin1(), ret);
}

bool Slave::getResFirePlugDevMac(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_FIREPLUG_DEVMAC, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}

/**************************************************************************
Description:建筑物（异常）设备汇总
Parameter Type: http body
Data Type:
{
  "isExcpetion": "string",
  "name": "string",
  "pageNum": 0,
  "selectID": 0
}
Description: 建筑物ID,模糊查询名称,页码,是否只显示异常设备：0否，1是

**************************************************************************/
bool Slave::getBuildDevList(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_BUILDDEVLIST, ret)){
        return RETURN_FALSE;
    }
    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:查看建筑物/企业列表显示
Parameter Type: http body
Data Type:
{
    "dataLineID":"strirng",
    "relatedID":"string",
    "name":"string",
    "type":0,
    "pageNum":0,
    "lat":0,
    "lng":0
}
Description: 数据线id,关联单位id||单位类型,建筑物/企业名称,类型，必填(1:建筑物视角,2:企业视角),页码

**************************************************************************/
bool  Slave::getBuildView(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    if ( jsonDto.isEmpty()){
        return returnHttpOtherErrMsg("Parameter  is empty!", LINK_RS_INPUT_NULL, ret);

    }
    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_BUILDVIEW, ret)){
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:查询设备详情
Parameter Type: http query
Data Type: string
Description: 通过设备ID查看设备详情
**************************************************************************/

bool Slave::getDevDetail(const QString &token, const long &devId, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_DETAIL, ret)){
        return RETURN_FALSE;
    }
    config->setRequestUrl(QUrl(config->urlToString() + tr("%1").arg(devId)));

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, QByteArray(), ret);

}

/**************************************************************************
Description:设备视角的数据显示
Parameter Type: http body
Data Type:
{
  "buidingID": 0,
  "itemType": "string",
  "lineID": 0,
  "selectID": 0,
  "selectType": "string"
}
Description: 查询对象的类型，查询对象的关联单位ID，数据线ID,为0查所有，
属于那栋建筑物ID，为0不限制，被监管单位的类型1为建筑物，2企业，3.4.5...
**************************************************************************/

bool  Slave::getDevView(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    if ( jsonDto.isEmpty()){
        return returnHttpOtherErrMsg("Parameter  is empty!", LINK_RS_INPUT_NULL, ret);

    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_DEVICEVIEW, ret)){
        return RETURN_FALSE;
    }
    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:查看设备详细
Parameter Type: http query
Data Type: string
Description: 通过设备ID查看设备类型详情
**************************************************************************/

bool Slave::getDevType(const QString &token, const long &devId, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_DEVTYPE, ret)){
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("?id=%1").arg(devId).toLatin1(), ret);

}

/**************************************************************************
Description:直属设备数据显示
Parameter Type: http body
Data Type:
{
  "lat": "string",
  "lineID": 0,
  "lng": "string",
  "pageNum": 0,
  "queryName": "string",
  "relatedID": 0,
  "type": "string"
}
Description: 直属设备查询时，只需传单位ID，类型
**************************************************************************/

bool Slave::getDirectDev(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    if ( jsonDto.isEmpty()){
        return returnHttpOtherErrMsg("Parameter  is empty!", LINK_RS_INPUT_NULL, ret);

    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_DIRECTDEV, ret)){
        return RETURN_FALSE;
    }
    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:直属企业数据显示
Parameter Type: http body
Data Type:
{
  "lat": 0,
  "lineID": 0,
  "lng": 0,
  "pageNum": 0,
  "queryName": "string",
  "relatedID": 0,
  "type": "string"
}
Description: 领导类型,领导所属关联单位id,要查看的数据线id，要模糊查询的名称(可为空)
**************************************************************************/

bool Slave::getDirectEnt(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    if ( jsonDto.isEmpty()){
        return returnHttpOtherErrMsg("Parameter  is empty!", LINK_RS_INPUT_NULL, ret);

    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_DIRECTENT, ret)){
        return RETURN_FALSE;
    }
    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:企业（异常）设备汇总
Parameter Type: http body
Data Type:
{
  "devTypeID": 0,
  "isExcpetion": "string",
  "pageNum": 0,
  "selectID": 0,
  "systemType": "string"
}
Description: 企业ID,搜索的系统类型和设备类型,页码,是否只显示异常设备：0否，1是
**************************************************************************/

bool Slave::getEntDevList(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    if ( jsonDto.isEmpty()){
        return returnHttpOtherErrMsg("Parameter  is empty!", LINK_RS_INPUT_NULL, ret);

    }

    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_ENTDEVLIST, ret)){
        return RETURN_FALSE;
    }
    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

/**************************************************************************
Description:根据设备历史记录id获取工作流记录
Parameter Name: historyID
Parameter Type: http path
Data Type:long

Parameter Name: userID
Parameter Type: http query
Data Type:long

**************************************************************************/

bool  Slave::getFireLstActByID(const QString &token, const long &historyID, const long &userID, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }
    HttpConfiguration *config = new HttpConfiguration();

    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_FIREWORKFLOW_LISTACTIVITYID, ret)){
        return RETURN_FALSE;
    }

    config->setRequestUrl(QUrl(config->urlToString() + tr("%1").arg(historyID)));
    LinkInterface *link = new HttpLink(config);

    QByteArray headerData;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("?userID=%1").arg(userID).toLatin1(), ret);

}

/**************************************************************************
Description:根据设备历史记录id获取工作流记录
Parameter Name: historyID
Parameter Type: http path
Data Type:long

**************************************************************************/
bool Slave::getFireSelEndTimeByID(const QString &token, const long &historyID, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("token is empty!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_FIREWORKFLOW_SELENDTIMEBUSID, ret)){
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    return slaveStartLink(link, headerData, tr("?historyID=%1").arg(historyID).toLatin1(), ret);
}

bool Slave::getInfoDetailById(const QString &token, int userId, int articleId, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_DETAIL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?articleId=%1&userID=%2").arg(articleId).arg(userId);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);

}

bool Slave::getInfoExcellentRecommend(const QString &token, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_EXCELLENTRECOMMEND, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto="";
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfoList(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() || jsonDto.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }


    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);


    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}



bool Slave::getInfoListClassifyID1(const QString &token, const int classifyID1, const QString title, QByteArray &ret)
{
    if ( token.isEmpty() || classifyID1<0 ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }


    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_CLASSIFYID1, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);
    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);
    QString jsonDto=QString("?title=%1&classifyID1=%2").arg(title).arg(classifyID1);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfoListMoreByID(const QString &token, const int classifyID2, const int pageNum, const QString title,
                                QByteArray &ret)
{
    if ( token.isEmpty()||pageNum<0||classifyID2<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_MOREBYID, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?classifyID2=%1&pageNum=%2&pageNum=%3").arg(classifyID2).arg(pageNum).arg(title);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfoCommentList(const QString &token, const int articleId, const int pageNum, const int userID, QByteArray &ret)
{
    if ( token.isEmpty()||pageNum<0||articleId<0||userID<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_COMMENTS, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?articleId=%1&pageNum=%2&userID=%3").arg(articleId).arg(pageNum).arg(userID);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::updateInfoLikeTimes(const QString &token, const int articleId, const int userID, QByteArray &ret)
{
    if ( token.isEmpty()||articleId<0||userID<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_UPDATELIKETIMES, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("{articleId:%1,userID:%2}").arg(articleId).arg(userID);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfochildLevel(const QString &token, const int relativeID, QByteArray &ret)
{
    if ( token.isEmpty()||relativeID<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_CHILDLEVEL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?relativeID=%1").arg(relativeID);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfoFirstLevel(const QString &token, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_FIRSTLEVEL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto="";
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getInfoNavigation(const QString &token, const int templateId, QByteArray &ret)
{
    if ( token.isEmpty()||templateId<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_LIST_NAVIGATION, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?template=%1").arg(templateId);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}


bool Slave::addInfoComments(const QString &token, const int articleId, const QString content, const int userID, QByteArray &ret)
{
    if ( token.isEmpty()||articleId<0||userID<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_COMMENTS_ADD, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("{\"articleId\":\"%1\",\"content\":\"%2\",\"createUserID\":\"%3\"}").arg(articleId).arg(content).arg(userID);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::delInfoComments(const QString &token, const int id, QByteArray &ret)
{
    if ( token.isEmpty()||id<0) {
        return returnHttpOtherErrMsg("has null parameter!", LINK_INVOKE_OTHER_ERR, ret);
    }

    HttpConfiguration *config = new HttpConfiguration();
    if (!setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_COMMENTS_DEL, ret)) {
        return RETURN_FALSE;
    }

    LinkInterface *link = new HttpLink(config);

    QByteArray headerData ;
    Tools::setLinkToken(token, headerData);

    QString jsonDto=QString("?id=%1").arg(id);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

}


