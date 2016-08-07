#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QDebug>


class Student : public QObject
{
public:
    Student(const QString sn, const QString lastname, const QString initials, const QString title);
    int CalculateTotalPoints();
    int CalculateAssignmentPoints(float mark);
    void UpdateRank();
    enum Rank
    {
        Roamer = 1,
        Rambler = 2,
        Rover = 3,
        Ranger = 4
    };
    void Output();
    const QString GetStudentNumber();
    const QString GetLastName();
    const QString GetInitials();
    const QString GetTitle();
    const int Introduced();
    const int GetNumberOfComments();
    const float GetA1Mark();
    const float GetA2Mark();
    const int GetPoints();
    Rank m_Rank;

    void SetNewTitle(QString title);
    void SetIntroduced(bool Introduced);
    void SetNumberOfComments(int number);
    void SetA1Mark(float mark);
    void SetA2Mark(float mark);

private:
    QString m_StudentNumber;
    QString m_LastName;
    QString m_Initials;
    QString m_Title;
    bool m_Introduced;
    int m_NumberOfComments;
    float m_A1Mark;
    float m_A2Mark;
    int m_Points;
};

#endif // STUDENT_H
