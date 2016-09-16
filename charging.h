#ifndef CHARGING_H
#define CHARGING_H

#include <QDialog>

namespace Ui {
class Charging;
}

class Charging : public QDialog
{
    Q_OBJECT

public:
    explicit Charging(QWidget *parent = 0);
    ~Charging();

private slots:
    void on_submit_clicked();

private:
    Ui::Charging *ui;
};

#endif // CHARGING_H
