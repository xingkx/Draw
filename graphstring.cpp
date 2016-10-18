#include "graphstring.h"
#include <QDebug>
#include <QFont>
GraphString::GraphString()
{
    m_edit = new QTextEdit();

    connect(m_edit, SIGNAL(textChanged()), this, SLOT(setText()));
}

GraphString::~GraphString()
{
    qDebug()<<Q_FUNC_INFO;
}

void GraphString::paint(QPainter *painter)
{
    painter->drawRect(m_rect);
    painter->drawText(m_rect,m_edit->alignment(),m_string);
}

void GraphString::save(QTextStream &ts)
{

}

void GraphString::load(QTextStream &ts)
{

}

void GraphString::setPoint(const QPoint &point)
{
    m_point = point;
}

void GraphString::setRect(const QRect &rect)
{
    m_rect = rect;
}

void GraphString::setString(const QString &str)
{
    m_string = str;
}

void GraphString::setSize(const int &size)
{
    m_size = size;
}

QTextEdit *GraphString::textEdit()
{
    return m_edit;
}

void GraphString::setText()
{
    m_string = m_edit->toPlainText();
    emit changed();
}

