#ifndef RATING_PRODUCT_H
#define RATING_PRODUCT_H

#include <QMainWindow>

namespace Ui {
class rating_product;
}

class rating_product : public QMainWindow
{
    Q_OBJECT

public:
    explicit rating_product(QWidget *parent = nullptr);
    ~rating_product();

private slots:
    void on_qpb_1_toggled(bool checked);

    void on_qpb_2_toggled(bool checked);

    void on_qpb_3_toggled(bool checked);

    void on_qpb_4_toggled(bool checked);

    void on_qpb_5_toggled(bool checked);

private:
    Ui::rating_product *ui;
};

#endif // RATING_PRODUCT_H
