#ifndef DATES_H
#define DATES_H

#include <QObject>

class Dates : public QObject
{
public:
    Dates(int, int, int, int, int);

signals:

public slots:

protected:
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

#endif // DATES_H
