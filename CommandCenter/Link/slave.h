/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef SLAVE_H
#define SLAVE_H
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

    bool            addResBuilding(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResBuildingList(const QString &token, int pageNum, QByteArray &ret);
    bool            updateResBuilding(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResBuildBasicDetailById(const QString &token, long id, QByteArray &ret);
    bool            getResBuildByName(const QString &token, const QString &name, QByteArray &ret);
    bool            addResEnforce(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResEnforceDetail(const QString &token, long id, QByteArray &ret);

    bool            getResEnforceDeviceView(const QString &token, long supervisorID, QByteArray &ret);

    bool            getResEnforceList(const QString& token, const QString& name,
                                      int type, int pageNum, QByteArray& ret);

    bool            addResEnforcePerson(const QString& token, long enforceId,
                                        const QString &jsonDto, QByteArray& ret);

    bool            getResEnforcePersonList(const QString& token, long enforceId,
                                            const QString &name, int pageNum, QByteArray& ret);

    bool            getResEnforcePersonDetail(const QString& token, long enforceid,
                                              long personid, QByteArray& ret);

    bool            updateResEnforcePerson(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            updateResEnforce(const QString& token, const QString &jsonDto, QByteArray& ret);

    bool            addResExtinguisher(const QString& token, const QString &jsonDto, QByteArray& ret);

    bool            getResExtinguisherDetail(const QString& token, long id, QByteArray& ret);

    bool            getResExtinguisherList(const QString& token, const QString& code, long relatedID,
                                           int type, const QString& startTime, const QString& endTime,
                                           int pageNum, QByteArray& ret);

    bool            updateResExtinguisher(const QString& token, const QString& jsonDto, QByteArray& ret);

    bool            addResFirePlug(const QString& token, const QString& jsonDto, QByteArray& ret);
    bool            getResFirePlugDetail(const QString& token, long id, QByteArray& ret);
    bool            getResFirePlugDeviceView(const QString& token, long chargerID, QByteArray& ret);
    bool            getResFirePlugDevMac(const QString& token, long id, QByteArray& ret);

    bool            getResFirePlugDoconern(const QString& token, long id, const QString &devMac, QByteArray& ret);
    bool            getResFirePlugList(const QString& token, const QString &code, int status, int isRelate, int type,
                                       const QString& devMac, int pageNum, const QString &longitude, const QString &latitude, int raidus, QByteArray& ret);

    bool            getResFirePlugConcernned(const QString& token, const QString &code, const QString &devMac, const int pageNum, QByteArray& ret );
    bool            getResFirePlugUnconcern(const QString& token, const QString &code, const int pageNum, QByteArray& ret );
    bool            updateResFirePlug(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResGetByKey(const QString &token, const QString &key, QByteArray &ret);
    bool            addResRecureCar(const QString &token, long recureId, const QString &jsonDto, QByteArray &ret);
    bool            updateResRecureCar(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            addResRescure(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResRescureCarDetail(const QString &token, long rescureId, long equipId, QByteArray &ret);
    bool            getResRescureCarList(const QString& token, int rescureId, int pageNum, QByteArray& ret);
    bool            getResRescureDetail(const QString &token, long id, QByteArray &ret);
    bool            getResRescureDeviceview(const QString &token, long supervisorId, QByteArray &ret);
    bool            addResRescurePerson(const QString &token, long rescureId, const QString &jsonDto, QByteArray &ret);
    bool            getResRescurePersonDetail(const QString &token, long rescureId, long personId, QByteArray &ret);
    bool            getResRescurePersonList(const QString &token, long rescureId, int pageNum, QByteArray &ret);
    bool            updateResRecurePerson(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            updateResRecure(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResRescureList(const QString &token, const QString &name, int type, int pageNum, QByteArray &ret);
    bool            addResWater(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResWaterDetail(const QString &token, long id, QByteArray &ret);
    bool            getResWaterDeviceView(const QString &token, long chargerID, QByteArray &ret);
    bool            getResWaterList(const QString &token, const QString &code, int waterType, const QString &longitude,
                                    const QString &latitude, int radus, int pageNum, QByteArray &ret);
    bool            updateResWater(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getResZoneByParent(const QString &token, int relativeID, QByteArray &ret);
    bool            getResFullZone(const QString &token, const QString &relativeID, QByteArray &ret);
    //![2]

    /*
     * @info-controller : 资讯相关接口
    */

    //![3]
    bool            getInfoDetailById(const QString &token, int userId, int articleId, QByteArray &ret);
    bool            getInfoExcellentRecommend(const QString &token, QByteArray &ret);
    bool            getInfoList(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool            getInfoListClassifyID1(const QString &token, const int classifyID1 , const QString title, QByteArray &ret);
    bool            getInfoListMoreByID(const QString &token,const int classifyID2,const int pageNum, const QString title,
                                        QByteArray &ret);
    bool            getInfoCommentList(const QString &token, const int articleId , const int pageNum,const int userID, QByteArray &ret);
    bool            updateInfoLikeTimes(const QString &token, const int articleId, const int userID, QByteArray &ret);
    bool            getInfochildLevel(const QString &token, const int relativeID, QByteArray &ret);
    bool            getInfoFirstLevel(const QString &token, QByteArray &ret);
    bool            getInfoNavigation(const QString &token, const int templateId,QByteArray &ret);
    bool            addInfoComments(const QString &token, const int articleId, const QString content, const int userID,
                                    QByteArray &ret);
    bool            delInfoComments(const QString &token, const int id,QByteArray &ret);
    bool            updateInfoReadTimes(const QString &token, const int articleId, const int userID, QByteArray &ret);
    //![3]

    /*
     * @device-controller : 设备相关接口
    */
    bool           getBuildDevList(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getBuildView(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getDevDetail(const QString &token, const long &devId, QByteArray &ret);
    bool           getDevView(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getDevType(const QString &token, const long &devId, QByteArray &ret);
    bool           getDirectDev(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getDirectEnt(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getEntDevList(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getFireLstActByID(const QString &token, const long &historyID, const long &userID, QByteArray &ret);
    bool           getFireSelEndTimeByID(const QString &token, const long &historyID, QByteArray &ret);
    bool           getLeaderView(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getMonitorList(const QString &token, const long &deviceID, QByteArray &ret);
    bool           getDevStateList(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getDevStatushisAdd(const QString &token, const QString &jsonDto, QByteArray &ret);
    bool           getStatushisList(const QString &token, const long &deviceID, const int pageNum, QByteArray &ret);
    bool           getSystemTypeList(const QString &token, QByteArray &ret);





    /*
     * @check-form-record-controller : 楼栋和单位消防检查相关接口
    */
    //![4]
    bool           getFireCheckItem(const QString &token, const QString jsonDto, QByteArray &ret);
    bool           getFireCheckForm(const QString &token,const int pageType, const QString areaName,const QString buildingAddress,
                                    const QString createTime, const QString evaluateLevel, const QString organizerName, QByteArray &ret);
    bool           getFireCheckFormList(const QString &token, const int pageType, const int pageNum, QByteArray &ret);
    bool           AddFireCheckForm(const QString &token, const int pageType, const QString appContent, const QString corperName,
                                       const QString corperSign, const QString corperPhone , const int id, QByteArray &ret);
    bool           searchFirecheck(const QString &token, const int pageType, const QString jsonDto, QByteArray &ret);
    //![4]

    /*
     * @check-controller : 检查表相关接口
    */

    bool getCheckFormID(const QString &token, const QString &jsonDto, QByteArray &ret);
    /*
     * @chat-controller : 聊天互动相关接口
    */
    bool         addChatMessage(const QString &token, const QString content, QByteArray &ret);
    bool         addChatMessageComment(const QString &token,const QString ids, const QString content, QByteArray &ret);

    /*
     * 楼栋和单位消防检查相关接口
     */

public slots:
    void            slaveFinishedWork();

Q_SIGNALS:
    void            slaveFetchLinkData(const QByteArray &data);

private:
    void            destroyLink(LinkInterface* link);
    bool            setLinkConfigurationData(LinkConfiguration *linkCfg,
                                             const QString &root,
                                             const QString &api, QByteArray &ret);

    /**************
     *所有的接口都会走这个函数，让奴隶去做
    **************/
    bool            slaveStartLink(LinkInterface *link,
                                   const QByteArray &headerData,
                                   const QByteArray &requestData, QByteArray &ret);

    void            setHttpApiOtherErrMsg(const QString &msg, int code, QByteArray &ret);
    bool            returnHttpOtherErrMsg(const QString &msg, int code, QByteArray &ret);
};
}

#endif // SLAVE_H
