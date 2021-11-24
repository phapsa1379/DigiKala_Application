#ifndef REPORT_H
#define REPORT_H
#include <QString>


class Report
{
private:
    QString date;
    QString reason;
    unsigned long long keyProduct;

public:
    Report();
    ~Report();
    Report(const Report & p);
    Report(Report && p);

    QString getDate();
    unsigned long long getKeyProduct();
    QString getReason();

    void setDate(QString);
    void setKeyProduct(unsigned long long);
    void setReason(QString);

    void operator=(Report p);

};

#endif // REPORT_H
