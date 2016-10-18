#ifndef GRAPHLINE_H
#define GRAPHLINE_H
#include<QPainter>
#include<QTextStream>
#include <QObject>

enum GraphType
{
    gLine,
    gRect,
    gEllipse,
    gImage,
    gString
};

class GraphItem : public QObject
{
    Q_OBJECT

public:
    virtual void paint(QPainter* painter) = 0;
    virtual void save(QTextStream &ts) = 0;
    virtual void load(QTextStream &ts) = 0;
    virtual GraphType type() = 0;
};

class GraphLine : public GraphItem
{
public:
    GraphLine();
    virtual void paint(QPainter *painter);
    virtual void save(QTextStream &ts);
    virtual void load(QTextStream &ts);
    virtual GraphType type()
    {
        return gLine;
    }

    void setLine(QLine line);
    void setPen(const QPen& pen);


private:
    QPen m_pen;
    QLine m_line;
};



#endif // GRAPHLINE_H
