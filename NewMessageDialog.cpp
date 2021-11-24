#include "NewMessageDialog.h"
#include "ui_NewMessageDialog.h"

#include "DetailOfAllProducts.h"
#include "DetailOfFavoriteProducts.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "Global.h"
#include "ContactListDialog.h"

using namespace std;
using namespace GlobalNameSpace;

NewMessageDialog::NewMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMessageDialog)
{
    ui->setupUi(this);

}

NewMessageDialog::~NewMessageDialog()
{
    delete ui;
}

void NewMessageDialog::setBack(ContactListDialog *b)
{
    this->back_ = b;
    return;
}

void NewMessageDialog::on_sendB_clicked()
{
    if (ui->userNameE->text().isEmpty()){
        QMessageBox::critical(this, "Failed", "First mention your reciever.");
    }
    else {

        const unsigned long long keyOfReciever = keyOfUser(ui->userNameE->text());

        if (keyOfReciever == 0){
            QMessageBox::critical(this, "Failed", "No user exists with this username.");
        }
        else{

            const QString text = ui->textE->text();

            if (text.isEmpty()){
                QMessageBox::critical(this, "Failed", "You forget to enter the message!");
            }
            else{
                Message m;
                m.setText(text);
                m.setKeySender(Globals::KEY_USER);
                m.setKeyReciever(keyOfReciever);
                Globals::MESSAGE_LIST.pushBack(m);
                Globals::MESSAGE_LIST.writeFile();

                QMessageBox::information(this, "Done", "Message sent.");

                ContactListDialog* d = new ContactListDialog();

                d->show();
                this->close();
                this->back_->hide();

            }
        }
    }
}


unsigned long long NewMessageDialog::keyOfUser(QString username){

    TNodeUser<Dealer> *temp = Globals::DEALER_LIST.getHead();

    while (temp != nullptr){
        if (temp->getData().getUserName() == username){
            return temp->getData().getKey();
        }
        temp = temp->getNext();
    }

    TNodeUser<Users> *temp2 = Globals::USER_LIST.getHead();

    while (temp2 != nullptr){
        if (temp2->getData().getUserName() == username){
            return temp2->getData().getKey();
        }
        temp2 = temp2->getNext();
    }

    return 0;
}


void NewMessageDialog::on_backB_clicked()
{
    close();
}

void NewMessageDialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_sendB_clicked();
    }

}
