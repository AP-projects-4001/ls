#include "widget_show_kala_customer.h"
#include "ui_widget_show_kala_customer.h"

widget_show_kala_customer::widget_show_kala_customer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_show_kala_customer)
{
    ui->setupUi(this);
}

widget_show_kala_customer::~widget_show_kala_customer()
{
    delete ui;
}
