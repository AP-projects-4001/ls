#include "mainwindow.h"
#include "load1.h"
#include "login.h"
#include "create_account.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    load1 Q;
    Q.show();
    return a.exec();
}
