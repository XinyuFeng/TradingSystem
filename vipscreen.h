#ifndef VIPSCREEN_H
#define VIPSCREEN_H

#include <QDialog>

namespace Ui {
class VIPScreen;
}

class VIPScreen : public QDialog
{
    Q_OBJECT

public:
    explicit VIPScreen(QWidget *parent = 0);
    ~VIPScreen();
    void ShowAccount();
    void ShowAllGoods();
private slots:
    void on_chargingBtn_clicked();

    void on_account_clicked();

    void on_purchasingBtn_clicked();

    void on_showgoods_clicked();

    void on_logout_clicked();

    void on_TokenCharging_clicked();

private:
    Ui::VIPScreen *ui;
};

#endif // VIPSCREEN_H
