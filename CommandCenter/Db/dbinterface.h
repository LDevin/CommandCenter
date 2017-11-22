/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/22
*/

#ifndef  DBINTERFACE_H
#define  DBINTERFACE_H
#include <QThread>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>
#include <QTimerEvent>
#include "dbdefines.h"


class DbInterface : public QThread
{
    Q_OBJECT

public:
    DbInterface                 (const QString& sql = tr(""));
    ~DbInterface                ();

    int                         waitTimeOut() const { return _waitTimeout; }
    int                         timerOutId() const { return _timerOutId; }
    bool                        getQuit() const { return _quit;}
    bool                        timeOut() const {return _timeOut; }

    void                        setWaitTimeOut(int waitTime);
    void                        setTimerOut();
    void                        setQuit(bool flag);
    void                        setTimeOut(bool flag);

    void                        resetTimer();


    void                        setSql(const QString& sql) { _sql = sql; }
    QString                     sql() const { return _sql; }

protected:
    void                        run() Q_DECL_OVERRIDE;
    void                        timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;


protected:
    QSqlDatabase                _db;
    QSqlQuery                   _query;

    QString                     _sql;

    int                         _waitTimeout;
    int                         _timerOutId;
    bool                        _quit;
    bool                        _timeOut;

private:

};

#endif // DBINTERFACE_H
