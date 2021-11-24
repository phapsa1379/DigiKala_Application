#ifndef RATINGDIALOG_H
#define RATINGDIALOG_H

#include "Product.h"
#include <QDialog>

namespace Ui {
class RatingDialog;
}

class RatingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RatingDialog(QWidget *parent = nullptr);
    ~RatingDialog();

private slots:
    void on_confirmB_clicked();

    void on_cancelB_clicked();

private:
    Ui::RatingDialog *ui;
    Product p;
};

#endif // RATINGDIALOG_H
