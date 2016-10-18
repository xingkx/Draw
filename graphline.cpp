#include "graphline.h"

#include <QDebug>


GraphLine::GraphLine()
{

}

void GraphLine::paint(QPainter *painter)
{
    qDebug()<<Q_FUNC_INFO;
    painter->setPen(m_pen);
    painter->drawLine(m_line);
}

void GraphLine::setLine(QLine line)
{
    m_line = line;
}

void GraphLine::setPen(const QPen &pen)
{
    m_pen = pen;
}

void GraphLine::save(QTextStream &ts)
{
    ts<<type()<<"\n";
    ts<<m_pen.width()<<"\n";
    ts<<m_pen.color().name()<<"\n";
    ts<<m_line.p1().x()<<"\n";
    ts<<m_line.p1().y()<<"\n";
    ts<<m_line.p2().x()<<"\n";
    ts<<m_line.p2().y()<<"\n";
}
#include <QDebug>
void GraphLine::load(QTextStream &ts)
{
    qDebug()<<Q_FUNC_INFO;
    int pw;
    QString cn;
    int x1,y1,x2,y2;
    ts>>pw;
    ts>>cn;
    ts>>x1;
    ts>>y1;
    ts>>x2;
    ts>>y2;

    m_pen.setWidth(pw);
    m_pen.setColor(cn);
    m_line.setLine(x1,y1,x2,y2);
}


