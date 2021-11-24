#ifndef DETAILOFBOUGHTPRODUCTS_H
#define DETAILOFBOUGHTPRODUCTS_H

#include <QDialog>
#include "Product.h"

namespace Ui {
class DetailOfBoughtProducts;
}

class DetailOfBoughtProducts : public QDialog
{
    Q_OBJECT

public:
    explicit DetailOfBoughtProducts(QWidget *parent = nullptr);
    ~DetailOfBoughtProducts();


    static int givenRating;


private slots:
    void on_btn_removeB_Clicked(bool);
    void on_btn_likedB_Clicked(bool);
    void on_btn_rateB_Clicked(bool);

private:
    QPushButton *likedB;
    Ui::DetailOfBoughtProducts *ui;
    Product p;

};

#endif // DETAILOFBOUGHTPRODUCTS_H
