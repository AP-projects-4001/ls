#ifndef WIDGET_TRANSACTIONS_H
#define WIDGET_TRANSACTIONS_H

#include <QWidget>

namespace Ui {
class widget_transactions;
}

class widget_transactions : public QWidget
{
    Q_OBJECT

public:
    explicit widget_transactions(QWidget *parent = nullptr);
    ~widget_transactions();

private:
    Ui::widget_transactions *ui;
};

#endif // WIDGET_TRANSACTIONS_H
