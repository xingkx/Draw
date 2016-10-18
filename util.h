#ifndef UTIL_H
#define UTIL_H
#include <QImage>
#include <QByteArray>

class Util
{
public:
    Util();
    static QString stringByImage(const QImage& image);
    static QImage imageByString(const QString& text);
};

#endif // UTIL_H
