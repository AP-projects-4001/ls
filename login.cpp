#include "login.h"
#include "ui_login.h"
#include "create_account.h"
#include "forget_password.h"
#include<QString>
#include <iostream>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    this->setFixedSize(954,581);
    ui->setupUi(this);
    int a=rand()%(51);
    int b=rand()%(51);

    QString x=QString::number(a);
    QString y=QString::number(b);

    ui->label_4->setText("Enter the Answer "+x+"+"+y+" =");
}

login::~login()
{
    delete ui;
}



void login::on_pushButton_Creat_clicked()
{
   Create_account *d=new Create_account(this);
   d->show();
}


void login::on_commandLinkButton_clicked()
{
    forget_password *d=new forget_password(this);
    d->show();
}

