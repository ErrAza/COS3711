#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <student.h>
#include <QList>

class StudentList : public QList<Student*>
{
private:
    StudentList();
    ~StudentList();
    static StudentList* m_StudentList;
public:
    static StudentList* getInstance();
    static void OutputList();
};

#endif // STUDENTLIST_H
