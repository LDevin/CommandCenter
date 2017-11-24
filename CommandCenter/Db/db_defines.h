/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/22
*/

#ifndef  DBDEFINES_H
#define  DBDEFINES_H

/**
  * 数据库驱动
**/
#if    defined(QMYSQL)
#      define DB_DRIVER_TYPE    "QMYSQL"
#elif  defined(QDB2)
#      define DB_DRIVER_TYPE    "QDB2"
#elif  defined(QIBASE)
#      define DB_DRIVER_TYPE    "QIBASE"
#elif  defined(QOCI)
#      define DB_DRIVER_TYPE    "QOCI"
#elif  defined(QODBC)
#      define DB_DRIVER_TYPE    "QODBC"
#elif  defined(QPSQL)
#      define DB_DRIVER_TYPE    "QPSQL"
#elif  defined(QSQLITE)
#      define DB_DRIVER_TYPE    "QSQLITE"
#endif

/**
  * 设置默认的数据库
**/
#define DB_PORT                 3306
#define DB_HOST_NAME            "192.168.1.228"
#define DB_NAME                 "test_data"
#define DB_USER_NAME            "root"
#define DB_PASSWORD             "test@mysql"

/**
  * 数据库超时
**/

#define DB_QUERY_TIME_OUT        1000 * 15 //15s

/**
  * 数据库处理操作出现的错误
**/
#define DB_MANAGE_MSG "{\"code\":-200,\"msg\":\"operation is failed!\"}"

#endif // DBDEFINES_H
