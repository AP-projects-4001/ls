#ifndef PERSON_H
#define PERSON_H
#pragma once
#include "QString"
class Person {
public:

    Person(){}
    Person(QString Name, QString User_name, QString Phone_number, QString Address, QString Password, QString Mail, bool Ban, int Type , int Moneybags=0)
    {
        name = Name;
        user_name = User_name;
        phone_number = Phone_number;
        address = Address;
        password = Password;
        ban = Ban;
        type = Type;
        mail = Mail;
        moneybags=Moneybags;
    }
    void set(QString Name, QString User_name, QString Phone_number, QString Address, QString Password, QString Mail, bool Ban, int Type ,int Moneybags=0)
    {
        name = Name;
        user_name = User_name;
        phone_number = Phone_number;
        address = Address;
        password = Password;
        ban = Ban;
        type = Type;
        mail = Mail;
        moneybags=Moneybags;
    }

    void set_password(QString Password) { password = Password;}
    QString get_name() { return name;}
    QString get_user_name() { return user_name;}
    QString get_phone_number() { return phone_number;}
    QString get_address() { return address;}
    QString get_password() { return password;}
    QString get_Mail() { return mail;}
    bool get_ban() { return ban;}
    int get_type() { return type;}
    int get_moneybags(){return moneybags;}

private:
    QString name;
    QString user_name;
    QString phone_number;
    QString address;
    QString password;
    QString mail;
    bool ban;
    int type;
    int moneybags{0};
};
#endif // PERSON_H
