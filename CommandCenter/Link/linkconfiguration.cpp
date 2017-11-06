#include "linkconfiguration.h"

LinkConfiguration::LinkConfiguration(const QString &name)
    :_name(name)
{

}

LinkConfiguration::LinkConfiguration(const LinkConfiguration &copy)
{
    _name = copy.name();
}

LinkConfiguration::~LinkConfiguration()
{

}

void LinkConfiguration::setName(const QString name)
{
    _name = name;
}
