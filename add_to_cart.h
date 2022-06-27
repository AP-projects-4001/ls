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

private:
    Ui::add_to_cart *ui;
};

#endif // ADD_TO_CART_H
