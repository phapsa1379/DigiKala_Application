#ifndef COMMON_QUESTIONS_H
#define COMMON_QUESTIONS_H

#include <QMainWindow>
#include "personal_page1.h"
#include "personal_page2.h"

namespace Ui {
class common_questions;
}

class common_questions : public QMainWindow
{
    Q_OBJECT

public:
    explicit common_questions(QWidget *parent = nullptr);
    ~common_questions();

    void setBackUser(personal_page1* back);
    void setBackDealer(personal_page2* back);

private slots:
    void on_qpb1_clicked();

    void on_qpb_back_clicked();

    void on_qpb_2_clicked();

    void on_qpb_3_clicked();

    void on_qpb_4_clicked();

    void on_qpb_5_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::common_questions *ui;
    personal_page1* back_user;
    personal_page2* back_dealer;

};

#endif // COMMON_QUESTIONS_H
