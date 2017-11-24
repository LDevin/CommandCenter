/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/24
*/

#ifndef  UTILS_H
#define  UTILS_H

#include "utils_global.h"
#include "utils_defines.h"

class UTILSSHARED_EXPORT Utils
{

public:
    Utils();

public:
    static bool openFile(QByteArray &data, QString fileName);
};

#endif // UTILS_H
