#include "seller.h"
#include "user.h"
#include "goods.h"
#include "controller.h"

Seller::Seller(QString id, QString username, QString password, double balance):
    User(id, username, password, balance)
{
}

QVector<Goods*>& Seller::GetGoodsList()
{
    return this->list;
}

void Seller::add_personal_goods(Goods* good)
{
    this->list.push_back(good);
}


QString Seller::Getidentity()
{
    return "seller";
}

void Seller::Getprofit(double profit)
{
    this->balance += profit;
}

int Seller::GetGoodsamount()
{
    QVector<Goods*>::iterator track;
    int count = 0;

    for(track = this->list.begin(); track != this->list.end(); track++)
        count++;
    return count;
}

int Seller::Imported(Goods* good)
{
    QVector<Goods*>&list = Controller::GetInstance()->GetGoodsList();

    this->list.push_back(good);
    list.push_back(good);
    return 1;

}

