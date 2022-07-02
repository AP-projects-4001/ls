#include "test.h"
#include "ui_test.h"
#include"widget_transactions.h".h"
test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    widget_transactions *d=new widget_transactions[8];
    ui->setupUi(this);
    QListWidgetItem *m_ulitems = new QListWidgetItem[8];
    for(int i=0;i<7;i++)
    {
        ui->listWidget->addItem(&m_ulitems[i]);
        m_ulitems[i].setSizeHint(QSize(411,112));
        ui->listWidget->setItemWidget(&m_ulitems[i],&d[i]);
    }
}

test::~test()
{
    delete ui;
}
