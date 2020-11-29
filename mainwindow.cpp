#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "protein.h"
#include "proteincollection.h"
#include "show_protein_window.h"
#include "add_protein_window.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("THE BEST APP EVER (PLZ 10)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ProteinCollection& ProteinCollection = ProteinCollection::getInstance();
    if (ProteinCollection.getProteinList().empty()){
        int ans = QMessageBox::critical(this, "Отсутствуют белки", "Создать новый?",
                                        QMessageBox::Yes);

        if (ans == QMessageBox::Yes){
            add_protein_window* new_window = new add_protein_window();
            new_window->show();
        }

    }
    else{
        show_protein_window* new_window = new show_protein_window();
        new_window->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    add_protein_window* new_window = new add_protein_window();
    new_window->show();
}
