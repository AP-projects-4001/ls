#ifndef ADD_TO_CART_H
#define ADD_TO_CART_H

#include <QDialog>

namespace Ui {
class add_to_cart;
}

class add_to_cart : public QDialog
{
    Q_OBJECT

public:
    explicit add_to_cart(QWidget *parent = nullptr);
    ~add_to_cart();
    void set(int id);
    void admin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::add_to_cart *ui;
    int id;
};

#endif // ADD_TO_CART_H
