#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(9);
    ui->lcdNumber->display(76);
    ui->lcdNumber->display(ui->lcdNumber->value()+1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{
    //ui->lineEdit->hide();
}

void MainWindow::on_checkBox_stateChanged()
{
    //x1 x2;
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->setStyleSheet("background-image:url(:/new/prefix1/creat_account.png);");

}
