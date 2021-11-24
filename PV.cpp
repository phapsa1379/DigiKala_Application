#include "PV.h"
#include "ui_PV.h"

#include "Global.h"
#include "ContactListDialog.h"
#include <QMessageBox>
#include "ExternalFunctions.h"

using namespace GlobalNameSpace;

PV::PV(const unsigned long long key1, QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PV)
{
    ui->setupUi(this);

    keyOfContact = key1;
    usernameOfContact = username;

    if (keyOfContact == Globals::KEY_USER){
        ui->headingL->setText("Saved Messages");
    }
    else{
        ui->headingL->setText("Your chat log with " + usernameOfContact + " :");
    }

    ui->headingL->setStyleSheet("QLabel { background-color : #00bfff	; color : #4d3900	;font-weight: bold;font-size: 16px;font-family: Arial; }");

    refresh();
}


PV::~PV()
{
    delete ui;
}

void PV::setBack(ContactListDialog *back)
{
    this->back_contacts = back;
    return;
}


void PV::refresh(){

    const unsigned long long MyKey = Globals::KEY_USER;

    LinkedListMessage tempList;

    const int SIZE = Globals::MESSAGE_LIST.size();

    Message message;

    if (MyKey != keyOfContact){

        for (int i = 0; i < SIZE; i++){

            message = Globals::MESSAGE_LIST.get(i);

            if (message.getKeySender() == MyKey && message.getKeyReciever() == keyOfContact) {

                message.setText("\nMe :  " + message.getText() + "\n");
                tempList.pushBack(message);
            }
            else if(message.getKeySender() == keyOfContact && message.getKeyReciever() == MyKey){

                message.setText("\n" + usernameOfContact + " :  " + message.getText() + "\n");
                tempList.pushBack(message);
            }
        }
    }
    else{

        for (int i = 0; i < SIZE; i++){

            message = Globals::MESSAGE_LIST.get(i);

            if (message.getKeySender() == MyKey && message.getKeyReciever() == MyKey){
                message.setText("\n" + message.getText() + "\n");
                tempList.pushBack(message);
            }
        }
    }


    const int SIZE_2 = tempList.size();

    for (int i = 0; i < SIZE_2; i++){
        ui->listWidget->addItem(tempList.get(i).getText());
    }

    const QString lastTime = tempList.getTail()->getData().getDate();
    ui->timeL->setText(lastTime);
}



void PV::on_backB_clicked()
{
    ContactListDialog* d = new ContactListDialog();

    d->show();
    hide();
}


void PV::on_deleteB_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "",
                                  "Messages will be deleted for both sides.\nAre you sure?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        Globals::MESSAGE_LIST.remove(keyOfContact, Globals::KEY_USER);
        Globals::MESSAGE_LIST.writeFile();

        ui->listWidget->clear();

        ContactListDialog* d = new ContactListDialog();

        d->show();
        hide();
    }
}


void PV::on_sendB_clicked()
{

    if (!ui->textE->text().isEmpty()){

        ui->listWidget->clear();

        Message m;
        m.setKeySender(Globals::KEY_USER);
        m.setKeyReciever(keyOfContact);
        m.setText(ui->textE->text());

        Globals::MESSAGE_LIST.pushBack(m);
        Globals::MESSAGE_LIST.writeFile();

        ui->textE->clear();
        refresh();
    }
}

void PV::closeEvent(QCloseEvent *event) {
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec())
    {
    case 3:
    {
        updateFiles();
        event->accept();

        //rewrite files egain...


        break;
    }
    default:
    {

        event->ignore();
        break;
    }
    }
}

