#include "create_account.h"
#include "ui_create_account.h"

Create_account::Create_account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_account)
{
    ui->setupUi(this);
}

Create_account::~Create_account()
{
    delete ui;
}
