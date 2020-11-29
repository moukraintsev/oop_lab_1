#ifndef ADD_ACID_WINDOW_H
#define ADD_ACID_WINDOW_H

#include <QMainWindow>


namespace Ui {
class add_acid_window;
}

class add_acid_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_acid_window(QWidget *parent = nullptr, std::string protein_name="");
    ~add_acid_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_acid_window *ui;
    std::string _protein_name;
};


#endif // ADD_ACID_WINDOW_H
