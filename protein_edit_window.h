#ifndef PROTEIN_EDIT_WINDOW_H
#define PROTEIN_EDIT_WINDOW_H

#include <QMainWindow>

namespace Ui {
class protein_edit_window;
}

class protein_edit_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit protein_edit_window(QWidget *parent = nullptr, std::string proteinName="");
    ~protein_edit_window();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    std::string _protein_name;
    Ui::protein_edit_window *ui;
};

#endif // PROTEIN_EDIT_WINDOW_H
