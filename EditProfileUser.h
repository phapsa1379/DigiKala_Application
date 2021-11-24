#ifndef EDITPROFILEUSER_H
#define EDITPROFILEUSER_H

#include <QDialog>
#include "IncreaseMoney.h"
#include "ChangePassword.h"

namespace Ui {
class EditProfile;
}

class EditProfile : public QDialog
{
    Q_OBJECT
    //friend void IncreaseMoney::on_btn_box_accepted();

public:


    explicit EditProfile(QWidget *parent = nullptr);
    ~EditProfile();
    QString getPass();
    double getMoney();
private slots:
    void on_btn_box_rejected();

    void on_btn_box_accepted();

 //   void on_lbl_company_linkActivated(const QString &link);

  //  void on_led_companyname_cursorPositionChanged(int arg1, int arg2);

  //  void on_led_companyname_customContextMenuRequested(const QPoint &pos);

  //  void on_lbl_company_destroyed();

    void on_btn_increasemoney_clicked();


    //void on_EditProfile_accepted();

    void on_btn_changepass_clicked();


signals:
    //void send_money_signal(double money_);

private:

    Ui::EditProfile *ui;
    void fillBlanks();
    QString new_pass = "";
    double money_ =0;
};

#endif // EDITPROFILEUSER_H
