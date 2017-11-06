#include "config.h"


namespace Link {

Config* Config::s_config = NULL;

Config* Config::config()
{
   if ( NULL == s_config ) {
       s_config = new Config();
   }

   return s_config;
}

Config::Config()
{

}

Config::~Config()
{

}

void Config::setRootUrl(QString &url)
{
    _rootUrl = url;
}

void Config::setRootKeys(QStringList rootKeys)
{
    _rootKeys = rootKeys;
}

void Config::setApiNames(QStringList apiNames)
{
    _allApiNames = apiNames;
}

void Config::appendRootKey(QString key)
{
    _rootKeys.append(key);
}

void Config::appendApiName(QString name)
{
    _allApiNames.append(name);
}

void Config::setDataBagMap(QString rootKey, QMap<QString, LinkDataBag> bagMap)
{
    _dataBgMap.remove(rootKey);
    _dataBgMap[rootKey] = bagMap;
}

QMap<QString, QMap<QString, LinkDataBag>> Config::dataBagMap() const
{
    return _dataBgMap;
}

QMap<QString, LinkDataBag> Config::linkBagMap(QString &rootKey) const
{
    return _dataBgMap.value(rootKey);
}

LinkDataBag Config::linkBag(QString &rootKey, QString &api) const
{
    QMap<QString, LinkDataBag> bagBuf = _dataBgMap.value(rootKey);
    return bagBuf.value(api);
}

void Config::setHttpOverTimeErrMsg(QString msg)
{
    _httpOverTimeErrMsg = msg;
}

QString Config::httpOverTimeErrMsg() const
{
    return _httpOverTimeErrMsg;
}
}
