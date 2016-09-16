#include "clickpurchasing.h"
#include "ui_clickpurchasing.h"
#include "controller.h"
#include "buyer.h"
#include "QtWidgets"

ClickPurchasing::ClickPurchasing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClickPurchasing)
{
    ui->setupUi(this);

    QString id;
    id = Controller::GetInstance()->Getcurrentid();
    ui->id->setText(id);
}

ClickPurchasing::~ClickPurchasing()
{
    delete ui;
}

void ClickPurchasing::on_submit_clicked()
{
    QString id;
    id = Controller::GetInstance()->Getcurrentid();

    int amount = ui->amount->text().toInt();
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
