#ifndef DETAILOFALLPRODUCTS_H
#define DETAILOFALLPRODUCTS_H

#include "Product.h"
#include <QDialog>

namespace Ui {
class DetailOfAllProducts;
}

class DetailOfAllProducts : public QDialog
{
    Q_OBJECT

public:
    explicit DetailOfAllProducts(QWidget *parent = nullptr);
    ~DetailOfAllProducts();

private slots:
    void on_btn_buyB_Clicked(bool);
    void on_btn_contactB_Clicked(bool);
    void on_btn_likedB_Clicked(bool);
    void on_btn_reportB_Clicked(bool);

private:
    Ui::DetailOfAllProducts *ui;
    Product p;
    QPushButton* likedB;
};

#endif // DETAILOFALLPRODUCTS_H
