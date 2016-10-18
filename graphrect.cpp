#include "graphrect.h"
#include <QDebug>
GraphRect::GraphRect()
{
    m_color = Qt::red;
}

void GraphRect::paint(QPainter *painter)
{
    painter->save();
    painter->setPen(m_pen);
    painter->setBrush(m_color);
    painter->drawRect(m_rect);
    painter->restore();
}

void GraphRect::setRect(QRect rect)
{
    m_rect = rect;
}

void GraphRect::setPen(const QPen& pen)
{
    m_pen = pen;
}

void GraphRect::setColor(const QColor &color)
{
    m_color = color;
}

void GraphRect::save(QTextStream &ts)
{
    ts<<type()<<"\n";
    ts<<m_pen.width()<<"\n";
    ts<<m_color.name()<<"\n";
    ts<<m_rect.x()<<"\n";
    ts<<m_rect.y()<<"\n";
    ts<<m_rect.width()<<"\n";
    ts<<m_rect.height()<<"\n";
}

void GraphRect::load(QTextStream &ts)
{
    int pw;
    QString name;
    int x,y,w,h;
    ts>>pw;
    ts>>name;
    ts>>x;
    ts>>y;
    ts>>w;
    ts>>h;
    m_pen.setWidth(pw);
    m_color = name;
    m_rect = QRect(x,y,w,h);
}

GraphEllipse::GraphEllipse()
{

}

void GraphEllipse::paint(QPainter *painter)
{
    painter->save();
    painter->setPen(m_pen);
    painter->setBrush(m_color);
    painter->drawEllipse(m_rect);
    painter->restore();
}

