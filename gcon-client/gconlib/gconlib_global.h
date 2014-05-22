#ifndef GCONLIB_GLOBAL_H
#define GCONLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GCONLIB_LIBRARY)
#  define GCONLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GCONLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GCONLIB_GLOBAL_H
