#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QDialog>

namespace Ui {
class Create_account;
}

class Create_account : public QDialog
{
    Q_OBJECT

public:
    explicit Create_account(QWidget *parent = nullptr);
    ~Create_account();

private:
    Ui::Create_account *ui;
};

#endif // CREATE_ACCOUNT_H
