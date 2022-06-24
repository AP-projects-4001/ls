
#ifndef GLOBAL_H
#define GLOBAL_H
#include "QVector"
#include "Person.h"
#include "fstream"
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <iostream>
#include <QString>
class Global{
public:
    static QVector <Person> vec_person;
    static Person Active_person;
    void load()
    {

        Global glob;
        QFile file("save.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        else
        {
            QTextStream stream(&file);
            std::string x , y;
            std::fstream in("save.txt", std::ios::in);

            std::string name, username, password, password2, phone, address, mail ,type , ban;
            while (getline(in, name) && getline(in, username) && getline(in, phone) && getline(in, address) && getline(in, password) && getline(in, mail), getline(in, ban) && getline(in, type))
            {
                Person x;
                x.set( QString::fromStdString(name), QString::fromStdString(username), QString::fromStdString(phone), QString::fromStdString(address), QString::fromStdString(password),QString::fromStdString(mail),stoi(ban), stoi(type));
                glob.vec_person.push_back(x);
            }
            in.close();
        }
        file.close();
        if(glob.vec_person.size()==0)
        {
            std::string x = "Admin", y = "Admin.gmail.com";
            Person admin;
            admin.set(QString::fromStdString(x), QString::fromStdString(x), QString::fromStdString(x), QString::fromStdString(x), QString::fromStdString(x), QString::fromStdString(y), 0, 0);
            save();
        }
    }

    void save()
    {
        Global glob;
        std::fstream out("save.txt", std::ios::out);
        for (int i = 0; i < glob.vec_person.size(); i++)
        {
            out << glob.vec_person[i].get_name().toStdString() << "\n"
                << glob.vec_person[i].get_user_name().toStdString() << "\n"
                << glob.vec_person[i].get_phone_number().toStdString() << "\n"
                << glob.vec_person[i].get_address().toStdString() << "\n"
                << glob.vec_person[i].get_password().toStdString() << "\n"
                << glob.vec_person[i].get_Mail().toStdString() << "\n"
                << glob.vec_person[i].get_ban() << "\n"
                << glob.vec_person[i].get_type() << "\n";
        }
        out.close();
    }

};
#endif // GLOBAL_H
