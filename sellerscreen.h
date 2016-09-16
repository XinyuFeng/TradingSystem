#ifndef SELLERSCREEN_H
#define SELLERSCREEN_H

#include <QDialog>
#include "goods.h"
#include "qtreewidget.h"
namespace Ui {
class SellerScreen;
}

class SellerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SellerScreen(QWidget *parent = 0);
    ~SellerScreen();
     void FoodBuilding(Goods*, QTreeWidgetItem*, int);
     void ElectronicBuilding(Goods*, QTreeWidgetItem*, int);
     void DailyUseBuilding(Goods*, QTreeWidgetItem*, int);
private slots:
     void on_Goods_clicked();

     void on_yourgoods_clicked();

     void on_purchasing_clicked();

     void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

     void on_Import_clicked();

     void on_account_clicked();

     void on_charging_clicked();

     void on_logout_clicked();

private:
    Ui::SellerScreen *ui;
};

#endif // SELLERSCREEN_H
