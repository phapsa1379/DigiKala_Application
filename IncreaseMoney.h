#ifndef INCREASEMONEY_H
#define INCREASEMONEY_H

#include <QDialog>

namespace Ui {
class IncreaseMoney;
}

class IncreaseMoney : public QDialog
{
    Q_OBJECT
public:

    void fillBlanks(double);
    double getMoney();
    explicit IncreaseMoney(QWidget *parent = nullptr);
    ~IncreaseMoney();

private slots:
    void on_spb_add_valueChanged(double arg1);


public slots:
     void on_btn_box_accepted();

private:
    Ui::IncreaseMoney *ui;
};

#endif // INCREASEMONEY_H
