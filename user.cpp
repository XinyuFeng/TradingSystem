#include "user.h"
#include "goods.h"

User::User(QString id, QString username, QString password, double balance)
{
    this->userName = username;
    this->password = password;
    this->id = id;
    this->balance = balance;
}

QString User::GetUsrname()
{
    return this->userName;
}

QString User::GetPassword()
{
    return this->password;
}

QString User::Getid()
{
    return this->id;
}

QString User::Getidentity()
{
    return "user";
}

double User::Getbalance()
{
    return balance;
}


