#ifndef SLAVE_H
#define SLAVE_H

/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#include <QObject>
#include <QMutex>
#include "link_global.h"
#include "httplink.h"
#include "httpconfiguration.h"
#include "comm/jsonhelper.h"
#include "comm/tools.h"


namespace Link {

class LINKSHARED_EXPORT Slave : public QObject
{
    Q_OBJECT

public:
    static Slave*   slave();

    QString         callTimeOutMsg() const;
    void            setCallTimeOutMsg(QString msg);
protected:
    Slave();
    virtual         ~Slave();

private:
    static Slave*   s_slave;
    QMutex          _mutex;

    QString         _callTimeOutMsg;
    /*
     * 获取http接口api的任务，让Slave这个实例去干
    */
public:
    void            getUserInfo(const QString &authorization);
    void            getDatalinelist(const QByteArray &para);

public slots:
    void            slaveFinishedWork();

Q_SIGNALS:
    void            slaveFetchLinkData(const QByteArray &data);
};
}

#endif // SLAVE_H
