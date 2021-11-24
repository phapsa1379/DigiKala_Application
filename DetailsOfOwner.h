#ifndef DETAILSOFOWNER_H
#define DETAILSOFOWNER_H

#include <QDialog>
#include "DetailOfAllProducts.h"
#include "DetailOfFavoriteProducts.h"
namespace Ui {
class DetailsOfOwner;
}

class DetailsOfOwner : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsOfOwner(const unsigned long long keyOfOwner, QWidget *parent = nullptr);
    ~DetailsOfOwner();
    void setBack(DetailOfAllProducts* back);
    void setBackFavorite(DetailOfFavoriteProducts * back);
    void setInt(int a);

private slots:
    void on_btn_ok_clicked();
    void on_chatB_clicked();

private:
    Ui::DetailsOfOwner *ui;
    int keyOfOwner;
    DetailOfAllProducts* back_details;
    DetailOfFavoriteProducts* back_favorite;
    int back=0;

};

#endif // DETAILSOFOWNER_H
