#include "dbinterface.h"

DbInterface::DbInterface()
    : _waitTimeout(DB_QUERY_TIME_OUT),
      _quit(false), _timeOut(false), _timerOutId(-1)
{

}

DbInterface::~DbInterface()
{
    setQuit(true);
    wait();
    quit();
}

bool DbInterface::setDataBase(QSqlDatabase &db, const QString &driver, const QString &connection,
                              const QString &host, int p, const QString &dbName,
                              const QString &user, const QString &ps)
{
    db = QSqlDatabase::addDatabase(driver, connection);

    setHostName(db, host);
    setPort(db, p);
    setDatabaseName(db, dbName);
    setUserName(db, user);
    setPassword(db, ps);

    return db.isValid();
}

void DbInterface::removeDataBase()
{
    QString name;
    {
        name = QSqlDatabase::database().connectionName();
    }
    QSqlDatabase::removeDatabase(name);
}

/***
 * timerEvent 好像有问题，暂时没什么用
***/
void DbInterface::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerOutId()) {
        setTimeOut(true);
        killTimer(timerOutId());

        if ( isRunning() ) {
            LOG("TIME OUT!")
        }
    }
}

bool DbInterface::queryTableData(const QString& querySql)
{
    Q_UNUSED(querySql)
    return true;
}

bool DbInterface::parseDbManageMsg(const int &code,
                                   const QString &content,
                                   QString &msg)
{
    if (QJsonDocument::fromJson(QByteArray(DB_MANAGE_MSG)).isObject()) {
        QJsonObject obj = QJsonDocument::fromJson(QByteArray(DB_MANAGE_MSG)).object();
        obj.insert("code", code);
        obj.insert("msg", content);

        msg = QString::fromLocal8Bit(QJsonDocument(obj).toJson());
        setErrorMsg(msg);
    } else {
        return false;
    }

    return ( code == static_cast<int>(QSqlError::NoError));
}

void DbInterface::setWaitTimeOut(int waitTime)
{
    Q_ASSERT(waitTime > 0);
    _waitTimeout = waitTime;
}

void DbInterface::setTimerOut()
{
    Q_ASSERT(waitTimeOut() > 0);
    _timerOutId = startTimer(waitTimeOut());
}

void DbInterface::setQuit(bool flag)
{
    _quit = flag;
}

void DbInterface::setTimeOut(bool flag)
{
    _timeOut = flag;
}

void DbInterface::resetTimer()
{
    if ( timerOutId() > 0 ) {
        killTimer(timerOutId());
    }

    _timerOutId = startTimer(waitTimeOut());
}
