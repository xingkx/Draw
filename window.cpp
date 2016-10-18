#include "window.h"
#include "QMenu"
#include "QMenuBar"
#include "QToolBar"
#include "typewidget.h"
#include "colorbutton.h"
#include "QDebug"
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QLineEdit>
Window::Window(QMainWindow *parent):
    QMainWindow(parent)
{
    resize(800,600);
    m_menubar = menuBar();

    //fileMenu
    m_fileMenu=new QMenu();
    m_fileMenu->setTitle("File");
    m_actNew=new QAction(0);
    m_actNew->setText("New");
    QIcon Inew(":/Icon/FileNew.png");
//    m_actNew->setToolTip("chuang jian wenjian");
    m_actNew->setIcon(Inew);
    m_fileMenu->addAction(m_actNew);
    m_menubar->addMenu(m_fileMenu);

    QAction act1("Test",0);
    m_fileMenu->addAction(&act1); // QList<QAction*> actions;

    m_actOpen = new QAction(0);
    m_actOpen->setText("Open");
    QIcon Iopen(":/Icon/FileOpen.png");
    m_actOpen->setIcon(Iopen);
    m_fileMenu->addAction(m_actOpen);

    m_actSave=new QAction(0);
    m_actSave->setText("Save");
    QIcon Isave(":/Icon/FileSave.png");
    m_actSave->setIcon(Isave);
    m_fileMenu->addAction(m_actSave);

    m_actExit =new QAction(0);
    m_actExit->setText("Exit");
    m_fileMenu->addAction(m_actExit);

//editMenu
    m_editMenu=new QMenu();
    m_editMenu->setTitle("Edit");
    m_menubar->addMenu(m_editMenu);
    m_actMove=new QAction(QIcon(":/Icon/EditMove.png"), "Move",this);
    m_actMove->setCheckable(true);
    m_editMenu->addAction(m_actMove);

//typeMenu
    m_typeMenu = new QMenu();
    m_typeMenu->setTitle("Type");
    m_menubar->addMenu(m_typeMenu);

    m_actLine=new QAction(QIcon(":/Icon/DrawLine.png"),"Line",this);
    m_typeMenu->addAction(m_actLine);
    m_actLine->setCheckable(true);

    m_actRect=new QAction(QIcon(":/Icon/DrawRectangle.png"),"Rect",this);
    m_typeMenu->addAction(m_actRect);
    m_actRect->setCheckable(true);

    m_actEllipse=new QAction(QIcon(":/Icon/DrawEllipse.png"),"Ellipse",this);
    m_typeMenu->addAction(m_actEllipse);
    m_actEllipse->setCheckable(true);

    m_actImage=new QAction(QIcon(":Icon/DrawImage.png"),"Image",this);
    m_typeMenu->addAction(m_actImage);
    m_actImage->setCheckable(true);

    m_actString=new QAction(QIcon(":Icon/DrawString.png"),"Text",this);
    m_typeMenu->addAction(m_actString);
    m_actString->setCheckable(true);

//boolBar
    tool=new QToolBar();
    tool->addAction(m_actNew);
    tool->addAction(m_actOpen);
    tool->addAction(m_actSave);
    tool->addSeparator();
    tool->addAction(m_actMove);
    tool->addSeparator();
    tool->addAction(m_actLine);
    tool->addAction(m_actRect);
    tool->addAction(m_actEllipse);
    tool->addAction(m_actImage);
    tool->addAction(m_actString);
    tool->addSeparator();
//shurukuang
    m_spinBox = new QSpinBox(tool);
    tool->addWidget(m_spinBox);
    m_spinBox->setMaximumWidth(60);
    m_spinBox->setMinimumWidth(60);
    m_spinBox->setValue(1);
//btn
    m_button = new ColorButton();
    tool->addWidget(m_button); 
    tool->addSeparator();

    m_edit = new QLineEdit();
    tool->addWidget(m_edit);

    m_btn = new QPushButton();
    tool->addWidget(m_btn);
//addToolBar
    addToolBar(tool);

    m_tw = new TypeWidget();
    m_tw->setWindow(this);
    m_tw->setLineEdit(m_edit);
    this->setCentralWidget(m_tw);


    connect(m_menubar, SIGNAL(triggered(QAction*)),this, SLOT(slotmenuBar(QAction*)));
    connect(tool, SIGNAL(actionTriggered(QAction*)), this, SLOT(slotAction(QAction*)));
}

int Window::getWidth()
{
    return m_spinBox->value();
}

QColor Window::color()
{
    return m_button->color();
}

void Window::slotAction(QAction *action)
{
    qDebug()<<m_actEllipse->isChecked();
    if(action==m_actMove)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actEllipse->setChecked(false);
        m_actImage->setChecked(false);
        m_actString->setChecked(false);
        m_tw->setType(None);
        if(!m_actMove->isChecked())
        {
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actLine)
    {
        m_actMove->setChecked(false);
        m_actRect->setChecked(false);
        m_actEllipse->setChecked(false);
        m_actImage->setChecked(false);
        m_actString->setChecked(false);
        m_tw->setType(Line);
        if(!m_actLine->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actRect)
    {
        m_actLine->setChecked(false);
        m_actMove->setChecked(false);
        m_actEllipse->setChecked(false);
        m_actImage->setChecked(false);
        m_actString->setChecked(false);
        m_tw->setType(Rect);
        if(!m_actRect->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actEllipse)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actMove->setChecked(false);
        m_actImage->setChecked(false);
        m_actString->setChecked(false);
        m_tw->setType(Ellipse);
        if(!m_actEllipse->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actImage)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actMove->setChecked(false);
        m_actString->setChecked(false);
        m_tw->setType(Image);
        if(!m_actImage->isChecked())
        {
            m_tw->setType(None);
            m_actMove->setChecked(true);
        }
    }
    else if(action==m_actString)
    {
        m_actLine->setChecked(false);
        m_actRect->setChecked(false);
        m_actMove->setChecked(false);
        m_actImage->setChecked(false);
        m_tw->setType(Text);
//        if(!m_actString->isChecked())
//        {
//            m_tw->setType(None);
//            m_actMove->setChecked(true);
//        }
    }
    else if(action == m_actSave)
    {
        QString fileName = QFileDialog::getSaveFileName();
        m_tw->save(fileName);
        setWindowTitle(fileName);
    }
    else if(action == m_actOpen)
    {
        QString fileName = QFileDialog::getOpenFileName();
        Thread *read = new Thread(fileName, m_tw);
        read->setFileName(fileName);
        read->setTypeWidget(m_tw);
        read->start();
//        m_tw->open(fileName);
        setWindowTitle(fileName);
    }  
}
void Window::slotmenuBar(QAction *act)
{
    if(act == m_actExit)
    {
        if(m_tw->buer())
        {
            int val = QMessageBox::warning(this, "a", "b", QMessageBox::Ok|QMessageBox::Cancel|QMessageBox::Apply, QMessageBox::Cancel);
            if(val == QMessageBox::Cancel)
            {
                qDebug()<<"dslafjasdfj";
            }
            else
            {

            }
        }
        qApp->quit();
    }
}
