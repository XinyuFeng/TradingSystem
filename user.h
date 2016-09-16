#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QVector>
#include "goods.h"
class Goods;
class User : public QObject
{
public:
    User(QString, QString,QString, double);
     QString GetUsrname();
     QString GetPassword();
     QString Getid();
     double Getbalance();
     //virtual QVector<Goods*>& GetGoodsList();
     virtual QString Getidentity();
signals:

public slots:

protected:
    QString userName;
    QString password;
    QString id;
    double balance;
};
#endif // USER_H
