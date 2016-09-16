#ifndef SELLER_H
#define SELLER_H
#include "user.h"
#include <QVector>
#include <QString>

#include "QObject"
class Goods;

class Seller : public User
{
public:
    Seller(QString, QString, QString, double);
    virtual QVector<Goods*>& GetGoodsList();
    void add_personal_goods(Goods*);
    virtual QString Getidentity();
    void Getprofit(double);
    int GetGoodsamount();
    int Imported(Goods*);

protected:
    QVector<Goods*>list;
};

#endif // SELLER_H
