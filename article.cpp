#include "article.h"
#include "Global.h"
article::article(int type,QString name,QString image_file, QString Seller_username, QString Brand_name, QString Color, int Weight, int Price, int Stock )
{
    this->name=name;
    image_File=image_file;
    seller_username=Seller_username;
    brand_name=Brand_name;
    color=Color;
    weight=Weight;
    price=Price;
    stock=Stock;
    id=Global::get_number_of_article();
    this->type=type;
}

void article::set(int type,QString name,QString image_file, QString Seller_username, QString Brand_name, QString Color, int Weight, int Price, int Stock , int Id , int Number_sold)
{
    this->name=name;
    image_File=image_file;
    seller_username=Seller_username;
    brand_name=Brand_name;
    color=Color;
    weight=Weight;
    price=Price;
    stock=Stock;
    id=Id;
    number_sold=Number_sold;
    this->type=type;
}

void article::set_stock(int x)
{
    stock=x;
}

void article::set_Price(int x)
{
    price=x;
}

void article::set_number_sold(int x)
{
    number_sold=x;
}

QString article::get_image_file()
{
    return image_File;
}

QString article::get_seller_username()
{
    return seller_username;
}

QString article::get_brand_name()
{
   return brand_name;
}

QString article::get_color()
{
    return color;
}

int article::get_weight()
{
    return weight;
}

int article::get_price()
{
    return price;
}

int article::get_stock()
{
    return stock;
}

int article::get_id()
{
    return id;
}

int article::get_number_sold()
{
    return number_sold;
}

int article::get_type()
{
    return type;
}

QString article::get_name()
{
    return name;
}

void article::setImage_File(const QString &newImage_File)
{
    image_File = newImage_File;
}
