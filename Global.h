#ifndef GLOBAL_H
#define GLOBAL_H
#include "QVector"
#include "Person.h"
#include "article.h"
#include "fstream"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <iostream>
#include <QString>
#include "sporting_goods.h"
#include "cloths.h"
class Global{
public:
    static QVector <Person> vec_person;
    static Person Active_person;
    static QVector<cloths> vec_article_cloths;
    static QVector<Sporting_goods> vec_article_sporting_goods;
    static QVector <QPair<QPair<int,QString> , QPair<QString , int>>> vec_of_Buyer;// id usernaem date  price
    static QVector<int> Shopping_cart;
    void load();
    void save();
    void load_article();
    void save_article();
    void save_buyer();
    void load_buyer();
    static int serch_id_cloths(int id);
    static int serch_id_sporting_goods(int id);


    static int get_number_of_article();

private:
    static int number_of_article;

};
#endif // GLOBAL_H
