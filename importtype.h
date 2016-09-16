#ifndef IMPORTTYPE_H
#define IMPORTTYPE_H

#include <QDialog>

namespace Ui {
class ImportType;
}

class ImportType : public QDialog
{
    Q_OBJECT

public:
    explicit ImportType(QWidget *parent = 0);
    ~ImportType();

private slots:
    void on_Submit_clicked();

private:
    Ui::ImportType *ui;
};

#endif // IMPORTTYPE_H
