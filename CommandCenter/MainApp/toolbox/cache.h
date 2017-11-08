/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/08
*/

#ifndef CACHE_H
#define CACHE_H
#include <QString>


class Cache
{

public:
    Cache*                  cache();
protected:
    Cache();
    virtual                 ~Cache();

private:
    Cache*                  _cache;


public:
    QString accessToken() const { return _access_token; }
    QString refreshToken() const { return _refresh_token; }

    void setAccessToken(QString &token) { _access_token = token; }
    void setRefreshToken(QString &token) { _refresh_token = token; }

private:
    QString                 _access_token;
    QString                 _refresh_token;
};
#endif // CACHE_H
