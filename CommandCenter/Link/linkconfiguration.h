/*
 * @author DevinLai
 * @email  laidawang@zds-t.com
 * @date   2017/11/06
*/

#ifndef LINKCONFIGURATION_H
#define LINKCONFIGURATION_H
#include <QObject>


class LinkConfiguration : public QObject
{
    Q_OBJECT
    Q_ENUMS(LinkType)

public:
    LinkConfiguration() {}
    LinkConfiguration(const QString &name);
    LinkConfiguration(const LinkConfiguration &copy);
    ~LinkConfiguration();

    Q_PROPERTY(QString     name     READ name  WRITE setName  NOTIFY nameChanged)

    QString             name(void) const { return _name; }
    void                setName(const QString name);

    enum LinkType {
        TypeHttp,
        TypeTcp,
        TypeUdp,
        TypeSerial,
#ifdef QT_DEBUG
        TypeMock,
#endif
    };

    virtual LinkType    type() const = 0;
    virtual QString     timeOutMsg() const { return _timeOutMsg; }
    virtual void        setTimeOutMsg(QString msg) { _timeOutMsg = msg; }

signals:
    void                nameChanged(const QString& name);


private:
    QString             _name;

protected:
    QString             _timeOutMsg;
};

#endif // LINKCONFIGURATION_H
