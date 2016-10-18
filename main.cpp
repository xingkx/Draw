#include<QDebug>
#include<QApplication>
#include<window.h>
#include <QProgressBar>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication tion(argc,argv);
    Window wod;
    wod.show();
    return tion.exec();
}
