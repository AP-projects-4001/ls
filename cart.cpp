#include "cart.h"
#include "ui_cart.h"
#include "client.h"
#include "Global.h"
#include "QListWidgetItem"
#include "widget_kala.h"
Cart::Cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
    this->setFixedSize(1241,688);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

void Cart::show_item()
{
    for(int i=0;i<Global::Shopping_cart.size();i++)
    {
       // t=1;
         int id=Global::Shopping_cart[i];
         if (Global::serch_id_cloths(id)!=-1)
         {
             int index=Global::serch_id_cloths(id);
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_kala *m = new widget_kala;
             m->set(Global::vec_article_cloths[index].get_image_file() ,Global::vec_article_cloths[index].get_name(),Global::vec_article_cloths[index].get_color(),Global::vec_article_cloths[index].get_price());
             ui->listWidget->addItem(m_ulitems);
             ui->listWidget->setItemWidget(m_ulitems,m);
             sum+=Global::vec_article_cloths[index].get_price();
         }
         else
         {
             int index=Global::serch_id_sporting_goods(id);
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_kala *m = new widget_kala;
             m->set(Global::vec_article_sporting_goods[index].get_image_file() ,Global::vec_article_sporting_goods[index].get_name(),Global::vec_article_sporting_goods[index].get_color(),Global::vec_article_sporting_goods[index].get_price());
             ui->listWidget->addItem(m_ulitems);
             ui->listWidget->setItemWidget(m_ulitems,m);
             sum+=Global::vec_article_sporting_goods[index].get_price();
         }
    }
    ui->lineEdit_pice->setText(QString::number(sum));
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_pushButton_close_clicked()
{
    Client* x=new Client(this);
    this->close();
    x->show();
}


void Cart::on_pushButton_romove_clicked()
{
     int i=ui->listWidget->currentRow();
     int id = Global::Shopping_cart[i];
     QListWidgetItem *m=ui->listWidget->currentItem();
     ui->listWidget->removeItemWidget(m);
     delete m;
     if (Global::serch_id_cloths(id)!=-1)
     {
         int index=Global::serch_id_cloths(id);
         sum-=Global::vec_article_cloths[index].get_price();
     }
     else
     {
         int index=Global::serch_id_sporting_goods(id);
         sum-=Global::vec_article_sporting_goods[index].get_price();
     }
     ui->lineEdit_pice->text().clear();
     ui->lineEdit_pice->setText(QString::number(sum));
}

