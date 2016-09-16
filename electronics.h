#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include "goods.h"
#include <QObject>
#include "qdatetime.h"

class Electronics: public Goods
{

public:
    Electronics(QString, QString, int, double, Seller*, QDate*, QDate*, double);
    virtual double Getcurrentprice();
    double Getfactor();
    virtual int CheckValidable();
    virtual QString GetType();
private:
    QDate* valid_time;
    QDate* produce_time;
    double reduce_factor;
};

#endif // ELECTRONICS_H
