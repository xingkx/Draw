#ifndef GRAPSTRING_H
#define GRAPSTRING_H
#include<graphline.h>
#include<QTextEdit>

class GraphString : public GraphItem
{
    Q_OBJECT

public:
    GraphString();
    ~GraphString();

    virtual void paint(QPainter *painter);
    virtual void save(QTextStream &ts);
    virtual void load(QTextStream &ts);
    virtual GraphType type()
    {
        return gString;
    }
    void setPoint(const QPoint &point);
    void setRect(const QRect &rect);
    void setString(const QString &str);
    void setSize(const int &size);
    QTextEdit* textEdit();
signals:
    void changed();

public slots:
    void setText();

private:
    int m_size;
    QPoint m_point;
    QRect m_rect;
    QString m_string;
    QTextEdit* m_edit;
};

#endif // GRAPSTRING_H
