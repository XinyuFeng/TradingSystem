#include "charging.h"
#include <QtWidgets>
#include "ui_charging.h"
#include "controller.h"
#include "buyer.h"

Charging::Charging(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Charging)
{
    ui->setupUi(this);
}

Charging::~Charging()
{
    delete ui;
}

void Charging::on_submit_clicked()
{
    QString charge;
    double value;

    charge = ui->chargenum->text();

    if(charge=="0.00")
    {
        QMessageBox::warning(this,tr("info"),tr("please input the amount you want to charge!"),QMessageBox::Yes);
        return;
    }
    value = charge.toDouble();
    Buyer* buyer;
    buyer = (Buyer*)Controller::GetInstance()->GetCurrentuser();
    buyer->BalanceCharging(value);
    QMessageBox::warning(this,tr("info"),tr("charging successfully!"),QMessageBox::Yes);
    close();
}
