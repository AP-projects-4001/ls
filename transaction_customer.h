#ifndef TRANSACTION_CUSTOMER_H
#define TRANSACTION_CUSTOMER_H

#include <QDialog>

namespace Ui {
class transaction_customer;
}

class transaction_customer : public QDialog
{
    Q_OBJECT

public:
    explicit transaction_customer(QWidget *parent = nullptr);
    ~transaction_customer();

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::transaction_customer *ui;
};

#endif // TRANSACTION_CUSTOMER_H
