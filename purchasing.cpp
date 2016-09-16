#include "purchasing.h"
#include "ui_purchasing.h"
#include "controller.h"
#include "buyer.h"
#include "QtWidgets"
Purchasing::Purchasing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Purchasing)
{
    ui->setupUi(this);
}

Purchasing::~Purchasing()
{
    delete ui;
}

void Purchasing::on_submitBtn_clicked()
{
    int amount = ui->amount->text().toInt();
    QString id = ui->goodsid->text();
    Buyer* consumer;
    consumer =(Buyer*)Controller::GetInstance()->GetCurrentuser();
    int check = consumer->Purchasing(id,amount);

    if(check == 1)
        QMessageBox::warning(this,tr("Congradulation"),tr("Purchasing Successfully!"),QMessageBox::Yes);
    else if(check == -1)
        QMessageBox::warning(this,tr("Warning"),tr("Purchasing failed! This kind of good is obsoleted!"),QMessageBox::Yes);
    else
        QMessageBox::warning(this,tr("Warning"),tr("Purchasing failed! Please check the input of your id or amount."),QMessageBox::Yes);
    close();
}
