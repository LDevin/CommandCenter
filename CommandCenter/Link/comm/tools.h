/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef TOOLS_H
#define TOOLS_H
#include <QObject>
#include "jsonhelper.h"
#include "comm/config.h"


namespace Link {

#define LINK_URL_FILE ":/link/linkUrl.json"
#define LINK_TOOLS_FILE ":/tool/tools.json"


#define LINK_ROOT_URL_KEY "root"

#define LINK_API "api"
#define LINK_HREF "href"
#define LINK_REQ "req"
#define LINK_PARA "para"

#define LINK_ROOT_API_USER "user"
#define LINK_API_USERINFO  "userInfo"

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
};
}
#endif // TOOLS_H
