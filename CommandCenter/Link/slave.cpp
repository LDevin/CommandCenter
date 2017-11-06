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

void Slave::destroyLink(LinkInterface *link)
{
    link->deleteLater();
    delete link;
    link = NULL;
    qDebug() << (link ? "destroy link failed! " : "destroy link success!");
}

void Slave::getUserInfo(const QString &authorization, QByteArray &ret)
{
    if ( authorization.isEmpty() ) return;

    HttpConfiguration *config = new HttpConfiguration();

    Link::LinkDataBag linkDataBag = Link::Config::config()->dataBagMap()[LINK_ROOT_API_USER][LINK_API_USERINFO];

    config->setRequestUrl(QUrl(linkDataBag.fullUrl));
    config->setRequestType(static_cast<HttpConfiguration::RequestType>(linkDataBag.req));

    config->setTimeOutMsg(callTimeOutMsg());

    LinkInterface *link = new HttpLink(config);

    QEventLoop eventLoop;
    connect(link, &LinkInterface::finished, &eventLoop, &QEventLoop::quit);

    QJsonObject p = QJsonDocument::fromVariant(QVariant(linkDataBag.para)).object();
    p.remove("Authorization");
    p.insert("Authorization", authorization);

    link->startRequest(QJsonDocument(p).toJson());
    eventLoop.exec();
    qDebug()<<"link data: "<<link->contentData();
    ret = link->contentData();
    destroyLink(link);
}

void Slave::getDatalinelist(const QByteArray &para, QByteArray &ret)
{
    Q_UNUSED(para)
    Q_UNUSED(ret)
}

}

