#include "slave.h"

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
    _mutex.lock();
    LinkInterface *link = (LinkInterface *)sender();

    emit slaveFetchLinkData(link->contentData());
    qDebug()<<"contentData: "<<link->contentData();

    link->deleteLater();
    delete link;
    link = Q_NULLPTR;

    if (link) {
        qDebug() << "the link is destroyed failed ";
    } else {
        qDebug()<<"the link is destroyed success!  ";
    }
    _mutex.unlock();
}

void Slave::getUserInfo(const QString &authorization)
{
    if ( authorization.isEmpty() ) return;

    HttpConfiguration *config = new HttpConfiguration();

    Link::LinkDataBag linkDataBag = Link::Config::config()->dataBagMap()[LINK_ROOT_API_USER][LINK_API_USERINFO];

    config->setRequestUrl(QUrl(linkDataBag.fullUrl));
    config->setRequestType(static_cast<HttpConfiguration::RequestType>(linkDataBag.req));

    config->setTimeOutMsg(callTimeOutMsg());

    LinkInterface *link = new HttpLink(config);

    connect(link, &LinkInterface::finished, this, &Slave::slaveFinishedWork);

    qDebug()<<"linkDataBag "<<linkDataBag.para;

    QJsonObject p = QJsonDocument::fromVariant(QVariant(linkDataBag.para)).object();
    p.remove("Authorization");
    p.insert("Authorization", authorization);

    link->startRequest(QJsonDocument(p).toJson());
}

void Slave::getDatalinelist(const QByteArray &para)
{
    Q_UNUSED(para)
}

}

