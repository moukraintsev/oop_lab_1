#ifndef ADD_PROTEIN_WINDOW_H
#define ADD_PROTEIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class add_protein_window;
}

class add_protein_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_protein_window(QWidget *parent = nullptr);
    ~add_protein_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_protein_window *ui;
};

#endif // ADD_PROTEIN_WINDOW_H
