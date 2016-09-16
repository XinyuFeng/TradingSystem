#ifndef DAILYIMPORTING_H
#define DAILYIMPORTING_H

#include <QDialog>

namespace Ui {
class DailyImporting;
}

class DailyImporting : public QDialog
{
    Q_OBJECT

public:
    explicit DailyImporting(QWidget *parent = 0);
    ~DailyImporting();
    void Importing();
private slots:
    void on_pushButton_clicked();

private:
    Ui::DailyImporting *ui;
};

#endif // DAILYIMPORTING_H
