#ifndef DETAILOFFAVORITEPRODUCTS_H
#define DETAILOFFAVORITEPRODUCTS_H

#include <QDialog>
#include "Product.h"

namespace Ui {
class DetailOfFavoriteProducts;
}

class DetailOfFavoriteProducts : public QDialog
{
    Q_OBJECT

public:
    explicit DetailOfFavoriteProducts(QWidget *parent = nullptr);
    ~DetailOfFavoriteProducts();

private slots:
    void on_btn_ownerB_Clicked(bool);
    void on_btn_likedB_Clicked(bool);

private:
    Product p;
    Ui::DetailOfFavoriteProducts *ui;
};

#endif // DETAILOFFAVORITEPRODUCTS_H
