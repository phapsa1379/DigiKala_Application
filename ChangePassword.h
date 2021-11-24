#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT


public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();
    QString getPass();

private slots:
    void on_led_newpass_textChanged(const QString &arg1);

    void on_btn_box_accepted();


private:
    Ui::ChangePassword *ui;
    QString pass;
};

#endif // CHANGEPASSWORD_H
