#include "import.h"
#include "ui_import.h"
#include "foods.h"
Import::Import(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Import)
{
    ui->setupUi(this);
}

Import::~Import()
{
    delete ui;
}


void Import::on_pushButton_clicked()
{
    QString type, id, name;
    double price, factor;
    int amount;
    QDate ProduceTime;
    QDate ValidTime;
    QDate CutTime;
    type = ui->Type->text();
    id = ui->Id->text();
    name = ui->Name->text();
    price = ui->Price->text().toDouble();
    factor = ui->factor->text().toDouble();
    amount = ui->Amount->text().toDouble();
    ProduceTime.setDate(ui->Pyear->text().toInt(),ui->Pmonth->text().toInt(),ui->Pday->text().toInt());
    ValidTime.setDate(ui->Vyear->text().toInt(),ui->Vmonth->text().toInt(),ui->Vday->text().toInt());
    CutTime.setDate(ui->Cyear->text().toInt(),ui->Cmonth->text().toInt(),ui->Cday->text().toInt());

}
