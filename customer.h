#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include <QVector>
#include <cloths.h>
#include <sporting_goods.h>
#include <add_kala.h>
namespace Ui {
class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    ~customer();
    static QVector<cloths> vec_cloths;
    static QVector<Sporting_goods> vec_sporting;
    static QVector <int> id;

    int getSize_of_widget() const;
    void setSize_of_widget(int newSize_of_widget);
    void show_item();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::customer *ui;
    static int size_of_widget;
};

#endif // CUSTOMER_H
