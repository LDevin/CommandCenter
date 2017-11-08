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


namespace Link {

#define LINK_URL_FILE ":/link/linkUrl.json"
#define LINK_TOOLS_FILE ":/tool/tools.json"


#define LINK_ROOT_URL_KEY "root"

#define LINK_API "api"
#define LINK_HREF "href"
#define LINK_REQ "req"
#define LINK_PARA "para"
#define LINK_SET_REQ_HEAD "reqHead"

#define LINK_ROOT_API_USER "user"

#define LINK_API_USERINFO  "userInfo"
#define LINK_API_DATALINE_LIST  "datalinelist"

#define LINK_ROOT_API_RES "resource"
#define LINK_API_RES_BUILD_BASIC_DETAIL "building/basic/detail"

#define LINK_API_RES_ENFORCE_DEVICEVIEW  "enforce/deviceview"



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
