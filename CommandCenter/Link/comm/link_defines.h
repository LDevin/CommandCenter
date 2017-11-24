/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef LINKDEFINES_H
#define LINKDEFINES_H

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
#define LINK_API_RES_FIREPLUG_DOCONERN "fireplug/doconern" //室外水压关联的消火栓
#define LINK_API_RES_FIREPLUG_LIST "fireplug/list" //消火栓列表
#define LINK_API_RES_FIREPLUG_CONCERNNED "fireplug/concernned" //查询室外水压已关联的消火栓列表
#define LINK_API_RES_FIREPLUG_UNCONCERN "fireplug/unconcern" //查询室外水压未关联的消火栓列表
#define LINK_API_RES_FIREPLUG_UPDATE "fireplug/update" //修改消防栓
#define LINK_API_RES_GETBYKEY "getByKey" //查询数据字典

#define LINK_API_RES_RECURE_CAR_ADD "recure/car/add" //新增消防车辆
#define LINK_API_RES_RECURE_CAR_UPDATE "recure/car/update" //修改消防车辆
#define LINK_API_RES_RESCURE_ADD "rescure/add" //新增救援队伍
#define LINK_API_RES_RESCURE_CAR_DETAIL "rescure/car/detail" //查询消防车辆详情
#define LINK_API_RES_RESCURE_CAR_LIST "rescure/car/list" //查询消防车辆列表
#define LINK_API_RES_RESCURE_DETAIL "rescure/detail" //查询救援队伍详情
#define LINK_API_RES_RESCURE_DEVICEVIEW "rescure/deviceview" //统计分析救援队伍
#define LINK_API_RES_RESCURE_PERSON_ADD "rescure/person/add" //新增救援人员
#define LINK_API_RES_RESCURE_PERSON_DETAIL "rescure/person/detail" //查询救援人员详情
#define LINK_API_RES_RESCURE_PERSON_LIST "rescure/person/list" //查询救援人员列表
#define LINK_API_RES_RESCURE_PERSON_UPDATE "rescure/person/update" //修改救援人员
#define LINK_API_RES_RESCURE_UPDATE "rescure/update" //修改救援队伍
#define LINK_API_RES_RESOURE_LIST "resoure/list" //救援队伍列表
#define LINK_API_RES_WATER_ADD "water/add" //新增消防水源
#define LINK_API_RES_WATER_DETAIL "water/detail" //获取消防水源详情
#define LINK_API_RES_WATER_DEVICEVIEW "water/deviceview" //统计分析消防水源
#define LINK_API_RES_WATER_LIST "water/list" //消防水源列表
#define LINK_API_RES_WATER_UPDATE "water/update" //修改消防水源信息
#define LINK_API_RES_ZONE_GETBYPARENT "zone/getByParent" //获取父地域
#define LINK_API_RES_ZONE_GETFULLZONE "zone/getFullZone" //根据父地域获取子地域

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
#define LINK_API_DEV_LEADERVIEW   "leaderview"
#define LINK_API_DEV_MONITOR_LIST    "monitor/list"
#define LINK_API_DEV_STATE_LIST     "state/list"
#define LINK_API_DEV_STATUSHIS_ADD  "statushis/add"
#define LINK_API_DEV_STATUSHIS_LIST     "statushis/list"
#define LINK_API_DEV_SYSTEMTYPE_LIST     "systemtype/list"


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

#define LINK_ROOT_API_CHECK "firecheck"
#define LINK_API_CHECK_ADDCHECKITEM "firecheck/addCheckDangerItem"
#define LINK_API_CHECK_FORMDETAIL "firecheck/detailForm"
#define LINK_API_CHECK_FORMADD "firecheck/addForm"
#define LINK_API_CHECK_FORM "firecheck/listForm"
#define LINK_API_CHECK_SEARCH "firecheck/searchForm"

#define LINK_ROOT_API_CHAT "chat"
#define LINK_API_CHAT_MESSAGE "chat/addmessage"
#define LINK_API_CHAT_COMMENT "chat/addmessagecomment"

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
