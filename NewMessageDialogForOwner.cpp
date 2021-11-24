#include "NewMessageDialogForOwner.h"
#include "ui_NewMessageDialogForOwner.h"
#include "Global.h"
#include <QMessageBox>
#include <QKeyEvent>

using namespace GlobalNameSpace;

NewMessageDialogForOwner::NewMessageDialogForOwner(unsigned long long keyOfOwner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMessageDialogForOwner)
{
    ui->setupUi(this);

    this->keyOfOwner = keyOfOwner;
}

NewMessageDialogForOwner::~NewMessageDialogForOwner()
{
    delete ui;
}

void NewMessageDialogForOwner::on_sendB_clicked()
{

    const QString text = ui->textE->text();

    if (text.isEmpty()){
        QMessageBox::critical(this, "Failed", "You forget to enter the message!");
    }
    else{
        Message m;
        m.setText(text);
        m.setKeySender(Globals::KEY_USER);
        m.setKeyReciever(keyOfOwner);
        Globals::MESSAGE_LIST.pushBack(m);
        Globals::MESSAGE_LIST.writeFile();

        QMessageBox::information(this, "Done", "Message sent.");

        this->close();
    }
}


void NewMessageDialogForOwner::on_backB_clicked()
{
    this->close();
}
void NewMessageDialogForOwner::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_sendB_clicked();
    }

}
