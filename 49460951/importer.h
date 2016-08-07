#ifndef IMPORTER_H
#define IMPORTER_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <student.h>
#include <studentlist.h>
#include <QMessageBox>
#include <xmlparser.h>

class Importer
{
public:
    Importer(QString fileName);
    void Import();
private:
    QString m_FileName;
};

#endif // IMPORTER_H
