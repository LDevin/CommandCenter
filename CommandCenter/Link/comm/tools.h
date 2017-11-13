/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef TOOLS_H
#define TOOLS_H
#include <QObject>
#include "helper/jsonhelper.h"
#include "comm/config.h"
#include "linkdefines.h"


namespace Link {

class Tools : public QObject
{

public:
   static Tools* tools();

protected:
    Tools();
    virtual ~Tools();

private:
   static Tools* s_tools;

public:
    static bool openFile(QByteArray &data, QString fileName);

    static bool loadLinkUrl(QByteArray &content);
    static bool loadLinkUrl(QJsonObject &content);

    static bool loadToolsJson(QJsonObject &toolsData);

    static bool setLinkToken(const QString &token, QJsonObject &obj);
    static bool setLinkToken(const QString &token, QByteArray &json);

};
}
#endif // TOOLS_H
