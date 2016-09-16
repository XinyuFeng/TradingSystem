#ifndef FOODSIMPORTING_H
#define FOODSIMPORTING_H

#include <QDialog>

namespace Ui {
class FoodsImporting;
}

class FoodsImporting : public QDialog
{
    Q_OBJECT

public:
    explicit FoodsImporting(QWidget *parent = 0);
    ~FoodsImporting();
    void Importing();
private slots:
    void on_pushButton_clicked();

private:
    Ui::FoodsImporting *ui;
};

#endif // FOODSIMPORTING_H
