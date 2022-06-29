#ifndef WIDGET_KALA_H
#define WIDGET_KALA_H

#include <QWidget>

namespace Ui {
class widget_kala;
}

class widget_kala : public QWidget
{
    Q_OBJECT

public:
    explicit widget_kala(QWidget *parent = nullptr);
    ~widget_kala();

private:
    Ui::widget_kala *ui;
};

#endif // WIDGET_KALA_H
