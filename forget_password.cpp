#include "forget_password.h"
#include "ui_forget_password.h"

forget_password::forget_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forget_password)
{
    ui->setupUi(this);
}

forget_password::~forget_password()
{
    delete ui;
}
