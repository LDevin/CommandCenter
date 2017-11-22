/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/22
*/

#ifndef  DBDEFINES_H
#define  DBDEFINES_H
#include <QDebug>

/******
 *
 * LOG宏,可以定位到打印的哪个文件和哪一行
 *
******/
#undef LOG
#if defined(DB_LOG)
#   define LOG(...) {\
qDebug() \
<< __VA_ARGS__ \
<< "(File:" << __FILE__ << ", " \
<< "Line:" << __LINE__ << ")\n\t";\
}
#else
#   define LOG(...) ;
#endif


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
  * 数据库超时
**/

#define DB_QUERY_TIME_OUT        1000 * 15 //15s

#endif // DBDEFINES_H
