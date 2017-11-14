/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef HTTPCONFIGURATION_H
#define HTTPCONFIGURATION_H
#include "linkconfiguration.h"
#include <QUrl>

#define MUTILEPLE 1

class HttpConfiguration : public LinkConfiguration
{
   Q_OBJECT
   Q_ENUMS(RequestType)
   Q_ENUMS(RequestContentType)

public:
    HttpConfiguration();
    HttpConfiguration(const QString &name);
    HttpConfiguration(const HttpConfiguration &copy);

    ~HttpConfiguration();

    /*
     * http get和post请求方式
    */
    enum RequestType {
        HEAD,
        GET,
        POST,
        PUT,
        DELETE,
        CUSTOM
    };

    /*
     * http post 请求时 头header的Content-Type
    */
    enum RequestContentType {
        JsonType, //application/json
#if MUTILEPLE
        FormDataType, // multipart/form-data
        XwwwType, // application/x-www-form-urlencoded
        TextXmlType // text/xml
#endif
    };

    LinkType                type() const { return LinkConfiguration::TypeHttp; }

    RequestType             requestType() const { return _requestType; }
    void                    setRequestType(RequestType type);

    QUrl                    requestUrl() const { return _requestUrl; }
    QString                 urlToString() const { return _requestUrl.toString(); }
    void                    setRequestUrl(QUrl url);

    RequestContentType      contentType() const { return _contentType; }
    void                    setContentType(RequestContentType type);


private:
    RequestType             _requestType;
    QUrl                    _requestUrl;

    RequestContentType      _contentType;

};

#endif // HTTPCONFIGURATION_H
