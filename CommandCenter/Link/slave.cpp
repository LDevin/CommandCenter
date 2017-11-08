﻿#include "slave.h"
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

void Slave::setLinkConfigurationData(LinkConfiguration *linkCfg,
                                     const QString &root,
                                     const QString &api)
{
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

bool Slave::getResBuildBasicDetailById(QString &token, long id, QByteArray &ret)
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

}

