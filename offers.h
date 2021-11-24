#ifndef OFFERS_H
#define OFFERS_H

#include <QMainWindow>
#include "personal_page1.h"
#include "personal_page2.h"

namespace Ui {
class offers;
}

class offers : public QMainWindow
{
    Q_OBJECT

public:
    explicit offers(QWidget *parent = nullptr);
    ~offers();
    void setBackUser(personal_page1 * back);
    void setBackDealer(personal_page2* back);

private slots:

    void on_btn_back_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::offers *ui;
    personal_page1* back_user;
    personal_page2* back_dealer;

};

#endif // OFFERS_H
