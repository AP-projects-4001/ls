#ifndef FACTOR_H
#define FACTOR_H

#include <QDockWidget>
#include "QVector"
namespace Ui {
class factor;
}

class factor : public QDockWidget
{
    Q_OBJECT

public:
    explicit factor(QWidget *parent = nullptr);
    ~factor();
    void show_item(int index);

private slots:
    void on_pushButton_next_clicked();

    void on_pushButton_previous_clicked();

private:
    Ui::factor *ui;
    QVector <int> ind;
    int now{0};
};

#endif // FACTOR_H
