#include "graphimage.h"
#include "util.h"
void GraphImage::setImage(const QImage &img)
{
    m_image = img;
}

void GraphImage::setpoint(QPoint &point)
{
    m_point = point;
}

void GraphImage::paint(QPainter *painter)
{
    painter->drawImage(m_point,m_image);
}

void GraphImage::save(QTextStream &ts)
{
    ts<<type()<<"\n";
    ts<<m_point.x()<<"\n";
    ts<<m_point.y()<<"\n";
    ts<<Util::stringByImage(m_image)<<"\n";
}

void GraphImage::load(QTextStream &ts)
{
    int x, y;
    QString text;
    ts>>x;
    ts>>y;
    ts>>text;
    m_point = QPoint(x,y);
    m_image = Util::imageByString(text);
}
