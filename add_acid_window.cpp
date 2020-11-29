#include "add_acid_window.h"
#include "ui_add_acid_window.h"
#include "proteincollection.h"
#include "protein_edit_window.h"
#include <sstream>


add_acid_window::add_acid_window(QWidget *parent, std::string protein_name) :
    QMainWindow(parent),
    ui(new Ui::add_acid_window), _protein_name(protein_name)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Add new acid"));
}


add_acid_window::~add_acid_window()
{
    delete ui;
}


void add_acid_window::on_pushButton_clicked()
{
    ProteinCollection& program = ProteinCollection::getInstance();

    bool in_the_beginning = ui->radioButton->isChecked();
    bool in_the_end = ui->radioButton_2->isChecked();
    bool in_the_position = ui->radioButton_3->isChecked();

    std::string acid_name = (ui->lineEdit->text()).toStdString();
    std::string acid_short_name = (ui->lineEdit_3->text()).toStdString();
    int position = 0;

    if (in_the_position) {
        std::string pos = (ui->lineEdit_2->text()).toStdString();
        std::istringstream ist(pos);
        ist >> position;
        if (position > program.countAcidInProtein(_protein_name)) {
            in_the_end = true;
        }
    }

    if (position <= 1 && !in_the_end && !in_the_position) {
        in_the_beginning = true;
    }

    program.addAminoAcid(_protein_name, acid_name, acid_short_name, in_the_beginning, in_the_end, position);
    protein_edit_window* new_window = new protein_edit_window(nullptr, _protein_name);
    new_window->show();
    this->close();
}
