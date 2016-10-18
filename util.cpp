#include "util.h"
#include <QBuffer>

Util::Util()
{
}

QString Util::stringByImage(const QImage &image)
{
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    ba = ba.toBase64();
    QString text = QString(ba.constData());
    return text;
}

QImage Util::imageByString(const QString &text)
{
    QByteArray ba(text.toStdString().c_str());
    ba = ba.fromBase64(ba);
    QImage image;
    image.loadFromData(ba, "PNG");
    return image;
}
