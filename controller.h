#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "user.h"
#include <QVector>
#include "foods.h"
#include "vip.h"
#include "buyer.h"
#include "seller.h"
#include "electronics.h"
#include "dailyuse.h"

class Controller
{
private:
    Controller()
    {
        QDate* date1 = new QDate(2012,4,4);
        QDate* date2 = new QDate(2013,6,7);
        QDate* date3 = new QDate(2016,7,8);
        VIP* Alessa = new VIP("888","Alessa","123456",1000,3,100);
        Buyer* Administro = new Buyer("123","aaa","123456",3.14);
        Seller* wangqiang = new Seller("666","wangqiang","123456",0.00);
        Seller* liming = new Seller("888","liming","123456",6.77);
        Seller* xiaoming = new Seller("333","xiaoming","123456",3.35);
        Foods* broad = new Foods("111","broad",3,1.00,wangqiang,date2,date1,0.5,date2);
        Foods* tomato = new Foods("222","tomato",5,2.00,liming,date2,date1,0.5,date2);
        Foods* nuts = new Foods("432","nuts",20,6.70,wangqiang,date3,date2,0.3,date2);
        Electronics* iphone = new Electronics("00001","iphone",10,2000.00,wangqiang,date3,date1,0.22);
        DailyUse* soap = new DailyUse("00005","soap",100,10.50,liming,date3,date1,0.3,date1);

        userlist.push_back(Administro);
        userlist.push_back(wangqiang);
        userlist.push_back(liming);
        userlist.push_back(xiaoming);
        userlist.push_back(Alessa);
        goodlist.push_back(broad);
        goodlist.push_back(tomato);
        goodlist.push_back(nuts);
        goodlist.push_back(iphone);
        goodlist.push_back(soap);

        wangqiang->add_personal_goods(broad);
        wangqiang->add_personal_goods(nuts);
        wangqiang->add_personal_goods(iphone);
        liming->add_personal_goods(tomato);
        liming->add_personal_goods(soap);
    }

    static Controller* control;

public:
    int login(QString, QString);
    void Add_User(User*);
    void Add_Goods(Goods*);
    void init();
    QVector<Goods*>& GetGoodsList();
    int GetGoodsamount();
    QString Getcurrentid();
    void Setcurrentid(QString);
    User* GetCurrentuser();
    void Setcurrentuser(User*);
    int checkid(QString);
    static Controller * GetInstance();

private:
    QVector<User*> userlist;
    QVector<Goods*> goodlist;
    User* currentusr;
    QString currentid;

};
#endif // CONTROLLER_H
