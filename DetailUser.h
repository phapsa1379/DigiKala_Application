#ifndef DETAILUSER_H
#define DETAILUSER_H

#include <QDialog>

namespace Ui {
class DetailUser;
}

class DetailUser : public QDialog
{
    Q_OBJECT

public:
    explicit DetailUser(QWidget *parent = nullptr);
    ~DetailUser();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::DetailUser *ui;
    void fillBlonks();
};

#endif // DETAILUSER_H
