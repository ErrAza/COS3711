#include "student.h"

Student::Student(QString sn, QString lastname, QString initials, QString title)
{
    m_StudentNumber = sn;
    m_LastName = lastname;
    m_Initials = initials;
    m_Title = title;
    m_Points = 0;
    m_Rank = Roamer;
    m_A1Mark = 0.0f;
    m_A2Mark = 0.0f;
    m_Introduced = false;
    m_NumberOfComments = 0;
}

void Student::SetA1Mark(float mark)
{
    m_A1Mark = mark;
}

void Student::SetA2Mark(float mark)
{
    m_A2Mark = mark;
}

void Student::SetIntroduced(bool Introduced)
{
    m_Introduced = Introduced;
}

void Student::SetNewTitle(QString title)
{
    m_Title = title;
}

void Student::SetNumberOfComments(int number)
{
    m_NumberOfComments = number;
}

const QString Student::GetLastName()
{
    return m_LastName;
}

const QString Student::GetInitials()
{
    return m_Initials.replace(" ", "");
}

const QString Student::GetTitle()
{
    return m_Title;
}

const int Student::Introduced()
{
    if (m_Introduced)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

const int Student::GetNumberOfComments()
{
    return m_NumberOfComments;
}

const float Student::GetA1Mark()
{
    return m_A1Mark;
}

const float Student::GetA2Mark()
{
    return m_A2Mark;
}

const int Student::GetPoints()
{
    m_Points = CalculateTotalPoints();

    return m_Points;
}

int Student::CalculateTotalPoints()
{
    int points = 100;

    if (m_Introduced)
    {
        points += 1000;
    }

    int pointsFromComments = m_NumberOfComments * 100;

    points += pointsFromComments;

    points += CalculateAssignmentPoints(m_A1Mark);
    points += CalculateAssignmentPoints(m_A2Mark);

    return points;
}

int Student::CalculateAssignmentPoints(float mark)
{
    int points = 0;

    if (mark < 50)
    {
        points = mark * 50;
    }
    else if (mark >= 50 && mark < 60)
    {
        points = mark * 100;
    }
    else if (mark >= 60 && mark < 80)
    {
        points = mark * 150;
    }
    else if (mark >= 80)
    {
        points = mark * 200;
    }

    return points;
}

void Student::UpdateRank()
{
    if (m_Points < 10000)
    {
        m_Rank = Roamer;
    }
    else if (m_Points < 20000 && m_Points >= 10000)
    {
        m_Rank = Rambler;
    }
    else if (m_Points < 30000 && m_Points >= 20000)
    {
        m_Rank = Rover;
    }
    else if (m_Points >= 30000)
    {
        m_Rank = Ranger;
    }
}

const QString Student::GetStudentNumber()
{
    return m_StudentNumber;
}

void Student::Output()
{
    qDebug() << m_LastName;
    qDebug() << m_StudentNumber;
    qDebug() << m_Initials;
    qDebug() << m_Title;
}
