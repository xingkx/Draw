#include "colorbutton.h"
#include <QColorDialog>
#include <QPainter>
ColorButton::ColorButton(QWidget *parent) :
    QPushButton(parent)
{
    m_color = Qt::blue;
    connect(this,SIGNAL(clicked()),this,SLOT(setColor()));
}

QColor ColorButton::color()
{
    return m_color;
}

void ColorButton::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    paint.setBrush(m_color);
    paint.drawRoundedRect(this->rect(), 7, 7);

}

void ColorButton::setColor()
{
    m_color = QColorDialog::getColor();
    update();
}
