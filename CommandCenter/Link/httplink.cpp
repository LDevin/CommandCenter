#include "httplink.h"
#include "helper/jsonhelper.h"


HttpLink::HttpLink(HttpConfiguration *config) : _linkDone(false)
{
    Q_ASSERT(_config != NULL);
    _config = config;
    _content.clear();
}

HttpLink::~HttpLink()
{
    _content.clear();
    setQuit(true);
    quit();
    wait();
    delete _config;
    _config = Q_NULLPTR;
}

QString HttpLink::getName() const
{
    return _config->name();
}

void HttpLink::setLinkConfiguration(LinkConfiguration *cfg)
{
    Q_ASSERT(cfg != NULL);
    _config = dynamic_cast<HttpConfiguration*>(cfg);
}

LinkConfiguration* HttpLink::getLinkConfiguration()
{
    return _config;
}

void HttpLink::setUrl(QUrl url)
{
    req.setUrl(url);
}

void HttpLink::setContentType(HttpConfiguration::RequestContentType type)
{
    if ( type == HttpConfiguration::JsonType ) {
        req.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    }

#if MUTILEPLE
    else {}
#endif

}

void HttpLink::startRequest(const QByteArray &requestData)
{
    startHttpRequest(requestData);
}

void HttpLink::startHttpRequest(const QByteArray &data)
{
    QString href = _config->urlToString();
    qDebug()<<href;

    if (href.isEmpty()) return;

    if (isRunning()) return;
    resetTimer();

    setContentType(_config->contentType());

    QNetworkReply *reply;

    if ( _config->requestType() == HttpConfiguration::GET) {
        setUrl(QUrl(href.append(data)));
        reply = qam.get(req);
    } else if (_config->requestType() == HttpConfiguration::POST) {
        setUrl(QUrl(href));
        reply = qam.post(req, data);
    }

    qDebug()<<"req url "<<req.url();
    if ( NULL == reply )return;

    connect(reply, &QNetworkReply::finished, this, &LinkInterface::linkFinished);
    connect(reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
            [=](QNetworkReply::NetworkError code){ qDebug()<< (int)code;});

    start();
}

void HttpLink::run()
{
    while (!getQuit()) {
        if (timeOut()) {
            setQuit(true);
            linkTimeOutReply();
            qDebug() << "link request time out!";
        }
    }

    qDebug() << "link thread exec!";
}

void HttpLink::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerOutId()) {
        setTimeOut(true);
        killTimer(timerOutId());
    }
}

void HttpLink::linkFinished()
{
    QNetworkReply *reply = (QNetworkReply *)sender();

    qDebug() << reply->header(QNetworkRequest::ContentTypeHeader);
    qDebug() << reply->rawHeaderPairs();

    QByteArray  data = reply->readAll();

    setContentData(data);
    emit readFinished(data);

    qDebug() << data;

    reply->deleteLater();
    if (reply) {
        delete reply;
        reply = Q_NULLPTR;
    }

    setQuit(true);
}

QByteArray HttpLink::contentData() const
{
    return _content;
}

void HttpLink::setContentData(QByteArray &content)
{
    _content = content;
}

void HttpLink::linkTimeOutReply()
{
    if ( _config ) {
        setContentData(QByteArray().append(_config->timeOutMsg()));
        emit readFinished(QByteArray().append(_config->timeOutMsg()));
    }
}

void HttpLink::setlinkDone(bool linkDone)
{
    _linkDone = linkDone;
}

bool HttpLink::isLinkDone() const
{
    return _linkDone;
}

void HttpLink::setRequestHeader(const QByteArray &header)
{
    QJsonObject obj;
    if (!JsonHelper::toObject(header, obj)) {
        return;
    }

    QStringList keys = obj.keys();
    foreach (QString key, keys) {
        QVariant val = obj[key].toVariant();
        req.setRawHeader(key.toLatin1(), val.toByteArray());
    }
}

void HttpLink::setRequestBody(const QByteArray &body)
{
    switch (_config->contentType()) {

    case HttpConfiguration::JsonType: {

    }
        break;

    case HttpConfiguration::FormDataType: {

    }
        break;

    case HttpConfiguration::XwwwType: {

    }
        break;

    case HttpConfiguration::TextXmlType: {

    }
        break;
    default:
        break;
    }
}
