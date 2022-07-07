#include "widget_user.h"
#include "ui_widget_user.h"

widget_user::widget_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_user)
{
    ui->setupUi(this);
}

widget_user::~widget_user()
{
    delete ui;
}

void widget_user::set(QString x)
{
    ui->label_username->setText(x);
}
