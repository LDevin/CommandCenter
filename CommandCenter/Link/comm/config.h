/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef CONFIG_H
#define CONFIG_H
#include <QObject>
#include <QMap>


namespace Link {

#define REQ_HEAD_SET_FLAG 1
#define REQ_HEAD_NOT_SET_FLAG 0

typedef struct {
    QString fullUrl;
    QString api; //接口名称
    int req; //get或者post方式
    QString para; //{"Authorization":""} 传参格式
    int headFlag; // 0： 不设置request的head，1：设置
} LinkDataBag;

class Config
{

public:
    static      Config* config();

    void        setRootKeys(QStringList rootKeys);
    void        setApiNames(QStringList apiNames);

    void        appendRootKey(QString key);
    void        appendApiName(QString name);

    void        setRootUrl(QString &url);
    QString     rootUrl() const { return _rootUrl; }

    QStringList rootKeys() const { return _rootKeys; }
    QStringList allApiNames() const { return _allApiNames; }

    void setDataBagMap(QString rootKey, QMap<QString, LinkDataBag> bagMap);

    QMap<QString, QMap<QString, LinkDataBag>> dataBagMap() const;
    QMap<QString, LinkDataBag> linkBagMap(QString &rootKey) const;

    LinkDataBag linkBag(QString &rootKey, QString &api) const;

    QString httpOverTimeErrMsg() const;
    void    setHttpOverTimeErrMsg(QString msg);

private:

protected:
    Config();
    virtual ~Config();

private:
    static Config*                            s_config;

    //[0] http 接口相关的
    QString                                   _rootUrl;
    QStringList                               _rootKeys;
    QStringList                               _allApiNames;

    QMap<QString, QMap<QString, LinkDataBag>> _dataBgMap;
    //[0] http 接口相关的

    //[1]访问接口超市的msg,从tools.json文件获取
    QString                                   _httpOverTimeErrMsg;
    //[1]访问接口超市的msg,从tools.json文件获取


};

}

#endif // CONFIG_H
