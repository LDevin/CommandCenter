#ifndef LINK_GLOBAL_H
#define LINK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LINK_LIBRARY)
#  define LINKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LINKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LINK_GLOBAL_H
