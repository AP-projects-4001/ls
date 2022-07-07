#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "QListWidgetItem"
#include "QVector"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    void show_item();
    static QVector<int> vec_id_kala;
private slots:
    void on_listWidget_user_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_commodity_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_log_out_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
