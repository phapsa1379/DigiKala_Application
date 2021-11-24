#ifndef ADDPRODUCT1_H
#define ADDPRODUCT1_H

#include <QDialog>
#include <QtWidgets>
#include <QWidget>

namespace Ui {
class AddProduct1;
}

class AddProduct1 : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct1(QWidget *parent = nullptr);
    ~AddProduct1();

private slots:

    void on_confirmB_clicked();

    void on_cancelB_clicked();

private:
    Ui::AddProduct1 *ui;
};

#endif // ADDPRODUCT1_H
