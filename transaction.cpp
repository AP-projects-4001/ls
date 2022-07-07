#include "transaction.h"
#include "ui_transaction.h"
#include "random"
#include "qmessagebox.h"
#include "Global.h"
#include <QTextStream>
#include <QTime>
#include <QDate>
Transaction::Transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
    this->setFixedSize(958,479);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::on_pushButton_password_clicked()
{
    pass=rand()%1000000;
    QMessageBox *x=new QMessageBox;
    x->setText(QString::number(pass));
    x->exec();
}

void Transaction::set(int p)
{
    if (p==0)
    {
        ui->label_seller->setText("charge moneybags");
        ui->label_name->setText(Global::Active_person.get_name());
        ui->label_phone->setText(Global::Active_person.get_phone_number());
        ui->lineEdit_price->setReadOnly(0);
    }
    else
    {
        ui->label_seller->setText("buyer information");
        ui->label_name->setText(Global::Active_person.get_name());
        ui->label_phone->setText(Global::Active_person.get_phone_number());
        ui->lineEdit_price->setText(QString::number(p));
        ui->lineEdit_price->setReadOnly(1);

    }
}


void Transaction::on_pushButton_payment_clicked()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    QString now=cd.toString()+"\t"+ct.toString();
    if(ui->label_seller->text()=="charge moneybags")
    {
        if(ui->lineEdit_pssword->text().toInt()==pass)
        {
            Global::vec_tran.push_back(qMakePair(qMakePair(ui->lineEdit_price->text().toInt(),Global::Active_person.get_user_name()),qMakePair("charge moneybags",now) ));
            for(int i=0;i<Global::vec_person.size();i++)
            {
                if(Global::vec_person[i].get_user_name()==Global::Active_person.get_user_name())
                {
                    Global::Active_person.setMoneybags(Global::Active_person.get_moneybags()+ui->lineEdit_price->text().toInt());
                    Global::vec_person[i].setMoneybags(Global::Active_person.get_moneybags());
                    Global::save();
                }
            }
            this->close();
        }
        else
        {

        }
    }
    else
    {
        if(ui->lineEdit_pssword->text().toInt()==pass)
        {
            Global::vec_tran.push_back(qMakePair(qMakePair(ui->lineEdit_price->text().toInt(),Global::Active_person.get_user_name()),qMakePair("deposit",now) ));
            Global::vec_tran.push_back(qMakePair(qMakePair(ui->lineEdit_price->text().toInt(), username),qMakePair("withdraw",now) ));
            Global::buy=1;
            for(int i=0;i<Global::vec_person.size();i++)
            {
                if(Global::vec_person[i].get_user_name()==username)
                {
                    Global::vec_person[i].setMoneybags(Global::vec_person[i].get_moneybags()+ui->lineEdit_price->text().toInt());
                    Global::save();
                }
            }
            this->close();
        }
        else
        {

        }
    }
}


void Transaction::on_pushButton_cancel_clicked()
{
    this->close();
}

