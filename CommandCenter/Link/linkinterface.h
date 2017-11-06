/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef LINKINTERFACE_H
#define LINKINTERFACE_H
#include <QObject>
#include <QThread>
#include <QJsonObject>


#define LINK_REQUEST_WAIT_TIME 10000

class LinkConfiguration;

class LinkInterface : public QThread
{
  Q_OBJECT

public:
    LinkInterface();
    virtual ~LinkInterface();

    virtual LinkConfiguration* getLinkConfiguration() = 0;
    virtual void               setLinkConfiguration(LinkConfiguration *cfg) = 0;

    virtual QString             getName() const = 0;

    virtual QByteArray          contentData() const = 0;
    virtual void                setContentData(QByteArray &content) = 0;

    /*
     * @@子类必须重写这个方法：startRequest
    */
    virtual void                startRequest(const QByteArray &requestData) = 0;

    int                         waitTimeOut() const { return _waitTimeout; }
    int                         timerOutId() const { return _timerOutId; }
    bool                        getQuit() const { return _quit;}
    bool                        timeOut() const {return _timeOut; }

    void                        setWaitTimeOut(int waitTime);
    void                        setTimerOut();
    void                        setQuit(bool flag);
    void                        setTimeOut(bool flag);

    void                        resetTimer();

protected:
    int                         _waitTimeout;
    int                         _timerOutId;
    bool                        _quit;
    bool                        _timeOut;

Q_SIGNALS:
    void                        readFinished(const QByteArray &data);
    void                        invokeWriteBytes(QByteArray);

public slots:
    virtual void                linkFinished() = 0;
    virtual void                linkTimeOutReply() = 0;

private slots:


};
#endif // LINKINTERFACE_H
