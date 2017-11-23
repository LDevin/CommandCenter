#include "dbinterface.h"

DbInterface::DbInterface()
    : _waitTimeout(DB_QUERY_TIME_OUT),
      _quit(false), _timeOut(false), _timerOutId(-1)
{
    _db = QSqlDatabase::addDatabase(DB_DRIVER_TYPE);
    initDb();
}

DbInterface::~DbInterface()
{
    setQuit(true);
    wait();
    quit();
}

void DbInterface::initDb()
{
    _db.setHostName(DB_HOST_NAME);
    _db.setPort(DB_PORT);
    _db.setDatabaseName(DB_NAME);
    _db.setUserName(DB_USER_NAME);
    _db.setPassword(DB_PASSWORD);
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
