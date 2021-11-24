#ifndef DETAILOFONSALEPRODUCTS_H
#define DETAILOFONSALEPRODUCTS_H

#include <QDialog>

namespace Ui {
class DetailOfOnSaleProducts;
}

class DetailOfOnSaleProducts : public QDialog
{
    Q_OBJECT

public:
    explicit DetailOfOnSaleProducts(QWidget *parent = nullptr);
    ~DetailOfOnSaleProducts();

    QPushButton *likedB;
    QPushButton *activeB;


private slots:
    void on_btn_activeB_Clicked(bool);
    void on_btn_likedB_Clicked(bool);
    void on_btn_editB_Clicked(bool);


private:
    Ui::DetailOfOnSaleProducts *ui;
};

#endif // DETAILOFONSALEPRODUCTS_H
