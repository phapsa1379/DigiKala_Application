#ifndef LISTOFPRODUCTS_H
#define LISTOFPRODUCTS_H

#include <QDialog>
#include "personal_page1.h"
#include "personal_page2.h"

#include <QTableWidget>
namespace Ui {
class ListOfProducts;
}

class ListOfProducts : public QDialog
{
    Q_OBJECT

public:
    explicit ListOfProducts(QWidget *parent = nullptr);
    ~ListOfProducts();
    void setBackUser(personal_page1 * back);
    void setBackDealer(personal_page2 * back);

public slots:
    void on_btn_back_clicked();

    void on_btn_filter_clicked();

    void on_refreshB_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void on_qpb_search_clicked();

private:

    QTableWidget *tableWidget;
    void refresh();
    Ui::ListOfProducts *ui;
    personal_page1* back_user;
    personal_page2* back_dealer;

};

#endif // LISTOFPRODUCTS_H
