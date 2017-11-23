/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/23
 * @brief  handle the process for database
*/

#ifndef  DBUTILS_H
#define  DBUTILS_H
#include "dbinterface.h"


class DbUtils : public DbInterface
{
    Q_OBJECT

public:
                                DbUtils(const QString& sql = tr(""));
                                ~DbUtils();

    void                        startRun();

protected:
    void                        run() Q_DECL_OVERRIDE;

public:
    bool                        queryTableData(const QString& querySql = tr(""));


private:
    bool                        executeQuery();

};
#endif // DBUTILS_H
