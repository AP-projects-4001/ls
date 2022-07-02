#ifndef ADD_KALA_H
#define ADD_KALA_H

#include <QDialog>

namespace Ui {
class add_kala;
}

class add_kala : public QDialog
{
    Q_OBJECT

public:
    explicit add_kala(QWidget *parent = nullptr);
    ~add_kala();

private:
    Ui::add_kala *ui;
};

#endif // ADD_KALA_H
