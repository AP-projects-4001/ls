#include "cart.h"
#include "ui_cart.h"
#include "client.h"
#include "Global.h"
#include "QListWidgetItem"
#include "widget_kala.h"
#include "QMessageBox"
#include "transaction.h"
Cart::Cart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
    this->setFixedSize(1241,688);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    show_item();
}

void Cart::show_item()
{
    if(ui->listWidget->count()>0)
        ui->listWidget->clear();
    for(int i=0;i<Global::Shopping_cart.size();i++)
    {
       // t=1;
         int id=Global::Shopping_cart[i].first;
         if (Global::serch_id_cloths(id)!=-1)
         {
             int index=Global::serch_id_cloths(id);
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_kala *m = new widget_kala;
             m->set(Global::vec_article_cloths[index].get_image_file() ,Global::vec_article_cloths[index].get_name(),Global::vec_article_cloths[index].get_color(),Global::vec_article_cloths[index].get_price());
             ui->listWidget->addItem(m_ulitems);
             ui->listWidget->setItemWidget(m_ulitems,m);
             sum+=Global::vec_article_cloths[index].get_price()*Global::Shopping_cart[i].second;
         }
         else
         {
             int index=Global::serch_id_sporting_goods(id);
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_kala *m = new widget_kala;
             m->set(Global::vec_article_sporting_goods[index].get_image_file() ,Global::vec_article_sporting_goods[index].get_name(),Global::vec_article_sporting_goods[index].get_color(),Global::vec_article_sporting_goods[index].get_price());
             ui->listWidget->addItem(m_ulitems);
             ui->listWidget->setItemWidget(m_ulitems,m);
             sum+=Global::vec_article_sporting_goods[index].get_price()*Global::Shopping_cart[i].second;
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
     int id = Global::Shopping_cart[i].first;
     Global::save_shopping_cart();
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


void Cart::on_pushButton_buy_clicked()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    QString now=cd.toString()+"\t"+ct.toString();
    if (Global::Active_person.get_moneybags()>sum)
    {
        Global::Active_person.setMoneybags(Global::Active_person.get_moneybags()-sum);
        for(int i=0 ; i<Global::vec_person.size();i++)
        {
            if(Global::vec_person[i].get_user_name()==Global::Active_person.get_user_name())
            {
                Global::vec_person[i].setMoneybags(Global::Active_person.get_moneybags());
            }
        }
        for(int i=0;i<Global::Shopping_cart.size();i++)
        {
            int id = Global::Shopping_cart[i].first;
            int ind=Global::serch_id_cloths(id);
            if (ind>=0)
            {
                Global::vec_article_cloths[ind].set_number_sold(Global::vec_article_cloths[ind].get_number_sold()+Global::Shopping_cart[i].second);
                QString user=Global::vec_article_cloths[ind].get_seller_username();
                for(int j=0;j<Global::vec_person.size();j++)
                {
                    if(user==Global::vec_person[j].get_user_name())
                    {
                        Global::vec_person[j].setMoneybags(Global::vec_person[j].get_moneybags()+Global::vec_article_cloths[ind].get_price()*Global::Shopping_cart[i].second);
                    }
                }
                Global::vec_of_Buyer.push_back(qMakePair(Global::Shopping_cart[i].second,qMakePair(qMakePair(Global::Shopping_cart[i].first,Global::Active_person.get_user_name()),qMakePair(now,Global::vec_article_cloths[ind].get_price()))));
            }
        }
        Global::save();
        Global::save_article();
        Global::save_buyer();

        QMessageBox *x=new QMessageBox;
        x->setText("paid with money bags");
        x->exec();
        this->close();
        Global::Shopping_cart.clear();
        Global::save_shopping_cart();
    } 
    else
    {
        Transaction *x=new Transaction;
        x->set(ui->lineEdit_pice->text().toInt());
        if(Global::buy==1)
        {
            Global::buy=0;
            Global::Active_person.setMoneybags(Global::Active_person.get_moneybags()-sum);
            for(int i=0 ; i<Global::vec_person.size();i++)
            {
                if(Global::vec_person[i].get_user_name()==Global::Active_person.get_user_name())
                {
                    Global::vec_person[i].setMoneybags(Global::Active_person.get_moneybags());
                }
            }
            for(int i=0;i<Global::Shopping_cart.size();i++)
            {
                int id = Global::Shopping_cart[i].first;
                int ind=Global::serch_id_cloths(id);
                if (ind>=0)
                {
                    Global::vec_article_cloths[ind].set_number_sold(Global::vec_article_cloths[ind].get_number_sold()+Global::Shopping_cart[i].second);
                    QString user=Global::vec_article_cloths[ind].get_seller_username();
                    for(int j=0;j<Global::vec_person.size();j++)
                    {
                        if(user==Global::vec_person[j].get_user_name())
                        {
                            Global::vec_person[j].setMoneybags(Global::vec_person[j].get_moneybags()+Global::vec_article_cloths[ind].get_price()*Global::Shopping_cart[i].second);
                        }
                    }
                    Global::vec_of_Buyer.push_back(qMakePair(Global::Shopping_cart[i].second,qMakePair(qMakePair(Global::Shopping_cart[i].first,Global::Active_person.get_user_name()),qMakePair(now,Global::vec_article_cloths[ind].get_price()))));
                }
            }
            Global::save();
            Global::save_article();
            Global::save_buyer();

            QMessageBox *x=new QMessageBox;
            x->setText("paid with cart");
            x->exec();
            this->close();
            Global::Shopping_cart.clear();
            Global::save_shopping_cart();
        }
    }
}

