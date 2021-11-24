#ifndef FORGOT_PASSWORD_H
#define FORGOT_PASSWORD_H

#include <QDialog>
#include "login.h"

namespace Ui {
class forgot_password;
}

class forgot_password : public QDialog
{
    Q_OBJECT

public:
    void setLastPage(login * log);
    explicit forgot_password(QWidget *parent = nullptr);
    ~forgot_password();

private slots:
    void on_qpb_back_clicked();

    void on_qpb_confirm_clicked();

private:
    Ui::forgot_password *ui;
    login *last_page;
};

#endif // FORGOT_PASSWORD_H
