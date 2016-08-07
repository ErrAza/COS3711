#include "studentlist.h"

StudentList* StudentList::m_StudentList = 0;

StudentList::StudentList()
{

}

StudentList::~StudentList()
{

}

StudentList* StudentList::getInstance()
{
    if (m_StudentList == NULL)
    {
        m_StudentList = new StudentList();
    }

    return m_StudentList;
}

void StudentList::OutputList()
{
        qDebug() << getInstance()->count();
}

