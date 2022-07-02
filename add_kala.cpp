#include "add_kala.h"
#include "ui_add_kala.h"

add_kala::add_kala(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_kala)
{
    ui->setupUi(this);
}

add_kala::~add_kala()
{
    delete ui;
}
