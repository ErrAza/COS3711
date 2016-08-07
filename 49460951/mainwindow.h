#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <importer.h>
#include <QString>
#include <QFileDialog>
#include <QTableView>
#include <studentmodel.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void RefreshModel();
    void RefreshPoints();

private slots:
    void on_btnImport_clicked();

    void on_btnRefresh_clicked();

private:
    Ui::MainWindow *ui;
    QTableView *view;
};

#endif // MAINWINDOW_H
