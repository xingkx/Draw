#ifndef GRAPHRECT_H
#define GRAPHRECT_H
#include "graphline.h"

class GraphRect : public GraphItem
{
public:
    GraphRect();
    virtual void paint(QPainter *painter);
    GraphType type()
    {
        return gRect;
    }
    void setRect(QRect rect);
    void setPen(const QPen &pen);
    void setColor(const QColor &color);

    //save
    void save(QTextStream &ts);
    void load(QTextStream &ts);
protected:
    QRect m_rect;
    QPen m_pen;
    QColor m_color;
};


class GraphEllipse : public GraphRect
{
public:
    GraphEllipse();
    void paint(QPainter *painter);
    GraphType type()
    {
        return gEllipse;
    }
};

#endif // GRAPHRECT_H
