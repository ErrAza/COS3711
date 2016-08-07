/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_Students;
    QWidget *centralWidget;
    QPushButton *btnImport;
    QPushButton *btnRefresh;
    QTableView *mainTable;
    QTableView *subTable;
    QMenuBar *menuBar;
    QMenu *menuImport;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(897, 801);
        actionImport_Students = new QAction(MainWindow);
        actionImport_Students->setObjectName(QStringLiteral("actionImport_Students"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnImport = new QPushButton(centralWidget);
        btnImport->setObjectName(QStringLiteral("btnImport"));
        btnImport->setGeometry(QRect(10, 10, 75, 23));
        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setGeometry(QRect(180, 10, 75, 23));
        mainTable = new QTableView(centralWidget);
        mainTable->setObjectName(QStringLiteral("mainTable"));
        mainTable->setGeometry(QRect(10, 70, 871, 321));
        mainTable->setSortingEnabled(true);
        subTable = new QTableView(centralWidget);
        subTable->setObjectName(QStringLiteral("subTable"));
        subTable->setGeometry(QRect(10, 410, 871, 321));
        subTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        subTable->setSortingEnabled(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 897, 21));
        menuImport = new QMenu(menuBar);
        menuImport->setObjectName(QStringLiteral("menuImport"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuImport->menuAction());
        menuImport->addAction(actionImport_Students);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionImport_Students->setText(QApplication::translate("MainWindow", "Import Students", 0));
        btnImport->setText(QApplication::translate("MainWindow", "Import", 0));
        btnRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
        menuImport->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
