#ifndef EDITPRODUCT_H
#define EDITPRODUCT_H

#include <QDialog>
#include "EnumsProduct.h"

namespace Ui {
class EditProduct;
}

class EditProduct : public QDialog
{
    Q_OBJECT

public:
    explicit EditProduct(QWidget *parent = nullptr);
    ~EditProduct();

private slots:
    void on_confirmB_clicked();

    void on_cancelB_clicked();

private:
    Ui::EditProduct *ui;
};

#endif // EDITPRODUCT_H
