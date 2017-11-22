#include "dbinterface.h"

DbInterface::DbInterface(const QString& sql)
    : _sql(sql), _waitTimeout(DB_QUERY_TIME_OUT),
      _quit(false), _timeOut(false), _timerOutId(-1)
{

}

DbInterface::~DbInterface()
{
    setQuit(true);
    quit();
    wait();
}

void DbInterface::run()
{
    LOG("DFDFDF")
}

void DbInterface::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerOutId()) {
        setTimeOut(true);
        killTimer(timerOutId());
    }
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
