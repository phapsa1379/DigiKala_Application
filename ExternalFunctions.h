#ifndef EXTERNALFUNCTIONS_H
#define EXTERNALFUNCTIONS_H

#include <QString>
#include "TLinkedListUser.h"
#include "KeyLinkedList.h"
#include <QTableWidget>
#include "ProductDelegateClass.h"
using namespace std;

QString NowTime();
void startApp();
void updateFiles();

long long findKeyInString(long long key, QString str_key);
KeyLinkedList keyConvertStringToLinkedList(QString keys);
int ComputePassPow(QString pass);
unsigned long long int CreateKey();

int countDigit(long long n);

template<class N>
ostream& operator<< (ostream& out , TLinkedListUser<N> list);
void TableWidgetAll(QTableWidget *tableWidget , QString target);
void TableWidgetBought(QTableWidget *tableWidget, QString target);
void TableWidgetSold(QTableWidget *tableWidget, QString target);
void TableWidgetFavorites(QTableWidget *tableWidget, QString target);
LinkedListProduct sortBaseSearch(LinkedListProduct list);
vector<ProductDelegateClass> dell(vector<ProductDelegateClass> vec , int a);
unsigned long long createKeyProduct();
bool update();

bool uniqueUserName(QString u_name);
QTextStream& qStdOut();

#endif // EXTERNALFUNCTIONS_H
