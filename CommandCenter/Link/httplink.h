/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef HTTPLINK_H
#define HTTPLINK_H
#include "linkinterface.h"
#include "httpconfiguration.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimerEvent>
#include <QHttpMultiPart>
#include "utils_defines.h"


class HttpLink : public LinkInterface
{

    Q_OBJECT

public:
                        HttpLink(HttpConfiguration *config);
                        ~HttpLink();

    LinkConfiguration*  getLinkConfiguration();
    void                setLinkConfiguration(LinkConfiguration *cfg);

    QString             getName() const;

    QByteArray          contentData() const Q_DECL_OVERRIDE;
    void                setContentData(QByteArray &content) Q_DECL_OVERRIDE;

    void                setUrl(QUrl url);
    void                setContentType(HttpConfiguration::RequestContentType type);

    void                startHttpRequest(const QByteArray &data);

    void                startRequest(const QByteArray &requestData) Q_DECL_OVERRIDE;

    bool                isLinkDone() const Q_DECL_OVERRIDE;
    void                setlinkDone(bool linkDone) Q_DECL_OVERRIDE;

    void                setRequestHeader(const QByteArray &header) Q_DECL_OVERRIDE;
    void                setRequestBody(const QByteArray &body) Q_DECL_OVERRIDE;

    void                setHttpMultiPart(QHttpMultiPart &part,
                                         const QByteArray &jsonBody,
                                         QHttpMultiPart::ContentType type
                                         = QHttpMultiPart::FormDataType
                                         );
    QHttpMultiPart*     httpMultiPart(QHttpMultiPart *part) const { return part; }

public slots:
    void                linkFinished();
    void                linkTimeOutReply();


protected:
    void                run() Q_DECL_OVERRIDE;
    void                timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    HttpConfiguration       *_config;
    QNetworkAccessManager   qam;
    QNetworkRequest         req;

    QByteArray              _content;
    bool                    _linkDone;

private:
   // void                setFormDataBody();


};
#endif // HTTPLINK_H
