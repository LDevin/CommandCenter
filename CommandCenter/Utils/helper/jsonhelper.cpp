#include "jsonhelper.h"

bool JsonHelper::isObject(const QString &str)
{
    if (str.isEmpty()) return false;

    QByteArray data;
    data.append(str);
    return QJsonDocument::fromJson(data).isObject();
}

bool JsonHelper::isObject(const QByteArray &data)
{
    if (data.isEmpty()) return false;

    return QJsonDocument::fromJson(data).isObject();
}

bool JsonHelper::isArray(const QString &str)
{
    if (str.isEmpty()) return false;

    QByteArray data;
    data.append(str);
    return QJsonDocument::fromJson(data).isArray();
}

bool JsonHelper::isArray(const QByteArray &data)
{
    if (data.isEmpty()) return false;

    return QJsonDocument::fromJson(data).isArray();
}

bool JsonHelper::isValid(const QString &str)
{
    return isObject(str) || isArray(str);
}

bool JsonHelper::isValid(const QByteArray &data)
{
    return isObject(data) || isArray(data);
}

bool JsonHelper::toObject(const QString &src, QJsonObject &des)
{
    if (isObject(src)) {
        QByteArray data;
        data.append(src);
        des = QJsonDocument::fromJson(data).object();
        return true;
    }
    return false;
}

bool JsonHelper::toObject(const QByteArray &src, QJsonObject &des)
{
    if (isObject(src)) {
        des = QJsonDocument::fromJson(src).object();
        return true;
    }
    return false;
}


