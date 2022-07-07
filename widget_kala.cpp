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

void widget_kala::set(QString phonto, QString name, QString color, int price)
{
    ui->label_name->setText(name);
    ui->label_price->setText(QString::number(price));
    QString x="QWidget {background-image: url("+phonto+") ;}";
    ui->frame->setStyleSheet(x);

}
