#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "goods.h"
#include "QTreeWidgetItem"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void ItemBuilding(Goods*, QTreeWidgetItem*);
    void InitTree(QVector<Goods*>&, int);
private slots:
    void on_account_clicked();

    void on_logout_clicked();

    void on_chargingBtn_clicked();

    void on_purchasingBtn_clicked();

    void on_showgoods_clicked();

    void on_Import_clicked();
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_yourgoods_clicked();

    void on_tokencharge_clicked();

public slots:
    void update_time();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
