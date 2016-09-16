#include "importtype.h"
#include "ui_importtype.h"
#include "foodsimporting.h"
#include "electronicimporting.h"
#include "dailyimporting.h"

ImportType::ImportType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportType)
{
    ui->setupUi(this);
}

ImportType::~ImportType()
{
    delete ui;
}

void ImportType::on_Submit_clicked()
{
    close();
    QString type = ui->Select->currentText();

    if(type == "Foods")
    {
        FoodsImporting food;
        food.exec();
    }
    else if(type == "Electronics")
    {
        ElectronicImporting electronic;
        electronic.exec();
    }
    else
    {
        DailyImporting Daily;
        Daily.exec();
    }
}
