#include "transaction_customer.h"
#include "ui_transaction_customer.h"
#include "Global.h"
transaction_customer::transaction_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transaction_customer)
{
    ui->setupUi(this);
}

transaction_customer::~transaction_customer()
{
    delete ui;
}

void transaction_customer::on_pushButton_confirm_clicked()
{
    Global::buy=1;
    this->close();
}


void transaction_customer::on_pushButton_cancel_clicked()
{
    this->close();
}

