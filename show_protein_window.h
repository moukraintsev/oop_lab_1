#ifndef SHOW_PROTEIN_WINDOW_H
#define SHOW_PROTEIN_WINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class show_protein_window;
}

class show_protein_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_protein_window(QWidget *parent = nullptr);
    ~show_protein_window();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::show_protein_window *ui;
};

#endif // SHOW_PROTEIN_WINDOW_H
