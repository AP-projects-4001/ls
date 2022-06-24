#ifndef FORGET_PASSWORD_H
#define FORGET_PASSWORD_H

#include <QDialog>

namespace Ui {
class forget_password;
}

class forget_password : public QDialog
{
    Q_OBJECT

public:
    explicit forget_password(QWidget *parent = nullptr);
    ~forget_password();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::forget_password *ui;
};

#endif // FORGET_PASSWORD_H
