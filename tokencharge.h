#ifndef TOKENCHARGE_H
#define TOKENCHARGE_H

#include <QDialog>

namespace Ui {
class TokenCharge;
}

class TokenCharge : public QDialog
{
    Q_OBJECT

public:
    explicit TokenCharge(QWidget *parent = 0);
    ~TokenCharge();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TokenCharge *ui;
};

#endif // TOKENCHARGE_H
