#ifndef DAILYUSE_H
#define DAILYUSE_H
#include "goods.h"
#include <QObject>
#include "qdatetime.h"

class DailyUse: public Goods
{

public:
    DailyUse(QString, QString, int, double, Seller*, QDate*, QDate*, double, QDate*);
    virtual double Getcurrentprice();
    QDate* Getcuttime();
    double Getfactor();
    virtual int CheckValidable();
    virtual QString GetType();
private:
    QDate* valid_time;
    QDate* produce_time;
    double reduce_factor;
    QDate* cut_time;
};

#endif // DAILYUSE_H
