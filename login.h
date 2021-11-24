#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

//#include "forgot_password.h"
#include "help.h"
#include "about.h"
//#include "signup.h"
#include "personal_page1.h"


QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    void setLogin(login* log);
    login *getLogin();
    ~login();

private slots:
    void on_qpb_signup_clicked();

    void on_pushButton_clicked();

    void on_actionExit_3_triggered();

    void on_actionReset_2_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();

    void on_qpb_signin_clicked();

    void on_qpb_replace_clicked();

    void on_qpb_show_password_toggled(bool checked);

protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::login *ui;
    QPixmap makeImg(QString);
    QPixmap distortImg(QPixmap);
    long int a;

    login* l;

    help* h;
    about* ab;

};
#endif // LOGIN_H
