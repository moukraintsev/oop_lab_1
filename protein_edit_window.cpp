#include "protein_edit_window.h"
#include "ui_protein_edit_window.h"
#include "proteincollection.h"
#include "show_protein_window.h"
#include "show_full_protein_window.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QDebug>
#include "mainwindow.h"
#include "add_acid_window.h"
#include <sstream>


protein_edit_window::protein_edit_window(QWidget *parent, std::string protein_name):
    QMainWindow(parent),  _protein_name(protein_name),
    ui(new Ui::protein_edit_window)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Protein "+protein_name));
    ProteinCollection& program = ProteinCollection::getInstance();
    auto proteinFromList = program.getProteinList().at(protein_name);
    if (proteinFromList.GetCount() == 0)
    {
      ui->label->hide(); // "There is one acid" label
      ui->label_3->hide(); // "First acid" label
      ui->label_4->hide(); // "First acid" value label
      ui->label_5->hide(); // "Last acid" label
      ui->label_6->hide(); // "Last acid" value label
      ui->pushButton_3->hide();
      ui->pushButton_4->hide();
      ui->pushButton_5->hide();
      ui->pushButton_6->hide();
      ui->pushButton_8->hide();
      ui->pushButton_9->hide();
      ui->lineEdit->hide();
    }
    else if (proteinFromList.GetCount() == 1){
        ui->label_2->hide(); // "Protein is empty" label
        ui->label_5->hide();
        ui->label_6->hide();
        std::string full_name = (proteinFromList.GetHead())->data.getFullName();
        std::string short_name = (proteinFromList.GetHead())->data.getShortName();
        std::string text = full_name + " ['" + short_name + "']";
        ui->label_4->setText(QString::fromStdString(text));
        ui->pushButton_3->hide();
        ui->pushButton_6->hide();
    }
    else{
        ui->label_2->hide();
        ui->label->hide();
        std::string full_name = (proteinFromList.GetHead())->data.getFullName();
        std::string short_name = (proteinFromList.GetHead())->data.getShortName();
        std::string text = full_name + " ['" + short_name + "']";
        ui->label_4->setText(QString::fromStdString(text));
        full_name = (proteinFromList.GetTail())->data.getFullName();
        short_name = (proteinFromList.GetTail())->data.getShortName();
        text = full_name + " ['" + short_name + "']";
        ui->label_6->setText(QString::fromStdString(text));
    }
}


protein_edit_window::~protein_edit_window()
{
    delete ui;
}


void protein_edit_window::on_pushButton_clicked()
{
    // "Back to the list" button
    show_protein_window* new_window = new show_protein_window();
    new_window->show();
    this->close();
}


void protein_edit_window::on_pushButton_2_clicked()
{
    // "Add" button
    add_acid_window* new_window = new add_acid_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}


void protein_edit_window::on_pushButton_3_clicked()
{
    // "Show full protein" button
    show_full_protein_window* new_window = new show_full_protein_window(nullptr, _protein_name);
    new_window->show();
}



void protein_edit_window::on_pushButton_4_clicked()
{
    // "Clear protein" button
    ProteinCollection& program = ProteinCollection::getInstance();
    program.clearProtein(_protein_name);
    protein_edit_window* new_window = new protein_edit_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}


void protein_edit_window::on_pushButton_5_clicked()
{
    // "Delete first acid" button
    ProteinCollection& program = ProteinCollection::getInstance();
    program.deleteAminoAcid(_protein_name, true);
    protein_edit_window* new_window = new protein_edit_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}



void protein_edit_window::on_pushButton_6_clicked()
{
    // "Delete last acid" button
    ProteinCollection& program = ProteinCollection::getInstance();
    program.deleteAminoAcid(_protein_name, false);
    protein_edit_window* new_window = new protein_edit_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}


void protein_edit_window::on_pushButton_7_clicked()
{
    // "Delete protein" button
    ProteinCollection& program = ProteinCollection::getInstance();
    program.deleteProtein(_protein_name);
    if (!program.getProteinList().empty()){
        show_protein_window* new_window = new show_protein_window();
        new_window->show();
    }
    this->close();
}


void protein_edit_window::on_pushButton_8_clicked()
{
    std::string filename = QFileDialog::getSaveFileName(this, tr("Имя файла"), "/").toStdString();
    ProteinCollection& program = ProteinCollection::getInstance();
    Protein protein = program.getProteinList().at(_protein_name);
    protein.toFile(filename);
}


void protein_edit_window::on_pushButton_9_clicked()
{
    // "Delete from (position)" button
    ProteinCollection& program = ProteinCollection::getInstance();
    int position;
    std::string pos = (ui->lineEdit->text()).toStdString();
    std::istringstream ist(pos);
    ist >> position;

    if (position >= 1 || position <= program.countAcidInProtein(_protein_name)) {
        program.deleteAminoAcidFromPos(_protein_name, position);
    }
    protein_edit_window* new_window = new protein_edit_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}
