#include "dbmanager.h"


DbManager* DbManager::_manager = Q_NULLPTR;

DbManager* DbManager::manager()
{
    if ( Q_NULLPTR != _manager ) {
        _manager = new DbManager();
    }
    return _manager;
}

DbManager::DbManager()
{
}

DbManager::~DbManager()
{

}

void DbManager::destroyDbUtils(DbUtils *utils)
{
    if ( utils ) {
        utils->terminate();
        utils->deleteLater();
    }

    utils = Q_NULLPTR;
    LOG((utils ? "destroy utils failed! " : "destroy utils success!"));
}

bool DbManager::executeQuery(const QString &sql, QJsonArray &data,  QString &error)
{
    DbUtils* dbUtils = new DbUtils();

    QEventLoop eventLoop;
    connect(dbUtils, &DbUtils::finished, &eventLoop, &QEventLoop::quit);
    connect(dbUtils, &DbUtils::timeOutSignal, &eventLoop, &QEventLoop::quit);

    dbUtils->queryTableData(sql);

    eventLoop.exec();
    LOG(dbUtils->queryData().size());

    data = dbUtils->queryData();
    error = dbUtils->errorMsg();

    LOG("error: " + error);
    if (dbUtils->isRunning()) {
        dbUtils->terminate();
    }
    destroyDbUtils(dbUtils);

    return RETURN_OK;
}



