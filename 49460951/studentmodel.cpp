#include "studentmodel.h"
#include <QDebug>

StudentModel::StudentModel()
{
    m_Students = StudentList::getInstance();

    headerList = new QStringList();
    headerList->append("Student #");
    headerList->append("Name");
    headerList->append("Known as");
    headerList->append("Introduced");
    headerList->append("# of Comments");
    headerList->append("A1 Mark");
    headerList->append("A2 Mark");
    headerList->append("Current Rank");
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    return m_Students->size();
}

int StudentModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    Student *student = m_Students->at(index.row());

    student->CalculateTotalPoints();
    student->UpdateRank();


        switch(index.column())
        {
        case 0:
            return student->GetStudentNumber();
        break;
        case 1:
            return student->GetInitials() + " " + student->GetLastName();
            break;
        case 2:
            return student->GetTitle();
            break;
        case 3:
            return student->Introduced();
            break;
        case 4:
            return student->GetNumberOfComments();
            break;
        case 5:
            return student->GetA1Mark();
            break;
        case 6:
            return student->GetA2Mark();
            break;
        case 7:
            return student->m_Rank;
            break;
        }

    return QVariant();
}

Qt::ItemFlags StudentModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QVariant StudentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch(orientation) {
    case Qt::Horizontal:
        return headerList->at(section);
        break;
    case Qt::Vertical:
        break;
    }

    return QVariant();
}

bool StudentModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;
    int row = index.row();
    emit dataChanged(index, index);
    return true;
}

bool StudentModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, 1, 1);

    endInsertRows();
}

bool StudentModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, 1, 1);

    endRemoveRows();
}


























