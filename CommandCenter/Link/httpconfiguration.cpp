#include "httpconfiguration.h"


HttpConfiguration::HttpConfiguration() : _requestType(RequestType::GET)
{
    _contentType = HttpConfiguration::JsonType;
}

HttpConfiguration::HttpConfiguration(const QString &name)
    : LinkConfiguration(name), _requestType(RequestType::GET)
{
    _contentType = HttpConfiguration::JsonType;
}

HttpConfiguration::HttpConfiguration(const HttpConfiguration &copy)
    : LinkConfiguration(copy), _requestType(RequestType::GET)
{
    _contentType = copy.contentType();
}

HttpConfiguration::~HttpConfiguration()
{

}

void HttpConfiguration::setRequestType(RequestType type)
{
    _requestType = type;
}

void HttpConfiguration::setRequestUrl(QUrl url)
{
    _requestUrl = url;
}

void HttpConfiguration::setContentType(RequestContentType type)
{
    _contentType = type;
}
