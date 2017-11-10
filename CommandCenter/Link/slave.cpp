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
void Slave::setLinkConfigurationData(LinkConfiguration *linkCfg,
                                     const QString &root,
                                     const QString &api)
{
    Q_CHECK_PTR(linkCfg);

    HttpConfiguration *config = dynamic_cast<HttpConfiguration*>(linkCfg);

    Link::LinkDataBag linkDataBag = Link::Config::config()->dataBagMap()[root][api];

    config->setRequestUrl(QUrl(linkDataBag.fullUrl));
    config->setRequestType(static_cast<HttpConfiguration::RequestType>(linkDataBag.req));

    config->setTimeOutMsg(callTimeOutMsg());
}

bool Slave::slaveStartLink(LinkInterface *link,
                           const QByteArray &headerData,
                           const QByteArray &requestData, QByteArray &ret)
{
    QEventLoop eventLoop;
    connect(link, &LinkInterface::finished, &eventLoop, &QEventLoop::quit);

    link->setRequestHeader(headerData);
    link->startRequest(requestData);

    eventLoop.exec();
    qDebug()<<"link data: "<<link->contentData();
    ret = link->contentData();
    destroyLink(link);

    return RETURN_OK;
}


void Slave::destroyLink(LinkInterface *link)
{
    link->deleteLater();
    delete link;
    link = NULL;
    qDebug() << (link ? "destroy link failed! " : "destroy link success!");
}
/*****************link 配置*******************/


/***************各个接口******************/
bool Slave::getOauthToken(const QString &user, const QString &ps,
                          const QString &clientId, QByteArray &ret)
{
    if ( user.isEmpty() || ps.isEmpty() || clientId.isEmpty() ) {
        return RETURN_FALSE;
    }


    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_TOKEN, LINK_API_OAUTH_TOKEN);
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
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_USER, LINK_API_USERINFO);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray sendData = QJsonDocument(p).toJson();

    return slaveStartLink(link, sendData, sendData, ret);
}

bool Slave::getDatalinelist(const QString &token, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_USER, LINK_API_DATALINE_LIST);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();

    return slaveStartLink(link, headerData, QByteArray(), ret);
}

bool Slave::getResBuildBasicDetailById(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_BUILD_BASIC_DETAIL);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();

    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}

bool Slave::getResBuildByName(const QString &token, const QString &name, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_BUILD_SCH_BY_NAME);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();
    return slaveStartLink(link, headerData, name.toLatin1(), ret);
}

bool Slave::addResEnforce(const QString &token, const QString &jsonDto, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_ADD);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);
}

bool Slave::getResEnforceDetail(const QString &token, long id, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_RES, LINK_API_RES_ENFORCE_ADD);

    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();
    return slaveStartLink(link, headerData, tr("%1").arg(id).toLatin1(), ret);
}


bool Slave::getResEnforceDeviceView(long supervisorID, QByteArray &ret)
{

    HttpConfiguration *config = new HttpConfiguration();

    Link::LinkDataBag linkDataBag = Link::Config::config()->dataBagMap()[LINK_ROOT_API_RES][LINK_API_RES_ENFORCE_DEVICEVIEW];

    config->setRequestUrl(QUrl(linkDataBag.fullUrl));
    config->setRequestType(static_cast<HttpConfiguration::RequestType>(linkDataBag.req));

    config->setTimeOutMsg(callTimeOutMsg());

    LinkInterface *link = new HttpLink(config);

    QEventLoop eventLoop;
    connect(link, &LinkInterface::finished, &eventLoop, &QEventLoop::quit);

    QJsonObject p = QJsonDocument::fromVariant(QVariant(linkDataBag.para)).object();
    p.remove("supervisorID");
    p.insert("supervisorID", supervisorID);

    link->startRequest(QJsonDocument(p).toJson());
    eventLoop.exec();
    qDebug()<<"link data: "<<link->contentData();
    ret = link->contentData();
    destroyLink(link);

    return true;
}


bool Slave::getBuildDevList(const QString excpetion, const QString name, int pageNum, int selectId, QByteArray &ret)
{
    HttpConfiguration *config = new HttpConfiguration();

    setLinkConfigurationData(config, LINK_ROOT_API_DEV, LINK_API_DEV_BUILDDEVLIST);
    LinkInterface *link = new HttpLink(config);

    QJsonObject p;
    p.insert("isExcpetion", excpetion);
    p.insert("name", name);
    p.insert("pageNum", pageNum);
    p.insert("selectID", selectId);
    QByteArray headerData = QJsonDocument(p).toJson();
    return slaveStartLink(link, headerData, headerData, ret);
}


bool Slave::getInfoDetailById(const QString &token, int userId, int articleId, QByteArray &ret)
{
    if ( token.isEmpty() ) {
        return RETURN_FALSE;
    }

    HttpConfiguration *config = new HttpConfiguration();
    setLinkConfigurationData(config, LINK_ROOT_API_INFO, LINK_API_INFO_DETAIL);

    LinkInterface *link = new HttpLink(config);
    QJsonObject p;
    p.insert("Authorization", token);

    QByteArray headerData = QJsonDocument(p).toJson();

    QString jsonDto=QString("{articleId:%1, userID:%2}").arg(articleId).arg(userId);
    return slaveStartLink(link, headerData, jsonDto.toLatin1(), ret);

}

}


