#ifndef WIDGET_SHOW_KALA_CUSTOMER_H
#define WIDGET_SHOW_KALA_CUSTOMER_H

#include <QWidget>

namespace Ui {
class widget_show_kala_customer;
}

class widget_show_kala_customer : public QWidget
{
    Q_OBJECT

public:
    explicit widget_show_kala_customer(QWidget *parent = nullptr);
    ~widget_show_kala_customer();

private:
    Ui::widget_show_kala_customer *ui;
};

#endif // WIDGET_SHOW_KALA_CUSTOMER_H
