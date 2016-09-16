#include "electronics.h"
#include "foods.h"
#include "qdatetime.h"

Electronics::Electronics(QString id, QString name, int amount, double price, Seller* owner, QDate* valid_time, QDate* produce_time, double reduce_factor):
    Goods(id, name, amount, price, owner)
{
    this->valid_time = valid_time;
    this->produce_time = produce_time;
    this->reduce_factor = reduce_factor;
}

double Electronics::Getcurrentprice()
{
    QDate currentdate = QDate::currentDate();
    int days = this->produce_time->daysTo(currentdate);
    double mid = (1500/((double)days+1))+1/(this->reduce_factor);
    int price = (int) this->price*(1-1/mid);
    return (double)price;
}

double Electronics::Getfactor()
{
    return this->reduce_factor;
}

int Electronics::CheckValidable()
{
    QDate currentdate = QDate::currentDate();
    if(currentdate > *(this->valid_time))
        return 0;
    return 1;
}

QString Electronics::GetType()
{
    return "Electronics";
}
