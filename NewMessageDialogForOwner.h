#ifndef NEWMESSAGEDIALOGFOROWNER_H
#define NEWMESSAGEDIALOGFOROWNER_H

#include <QDialog>

namespace Ui {
class NewMessageDialogForOwner;
}

class NewMessageDialogForOwner : public QDialog
{
    Q_OBJECT

public:
    explicit NewMessageDialogForOwner(unsigned long long keyOfOwner, QWidget *parent = nullptr);
    ~NewMessageDialogForOwner();

private slots:

    void on_sendB_clicked();
    void on_backB_clicked();


protected:
    void keyPressEvent(QKeyEvent *event);

private:

    unsigned long long keyOfOwner;

    Ui::NewMessageDialogForOwner *ui;
};

#endif // NEWMESSAGEDIALOGFOROWNER_H
