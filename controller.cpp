#include "controller.h"
#include <QVector>
#include "user.h"
#include "seller.h"
#include "buyer.h"
#include <QDateTime>
#include "vip.h"

 int Controller::login(QString usrname, QString password)
 {
     QVector<User*>::iterator track;
     for(track = userlist.begin(); track != userlist.end(); track++)
     {
         if(usrname==(*track)->GetUsrname()&&password==(*track)->GetPassword())
         {
             //Currentuser = *track;
             Controller::GetInstance()->Setcurrentuser(*track);
             if((*track)->Getidentity() == "buyer")
                 return 1;
             else if((*track)->Getidentity() == "seller")
                 return 2;
             else
                 return 3;
         }
     }
     return 0;
 }

 void Controller::Add_User(User* user)
 {
     userlist.push_back(user);
 }



 void Controller::Add_Goods(Goods* good)
 {
     goodlist.push_back(good);
 }

QVector<Goods*>& Controller::GetGoodsList()
{
    return goodlist;
}

int Controller::GetGoodsamount()
{
    QVector<Goods*>::iterator track;
    int count = 0;
    for(track = goodlist.begin(); track != goodlist.end(); track++)
        count++;
    return count;
}

QString Controller::Getcurrentid()
{
    return currentid;
}

void Controller::Setcurrentid(QString id)
{
   currentid = id;

}

int Controller::checkid(QString id)
{
    QVector<Goods*>::iterator track;
    for(track = this->GetGoodsList().begin(); track != this->GetGoodsList().end(); track++)
    {
        if(id == (*track)->Getid())
           return 0;
    }
    return 1;
}

User* Controller::GetCurrentuser()
{
    return this->currentusr;
}

void Controller::Setcurrentuser(User* usr)
{
    this->currentusr = usr;
}

Controller* Controller::control = new Controller();
Controller* Controller::GetInstance(){
    return control;
}
