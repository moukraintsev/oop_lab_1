#include "show_full_protein_window.h"
#include "ui_show_full_protein_window.h"
#include "proteincollection.h"
#include <sstream>
#include <string>


show_full_protein_window::show_full_protein_window(QWidget *parent, std::string protein_name) :
    QMainWindow(parent), ui(new Ui::show_full_protein_window),  _protein_name(protein_name)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Protein "+protein_name));
    ProteinCollection& program = ProteinCollection::getInstance();
    Protein protein = program.getProteinList().at(protein_name);
    int i = 1;
    while (protein.GetElem(i) != nullptr) {
        std::string full_name = (protein.GetElem(i)->data.getFullName());
        std::string short_name = (protein.GetElem(i)->data.getShortName());
        std::ostringstream ost;
        ost << i;
        std::string s_num = ost.str();
        std::string text = s_num + ") " + full_name + " ['" + short_name + "']";
        ui->listWidget->addItem(QString::fromStdString(text));
        i++;
    }
}


show_full_protein_window::~show_full_protein_window()
{
    delete ui;
}
