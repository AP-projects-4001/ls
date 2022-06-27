#include "add_to_cart.h"
#include "ui_add_to_cart.h"
#include<QMovie>
add_to_cart::add_to_cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_to_cart)
{
     ui->setupUi(this);
     this->setFixedSize(1241,688);
     setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     QMovie* movie=new QMovie(":/new/prefix1/iranserver.gif");
     QMovie* movie1=new QMovie(":/new/prefix1/XXwt.gif");
     ui->label_8->setMovie(movie);
     ui->label_9->setMovie(movie1);
     movie1->start();
     movie->start();
}

add_to_cart::~add_to_cart()
{
    delete ui;
}
