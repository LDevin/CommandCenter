#include "dbutils.h"

DbUtils::DbUtils(const QString& sql)
{
    setSql(sql);
}

DbUtils::~DbUtils()
{

}

void DbUtils::run()
{
    LOG("start run db thread");

    executeQuery();

    LOG("db thread exit");
}

void DbUtils::startRun()
{
    resetTimer();
    start();
}

bool DbUtils::executeQuery()
{
    LOG("SQL: " + sql())
            LOG(QThread::currentThreadId())
            if ( sql().isEmpty() ) {
        setQuit(true);
        return parseDbManageMsg(QSqlError::UnknownError + 1, tr("sql is empty!"));
    }

    QString connection = tr("zdst_db_command_%1").arg((quintptr)(QThread::currentThreadId()));

    QSqlDatabase _db;
    bool isVaild = false;
    isVaild = setDataBase(_db, DB_DRIVER_TYPE, connection, DB_HOST_NAME, DB_PORT,
                          DB_NAME, DB_USER_NAME, DB_PASSWORD);

    LOG(isVaild);

    //[0]
    if (!_db.isOpen()) {
        if (!_db.open()) {
            setQuit(true);
            LOG(_db.lastError().text())
                    return parseDbManageMsg(_db.lastError().type(), _db.lastError().text());
        }
    }
    //[0]

    QSqlQuery *query = new QSqlQuery(_db);

    if (!query->exec(sql())) {
        LOG(query->lastError().text());

        _db.close();
        setQuit(true);
        removeDataBase();
        return parseDbManageMsg(query->lastError().type(), query->lastError().text());
    }

    QJsonArray jsonArray;

    do {

        while (query->next()) {

            QSqlRecord rec = query->record();
            QJsonObject obj;

            for (int i = 0; i < rec.count(); ++i) {
                obj.insert(rec.fieldName(i), QJsonValue::fromVariant(rec.value(rec.fieldName(i))));
            }

            jsonArray.append(obj);
        }

    } while(query->nextResult());

    query->finish();
    delete query;
    query = NULL;

    _db.close();

    removeDataBase();

    setQueryData(jsonArray);
    setQuit(true);

    return parseDbManageMsg(QSqlError::NoError, tr("execute sql query success!"));
}

bool DbUtils::queryTableData(const QString& querySql)
{
    setSql(querySql);
    startRun();
    return true;
}
