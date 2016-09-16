#include "vipscreen.h"
#include "ui_vipscreen.h"
#include "controller.h"
#include "mydialog.h"
#include "logindlg.h"
#include "charging.h"
#include "QtWidgets"
#include "purchasing.h"
#include "seller.h"
#include "vip.h"
#include "tokencharge.h"

VIPScreen::VIPScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VIPScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

VIPScreen::~VIPScreen()
{
    delete ui;
}

void VIPScreen::on_chargingBtn_clicked()
{
    Charging charge(this);
    charge.exec();
}

void VIPScreen::on_account_clicked()
{
    ShowAccount();
}

void VIPScreen::ShowAccount()
{
    Controller control;
    VIP* usr;
   usr = (VIP*)control.Getcurrentuser();
    ui->listWidget->clear();
    ui->listWidget->addItem(QString("Level: %1").arg(usr->GetLevel()));
    ui->listWidget->addItem(QString("username: %1").arg(usr->GetUsrname()));
    ui->listWidget->addItem(QString("id: %1").arg(usr->Getid()));
    ui->listWidget->addItem(QString("password: %1").arg(usr->GetPassword()));
    ui->listWidget->addItem(QString("balance: %1").arg(usr->Getbalance()));
    ui->listWidget->addItem(QString("Token: %1").arg(usr->GetToken()));


}
void VIPScreen::on_purchasingBtn_clicked()
{
    Purchasing purchase(this);
    purchase.exec();
}

void VIPScreen::on_showgoods_clicked()
{
    ui->listWidget->clear();
    ShowAllGoods();
}

void VIPScreen::ShowAllGoods()
{
    Controller control;
    VIP* usr;
    QVector<Goods*>list;
    list = control.GetGoodsList();
    int count = control.GetGoodsamount();
    for(int i = 0; i < count; i++)
    {
        ui->listWidget->addItem(QString("id: %1").arg(list[i]->Getid()));
        ui->listWidget->addItem(QString("name: %1").arg(list[i]->GetName()));
        ui->listWidget->addItem(QString("original price: %1").arg(list[i]->Getprice()));
        ui->listWidget->addItem(QString("current price: %1").arg(list[i]->Getcurrentprice()));
        ui->listWidget->addItem(QString("amount: %1").arg(list[i]->Getamount()));
        ui->listWidget->addItem(QString("sellername: %1").arg(list[i]->Getownername()));
     }
}

void VIPScreen::on_logout_clicked()
{
    ui->listWidget->clear();
    close();
    loginDlg login;
    login.exec();
}

void VIPScreen::on_TokenCharging_clicked()
{
   TokenCharge token;
   token.exec();
}
