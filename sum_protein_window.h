#ifndef SUM_PROTEIN_WINDOW_H
#define SUM_PROTEIN_WINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>


namespace Ui {
class sum_protein_window;
}

class sum_protein_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit sum_protein_window(const std::string&, QWidget *parent = nullptr);
    ~sum_protein_window();

private slots:
    void on_pushButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_listWidget_2_itemClicked(QListWidgetItem *item);

private:
    Ui::sum_protein_window *ui;
    std::string _protein_name, _first_protein_name, _second_protein_name;
};

#endif // SUM_PROTEIN_WINDOW_H
