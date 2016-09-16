#include "tokencharge.h"
#include "ui_tokencharge.h"
#include "controller.h"
#include "vip.h"
#include "QtWidgets"

TokenCharge::TokenCharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TokenCharge)
{
    ui->setupUi(this);
}

TokenCharge::~TokenCharge()
{
    delete ui;
}

void TokenCharge::on_pushButton_clicked()
{
    VIP* vip;
    int check;

    vip = (VIP*)Controller::GetInstance()->GetCurrentuser();
    check = vip->TokenCharging(ui->tokenamount->text().toInt());

    if(check == 1)
        QMessageBox::information(this,tr("info"),tr("Charging Successfully!"),QMessageBox::Yes);
    else if(check == -1)
        QMessageBox::warning(this,tr("Warning"),tr("Invalid Amount!"),QMessageBox::Yes);
    else
        QMessageBox::warning(this,tr("Warning"),tr("Charging Failed!"),QMessageBox::Yes);

}
