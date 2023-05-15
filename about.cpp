#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) : dfd
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    delete ui;
}
