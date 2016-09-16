#include "foods.h"
#include "qdatetime.h"
#include "qstring.h"
#include "qmath.h"

Foods::Foods(QString id, QString name, int amount, double price, Seller* owner, QDate* valid_time, QDate* produce_time, double reduce_factor, QDate* cut_time):
    Goods(id, name, amount, price, owner)
{
    this->valid_time = valid_time;
    this->produce_time = produce_time;
    this->reduce_factor = reduce_factor;
    this->cut_time = cut_time;
}

double Foods::Getcurrentprice()
{
    QDate currentdate = QDate::currentDate();
    double price;
    if((*(this->cut_time) < currentdate) && this->reduce_factor >0 &&currentdate < *(this->valid_time))
    {
        price = this->price * (1 - this->reduce_factor);
        price = round(price);
        return price;
    }
    else
        return this->price;
}

double Foods::Getfactor()
{
    return this->reduce_factor;
}

QDate* Foods::Getcuttime()
{
    return this->cut_time;
}

int Foods::CheckValidable()
{
    QDate currentdate = QDate::currentDate();
    if(currentdate > *(this->valid_time))
        return 0;
    return 1;
}

QString Foods::GetType()
{
    return "Foods";
}
