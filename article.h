#ifndef ARTICLE_H
#define ARTICLE_H
#include "QFile"
#include "QVector"
#include "QPair"
class article {
public:
    article(){}
    article(int type,QString name,QString image_file , QString Seller_username , QString Brand_name  , QString Color , int Weight , int Price , int Stock=0);
    void set(int type,QString name,QString image_file , QString Seller_username , QString Brand_name  , QString Color , int Weight , int Price , int Stock , int id , int number_sold=0 ) ;

    void set_stock(int x);
    void set_Price(int x);
    void set_number_sold(int x);

    QString get_image_file();
    QString get_seller_username();
    QString get_brand_name();
    QString get_color();
    int get_weight();
    int get_price();
    int get_stock();
    int get_id();
    int get_number_sold();
    int get_type();
    QString get_name();

    void setImage_File(const QString &newImage_File);

protected:
    int type;//0 for cloths 1 for sporting_goods
    QString name;
    QString image_File;
    QString seller_username;
    QString brand_name;
    QString color;
    int weight;
    int price;
    int stock;
    int id;
    int number_sold;
};

#endif // ARTICLE_H
