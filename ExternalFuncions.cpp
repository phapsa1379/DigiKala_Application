#include <QDateTime>
#include <QString>
#include <iostream>
#include <string.h>
#include <fstream>
#include "ExternalFunctions.h"
#include "Users.h"
#include "Dealer.h"
#include "Global.h"
#include "ProductDelegateClass.h"
#include "StarDelegate.h"
#include <QTableWidget>
#include "StarRating.h"
#include "ListSettingsProduct.h"
#include "FastArrays.h"
#include "ListSettingsProduct.h"
#include "EnumsProduct.h"
#include "QTextStream"

using namespace GlobalNameSpace;
using namespace std;
template<class N>
ostream& operator<< (ostream& out , TLinkedListUser<N> list)
{
    TNodeUser<N> * temp = list.getHead();
    while (temp)
    {
        N temp_u = temp->getData();
        temp_u.print();
        temp = temp->getNext();

    }
    return out;
}

template<>
ostream& operator<< (ostream& out , TLinkedListUser<Users> list)
{
    TNodeUser<Users> * temp = list.getHead();
    while (temp)
    {
        Users temp_u = temp->getData();
        temp_u.print();
        temp = temp->getNext();

    }
    return out;
}



template<>
ostream& operator<< (ostream& out , TLinkedListUser<Dealer> list)
{

    TNodeUser<Dealer> * temp = list.getHead();
    while (temp)
    {
        Dealer temp_u = temp->getData();
        temp_u.printDealer();
        temp = temp->getNext();

    }
    return out;

}








long long findKeyInString(long long key, QString str_key)
{
    int index_of_first_char = 0;;
    string numstr = "";
    string str_key_to_std = str_key.toLocal8Bit().constData();
    int j = 0;

    while (true)
    {
        if (j == str_key.length())
            break;

        int num = 0;
        if (isdigit(str_key_to_std[j]))
        {
            numstr.push_back(str_key_to_std[j]);
        }
        else
        {

            num = stoi(numstr);
            if (key == num)
            {
                return index_of_first_char;
            }
            numstr = "";
            index_of_first_char = j+1;
        }
        j++;
    }
    return -1;
}

//other functions:


KeyLinkedList keyConvertStringToLinkedList(QString keys_str)
{
    KeyLinkedList key_linkedlist;

    int j = 0;
    string numstr = "";
    string kehys_str_std = keys_str.toLocal8Bit().constData();
    while (true)
    {
        if (j == keys_str.length())
            break;

        int num = 0;
        if (isdigit(kehys_str_std[j]))
        {
            numstr.push_back(kehys_str_std[j]);
        }
        else
        {
            num = stoi(numstr);
            key_linkedlist.pushBack(num);
            numstr = "";
        }
        j++;
    }

    return key_linkedlist;
}

int ComputePassPow(QString pass)
{
    int percen_of_pass = 0;
    string pass_std = pass.toLocal8Bit().constData();
    for (size_t i = 0; i < pass_std.length(); i++)
    {
        if (isdigit(pass_std[i]))
            percen_of_pass += 3;
        else if (isupper(pass_std[i]))
            percen_of_pass += 4;
        else if (islower(pass_std[i]))
            percen_of_pass += 3;
        else if (isspace(pass_std[i]))
            percen_of_pass += 6;
        else if (ispunct(pass_std[i]))
            percen_of_pass += 8;

        if (percen_of_pass >= 100)
        {
            percen_of_pass = 100;
            return percen_of_pass;
        }
    }
    return percen_of_pass;

}

unsigned long long int CreateKey()
{

    unsigned long long key = 0;
    std::ifstream id_file("UniqeIdFile.txt");
    id_file >> key;
    key++;
    id_file.close();

    {
        std::ofstream id_file("UniqeIdFile.txt");
        id_file << key;
    }

    id_file.close();

    return key;
}


int countDigit(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}


void startApp()
{


    Globals::PRODUCT_LIST.readFile();
    Globals::USER_LIST.readFromFileUser();
    Globals::DEALER_LIST.readFromFileUser();
    Globals::MESSAGE_LIST.readFile();
    Globals::REPORT_LIST.readFile();
    Globals::setListUsernames();



    return;
}


QString NowTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_format ="yyyy/MM/dd   HH:mm:ss";
    QString now_time = time.toString(time_format);
    return now_time;
}

void sortBaseSearch(QString target)
{
    vector<ProductDelegateClass> last_list = Globals::DELEGATED_VECTOR_PRODUCT;
    vector<ProductDelegateClass> extern_list;
    Globals::DELEGATED_VECTOR_PRODUCT.clear();


    int size = last_list.size();
    for(int i=0; i<size ; i++)
    {

        QString name = last_list[i].getName();
        ProductDelegateClass prd = last_list[i];

        const char *ptr;
        ptr = strstr(name.toLocal8Bit().constData(),target.toLocal8Bit().constData());

        if(ptr)
        {


            Globals::DELEGATED_VECTOR_PRODUCT.push_back(prd);


        }
        else
        {
            extern_list.push_back(prd);
        }

    }
    int size2 =extern_list.size();
    for(int k = 0 ; k < size2 ; k++)
    {
        Globals::DELEGATED_VECTOR_PRODUCT.push_back(extern_list[k]);
    }

}



void TableWidgetAll(QTableWidget *tableWidget , QString target){

    Globals::DELEGATED_VECTOR_PRODUCT.clear();

    ListSettingsProduct::filterList();
    sortBaseSearch(target);
    const int SIZE = Globals::DELEGATED_VECTOR_PRODUCT.size();

    for (int row = 0; row < SIZE; row++) {

        QTableWidgetItem *item0 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getName() + "   ");

        QTableWidgetItem *item1 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getCompany() + "   ");

        QTableWidgetItem *item2 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getViewNumber()) + "   ");

        QTableWidgetItem *item3 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getPurePrice()) + "   ");

        QTableWidgetItem *item4 = new QTableWidgetItem("   " +
                    QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getAvailableNumber()) + "   ");

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setData(0, QVariant::fromValue(
                           StarRating(Globals::DELEGATED_VECTOR_PRODUCT[row].getRating())));

        tableWidget->setItem(row, 0, item0);
        tableWidget->setItem(row, 1, item1);
        tableWidget->setItem(row, 2, item2);
        tableWidget->setItem(row, 3, item3);
        tableWidget->setItem(row, 4, item4);
        tableWidget->setItem(row, 5, item5);
    }

    tableWidget->setRowCount(SIZE);
}



void TableWidgetBought(QTableWidget *tableWidget , QString target){

    Globals::DELEGATED_VECTOR_PRODUCT.clear();

    LinkedListProduct list;

    if (Globals::TYPE_USER == DEALER){
        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();
        list = d_data.getListOfBuyBeforeLinkList();
    }
    else {
        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();
        list = d_data.getListOfBuyBeforeLinkList();
    }

    if (ListSettingsProduct::getSortType() == ASCENDING)
        list.sortAscending(ListSettingsProduct::getSortBasedOn());
    else
        list.sortDescending(ListSettingsProduct::getSortBasedOn());

    const int SIZE = list.size();

    ProductDelegateClass pdc;
    for (int i = 0; i < SIZE; i++){
        Product p = list.get(i);
        pdc = p;
        Globals::DELEGATED_VECTOR_PRODUCT.push_back(pdc);
    }
     sortBaseSearch(target);

    for (int row = 0; row < SIZE; row++) {

        QTableWidgetItem *item0 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getName() + "   ");

        QTableWidgetItem *item1 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getCompany() + "   ");

        QTableWidgetItem *item2 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getViewNumber()) + "   ");

        QTableWidgetItem *item3 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getPurePrice()) + "   ");

        QTableWidgetItem *item4 = new QTableWidgetItem("   " +
                    QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getAvailableNumber()) + "   ");

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setData(0, QVariant::fromValue(
                           StarRating(Globals::DELEGATED_VECTOR_PRODUCT[row].getRating())));

        tableWidget->setItem(row, 0, item0);
        tableWidget->setItem(row, 1, item1);
        tableWidget->setItem(row, 2, item2);
        tableWidget->setItem(row, 3, item3);
        tableWidget->setItem(row, 4, item4);
        tableWidget->setItem(row, 5, item5);
    }
    tableWidget->setRowCount(SIZE);
}




void TableWidgetSold(QTableWidget *tableWidget ,QString target){

    Globals::DELEGATED_VECTOR_PRODUCT.clear();

    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
    Dealer d_data = d_node->getData();
    // d_data.getListOfSellLinkList().pushBack(p);

    /////////////////////////////////////////////////////////////
    d_data.getListOfSellLinkList().print();



    LinkedListProduct list = d_data.getListOfSellLinkList();

    //  list.print();


    if (ListSettingsProduct::getSortType() == ASCENDING)
        list.sortAscending(ListSettingsProduct::getSortBasedOn());
    else
        list.sortDescending(ListSettingsProduct::getSortBasedOn());

    const int SIZE = list.size();

    for (int i = 0; i < SIZE; i++){
        ProductDelegateClass pdc;
        pdc = list.get(i);
        Globals::DELEGATED_VECTOR_PRODUCT.push_back(pdc);
    }
     sortBaseSearch(target);

    for (int row = 0; row < SIZE; row++) {

        QTableWidgetItem *item0 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getName() + "   ");

        QTableWidgetItem *item1 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getCompany() + "   ");

        QTableWidgetItem *item2 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getViewNumber()) + "   ");

        QTableWidgetItem *item3 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getPurePrice()) + "   ");

        QTableWidgetItem *item4 = new QTableWidgetItem("   " +
                    QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getAvailableNumber()) + "   ");

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setData(0, QVariant::fromValue(
                           StarRating(Globals::DELEGATED_VECTOR_PRODUCT[row].getRating())));

        tableWidget->setItem(row, 0, item0);
        tableWidget->setItem(row, 1, item1);
        tableWidget->setItem(row, 2, item2);
        tableWidget->setItem(row, 3, item3);
        tableWidget->setItem(row, 4, item4);
        tableWidget->setItem(row, 5, item5);
    }
    tableWidget->setRowCount(SIZE);
}



void TableWidgetFavorites(QTableWidget *tableWidget, QString target){

    Globals::DELEGATED_VECTOR_PRODUCT.clear();
    LinkedListProduct list;
    if(Globals::TYPE_USER == DEALER)
    {
        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();
        list = d_data.getListOfInterestLinkList();
    }
    else {
        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();
        list = d_data.getListOfInterestLinkList();
    }




    if (ListSettingsProduct::getSortType() == ASCENDING)
        list.sortAscending(ListSettingsProduct::getSortBasedOn());
    else
        list.sortDescending(ListSettingsProduct::getSortBasedOn());

    const int SIZE = list.size();

    for (int i = 0; i < SIZE; i++){
        ProductDelegateClass pdc;
        pdc = list.get(i);
        Globals::DELEGATED_VECTOR_PRODUCT.push_back(pdc);
    }
     sortBaseSearch(target);

    for (int row = 0; row < SIZE; row++) {

        QTableWidgetItem *item0 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getName() + "   ");

        QTableWidgetItem *item1 = new QTableWidgetItem(
                    "   " + Globals::DELEGATED_VECTOR_PRODUCT[row].getCompany() + "   ");

        QTableWidgetItem *item2 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getViewNumber()) + "   ");

        QTableWidgetItem *item3 = new QTableWidgetItem(
                    "   " + QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getPurePrice()) + "   ");

        QTableWidgetItem *item4 = new QTableWidgetItem("   " +
                    QString::number(Globals::DELEGATED_VECTOR_PRODUCT[row].getAvailableNumber()) + "   ");

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setData(0, QVariant::fromValue(
                           StarRating(Globals::DELEGATED_VECTOR_PRODUCT[row].getRating())));

        tableWidget->setItem(row, 0, item0);
        tableWidget->setItem(row, 1, item1);
        tableWidget->setItem(row, 2, item2);
        tableWidget->setItem(row, 3, item3);
        tableWidget->setItem(row, 4, item4);
        tableWidget->setItem(row, 5, item5);
    }
    tableWidget->setRowCount(SIZE);
}



unsigned long long createKeyProduct()
{
    unsigned long long key = 0;
    std::ifstream id_file("idFileProduct.txt");
    id_file >> key;
    key++;
    id_file.close();

    {
        std::ofstream id_file("idFileProduct.txt");
        id_file << key;
    }

    id_file.close();

    return key;
}




bool update()
{
    if(Globals::KEY_USER == USER)
    {
        TNodeUser<Users> * temp = Globals::USER_LIST.getHead();
        while (temp)
        {
            Users usr = temp->getData();
            if(Globals::KEY_USER == usr.getKey())
            {
                temp->setData(Globals::THIS_USER);
                return true;
            }


            temp = temp->getNext();
        }
        return false;
    }
    else if(Globals::KEY_USER == DEALER) //////////////////////////
    {
        TNodeUser<Dealer> * temp = Globals::DEALER_LIST.getHead();
        while (temp)
        {
            Dealer usr = temp->getData();
            if(Globals::KEY_USER == usr.getKey())
            {
                temp->setData(Globals::THIS_DEALER);
                return true;
            }


            temp = temp->getNext();
        }
        return false;
    }
    return false;
}


void updateFiles()
{

    if(Globals::TYPE_USER == USER)
    {
        TNodeUser<Users> * temp = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users usr = temp->getData();
        usr.setDateOfLastExit(NowTime());
        temp->setData(usr);
    }
    else
    {
        TNodeUser<Dealer> * temp = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer usr = temp->getData();
        usr.setDateOfLastExit(NowTime());
        temp->setData(usr);
    }

    Globals::PRODUCT_LIST.writeFile();    
    Globals::USER_LIST.writeToFileUser();
    Globals::DEALER_LIST.writeToFileUser();
    Globals::REPORT_LIST.writeFile();
    Globals::MESSAGE_LIST.writeFile();

    return;
}


bool uniqueUserName(QString u_name)
{
    for(int i=0  ; i<Globals::LIST_USERNAMES.size() ; i++)
    {
        if(u_name == Globals::LIST_USERNAMES[i])
        {
            return false;
        }
    }
    return true;
}



vector<ProductDelegateClass> dell(vector<ProductDelegateClass> vec , int a)
{
    vector<ProductDelegateClass> new_vec;
    int s = vec.size();
    for(int i=0 ; i<s ; i++)
    {
        if(i == a)
            continue;
        new_vec.push_back(vec[i]);

    }
    return new_vec;
}

QTextStream& qStdOut()
{
    static QTextStream ts( stdout );
    return ts;
}
