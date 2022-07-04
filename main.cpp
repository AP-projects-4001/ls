#include "load1.h"
#include "login.h"
#include "create_account.h"
#include <QApplication>
#include "Global.h"
#include"client.h"
#include"add_to_cart.h"
#include"cart.h"
#include "client.h"
#include "test.h"
#include"edituser.h"
#include "widget_show_kala_customer.h"
#include "add_kala.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // test x;
    //x.show();
    Global::load();
    Global::load_article();
    Global::load_buyer();
    login *x =new login;
    x->show();
    return a.exec();
}
