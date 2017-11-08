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

bool JsonHelper::toObject(const QString &source, QJsonObject &des)
{
    if (isObject(source)) {
        QByteArray data;
        data.append(source);
        des = QJsonDocument::fromJson(data).object();
        return true;
    }
    return false;
}

bool JsonHelper::toObject(const QByteArray &source, QJsonObject &des)
{
    if (isObject(source)) {
        des = QJsonDocument::fromJson(source).object();
        return true;
    }
    return false;
}


