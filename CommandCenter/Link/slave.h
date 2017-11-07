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

    /*
     * @user-controller : 用户相关接口
    */

    //![0]
    bool            getUserInfo(const QString &authorization, QByteArray &ret);
    bool            getDatalinelist(const QString &token, QByteArray &ret);
    //![0]


    /*
     * @token-controller : 授权相关接口
    */


    /*
     * @resource-controller : 消防资源相关接口
    */

    //![2]
    bool            getResEnforceDeviceView(long supervisorID, QByteArray &ret);
    //![2]

    /*
     * @info-controller : 资讯相关接口
    */

    /*
     * @device-controller : 设备相关接口
    */

    /*
     * @check-form-record-controller : 楼栋和单位消防检查相关接口
    */


    /*
     * @check-controller : 检查表相关接口
    */

    /*
     * @chat-controller : 聊天互动相关接口
    */

public slots:
    void            slaveFinishedWork();

Q_SIGNALS:
    void            slaveFetchLinkData(const QByteArray &data);

private:
    void            destroyLink(LinkInterface* link);
};
}

#endif // SLAVE_H
