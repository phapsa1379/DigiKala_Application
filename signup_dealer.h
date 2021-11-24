#ifndef SIGNUP_DEALER_H
#define SIGNUP_DEALER_H

#include <QDialog>
#include<QMessageBox>
#include<string>
#include<QFile>
#include<QDebug>
#include<QDir>
#include "signup.h"

namespace Ui {
class signup_dealer;
}

class signup_dealer : public QDialog
{
    Q_OBJECT

public:
    void setLastPageSign(signup *lastpage);
    void setLogin(login* log);
    explicit signup_dealer(QWidget *parent = nullptr);
    ~signup_dealer();

private slots:
    void on_qle_password_textChanged(const QString &arg1);



    void on_qpb_back_clicked();

    void on_qpb_signup_clicked();

    void on_cob_country_currentIndexChanged(int index);


    void on_grb_adress_clicked();

    void on_qpb_show_password1_toggled(bool checked);

    void on_qpb_show_password2_toggled(bool checked);

private:
    Ui::signup_dealer *ui;
    signup *last_page_sign;
    login *log_in;
};

#endif // SIGNUP_DEALER_H
