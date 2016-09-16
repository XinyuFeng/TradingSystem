#include "buyer.h"
#include <QtWidgets>
#include "controller.h"
#include "goods.h"
#include "seller.h"
Buyer::Buyer(QString id, QString username, QString password, double balance):
    User(id, username, password, balance)
{
}

void Buyer::BalanceCharging(double charge)//The charging function
{
    this->balance += charge;
}

QString Buyer::Getidentity()
{
    return "buyer";
}

QVector<Goods*>& Buyer::GetGoodsList()
{
    return Controller::GetInstance()->GetGoodsList();
}

int Buyer::Purchasing(QString id, int amount) //The purchasing function
{
    QVector<Goods*>::iterator track,selftrack;
    QVector<Goods*>&goodslist = this->GetGoodsList();
    double Totalprice;

    for(track = goodslist.begin(); track != goodslist.end(); track++)
    {
        if(id == (*track)->Getid())
        {
            if(!(*track)->CheckValidable())
                return -1;
            Totalprice = (*track)->Getcurrentprice()*amount;
            if(((*track)->Getamount() >= amount)&&(this->balance >= Totalprice))
            {
                this->balance -= (Totalprice*(1-0.1*this->GetLevel()));//If current user is VIP, this can reduce the cost of him considering his level
                if(this->GetLevel() > 0)
                    this->SetToken();
                (*track)->Getowner()->Getprofit(Totalprice);
                if((*track)->Getamount() == amount)
                {
                    QVector<Goods*>&ownerlist = (*track)->Getowner()->GetGoodsList();
                    for(selftrack = ownerlist.begin(); selftrack != ownerlist.end(); selftrack++)
                   {
                        if(id == (*selftrack)->Getid())
                        {
                            ownerlist.erase(selftrack);
                            break;
                        }
                    }
                    goodslist.erase(track);
                }
                else
                   (*track)->fixamount(amount);
                return 1;
            }
        }
    }
    return 0;
}

int Buyer::GetLevel()
{
    return 0;
}
void Buyer::SetToken()
{
    return;
}
