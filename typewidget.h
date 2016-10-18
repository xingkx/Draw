#ifndef TYPEWIDGET_H
#define TYPEWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <window.h>
#include <graphline.h>
#include "graphrect.h"
#include "graphimage.h"
enum Type
{
    None,
    Line,
    Rect,
    Ellipse,
    Image,
    Text
};

class TypeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TypeWidget(QWidget *parent = 0);
    void setType(Type type);
    void setWindow(Window* window);
    void save(const QString& fileName);
    void open(const QString& fileName);
    bool buer() const;
    void setLineEdit(QLineEdit *edit);
    QLineEdit* getLineEdit();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

public slots:
private:
    bool m_save;
    QPoint m_p1,m_p2;
    Type m_type;
    bool m_buer;
    Window *m_dow;    
    QList<GraphItem*> m_childItems;
    QLineEdit *m_le;
};
#include <QThread>
class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(QObject *parent = 0);
    Thread(const QString& fileName, TypeWidget* tw, QObject* parent = 0);
    void setFileName(const QString &fileName);
    void setTypeWidget(TypeWidget *tw);
protected:
    void run();
private:
    TypeWidget *m_tw;
    QString m_fileName;
};

#endif // TYPEWIDGET_H
