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
#include "db_defines.h"
#include "utils_defines.h"


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

    void                        setDatabaseName(QSqlDatabase& db, const QString& name) {db.setDatabaseName(name);}
    void                        setUserName(QSqlDatabase& db, const QString& name) {db.setUserName(name);}
    void                        setPassword(QSqlDatabase& db, const QString& password) {db.setPassword(password);}
    void                        setHostName(QSqlDatabase& db, const QString& host) {db.setHostName(host);}
    void                        setPort(QSqlDatabase& db, int p) {db.setPort(p);}

    bool                        setDataBase(QSqlDatabase &db, const QString& driver, const QString& connection,
                                            const QString& host, int p, const QString& dbName,
                                            const QString& user, const QString& ps);

    void                        removeDataBase();

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
