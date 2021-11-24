#include "ContactListDialog.h"
#include "ui_ContactListDialog.h"
#include <QMessageBox>
#include "KeyLinkedList.h"
#include "Global.h"
#include "NewMessageDialog.h"
#include "ExternalFunctions.h"
#include "PV.h"
#include "personal_page1.h"
using namespace GlobalNameSpace;


ContactListDialog::ContactListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactListDialog)
{
    ui->setupUi(this);

    ui->listWidget->setStyleSheet( "QListWidget::item { border-bottom: 1px solid black; }" );

    findKeysOfContacts();
    setList();

    if (listOfKeys.size() == 0){
        ui->headingL->setText("You have no messages.");
    }
    else{
        ui->headingL->setText("Click on the contact to open PV.");
    }

    ui->headingL->setStyleSheet("QLabel { background-color : #00bfff	; color : #4d3900	;font-weight: bold;font-size: 16px;font-family: Arial; }");

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onListMailItemClicked(QListWidgetItem*)));

}


ContactListDialog::~ContactListDialog()
{
    delete ui;
}


int ContactListDialog::typeOfContact(unsigned long long key){

    TNodeUser<Dealer> *temp = Globals::DEALER_LIST.getHead();

    while (temp != nullptr){
        if (temp->getData().getKey() == key){
            return DEALER;
        }
        temp = temp->getNext();
    }

    TNodeUser<Users> *temp2 = Globals::USER_LIST.getHead();

    while (temp2 != nullptr){
        if (temp2->getData().getKey() == key){
            return USER;
        }
        temp2 = temp2->getNext();
    }

    return -1;
}



void ContactListDialog::findKeysOfContacts(){

    listOfKeys.~KeyLinkedList();

    const int SIZE = Globals::MESSAGE_LIST.size();

    Message message;
    for (int i = 0; i < SIZE; i++){

        message = Globals::MESSAGE_LIST.get(i);

        if (Globals::KEY_USER == message.getKeySender() || Globals::KEY_USER == message.getKeyReciever()){
            unsigned long long keyContact = (Globals::KEY_USER == message.getKeySender()) ?
                        message.getKeyReciever() : message.getKeySender();

            if (!listOfKeys.containsKey(keyContact)){
                listOfKeys.pushBack(keyContact);
            }
        }
    }

}


void ContactListDialog::setList(){

    const int SIZE = listOfKeys.size();

    QString userName = "";

    for (int i = 0; i < SIZE; i++){

        const unsigned long long key = listOfKeys.get(i);

        if (key == Globals::KEY_USER){

            if (Globals::TYPE_USER == DEALER){
                userName = Globals::DEALER_LIST.getByKey(key).getData().getUserName();
                ui->listWidget->addItem("\nSaved Messages\n");
            }
            else{
                userName = Globals::USER_LIST.getByKey(key).getData().getUserName();
                ui->listWidget->addItem("\nSaved Messages\n");
            }

        }
        else{

            if (typeOfContact(key) == DEALER){

                userName = Globals::DEALER_LIST.getByKey(key).getData().getUserName();
                ui->listWidget->addItem("\n" + userName + "\n");
            }
            else{

                userName = Globals::USER_LIST.getByKey(key).getData().getUserName();
                ui->listWidget->addItem("\n" + userName + "\n");
            }
        }
    }
}



void ContactListDialog::onListMailItemClicked(QListWidgetItem* item)
{
    const int SIZE = listOfKeys.size();

    for  (int i = 0; i < SIZE; i++){

        if (ui->listWidget->item(i) == item) {

            QString username = ui->listWidget->item(i)->text();
            username = username.replace('\n', "");

            unsigned long long key = listOfKeys.get(i);

            PV * d = new PV(key, username);
            d->setBack(this);
            d->show();
            hide();

            listOfKeys.~KeyLinkedList();

            break;
        }
    }
}



void ContactListDialog::on_backB_clicked()
{
    personal_page1* back_user = new personal_page1();
    personal_page2* back_dealer = new personal_page2();
    if(Globals::TYPE_USER == USER)
    {
        back_user->show();
    }
    else
    {
        back_dealer->show();
    }
    hide();
}


void ContactListDialog::on_writeB_clicked()
{
    NewMessageDialog *d = new NewMessageDialog();
    d->setModal(true);
    d->setBack(this);
    d->show();
}



void ContactListDialog::closeEvent(QCloseEvent *event) {
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec()) {
    case 3: {
        event->accept();
        //rewrite files egain...


        break;
    }
    default: {
        event->ignore();
        break;
    }
    }
}
