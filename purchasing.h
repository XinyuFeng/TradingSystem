#ifndef PURCHASING_H
#define PURCHASING_H

#include <QDialog>

namespace Ui {
class Purchasing;
}

class Purchasing : public QDialog
{
    Q_OBJECT

public:
    explicit Purchasing(QWidget *parent = 0);
    ~Purchasing();

private slots:
    void on_submitBtn_clicked();

private:
    Ui::Purchasing *ui;
};

#endif // PURCHASING_H
