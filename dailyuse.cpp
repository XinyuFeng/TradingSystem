#include "dailyuse.h"
#include "qdatetime.h"

DailyUse::DailyUse(QString id, QString name, int amount, double price, Seller* owner, QDate* valid_time, QDate* produce_time, double reduce_factor, QDate* cut_time):
    Goods(id, name, amount, price, owner)
{
    this->valid_time = valid_time;
    this->produce_time = produce_time;
    this->reduce_factor = reduce_factor;
    this->cut_time = cut_time;
}

double DailyUse::Getcurrentprice()
{
    QDate currentdate = QDate::currentDate();
    if((*(this->cut_time) < currentdate) && this->reduce_factor > 0)
    {
        return this->price * (1 - this->reduce_factor);
    }
    else
        return this->price;
}

double DailyUse::Getfactor()
{
    return this->reduce_factor;
}

QDate* DailyUse::Getcuttime()
{
    return this->cut_time;
}

int DailyUse::CheckValidable()
{
    QDate currentdate = QDate::currentDate();
    if(currentdate > *(this->valid_time))
        return 0;
    return 1;
}

QString DailyUse::GetType()
{
    return "DailyUse";
}
