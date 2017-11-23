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
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "dbdefines.h"


class DbInterface : public QThread
{
    Q_OBJECT
public:
    DbInterface();
    ~DbInterface();

    int                         waitTimeOut() const { return _waitTimeout; }
    int                         timerOutId() const { return _timerOutId; }
    bool                        getQuit() const { return _quit;}
    bool                        timeOut() const {return _timeOut; }

    void                        setWaitTimeOut(int waitTime);
    void                        setTimerOut();
    void                        setQuit(bool flag);
    void                        setTimeOut(bool flag);

    void                        resetTimer();

    void                        setDatabaseName(const QString& name) {_db.setDatabaseName(name);}
    void                        setUserName(const QString& name) {_db.setUserName(name);}
    void                        setPassword(const QString& password) {_db.setPassword(password);}
    void                        setHostName(const QString& host) {_db.setHostName(host);}
    void                        setPort(int p) {_db.setPort(p);}

    void                        initDb();

    void                        setSql(const QString& sql) { _sql = sql; }
    QString                     sql() const { return _sql; }

    void                        setErrorMsg(const QString& msg) {_errorMsg = msg;}
    QString                     errorMsg() const { return _errorMsg; }

    void                        setQueryData(const QJsonArray& data) {_queryData = data;}
    QJsonArray                  queryData() const { return _queryData; }

    bool                        queryTableData(const QString& querySql = tr(""));

protected:
    void                        timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;


    virtual bool                parseDbManageMsg(const int& code,
                                                 const QString& content,
                                                 QString& msg = tr(""));

protected:
    QSqlDatabase                _db;


    QString                     _sql;
    QString                     _errorMsg;
    QJsonArray                  _queryData;

    int                         _waitTimeout;
    int                         _timerOutId;
    bool                        _quit;
    bool                        _timeOut;

Q_SIGNALS:
    void                        queryDbFinished(const QString& msg,
                                                const QJsonArray& data);

    void                        timeOutSignal();
public:

};

#endif // DBINTERFACE_H
