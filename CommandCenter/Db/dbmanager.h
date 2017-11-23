/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/22
*/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "db_global.h"
#include <QObject>
#include <QEventLoop>
#include "dbutils.h"


#define RETURN_OK       true
#define RETURN_FALSE    false

class DBSHARED_EXPORT DbManager : public QObject
{
    Q_OBJECT

public:
   static DbManager*            manager();

   bool                         executeQuery(const QString& sql,
                                             QJsonArray& data = QJsonArray(),
                                             QString& error = QString());

protected:
                                DbManager();
                                ~DbManager();

private:
    static DbManager*           _manager;

    void                        destroyDbUtils(DbUtils* utils);
};


#endif // DBMANAGER_H
