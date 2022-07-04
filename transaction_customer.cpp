#include "transaction_customer.h"
#include "ui_transaction_customer.h"

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
