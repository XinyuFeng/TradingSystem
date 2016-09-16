#ifndef GOODS_H
#define GOODS_H

#include <QObject>
class Seller;
class Goods : public QObject
{

public:

    double GetTotalprice();
    Goods(QString, QString, int, double, Seller*);
    virtual ~Goods();
    virtual double Getcurrentprice();
    virtual int CheckValidable();
    virtual QString GetType();
    QString GetName();
    QString Getid();
    int Getamount();
    double Getprice();
    QString Getownername();
    void fixamount(int);
    Seller* Getowner();
signals:

public slots:

protected:
    QString id;
    QString name;
    int amount;
    double price;
    Seller* owner;

};

#endif // GOODS_H
