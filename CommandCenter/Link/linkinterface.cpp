#include "linkinterface.h"

LinkInterface::LinkInterface()
    : _waitTimeout(LINK_REQUEST_WAIT_TIME), _quit(false), _timeOut(false), _timerOutId(-1)
{

}

LinkInterface::~LinkInterface()
{

}

void LinkInterface::setWaitTimeOut(int waitTime)
{
    Q_ASSERT(waitTime > 0);
    _waitTimeout = waitTime;
}

void LinkInterface::setTimerOut()
{
    Q_ASSERT(waitTimeOut() > 0);
    _timerOutId = startTimer(waitTimeOut());
}

void LinkInterface::setQuit(bool flag)
{
    _quit = flag;
}

void LinkInterface::setTimeOut(bool flag)
{
    _timeOut = flag;
}

void LinkInterface::resetTimer()
{
    if ( timerOutId() > 0 ) {
        killTimer(timerOutId());
    }

    _timerOutId = startTimer(waitTimeOut());
}

