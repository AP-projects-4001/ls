#ifndef FACTOR_H
#define FACTOR_H

#include <QDockWidget>

namespace Ui {
class factor;
}

class factor : public QDockWidget
{
    Q_OBJECT

public:
    explicit factor(QWidget *parent = nullptr);
    ~factor();

private:
    Ui::factor *ui;
};

#endif // FACTOR_H
