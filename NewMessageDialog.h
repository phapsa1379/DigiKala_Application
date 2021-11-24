#ifndef NEWMESSAGEDIALOG_H
#define NEWMESSAGEDIALOG_H

#include <QDialog>
#include "personal_page1.h"
#include "personal_page2.h"
#include "ContactListDialog.h"

enum backButton{BACK_TO_PRODUCT_DETAILS, BACK_TO_CONTACT_DIALOG};

namespace Ui {
class NewMessageDialog;
}

class NewMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMessageDialog(QWidget *parent = nullptr);
    ~NewMessageDialog();
    void setBack(ContactListDialog * b);
    unsigned long long keyOfUser(QString username);

private slots:

    void on_sendB_clicked();
    void on_backB_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:

    Ui::NewMessageDialog *ui;
    ContactListDialog *back_;

};

#endif // NEWMESSAGEDIALOG_H
