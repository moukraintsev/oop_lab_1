#include "show_protein_window.h"
#include "ui_show_protein_window.h"
#include "proteincollection.h"
#include "protein_edit_window.h"


show_protein_window::show_protein_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_protein_window)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("List of proteins"));
    ProteinCollection& ProteinCollection = ProteinCollection::getInstance();
    auto protein_list = ProteinCollection.getProteinList();
    for (const auto& p: ProteinCollection.getProteinList()){
        ui->listWidget->addItem(QString::fromStdString(p.first));
    }
}

show_protein_window::~show_protein_window()
{
    delete ui;
}


void show_protein_window::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    std::string protein_name = item->text().toStdString();
    protein_edit_window* new_window = new protein_edit_window(nullptr, protein_name);
    new_window->show();
    this->close();
}
