#include "ReportDialog.h"
#include "ui_ReportDialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include "Global.h"
#include <QScrollArea>
#include <QPushButton>
#include <QCloseEvent>
#include <QMessageBox>


using namespace std;
using namespace GlobalNameSpace;

ReportDialog::ReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window
            | Qt::WindowMinimizeButtonHint
            | Qt::WindowMaximizeButtonHint);

    delete layout();

    this->setWindowTitle("List Of Reports");

    QString nameOfSuspectProduct = "";
    QString date = "";
    QString reason = "";
    QString complainNumber = "";


    QVBoxLayout *layout = new QVBoxLayout;

    Report r;
    Product p;

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true); // CRITICAL

    QFrame* inner = new QFrame(scroll);
    inner->setLayout(layout);


    scroll->setWidget(inner); // CRITICAL

    const int SIZE = Globals::REPORT_LIST.size();

    for (int i = 0; i < SIZE; i++){

        r = Globals::REPORT_LIST.get(i);
        int indexOfProduct = Globals::PRODUCT_LIST.findIndexByKey(r.getKeyProduct());
        p = Globals::PRODUCT_LIST.get(indexOfProduct);

        date = "Date: " + r.getDate() + "                                                                   ";
        nameOfSuspectProduct = "Name Of Reported Product: " + p.getName();
        reason = "Reason: " + r.getReason();
        complainNumber = "Complain Number: " + QString::number(p.getComplainNumber());

        QLabel *nameOfSuspectProductL = new QLabel(date);
        QLabel *dateL = new QLabel(nameOfSuspectProduct);
        QLabel *reasonL = new QLabel(reason);
        QLabel *complainNumberL = new QLabel(complainNumber);

        inner->layout()->addWidget(dateL);
        inner->layout()->addWidget(reasonL);
        inner->layout()->addWidget(complainNumberL);
        inner->layout()->addWidget(nameOfSuspectProductL);

        QFrame *line = new QFrame();
        line->setFrameShape(QFrame::HLine); // Horizontal line
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(3);

        inner->layout()->addWidget(line);
    }

    QPushButton* backB = new QPushButton("Back");
    inner->layout()->addWidget(backB);

    connect(backB, SIGNAL(clicked(bool)), this, SLOT(on_btn_backB_clicked(bool)));
}


void ReportDialog::on_btn_backB_clicked(bool)
{

    this->hide();
    this->scroll->hide();
}




ReportDialog::~ReportDialog()
{
    delete ui;
}


void ReportDialog::closeEvent(QCloseEvent *event) {
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


