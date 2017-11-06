/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef JSONHELPER_H
#define JSONHELPER_H
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


class JsonHelper
{
public:
    static bool isObject(const QString &str);
    static bool isObject(const QByteArray &data);

    static bool isArray(const QString &str);
    static bool isArray(const QByteArray &data);

    static bool isValid(const QString &str);
    static bool isValid(const QByteArray &data);

    static void toObject(const QString &source, QJsonObject &des);
    static void toObject(const QByteArray &source, QJsonObject &des);

};
#endif // JSONHELPER_H
