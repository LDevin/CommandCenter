#include "tools.h"
#include <QFile>
#include <QDebug>


namespace Link {

Tools* Tools::s_tools = NULL;

Tools* Tools::tools()
{
    if ( NULL == s_tools ) {
        s_tools = new Tools();
    }

    return s_tools;
}

Tools::Tools()
{
    Config::config();

    QByteArray data;

    if (openFile(data, LINK_URL_FILE)) {
        QJsonObject content;

        if (JsonHelper::toObject(data, content)) {
            loadLinkUrl(content);
        } else {
            qDebug() << "load LinkUrl.json failed, file is not json!";
        }

    }

    if (openFile(data, LINK_TOOLS_FILE)) {
        QJsonObject content;
        if (JsonHelper::toObject(data, content)) {
            loadToolsJson(content);
        } else {
            qDebug() << "load tools.json failed, file is not json!";
        }
    }

}

Tools::~Tools()
{

}

bool Tools::openFile(QByteArray &data, QString fileName)
{
    if (fileName.isEmpty()) return false;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    data = file.readAll();
    file.close();

    return true;
}

bool Tools::loadLinkUrl(QByteArray &content)
{
    if (!JsonHelper::isObject(content)) return false;

    return true;
}

bool Tools::loadLinkUrl(QJsonObject &content)
{
    if (content.isEmpty()) return false;

    QStringList rootKeys = content.keys();
    qDebug()<<rootKeys;

    if ( rootKeys.length() < 1 ) {
        return false;
    }

    Config::config()->setRootUrl(content[LINK_ROOT_URL_KEY].toString());
    Config::config()->setRootKeys(rootKeys);

    Config::config()->dataBagMap().clear();

    foreach (QString key, rootKeys) {

        if (key == LINK_ROOT_URL_KEY) {

        } else {

            QJsonValue apiJsonValue = content[key];
            if (!apiJsonValue.isArray()) {
                return false;
            }

            QJsonArray apiJsonArr = apiJsonValue.toArray();

            QMap<QString, LinkDataBag> linkDataBgMp;

            foreach (QJsonValue apiVal, apiJsonArr) {

                if (!apiVal.isObject()) return false;

                QJsonObject apiObj = apiVal.toObject();
                LinkDataBag linkDataBg;

                //[1]
                linkDataBg.fullUrl = Config::config()->rootUrl() + apiObj[LINK_HREF].toString();
                linkDataBg.api     = apiObj[LINK_API].toString();
                linkDataBg.req     = apiObj[LINK_REQ].toInt();

                QByteArray p = QJsonDocument::fromVariant(apiObj[LINK_PARA].toVariant()).toJson();
                linkDataBg.para    = QString(p);

                linkDataBgMp[linkDataBg.api] = linkDataBg;
                //[1]

                Config::config()->appendApiName(linkDataBg.api);

            }

            Config::config()->setDataBagMap(key, linkDataBgMp);

            qDebug()<<Config::config()->dataBagMap().value("user").value("userInfo").fullUrl;
        }
    }

    qDebug()<<"link url root keys count is: "<<Config::config()->dataBagMap().size();

    return true;
}

bool Tools::loadToolsJson(QJsonObject &toolsData)
{
    if (toolsData.isEmpty()) return false;

    QStringList toolsKeys = toolsData.keys();
    qDebug()<<toolsKeys;

    if ( toolsKeys.length() < 1 ) {
        return false;
    }

    QJsonValue httpOverTimeMsgVal = toolsData["httpOverTimeMsg"];

    if (!httpOverTimeMsgVal.isObject()) return false;

    QJsonDocument doc(httpOverTimeMsgVal.toObject());
    QByteArray httpMsg = doc.toJson();
    Config::config()->setHttpOverTimeErrMsg(QString::fromLatin1(httpMsg));

    return true;
}

}
