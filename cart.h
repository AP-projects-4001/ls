#ifndef CART_H
#define CART_H

#include <QDialog>

namespace Ui {
class Cart;
}

class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = nullptr);
    ~Cart();

private slots:
    void on_pushButton_close_clicked();
    void on_pushButton_romove_clicked();
    void on_pushButton_buy_clicked();

private:
    Ui::Cart *ui;
    void show_item();
    int sum=0;

};

#endif // CART_H
