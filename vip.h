#ifndef VIP_H
#define VIP_H
#include "buyer.h"

class VIP: public Buyer
{
public:
    VIP(QString, QString, QString, double, int, int);
    int TokenCharging(int);
    virtual QString Getidentity();
    virtual QVector<Goods*>& GetGoodsList();
    virtual int GetLevel();
    virtual void SetToken();
    virtual int GetToken();
protected:
    int level;
    int token;
};

#endif // VIP_H
