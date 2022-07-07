#include "widget_transactions.h"
#include "ui_widget_transactions.h"

widget_transactions::widget_transactions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_transactions)
{
    ui->setupUi(this);
}

widget_transactions::~widget_transactions()
{
    delete ui;
}

void widget_transactions::set(int price, QString username, QString type, QString Date)
{
    ui->label_username_2->setText(QString::number(price));
    ui->label_username->setText(username);
    ui->label_time->setText(Date);
    ui->label_type->setText(type);
}
