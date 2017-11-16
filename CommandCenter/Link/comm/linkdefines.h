#ifndef LINKDEFINES_H
#define LINKDEFINES_H
#include <QDebug>

#define LINK_URL_FILE ":/link/linkUrl.json"
#define LINK_TOOLS_FILE ":/tool/tools.json"

/*******link token*******/
#define LINK_TOKEN_KEY "Authorization"
/*******link token*******/

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
#define LINK_API_RES_ENFORCE_DETAIL "enforce/detail"


#define LINK_API_RES_ENFORCE_DEVICEVIEW "enforce/deviceview"
#define LINK_API_RES_ENFORCE_LIST "enforce/list"
#define LINK_API_RES_ENFORCE_PERSON_UPDATE "enforce/update"

#define LINK_API_RES_ENFORCE_PERSON_ADD "enforce/person/add"
#define LINK_API_RES_ENFORCE_PERSON_LIST "enforce/person/list"
#define LINK_API_RES_ENFORCE_PERSON_DETAIL "enforce/person/detail"


#define LINK_API_RES_EXTINGUISHER_ADD "extinguisher/add" //新增灭火器
#define LINK_API_RES_EXTINGUISHER_DETAIL "extinguisher/detail" //灭火器详情
#define LINK_API_RES_EXTINGUISHER_LIST "extinguisher/list" //灭火器列表
#define LINK_API_RES_EXTINGUISHER_UPDATE "extinguisher/update" //修改灭火器

#define LINK_API_RES_FIREPLUG_ADD "fireplug/add" //新增消火栓
#define LINK_API_RES_FIREPLUG_DETAIL "fireplug/detail" //消火栓详情
#define LINK_API_RES_FIREPLUG_DEVICEVIEW "fireplug/deviceview" //统计分析消火栓
#define LINK_API_RES_FIREPLUG_DEVMAC "fireplug/devmac" //获取供水压力值

#define LINK_ROOT_API_DEV "device"
#define LINK_API_DEV_BUILDDEVLIST "buidingdeviceList"
#define LINK_API_DEV_BUILDVIEW "buildingview"
#define LINK_API_DEV_DETAIL "detail"
#define LINK_API_DEV_DEVICEVIEW "deviceview"
#define LINK_API_DEV_DEVTYPE  "devtype"
#define LINK_API_DEV_DIRECTDEV  "directlydevice"
#define LINK_API_DEV_DIRECTENT   "directlyenterprise"
#define LINK_API_DEV_ENTDEVLIST  "enterprisedeviceList"
#define LINK_API_DEV_FIREWORKFLOW_LISTACTIVITYID  "fireWorkflow/listActivityByID"
#define LINK_API_DEV_FIREWORKFLOW_SELENDTIMEBUSID   "fireWorkflow/selectEndTimeByBusinessId"


#define LINK_ROOT_API_INFO "info"
#define LINK_API_INFO_DETAIL "article/detailByID"
#define LINK_API_INFO_EXCELLENTRECOMMEND  "article/excellentRecommend"
#define LINK_API_INFO_LIST  "article/list"
#define LINK_API_INFO_LIST_CLASSIFYID1  "article/listByClassifyID1"
#define LINK_API_INFO_LIST_MOREBYID  "article/moreByID"
#define LINK_API_INFO_LIST_UPDATELIKETIMES  "article/updateLikeTimes"
#define LINK_API_INFO_LIST_COMMENTS  "comments/list"
#define LINK_API_INFO_LIST_CHILDLEVEL  "conf/childLevelByPar"
#define LINK_API_INFO_LIST_FIRSTLEVEL  "conf/firstLevel"
#define LINK_API_INFO_LIST_NAVIGATION  "conf/list"
#define LINK_API_INFO_COMMENTS_ADD  "comments/add"
#define LINK_API_INFO_COMMENTS_DEL  "comments/del"
#define LINK_API_INFO_LIST_UPDATEREADTIMES  "article/updateReadTimes"

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

#define LINK_RS_INPUT_NULL          -3002 //输入参数为NULL


#endif // LINKDEFINES_H
