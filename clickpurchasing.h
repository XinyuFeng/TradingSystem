#ifndef CLICKPURCHASING_H
#define CLICKPURCHASING_H

#include <QDialog>

namespace Ui {
class ClickPurchasing;
}

class ClickPurchasing : public QDialog
{
    Q_OBJECT

public:
    explicit ClickPurchasing(QWidget *parent = 0);
    ~ClickPurchasing();

private slots:
    void on_submit_clicked();

private:
    Ui::ClickPurchasing *ui;
};

#endif // CLICKPURCHASING_H
