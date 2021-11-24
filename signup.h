#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "login.h"
//#include "signup_user.h"
//#include "signup_dealer.h"



namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT


public:


    void setLastPage(login * log);
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_qpb_next_clicked();

    void on_qpb_back_clicked();


private:
    Ui::signup *ui;

    login * last_page;


};

#endif // SIGNUP_H
