#include "test.h"
#include "ui_test.h"
#include"widget_transactions.h"
#include"widget_show_kala_customer.h"
#include "QMessageBox"
test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    widget_show_kala_customer *d=new widget_show_kala_customer[8];
    ui->setupUi(this);
    QListWidgetItem *m_ulitems = new QListWidgetItem[8];
    for(int i=0;i<7;i++)
    {
        ui->listWidget->addItem(&m_ulitems[i]);
        m_ulitems[i].setSizeHint(QSize(1031,218));
        ui->listWidget->setItemWidget(&m_ulitems[i],&d[i]);
    }
    QMessageBox *x=new QMessageBox;
    x->setText(QString::number(ui->listWidget->currentRow()));
    x->exec();
}

test::~test()
{
    delete ui;
}

void test::on_listWidget_doubleClicked(const QModelIndex &index)
{

}

