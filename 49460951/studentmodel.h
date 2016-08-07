#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H
#include <QAbstractTableModel>
#include <student.h>
#include <studentlist.h>
#include <QVariant>


class StudentModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    StudentModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

protected:
    int m_Columns;
    QStringList *headerList;
    QList<Student*> *m_Students;
};

#endif // STUDENTMODEL_H
