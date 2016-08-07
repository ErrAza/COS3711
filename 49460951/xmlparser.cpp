#include "xmlparser.h"

XMLParser* XMLParser::m_Parser = 0;

XMLParser::XMLParser()
{

}

XMLParser::~XMLParser()
{

}

XMLParser* XMLParser::getInstance()
{
    if (m_Parser == nullptr)
    {
        m_Parser = new XMLParser();
    }

    return m_Parser;
}

void XMLParser::ParseFromXML()
{
    QFile file("students.xml");
    if (file.open(QIODevice::ReadOnly))
    {
       QDomDocument doc;
       doc.setContent(&file);
       file.close();

        QDomElement root = doc.documentElement();

        QDomElement studentEle = root.firstChild().toElement();

        while (!studentEle.isNull())
        {
            if (studentEle.tagName()=="student")
            {
                QString ID = studentEle.attribute("student-number", "12345678");

                QDomElement child = studentEle.firstChild().toElement();

                QString initials;
                QString lastname;
                QString title;
                bool introduced;
                int comments;
                float a1mark;
                float a2mark;
                int points;

                while (!child.isNull())
                {
                    if(child.tagName()=="initials")
                        initials = child.firstChild().toText().data();
                    if(child.tagName()=="last_name")
                        lastname = child.firstChild().toText().data();
                    if(child.tagName()=="title")
                        title = child.firstChild().toText().data();
                    if(child.tagName()=="introduced")
                        introduced = child.firstChild().toText().data().toInt();
                    if(child.tagName()=="number_of_comments")
                        comments = child.firstChild().toText().data().toInt();
                    if(child.tagName()=="assignment_1_mark")
                        a1mark = child.firstChild().toText().data().toFloat();
                    if(child.tagName()=="assignment_2_mark")
                        a2mark = child.firstChild().toText().data().toFloat();
                    if(child.tagName()=="points")
                        points = child.firstChild().toText().data().toInt();

                    child = child.nextSibling().toElement();

                }

                Student *student = new Student(ID, lastname, initials, title);

                StudentList::getInstance()->append(student);
            }

            studentEle = studentEle.nextSibling().toElement();
        }

    }
}

void XMLParser::ParseToXML()
{
        QFile file("students.xml");
        if (file.open(QIODevice::ReadWrite))
        {
            QXmlStreamWriter stream(&file);
            stream.setAutoFormatting(true);
            stream.writeStartDocument();
            stream.writeStartElement("students");

            for(int i = 0; i < StudentList::getInstance()->count(); i++)
            {
                stream.writeStartElement("student");
                stream.writeAttribute("student-number", StudentList::getInstance()->at(i)->GetStudentNumber());
                stream.writeTextElement("initials", StudentList::getInstance()->at(i)->GetInitials());
                stream.writeTextElement("last_name", StudentList::getInstance()->at(i)->GetLastName());
                stream.writeTextElement("title", StudentList::getInstance()->at(i)->GetTitle());
                stream.writeTextElement("introduced", QString::number(StudentList::getInstance()->at(i)->Introduced()));
                stream.writeTextElement("number_of_comments", QString::number(StudentList::getInstance()->at(i)->GetNumberOfComments()));
                stream.writeTextElement("assignment_1_mark", QString::number(StudentList::getInstance()->at(i)->GetA1Mark()));
                stream.writeTextElement("assignment_2_mark", QString::number(StudentList::getInstance()->at(i)->GetA2Mark()));
                stream.writeTextElement("points", QString::number(StudentList::getInstance()->at(i)->GetPoints()));

                stream.writeEndElement();
            }

            stream.writeEndElement();

            stream.writeEndDocument();
        }

}
