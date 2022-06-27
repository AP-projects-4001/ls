#include "mainwindow.h"
#include "load1.h"
#include "login.h"
#include "create_account.h"
#include <QApplication>
#include "Global.h"
#include"client.h"
#include"add_to_cart.h"
#include"cart.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    load1 Q;
    //Global x;
    //Client g;
    //x.load();
    //Q.show();
    //g.show();
    //add_to_cart k;
    //k.show();
    Cart j;
    j.show();
    return a.exec();
}
