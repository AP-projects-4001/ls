#include "client.h"
#include "ui_client.h"
#include "login.h"
#include "cart.h"
#include<QChar>
#include "widget_kala.h"
int Client::count{0};
Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    add_global_to_item_widget();
    show_item();
    ui->setupUi(this);
    this->setFixedSize(1241,688);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

void Client::serch(QString name, int min, int max, QString color, QString brand, QString weight, QString Qtype, QString gender)
{
    item_widget_cloths.clear();
    item_widget_sporting.clear();
    int min_weight;
    int max_weight;
    if (weight[0]=='0')
    {
        min_weight=0;
        max_weight=999;
    }
    else if(weight[0]=='1')
    {
        min_weight=1000;
        max_weight=4999;
    }
    else
    {
        min_weight=5000;
        max_weight=1000000;
    }
    if(Qtype[0]=='E')
    {
        for(int i=0;i<Global::vec_article_cloths.size();i++)
        {
            cloths x=Global::vec_article_cloths[i];
            if ((x.get_name()==name || name.size()==0)&&(x.get_price()<=max &&x.get_price()>=min) && (x.get_color()==color || color.size()==0) && (x.get_brand_name()==brand || brand.size()==0) && (x.get_weight()>=min_weight && x.get_weight()<=max_weight)&& (x.get_gender()==gender))
            {
                item_widget_cloths.push_back(Global::vec_article_cloths[i]);
            }
        }
    }
    else if (Qtype[0]=='C')
    {
        for(int i=0;i<Global::vec_article_sporting_goods.size();i++)
        {
            Sporting_goods x=Global::vec_article_sporting_goods[i];
            if ((x.get_name()==name || name.size()==0)&&(x.get_price()<=max &&x.get_price()>=min) && (x.get_color()==color || color.size()==0) && (x.get_brand_name()==brand || brand.size()==0) && (x.get_weight()>=min_weight && x.get_weight()<=max_weight))
            {
                item_widget_sporting.push_back(Global::vec_article_sporting_goods[i]);
            }
        }

    }
    else
    {
        for(int i=0;i<Global::vec_article_cloths.size();i++)
        {
            cloths x=Global::vec_article_cloths[i];
            if ((x.get_name()==name || name.size()==0)&&(x.get_price()<=max &&x.get_price()>=min) && (x.get_color()==color || color.size()==0) && (x.get_brand_name()==brand || brand.size()==0) && (x.get_weight()>=min_weight && x.get_weight()<=max_weight)&& (x.get_gender()==gender))
            {
                item_widget_cloths.push_back(Global::vec_article_cloths[i]);
            }
        }
        for(int i=0;i<Global::vec_article_sporting_goods.size();i++)
        {
            Sporting_goods x=Global::vec_article_sporting_goods[i];
            if ((x.get_name()==name || name.size()==0)&&(x.get_price()<=max &&x.get_price()>=min) && (x.get_color()==color || color.size()==0) && (x.get_brand_name()==brand || brand.size()==0) && (x.get_weight()>=min_weight && x.get_weight()<=max_weight))
            {
                item_widget_sporting.push_back(Global::vec_article_sporting_goods[i]);
            }
        }
    }

    show_item();

}

void Client::show_item()
{
    if(count!=0)
    {
        ui->listWidget_commodity->clear();
        count=0;
    }
    count=item_widget_cloths.size()+item_widget_sporting.size();
    if(count>0)
    {
        for(int i=0;i<item_widget_cloths.size();i++)
        {
           // t=1;
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_kala *m = new widget_kala;
             m->set(item_widget_cloths[i].get_image_file(),item_widget_cloths[i].get_name(),item_widget_cloths[i].get_color(),item_widget_cloths[i].get_price());
             ui->listWidget_commodity->addItem(m_ulitems);
             ui->listWidget_commodity->setItemWidget(m_ulitems,m);

        }
        for(int i=0;i<item_widget_sporting.size();i++)
        {

             //t=1;
            QListWidgetItem *m_ulitems = new QListWidgetItem;
            widget_kala *m =new widget_kala;
            m->set(item_widget_sporting[i].get_image_file(),item_widget_sporting[i].get_name(),item_widget_sporting[i].get_color(),item_widget_sporting[i].get_price());
            ui->listWidget_commodity->addItem(m_ulitems);
            ui->listWidget_commodity->setItemWidget(m_ulitems,m);
        }
    }

}


void Client::add_global_to_item_widget()
{
    item_widget_cloths.clear();
    item_widget_sporting.clear();
    for(int i=0;i<Global::vec_article_cloths.size();i++)
    {
        item_widget_cloths.push_back(Global::vec_article_cloths[i]);
    }
    for(int i=0;i<Global::vec_article_sporting_goods.size();i++)
    {
        item_widget_sporting.push_back(Global::vec_article_sporting_goods[i]);
    }
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButton_logout_clicked()
{
    login *x=new login();
    this->close();
    x->show();
}

void Client::on_pushButton_Cart_clicked()
{
    Cart *x=new Cart();
    this->close();
    x->show();
}

void Client::on_pushButton_moneybags_clicked()
{

}

void Client::on_pushButton_serch_clicked()
{
    Name=ui->lineEdit_serch->text();
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}

void Client::on_spinBox_max_editingFinished()
{
    Max=ui->spinBox_max->value();
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}

void Client::on_spinBox_min_editingFinished()
{
    Min=ui->spinBox_min->value();
     serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}


void Client::on_comboBox_coler_currentIndexChanged(const QString &arg1)
{
    Color=arg1;
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}


void Client::on_comboBox_brand_currentIndexChanged(const QString &arg1)
{
    Brand=arg1;
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}

void Client::on_comboBox_Weight_currentIndexChanged(const QString &arg1)
{
    Weight = arg1;
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}

void Client::on_comboBox_type_currentIndexChanged(const QString &arg1)
{
    Type=arg1;
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}

void Client::on_comboBox_sex_currentIndexChanged(const QString &arg1)
{
    Gender=arg1;
    serch(Name,Min,Max,Color,Brand,Weight,Type,Gender);
}


void Client::on_listWidget_commodity_itemDoubleClicked(QListWidgetItem *item)
{
   // int o=ui->listWidget_commodity->indexFromItem(item).row();
}



