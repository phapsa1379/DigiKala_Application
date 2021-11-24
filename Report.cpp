#include "Report.h"

Report::Report(){

    keyProduct = 0;
    reason = "";
    date = "";
    return;
}

Report::Report(const Report & p){

    keyProduct = p.keyProduct;
    reason = p.reason;
    date = p.date;
    return;
}

Report::Report(Report && p){

    keyProduct = p.keyProduct;
    reason = p.reason;
    date = p.date;
    return;
}

Report::~Report(){}



QString Report::getDate(){
    return date;
}

unsigned long long Report::getKeyProduct(){
    return keyProduct;
}

QString Report::getReason(){
    return reason;
}






void Report::setDate(QString a){
    date = a;
    return;
}

void Report::setKeyProduct(unsigned long long a){
    keyProduct = a;
    return;
}

void Report::setReason(QString a){
    reason = a;
    return;
}

void Report::operator=(Report p){

    date = p.date;
    keyProduct = p.keyProduct;
    reason = p.reason;
    return;
}
