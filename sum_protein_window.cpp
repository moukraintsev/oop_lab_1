#include "sum_protein_window.h"
#include "ui_sum_protein_window.h"
#include "proteincollection.h"
#include <QMessageBox>


sum_protein_window::sum_protein_window(const std::string& protein_name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sum_protein_window), _protein_name(protein_name), _first_protein_name(""), _second_protein_name("")
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Combining proteins"));
    ProteinCollection& program = ProteinCollection::getInstance();
    auto protein_list = program.getProteinList();
    for (const auto& p: program.getProteinList()){
        ui->listWidget->addItem(QString::fromStdString(p.first));
        ui->listWidget_2->addItem(QString::fromStdString(p.first));
    }
}


sum_protein_window::~sum_protein_window()
{
    delete ui;
}


void sum_protein_window::on_pushButton_clicked()
{
    if (_first_protein_name == "" or _second_protein_name == ""){
        QMessageBox::critical(this, "Choose protein before clicking", "Choose protein",
                                                QMessageBox::Ok);
    }
    else{
        ProteinCollection& program = ProteinCollection::getInstance();
        auto protein_list = program.getProteinList();
        Protein first = protein_list.at(_first_protein_name),
                second = protein_list.at(_second_protein_name);
        Protein sum = first + second;
        program.addProtein(_protein_name, sum);
        this->destroy();
    }
}


void sum_protein_window::on_listWidget_itemClicked(QListWidgetItem *item)
{
    _first_protein_name = item->text().toStdString();
}


void sum_protein_window::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
 _second_protein_name = item->text().toStdString();
}
