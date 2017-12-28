/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/24
*/

#ifndef  UTILS_DEFINES_H
#define  UTILS_DEFINES_H
#include <QDebug>

/******
 *
 * LOG宏,可以定位到打印的哪个文件和哪一行
 *
******/
#   define LOG(...) {\
qDebug() \
<< ##__VA_ARGS__ \
<< "(File:" << __FILE__ << ", " \
<< "Line:" << __LINE__ << ")\n\t";\
}

#endif // UTILS_DEFINES_H
