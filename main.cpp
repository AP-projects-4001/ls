#include "mainwindow.h"
#include "load1.h"
#include "login.h"
#include "create_account.h"
#include <QApplication>
#include "Global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    load1 Q;
    Global x;
    x.load();
    Q.show();
    return a.exec();
}
