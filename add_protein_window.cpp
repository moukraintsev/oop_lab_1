#include "add_protein_window.h"
#include "ui_add_protein_window.h"
#include "proteincollection.h"
#include "sum_protein_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <fstream>


add_protein_window::add_protein_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_protein_window)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Add new protein"));
}

add_protein_window::~add_protein_window()
{
    delete ui;
}


void add_protein_window::on_pushButton_clicked()
{
    std::string name = (ui->lineEdit->text()).toStdString();
    ProteinCollection& program = ProteinCollection::getInstance();

    bool fromFile = ui->radioButton_2->isChecked();
    bool sumProtein = ui->radioButton_3->isChecked();

    Protein protein;

    if (fromFile){
        std::string filename = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "/").toStdString();
        protein.fromFile(filename);
    }

    if (sumProtein){
        if (program.getProteinList().size() < 2){
            QMessageBox::critical(this, "Not enough protein to summation", "Add protein",
                                                    QMessageBox::Ok);
        }
        else{
            sum_protein_window* new_window = new sum_protein_window(name);
            new_window->show();
            this->destroy();
        }
    } else {
        bool succes = program.addProtein(name, protein);
        if (!succes){
            int ans = QMessageBox::critical(this, "This protein alreadt exists", "Add new?",
                                        QMessageBox::Yes, QMessageBox::No);
            if (ans==QMessageBox::Yes){
                program.addProtein(name, protein, 1);
                succes = true;
            }
        }
        if (succes){
            this->close();
        }
    }
}
