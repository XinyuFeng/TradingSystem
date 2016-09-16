#include "vip.h"
#include "buyer.h"
#include "controller.h"

VIP::VIP(QString id, QString username, QString password, double balance, int level, int token):
    Buyer(id, username, password, balance)
{
    this->level = level;
    this->token = token;
}

int VIP::TokenCharging(int amount)
{
    if(amount > this->token)
        return -1;
    else if(amount == 0)
        return 0;
    else
    {
        this->balance += 0.01*amount;
        this->token -= amount;
        return 1;
    }
}

QVector<Goods*>& VIP::GetGoodsList()
{
    return Controller::GetInstance()->GetGoodsList();
}

QString VIP::Getidentity()
{
    return "VIP";
}

int VIP::GetLevel()
{
    return this->level;
}

int VIP::GetToken()
{
    return this->token;
}

void VIP::SetToken()
{
    this->token += 10;
}
