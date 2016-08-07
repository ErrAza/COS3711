#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnImport_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Input File"), "~/");

    Importer *importer = new Importer(filename);
    importer->Import();

    UpdateViews();
}

void MainWindow::RefreshPoints()
{
    int numRows = StudentList::getInstance()->count();

    QStandardItemModel* model = new QStandardItemModel(numRows, 3);

    QStringList labelList;
    labelList.append("Student #");
    labelList.append("Points");
    labelList.append("Rank");

    model->setHorizontalHeaderLabels(labelList);

    for (int row = 0; row < numRows; ++row)
    {
            Student *student = StudentList::getInstance()->at(row);

            QString ID = student->GetStudentNumber();
            QStandardItem* item1 = new QStandardItem(ID);
            model->setItem(row, 0, item1);

            int Points = student->GetPoints();
            QStandardItem* item2 = new QStandardItem(QString::number(Points));
            model->setItem(row, 1, item2);

            student->UpdateRank();
            QStandardItem* item3 = new QStandardItem(student->m_Rank);
            model->setItem(row, 2, item3);
    }

  ui->subTable->setModel(model);
  ui->subTable->resizeColumnsToContents();
}

void MainWindow::RefreshModel()
{
       int numRows = StudentList::getInstance()->count();

       QStandardItemModel* model = new QStandardItemModel(numRows, 8);

       QStringList labelList;
       labelList.append("Student #");
       labelList.append("Name");
       labelList.append("Known as");
       labelList.append("Introduced");
       labelList.append("# of Comments");
       labelList.append("A1 Mark");
       labelList.append("A2 Mark");
       labelList.append("Current Rank");

       model->setHorizontalHeaderLabels(labelList);

       for (int row = 0; row < numRows; ++row)
       {
               Student *student = StudentList::getInstance()->at(row);

               QString ID = student->GetStudentNumber();
               QStandardItem* item1 = new QStandardItem(ID);
               model->setItem(row, 0, item1);

               QString Name = student->GetInitials() + " " + student->GetLastName();
               QStandardItem* item2 = new QStandardItem(Name);
               model->setItem(row, 1, item2);

               QString Title = student->GetTitle();
               QStandardItem* item3 = new QStandardItem(Title);
               model->setItem(row, 2, item3);

               QString Introduced;
               if (student->Introduced() == 1)
               {
                   Introduced = "True";
               }
               else
               {
                   Introduced = "False";
               }
               QStandardItem* item4 = new QStandardItem(Introduced);
               model->setItem(row, 3, item4);\

               int CommentCount = student->GetNumberOfComments();
               QStandardItem* item5 = new QStandardItem(QString::number(CommentCount));
               model->setItem(row, 4, item5);\

               float A1Mark = student->GetA1Mark();
               QStandardItem* item6 = new QStandardItem(QString::number(A1Mark));
               model->setItem(row, 5, item6);

               float A2Mark = student->GetA2Mark();
               QStandardItem* item7 = new QStandardItem(QString::number(A2Mark));
               model->setItem(row, 6, item7);

               QStandardItem* item8 = new QStandardItem("1");
               model->setItem(row, 7, item8);

       }

     ui->mainTable->setModel(model);
     ui->mainTable->resizeColumnsToContents();
}


void MainWindow::on_btnRefresh_clicked()
{
    UpdateViews();
}

void MainWindow::UpdateViews()
{
    StudentModel *model = new StudentModel();

    ui->mainTable->setModel(model);

    ui->mainTable->resizeRowsToContents();

    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(on_btnRefresh_clicked()));
    RefreshPoints();
}
