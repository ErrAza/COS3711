#ifndef XMLPARSER_H
#define XMLPARSER_H
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <student.h>
#include <studentlist.h>
#include <QtXml/QDomDocument>


class XMLParser
{
private:
    XMLParser();
    ~XMLParser();
    static XMLParser* m_Parser;
public:
    static XMLParser* getInstance();
    static void ParseToXML();
    static void ParseFromXML();
};

#endif // XMLPARSER_H
