#include "mainwindow.h"
#include "load1.h"
#include "login.h"
#include "create_account.h"
#include <QApplication>
#include "Global.h"
#include"client.h"
#include"add_to_cart.h"
#include"cart.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client x;
    x.show();
    return a.exec();
}
