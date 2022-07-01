#include "add_to_cart.h"
#include "ui_add_to_cart.h"
#include<QMovie>
#include "Global.h"
add_to_cart::add_to_cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_to_cart),
    id{0}
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

void add_to_cart::set(int id)
{
    this->id=id;
    if(Global::serch_id_cloths(id)!=-1)
    {
        int index=Global::serch_id_cloths(id);
        ui->label_name->setText(Global::vec_article_cloths[index].get_name());
        ui->label_price->setText(QString::number(Global::vec_article_cloths[index].get_price()));
        ui->label_seller->setText(Global::vec_article_cloths[index].get_seller_username());
        ui->label_weight->setText(QString::number(Global::vec_article_cloths[index].get_weight()));
        ui->label_type->setText("cloths");
        ui->label_coler->setText(Global::vec_article_cloths[index].get_color());
        ui->label_brand->setText(Global::vec_article_cloths[index].get_brand_name());
        ui->label_other->setText(Global::vec_article_cloths[index].get_gender());
    }
    else if(Global::serch_id_sporting_goods(id)!=-1)
    {
        int index=Global::serch_id_sporting_goods(id);
        ui->label_name->setText(Global::vec_article_sporting_goods[index].get_name());
        ui->label_price->setText(QString::number(Global::vec_article_sporting_goods[index].get_price()));
        ui->label_seller->setText(Global::vec_article_sporting_goods[index].get_seller_username());
        ui->label_weight->setText(QString::number(Global::vec_article_sporting_goods[index].get_weight()));
        ui->label_type->setText("sporting_goods");
        ui->label_coler->setText(Global::vec_article_sporting_goods[index].get_color());
        ui->label_brand->setText(Global::vec_article_sporting_goods[index].get_brand_name());
        ui->label_other->setText(Global::vec_article_sporting_goods[index].get_material());
    }
}

void add_to_cart::on_pushButton_clicked()
{
    if(Global::serch_id_cloths(id)!=-1)
    {
        Global::Shopping_cart.push_back(id);
    }
    else if(Global::serch_id_sporting_goods(id)!=-1)
    {
        Global::Shopping_cart.push_back(id);
    }
}

