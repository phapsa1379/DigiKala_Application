#ifndef CONTACTLISTDIALOG_H
#define CONTACTLISTDIALOG_H

#include <QListWidgetItem>
#include <QDialog>
#include "KeyLinkedList.h"
#include "personal_page1.h"
#include "personal_page2.h"

namespace Ui {
class ContactListDialog;
}

class ContactListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactListDialog(QWidget *parent = nullptr);
    ~ContactListDialog();

    //void setBackUser(personal_page1 * back);
   //void setBackDealer(personal_page2* back);


private slots:
    void on_backB_clicked();
    void on_writeB_clicked();
    void onListMailItemClicked(QListWidgetItem*);


protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::ContactListDialog *ui;
    void findKeysOfContacts();

   // personal_page1* back_user;
    //personal_page2* back_dealer;

    void setList();
    int typeOfContact(unsigned long long key);
    KeyLinkedList listOfKeys;
};

#endif // CONTACTLISTDIALOG_H
