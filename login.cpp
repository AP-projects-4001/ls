#include "login.h"
#include "ui_login.h"
#include "create_account.h"
#include "forget_password.h"
#include<QString>
#include <iostream>
#include "time.h"
#include "QDebug"
#include "QMessageBox"
#include "admin.h"
#include "client.h"
#include "customer.h"
void login::check_correct_password(QString user_name, QString password)
{
    Global glob;
    bool exit1=0;
    for(int i=0;i<glob.vec_person.size();i++)
    {
        QString u=glob.vec_person[i].get_user_name() , p=glob.vec_person[i].get_password();
        if(user_name==u && password==p)
        {
            exit1=1;
            glob.Active_person=glob.vec_person[i];
            if(glob.Active_person.get_ban())
            {
                QMessageBox *qm = new QMessageBox(this);
                qm->setText("Account Baned");
                qm->exec();

            }
            else
            {
                if (glob.Active_person.get_type()==0)
                {
                    Admin *x= new Admin();
                    x->show();
                    this->close();
                }
                else if(glob.Active_person.get_type()==1)
                {
                    Global::load_shoppong_cart();
                    Client *x =  new Client();
                    x->show();
                    this->close();
                }
                else
                {
                    customer *x= new customer();
                    x->show();
                    this->close();
                }
            }
        }
    }
    if(exit1==0)
    {
        QMessageBox *qm = new QMessageBox(this);
        qm->setText("invalid password or username");
        qm->exec();
    }
}
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    this->setFixedSize(954,581);
    ui->setupUi(this);
    srand(time(0));
    int a=rand()%(51);
    int b=rand()%(51);
    sum=a+b;
    QString x=QString::number(a);
    QString y=QString::number(b);

    ui->label_4->setText("Enter the Answer "+x+"+"+y+" =");
    ui->lineEdit_sum->hide();
    ui->lineEdit_sum->show();
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


void login::on_pushButton_Login_clicked()
{
    QString password , user_name;
    user_name=ui->lineEdit_name->text();
    password = ui->lineEdit_password->text();
    int x=ui->lineEdit_sum->text().toInt();

    if (sum == x)
    {
        check_correct_password(user_name, password);
    }
    int a=rand()%(51);
    int b=rand()%(51);
    sum=a+b;
    QString xx=QString::number(a);
    QString y=QString::number(b);
    ui->label_4->setText("");
    ui->label_4->setText(ui->label_4->text()+"Enter the Answer "+xx+"+"+y+" =");
    ui->lineEdit_sum->setStyleSheet("background: rgb(255,0,0);");
}


