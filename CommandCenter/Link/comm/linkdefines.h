#ifndef LINKDEFINES_H
#define LINKDEFINES_H
#include <QDebug>

#define LINK_URL_FILE ":/link/linkUrl.json"
#define LINK_TOOLS_FILE ":/tool/tools.json"


#define LINK_ROOT_URL_KEY "root"

#define LINK_API "api"
#define LINK_HREF "href"
#define LINK_REQ "req"
#define LINK_PARA "para"
#define LINK_SET_REQ_HEAD "reqHead"

#define LINK_ROOT_API_TOKEN "token"
#define LINK_API_OAUTH_TOKEN "token"
#define LINK_API_REFRESH_TOKEN "refreshToken"

#define LINK_ROOT_API_USER "user"

#define LINK_API_USERINFO  "userInfo"
#define LINK_API_DATALINE_LIST  "datalinelist"

#define LINK_ROOT_API_RES "resource"
#define LINK_API_RES_BUILD_BASIC_DETAIL "building/basic/detail"
#define LINK_API_RES_BUILD_SCH_BY_NAME "building/search"
#define LINK_API_RES_ENFORCE_ADD "enforce/add"
#define LINK_API_RES_ENFORCE_ADD "enforce/detail"


#define LINK_API_RES_ENFORCE_DEVICEVIEW "enforce/deviceview"



#define LINK_ROOT_API_DEV "device"
#define LINK_API_DEV_BUILDDEVLIST "buidingdeviceList"

#define LINK_ROOT_API_INFO "info"
#define LINK_API_INFO_DETAIL "article/detailByID"



/******
 *
 * LOG宏,可以定位到打印的哪个文件和哪一行
 *
******/
#if defined(LINK_LOG)
#   define LOG(...) {\
qDebug() \
<< __VA_ARGS__ \
<< "(File:" << __FILE__ << ", " \
<< "Line:" << __LINE__ << ")\n\t";\
}
#else
#   define LOG(...) ;
#endif



/******
 *
 * http api 调用的一些错误码
 *
******/

#define LINK_INVOKE_TIME_OUT_CODE   -200 //超时


#define LINK_INVOKE_OTHER_ERR       -300 //其他错误,细分的包括下面几种： -301~~-304，可能后面还会有
#define LINK_INVOKE_CONFIG_NULL     -301 //LinkConfiguration instance is NULL!
#define LINK_URL_IS_EMPTY           -302 //link url 为空字符串
#define LINK_HTTP_REQ_TYPE_ERR      -303 //HTTP 请求方式get 或者post 有问题
#define LINK_HTTP_API_NAME_ERR      -304 //http api的名字有误


#endif // LINKDEFINES_H
