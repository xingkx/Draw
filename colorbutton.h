#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = 0);
    QColor color();
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void setColor();
private:
    QColor m_color;
};

#endif // COLORBUTTON_H
