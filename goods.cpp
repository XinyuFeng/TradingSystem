#include "goods.h"
#include "seller.h"

Goods::Goods(QString id, QString name, int amount, double price, Seller* owner)
{
    this->id = id;
    this->name = name;
    this->amount = amount;
    this->price = price;
    this->owner = owner;
}

double Goods::GetTotalprice()
{
    return (this->amount) * (this->price);
}

double Goods::Getcurrentprice()
{
}

Goods::~Goods()
{

}

QString Goods::GetName()
{
    return this->name;
}

QString Goods::Getid()
{
    return this->id;
}

int Goods::Getamount()
{
    return this->amount;
}

double Goods::Getprice()
{
    return this->price;
}

QString Goods::Getownername()
{
    return this->owner->GetUsrname();
}

Seller* Goods::Getowner()
{
    return this->owner;
}

void Goods::fixamount(int amount)
{
    this->amount -= amount;
}

int Goods::CheckValidable()
{

}

QString Goods::GetType()
{
    return "Goods";
}
