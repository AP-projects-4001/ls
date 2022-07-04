#include "factor.h"
#include "ui_factor.h"

factor::factor(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::factor)
{
    ui->setupUi(this);
    ui->dockWidgetContents->setWindowTitle("Factor");
}

factor::~factor()
{
    delete ui;
}
