#ifndef PV_H
#define PV_H

#include <QDialog>

#include <QCloseEvent>
#include "ContactListDialog.h"
namespace Ui {
class PV;
}

class PV : public QDialog
{
    Q_OBJECT

public:
    explicit PV(const unsigned long long key, QString username, QWidget *parent = nullptr);
    ~PV();
    void setBack(ContactListDialog * back);


private slots:
    //void on_pushButton_clicked();

    void on_backB_clicked();

    void on_deleteB_clicked();

    void on_sendB_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:

    Ui::PV *ui;
    ContactListDialog* back_contacts;
    void refresh();
    QString usernameOfContact;
    unsigned long long keyOfContact;
};

#endif // PV_H
