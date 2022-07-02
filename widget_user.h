#ifndef WIDGET_USER_H
#define WIDGET_USER_H

#include <QWidget>

namespace Ui {
class widget_user;
}

class widget_user : public QWidget
{
    Q_OBJECT

public:
    explicit widget_user(QWidget *parent = nullptr);
    ~widget_user();

private:
    Ui::widget_user *ui;
};

#endif // WIDGET_USER_H
