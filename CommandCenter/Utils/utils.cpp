#include <QFile>
#include "utils.h"


Utils::Utils()
{
}

bool Utils::openFile(QByteArray &data, QString fileName)
{
    if (fileName.isEmpty()) return false;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    data = file.readAll();
    file.close();

    return true;
}
