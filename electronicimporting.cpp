#include "electronicimporting.h"
#include "ui_electronicimporting.h"
#include "electronics.h"
#include "controller.h"
#include "qdatetime.h"
#include <QtWidgets>
#include "seller.h"

ElectronicImporting::ElectronicImporting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElectronicImporting)
{
    ui->setupUi(this);
}

ElectronicImporting::~ElectronicImporting()
{
    delete ui;
}

void ElectronicImporting::on_pushButton_clicked()
{
    QString id, name;
    double price, factor;
    int amount;
    Seller* usr;
    QDate* ProduceTime = new QDate;
    QDate* ValidTime = new QDate;

    usr = (Seller*) Controller::GetInstance()->GetCurrentuser();
    id = ui->Id->text();
    name = ui->Name->text();
    price = ui->Price->text().toDouble();
    factor = ui->factor->text().toDouble();
    amount = ui->Amount->text().toInt();

    ProduceTime->setDate(ui->Pyear->text().toInt(),ui->Pmonth->text().toInt(),ui->Pday->text().toInt());
    ValidTime->setDate(ui->Vyear->text().toInt(),ui->Vmonth->text().toInt(),ui->Vday->text().toInt());

    Electronics* electronic = new Electronics(id, name, amount, price, usr, ValidTime, ProduceTime, factor);

    if(!Controller::GetInstance()->checkid(id))
        QMessageBox::warning(this,tr("Warning"),tr("The id has been used!"),QMessageBox::Yes);

    else if(!(*ProduceTime <= (*ValidTime)))
        QMessageBox::warning(this,tr("Warning"),tr("invalid time setting!"),QMessageBox::Yes);

    else if(usr->Imported(electronic))
    {
        QMessageBox::warning(this,tr("Congradulation"),tr("Importing Successfully!"),QMessageBox::Yes);
        close();
    }
    else
        QMessageBox::warning(this,tr("Warning"),tr("Importing Failed!"),QMessageBox::Yes);

}
