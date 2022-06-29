#include "widget_kala.h"
#include "ui_widget_kala.h"

widget_kala::widget_kala(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_kala)
{
    ui->setupUi(this);
}

widget_kala::~widget_kala()
{
    delete ui;
}
