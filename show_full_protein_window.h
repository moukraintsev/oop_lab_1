#ifndef SHOW_FULL_PROTEIN_WINDOW_H
#define SHOW_FULL_PROTEIN_WINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class show_full_protein_window;
}

class show_full_protein_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_full_protein_window(QWidget *parent = nullptr, std::string protein_name="");
    ~show_full_protein_window();

private:
    Ui::show_full_protein_window *ui;
    std::string _protein_name;
};

#endif // SHOW_FULL_PROTEIN_WINDOW_H
