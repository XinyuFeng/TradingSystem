#include "widget.h"
#include "ui_widget.h"
#include "controller.h"
#include "mydialog.h"
#include "logindlg.h"
#include "charging.h"
#include "QtWidgets"
#include "purchasing.h"
#include "seller.h"
#include "importtype.h"
#include "qtimer.h"
#include "clickpurchasing.h"
#include "vip.h"
#include "tokencharge.h"



Widget::Widget(QWidget *parent) :
     QWidget(parent),
     ui(new Ui::Widget)
{
     ui->setupUi(this);
     //this->setStyleSheet("border-radius:10px;");
     //setStyleSheet ("border-radius:10px;");
     ui->treeWidget->setHeaderLabels(QStringList()<<"Id"<<"Name"<<"Original Price"<<"Current Price"<<"Amount"<<"Sellername");
     this->setWindowFlags(Qt::FramelessWindowHint);


     User* usr = Controller::GetInstance()->GetCurrentuser();
     if(usr->Getidentity() == "VIP")
     {
         VIP* usr = (VIP*)Controller::GetInstance()->GetCurrentuser();
         QString t;

         t = QString::number(usr->GetLevel(),10);
         ui->level->setText(t);
         ui->token->setText(QString::number(usr->GetToken(),10));
         ui->Title->setText("Welcome to Trading System of VIP Mode");
     }
     else
     {
         ui->labellevel->close();
         ui->token->close();
         ui->labeltoken->close();
         ui->level->close();
         ui->tokencharge->close();
     }
     if(usr->Getidentity() == "seller")
     {
         ui->Title->setText("Welcome to Trading System of Seller Mode");
         ui->purchasingBtn->close();
         ui->chargingBtn->close();
     }
     else
     {
         if(usr->Getidentity() == "buyer")
             ui->Title->setText("Welcome to Trading System of Buyer Mode");
         ui->yourgoods->close();
         ui->Import->close();
     }
     QString s = QString::number(usr->Getbalance());

     ui->id->setText(usr->Getid());
     ui->balance->setText(s);
     ui->name->setText(usr->GetUsrname());

     QDate cdate=QDate::currentDate();  //The time and calendar setting
     QTextCharFormat TodayFormat;
     QTimer *time = new QTimer(this);

     TodayFormat.setForeground(Qt::blue);
     ui->calendarWidget->setDateTextFormat(cdate,TodayFormat);
     ui->timeEdit->setDateTime(QDateTime::currentDateTime());
     connect( time, SIGNAL(timeout()), this, SLOT(update_time()) );
     time->start(1000);

     ui->calendarWidget->setDateEditEnabled(0);
     ui->calendarWidget->showToday();

     //==========实现上边角圆弧==========
         QRect rect = this->rect();
         QPainterPath path;
         path.addRoundRect(rect,5,5);
         QPolygon polygon= path.toFillPolygon().toPolygon();//获得这个路径上的所有的点
         QRegion region(polygon);//根据这些点构造这个区域
         setMask(region);
         //==========实现上边角圆弧==========

}
void Widget::update_time()
{
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
}


Widget::~Widget()
{
    delete ui;
}

void Widget::ItemBuilding(Goods* good, QTreeWidgetItem* item)
{
    QTreeWidgetItem *childfood = new QTreeWidgetItem (item);

    childfood->setText(0,good->Getid());
    childfood->setText(1,good->GetName());
    childfood->setText(2,QString::number(good->Getprice()));
    childfood->setText(3,QString::number(good->Getcurrentprice()));
    childfood->setText(4,QString::number(good->Getamount(),10));
    childfood->setText(5,good->Getownername());
}

void Widget::on_account_clicked()
{
     User* usr = Controller::GetInstance()->GetCurrentuser();
     if(usr->Getidentity() == "VIP")
     {
         VIP* usr = (VIP*)Controller::GetInstance()->GetCurrentuser();
         QString t;
         t = QString::number(usr->GetLevel(),10);
         ui->level->setText(t);
         ui->token->setText(QString::number(usr->GetToken(),10));
     }
     QString s;
     s = QString::number(usr->Getbalance());
     ui->id->setText(usr->Getid());
     ui->balance->setText(s);
     ui->name->setText(usr->GetUsrname());

}

void Widget::on_logout_clicked()
{
    close();
    loginDlg login;
    login.exec();
}

void Widget::on_chargingBtn_clicked()
{
    Charging charge(this);
    charge.exec();
}

void Widget::on_purchasingBtn_clicked()
{
    Purchasing purchase(this);
    purchase.exec();
}

void Widget::on_showgoods_clicked()
{
    QVector<Goods*>&list = Controller::GetInstance()->GetGoodsList();
    int count = Controller::GetInstance()->GetGoodsamount();
    InitTree(list,count);
}


void Widget::on_Import_clicked()
{
    ImportType Type;
    Type.exec();
}

void Widget::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(Controller::GetInstance()->GetCurrentuser()->Getidentity() == "seller")
        return;
    QTreeWidgetItem *current = item->parent();
    if(current)
    {
        Controller::GetInstance()->Setcurrentid(item->text(0));
        ClickPurchasing dlg;
        dlg.exec();
    }
}

void Widget::on_yourgoods_clicked()
{
   Seller *seller = (Seller*)Controller::GetInstance()->GetCurrentuser();
   QVector<Goods*>&list = seller->GetGoodsList();
   int count = seller->GetGoodsamount();
   InitTree(list,count);
}

void Widget::InitTree(QVector<Goods*>&list, int count)
{
   QTreeWidgetItem* food = new QTreeWidgetItem(QStringList()<<"Food");
   QTreeWidgetItem* electronic = new QTreeWidgetItem(QStringList()<<"Electronical Devices");
   QTreeWidgetItem* dailyuse = new QTreeWidgetItem(QStringList()<<"Daily Item");
   ui->treeWidget->clear();
   ui->treeWidget->close();
   ui->treeWidget->addTopLevelItem(food);
   ui->treeWidget->addTopLevelItem(electronic);
   ui->treeWidget->addTopLevelItem(dailyuse);
   for(int i = 0; i < count; i++)
   {
       if(list[i]->GetType() == "Foods")
       {
           ItemBuilding(list[i],food);
       }
       else if(list[i]->GetType() == "Electronics")
       {
           ItemBuilding(list[i],electronic);
       }
       else
       {
           ItemBuilding(list[i],dailyuse);
       }
   }
   ui->treeWidget->show();
}

void Widget::on_tokencharge_clicked()
{
    TokenCharge token;
    token.exec();
}
