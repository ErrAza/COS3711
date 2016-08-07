#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    XMLParser::getInstance()->ParseFromXML();

    int r = a.exec();

    XMLParser::getInstance()->ParseToXML();

    return r;
}
