#ifndef DIALOGBUY_H
#define DIALOGBUY_H

#include <QDialog>
#include "Product.h"
#include "Global.h"

namespace Ui {
class DialogBuy;
}

class DialogBuy : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBuy(QWidget *parent = nullptr);
    ~DialogBuy();    


private slots:

    void on_confirmB_clicked();

    void on_cancelB_clicked();

private:

    void refresh();

    Product p;
    Users user_buyer;
    Dealer dealer_buyer;


    Ui::DialogBuy *ui;
};

#endif // DIALOGBUY_H
