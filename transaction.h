#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>

namespace Ui {
class Transaction;
}

class Transaction : public QDialog
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    void set(int p=0);
    ~Transaction();

private slots:
    void on_pushButton_password_clicked();
    void on_pushButton_payment_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Transaction *ui;
    int pass{0};
    QString username{""};
};

#endif // TRANSACTION_H
