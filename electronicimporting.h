#ifndef ELECTRONICIMPORTING_H
#define ELECTRONICIMPORTING_H

#include <QDialog>

namespace Ui {
class ElectronicImporting;
}

class ElectronicImporting : public QDialog
{
    Q_OBJECT

public:
    explicit ElectronicImporting(QWidget *parent = 0);
    ~ElectronicImporting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ElectronicImporting *ui;
};

#endif // ELECTRONICIMPORTING_H
