#ifndef ENUMSREPORT_H
#define ENUMSREPORT_H

#include <QString>

const QString OTHERS = "Others";
const QString WRONG_NUMBER = "Wrong Number";
const QString PRICE = "Unacceptable Price";
const QString FRAUD = "Fraud";
const QString WRONG_ADDRESS = "Wrong Address";
const QString PROBLEMS_WITH_OWNER = "Problems With owner";
const QString UNAVAILABLE = "Unavaile Product";
const QString IMMORAL = "Immoral";

const QString report_array[8] = {IMMORAL, UNAVAILABLE, PROBLEMS_WITH_OWNER,
                                 WRONG_ADDRESS, FRAUD, PRICE, WRONG_NUMBER, OTHERS};

#endif // ENUMSREPORT_H
