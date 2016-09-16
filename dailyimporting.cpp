#include "dailyimporting.h"
#include "ui_dailyimporting.h"
#include "controller.h"
#include "qdatetime.h"
#include <QtWidgets>
#include "seller.h"
#include "dailyuse.h"

DailyImporting::DailyImporting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailyImporting)
{
    ui->setupUi(this);
}

DailyImporting::~DailyImporting()
{
    delete ui;
}

void DailyImporting::Importing()
{
    QString id, name;
    double price, factor;
    int amount;
    Seller* usr;
    QDate* ProduceTime = new QDate;
    QDate* ValidTime = new QDate;
    QDate* CutTime = new QDate;

    usr = (Seller*) Controller::GetInstance()->GetCurrentuser();
    id = ui->Id->text();
    name = ui->Name->text();
    price = ui->Price->text().toDouble();
    factor = ui->factor->text().toDouble();
    amount = ui->Amount->text().toInt();

    ProduceTime->setDate(ui->Pyear->text().toInt(),ui->Pmonth->text().toInt(),ui->Pday->text().toInt());
    ValidTime->setDate(ui->Vyear->text().toInt(),ui->Vmonth->text().toInt(),ui->Vday->text().toInt());
    CutTime->setDate(ui->Cyear->text().toInt(),ui->Cmonth->text().toInt(),ui->Cday->text().toInt());

    DailyUse* dailyuse = new DailyUse(id, name, amount, price, usr, ValidTime, ProduceTime, factor, CutTime);

    if(!Controller::GetInstance()->checkid(id))
        QMessageBox::warning(this,tr("Warning"),tr("The id has been used!"),QMessageBox::Yes);

    else if(!(*ProduceTime <= (*CutTime)&& *CutTime <= (*ValidTime)))
        QMessageBox::warning(this,tr("Warning"),tr("invalid time setting!"),QMessageBox::Yes);

    else if(usr->Imported(dailyuse))
    {
        QMessageBox::warning(this,tr("Congradulation"),tr("Importing Successfully!"),QMessageBox::Yes);
        close();
    }
    else
        QMessageBox::warning(this,tr("Warning"),tr("Importing Failed!"),QMessageBox::Yes);
}

void DailyImporting::on_pushButton_clicked()
{
    QDate ProduceTime;
    QDate ValidTime;
    QDate CutTime;

    ProduceTime.setDate(ui->Pyear->text().toInt(),ui->Pmonth->text().toInt(),ui->Pday->text().toInt());
    ValidTime.setDate(ui->Vyear->text().toInt(),ui->Vmonth->text().toInt(),ui->Vday->text().toInt());
    CutTime.setDate(ui->Cyear->text().toInt(),ui->Cmonth->text().toInt(),ui->Cday->text().toInt());

    if(!(ProduceTime <= (CutTime)&& CutTime <= (ValidTime)))
        QMessageBox::warning(this,tr("Warning"),tr("invalid time setting!"),QMessageBox::Yes);
    else
        Importing();
}


