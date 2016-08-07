#include "importer.h"

Importer::Importer(QString fileName)
{
    m_FileName = fileName;
}

void Importer::Import()
{
    QFile inputFile(m_FileName);
    int newEntries = 0;
    if (inputFile.open(QIODevice::ReadOnly))
    {

        QTextStream in(&inputFile);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList pieces = line.split(", ");
            Student *newStudent = new Student(pieces[0], pieces[1], pieces[2], pieces[3]);

            bool duplicateFound = false;


            for (int i = 0; i < StudentList::getInstance()->count(); i++)
            {
                if (StudentList::getInstance()->at(i)->GetStudentNumber() == newStudent->GetStudentNumber())
                {
                    duplicateFound = true;
                }
            }

            if (!duplicateFound)
            {
                StudentList::getInstance()->append(newStudent);
                newEntries++;
            }
        }
        inputFile.close();
    }

    QMessageBox msgBox;
    msgBox.setText(QString::number(newEntries) + " new students added.");
    msgBox.exec();
}
