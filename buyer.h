#ifndef BUYER_H
#define BUYER_H
#include "user.h"
#include "QString"
class Buyer: public User
{
public:
    Buyer(QString, QString, QString, double);
    void BalanceCharging(double);
    virtual QString Getidentity();
    virtual QVector<Goods*>& GetGoodsList();
    int Purchasing(QString,int);
    virtual int GetLevel();
    virtual void SetToken();
protected:
};

#endif // BUYER_H
