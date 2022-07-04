#include "customer.h"
#include "ui_customer.h"
#include "add_kala.h"
#include "login.h"
#include "widget_show_kala_customer.h"
#include "QListWidgetItem"

QVector<cloths> customer::vec_cloths;
QVector<Sporting_goods> customer::vec_sporting;
QVector <int> customer::id;
int customer::size_of_widget=0;
customer::customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer)
{

    ui->setupUi(this);
    for (int i=0;i<Global::vec_article_cloths.size();i++)
    {
        if (Global::vec_article_cloths[i].get_seller_username()==Global::Active_person.get_user_name())
        {
            vec_cloths.push_back(Global::vec_article_cloths[i]);
            id.push_back(Global::vec_article_cloths[i].get_id());
        }
    }
    for (int i=0;i<Global::vec_article_sporting_goods.size();i++)
    {
        if (Global::vec_article_sporting_goods[i].get_seller_username()==Global::Active_person.get_user_name())
        {
            vec_sporting.push_back(Global::vec_article_sporting_goods[i]);
            id.push_back(Global::vec_article_sporting_goods[i].get_id());

        }
    }
    show_item();

}

customer::~customer()
{
    delete ui;
}

void customer::on_pushButton_add_clicked()
{
    add_kala *x=new add_kala(this);
    this->close();
    x->show();
}


void customer::on_pushButton_4_clicked()
{
    int index=ui->listWidget->currentRow();
    if (index!=-1)
    {
        QListWidgetItem *x=ui->listWidget->currentItem();
        delete x;
        for(int i=0;i<vec_cloths.size();i++)
        {
            if(vec_cloths[i].get_id()==id[index])
            {
                vec_cloths.remove(i);
                int ind=Global::serch_id_cloths(id[index]);
                if (ind>=0)
                    Global::vec_article_cloths.remove(ind);
                break;
            }
        }
        for(int i=0;i<vec_sporting.size();i++)
        {
            if (vec_sporting[i].get_id()==id[index])
            {
                vec_sporting.remove(i);
                break;
                int ind=Global::serch_id_sporting_goods(id[index]);
                if (ind>=0)
                    Global::vec_article_sporting_goods.remove(ind);
            }
        }
        id.remove(index);
        Global::save_article();
        size_of_widget--;
        show_item();
    }
}


void customer::on_pushButton_logout_clicked()
{
    this->close();
    login *x=new login();
    x->show();
    delete this;
}

int customer::getSize_of_widget() const
{
    return size_of_widget;
}

void customer::setSize_of_widget(int newSize_of_widget)
{
    size_of_widget = newSize_of_widget;
}

void customer::show_item()
{
    if(size_of_widget!=0)
    {
        ui->listWidget->clear();
        size_of_widget=0;
    }
    size_of_widget=vec_cloths.size()+vec_sporting.size();
    if(size_of_widget>0)
    {
        for(int i=0;i<vec_cloths.size();i++)
        {
             QListWidgetItem *m_ulitems = new QListWidgetItem;
             widget_show_kala_customer *m = new widget_show_kala_customer;
             m->set(vec_cloths[i].get_id(),vec_cloths[i].get_image_file(),vec_cloths[i].get_name(),vec_cloths[i].get_color(),vec_cloths[i].get_price(),vec_cloths[i].get_stock());
             ui->listWidget->addItem(m_ulitems);
             m_ulitems->setSizeHint(QSize(1031,218));
             ui->listWidget->setItemWidget(m_ulitems,m);

        }
        for(int i=0;i<vec_sporting.size();i++)
        {
            QListWidgetItem *m_ulitems = new QListWidgetItem;
            widget_show_kala_customer *m = new widget_show_kala_customer;
            m->set(vec_sporting[i].get_id(),vec_sporting[i].get_image_file(),vec_sporting[i].get_name(),vec_sporting[i].get_color(),vec_sporting[i].get_price(),vec_sporting[i].get_stock());
            ui->listWidget->addItem(m_ulitems);
            m_ulitems->setSizeHint(QSize(1031,218));
            ui->listWidget->setItemWidget(m_ulitems,m);
        }
    }
}



