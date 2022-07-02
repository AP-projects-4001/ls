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
