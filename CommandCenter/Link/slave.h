﻿#ifndef SLAVE_H
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
#include "helper/jsonhelper.h"
#include "comm/tools.h"


#define RETURN_OK true
#define RETURN_FALSE false

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
    bool            getUserInfo(const QString &token, QByteArray &ret);
    bool            getDatalinelist(const QString &token, QByteArray &ret);
    //![0]


    /*
     * @token-controller : 授权相关接口
    */

    //![1]
    bool            getOauthToken(const QString &user, const QString &ps,
                                  const QString &clientId, QByteArray &ret);
    //![1]

    /*
     * @resource-controller : 消防资源相关接口
    */

    //![2]
    bool            getResBuildBasicDetailById(const QString &token, long id, QByteArray &ret);
    bool            getResBuildByName(const QString &token, const QString &name, QByteArray &ret);
    bool            addResEnforce(const QString &token, const QString &jsonDto, QByteArray &ret);

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
    bool getCheckFormID(const QString &token, const QString &jsonDto, QByteArray &ret);
    /*
     * @chat-controller : 聊天互动相关接口
    */

public slots:
    void            slaveFinishedWork();

Q_SIGNALS:
    void            slaveFetchLinkData(const QByteArray &data);

private:
    void            destroyLink(LinkInterface* link);
    void            setLinkConfigurationData(LinkConfiguration *linkCfg,
                                             const QString &root,
                                             const QString &api);

    /**************
     *所有的接口都会走这个函数，让奴隶去做
    **************/
    bool            slaveStartLink(LinkInterface *link,
                                   const QByteArray &headerData,
                                   const QByteArray &requestData, QByteArray &ret);
};
}

#endif // SLAVE_H
