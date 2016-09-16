#include "sellerscreen.h"
#include "ui_sellerscreen.h"
#include "controller.h"
#include "user.h"
#include "goods.h"
#include "seller.h"
#include "QtWidgets"
#include "clickpurchasing.h"
#include "importtype.h"
#include "charging.h"
#include "logindlg.h"

SellerScreen::SellerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerScreen)
{
    ui->setupUi(this);
    QTreeWidgetItem* food = new QTreeWidgetItem(QStringList()<<"food");
    QTreeWidgetItem* electronic = new QTreeWidgetItem(QStringList()<<"electronic");
    QTreeWidgetItem* dailyuse = new QTreeWidgetItem(QStringList()<<"dailyuse");
    ui->treeWidget->setHeaderLabels(QStringList()<<"id"<<"name"<<"original price"<<"current price"<<"amount"<<"sellername");
    ui->treeWidget->addTopLevelItem(food);
    ui->treeWidget->addTopLevelItem(electronic);
    ui->treeWidget->addTopLevelItem(dailyuse);
    Controller control;
    QVector<Goods*>&list = control.GetGoodsList();
    int count = control.GetGoodsamount();
    for(int i = 0; i < count; i++)
    {
        if(list[i]->GetType() == "Foods")
            FoodBuilding(list[i],food,1);
        else if(list[i]->GetType() == "Electronics")
            ElectronicBuilding(list[i],electronic,1);
        else
            DailyUseBuilding(list[i],dailyuse,1);
    }
    ui->treeWidget->show();

}

void SellerScreen::FoodBuilding(Goods* good, QTreeWidgetItem* food, int check)
{
    QTreeWidgetItem *childfood = new QTreeWidgetItem (food);
    childfood->setText(0,good->Getid());
    childfood->setText(1,good->GetName());
    childfood->setText(2,QString::number(good->Getprice()));
    childfood->setText(3,QString::number(good->Getcurrentprice()));
    childfood->setText(4,QString::number(good->Getamount(),10));
    childfood->setText(5,good->Getownername());
}

void SellerScreen::ElectronicBuilding(Goods* good, QTreeWidgetItem*electronic, int check)
{
    QTreeWidgetItem *childgood = new QTreeWidgetItem (electronic);
    childgood->setText(0,good->Getid());
    childgood->setText(1,good->GetName());
    childgood->setText(2,QString::number(good->Getprice()));
    childgood->setText(3,QString::number(good->Getcurrentprice()));
    childgood->setText(4,QString::number(good->Getamount(),10));
    childgood->setText(5,good->Getownername());
}

void SellerScreen::DailyUseBuilding(Goods* good, QTreeWidgetItem*dailyuse, int check)
{
    QTreeWidgetItem *childgood = new QTreeWidgetItem (dailyuse);
    childgood->setText(0,good->Getid());
    childgood->setText(1,good->GetName());
    childgood->setText(2,QString::number(good->Getprice()));
    childgood->setText(3,QString::number(good->Getcurrentprice()));
    childgood->setText(4,QString::number(good->Getamount(),10));
    childgood->setText(5,good->Getownername());

}

SellerScreen::~SellerScreen()
{
    delete ui;
}

void SellerScreen::on_Goods_clicked()
{
    QTreeWidgetItem* food = new QTreeWidgetItem(QStringList()<<"food");
    QTreeWidgetItem* electronic = new QTreeWidgetItem(QStringList()<<"electronic");
    QTreeWidgetItem* dailyuse = new QTreeWidgetItem(QStringList()<<"dailyuse");
    ui->treeWidget->clear();
    ui->treeWidget->close();
    ui->treeWidget->addTopLevelItem(food);
    ui->treeWidget->addTopLevelItem(electronic);
    ui->treeWidget->addTopLevelItem(dailyuse);
    Controller control;
    QVector<Goods*>&list = control.GetGoodsList();
    int count = control.GetGoodsamount();
    for(int i = 0; i < count; i++)
    {
        if(list[i]->GetType() == "Foods")
            FoodBuilding(list[i],food,1);
        else if(list[i]->GetType() == "Electronics")
            ElectronicBuilding(list[i],electronic,1);
        else
            DailyUseBuilding(list[i],dailyuse,1);
    }
    ui->treeWidget->show();
}


void SellerScreen::on_yourgoods_clicked()
{
     QTreeWidgetItem* food = new QTreeWidgetItem(QStringList()<<"food");
     QTreeWidgetItem* electronic = new QTreeWidgetItem(QStringList()<<"electronic");
     QTreeWidgetItem* dailyuse = new QTreeWidgetItem(QStringList()<<"dailyuse");


    ui->treeWidget->clear();
    ui->treeWidget->close();
    ui->treeWidget->addTopLevelItem(food);
    ui->treeWidget->addTopLevelItem(electronic);
    ui->treeWidget->addTopLevelItem(dailyuse);

    Controller control;
    Seller *seller = (Seller*)control.Getcurrentuser();
    QVector<Goods*>&list = seller->GetGoodsList();
    int count = seller->GetGoodsamount();
    for(int i = 0; i < count; i++)
    {
        if(list[i]->GetType() == "Foods")
        {
            FoodBuilding(list[i],food,0);
        }
        else if(list[i]->GetType() == "Electronics")
        {
            ElectronicBuilding(list[i],electronic,0);
        }
        else
        {
            DailyUseBuilding(list[i],dailyuse,0);
        }
    }
    ui->treeWidget->show();
}

void SellerScreen::on_purchasing_clicked()
{
     QTreeWidgetItem* item = ui->treeWidget->currentItem();



}

void SellerScreen::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)

{
    QTreeWidgetItem *current = item->parent();
    if(current)
    {
        Controller control;
        control.Setcurrentid(item->text(0));
        ClickPurchasing dlg;
        dlg.exec();
    }

}

void SellerScreen::on_Import_clicked()
{
    ImportType Type;
    Type.exec();
}

void SellerScreen::on_account_clicked()
{
    Controller control;
    Seller* usr;
    usr = (Seller*)control.Getcurrentuser();
    QString s,t;
    s = QString::number(usr->Getbalance());
    t = QString::number(usr->GetLevel(),10);
    ui->level->setText(t);
    ui->id->setText(usr->Getid());
    ui->balance->setText(s);
    ui->name->setText(usr->GetUsrname());
}

void SellerScreen::on_charging_clicked()
{
    Charging charge(this);
    charge.exec();
}

void SellerScreen::on_logout_clicked()
{
    close();
    loginDlg login;
    login.exec();
}
