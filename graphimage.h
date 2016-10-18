#ifndef GRAPHIMAGE_H
#define GRAPHIMAGE_H
#include "graphline.h"
class GraphImage : public GraphItem
{
public:
    GraphImage()
    {

    }
    GraphType type()
    {
        return gImage;
    }
    void setImage(const QImage& img);
    void setpoint(QPoint &point);
    void paint(QPainter* painter);
    virtual void save(QTextStream &ts);
    virtual void load(QTextStream &ts);
private:
    QImage m_image;
    QPoint m_point;
};

#endif // GRAPHIMAGE_H
