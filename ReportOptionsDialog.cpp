#include "ReportOptionsDialog.h"
#include "ui_ReportOptionsDialog.h"
#include "ReportTypes.h"
#include "Global.h"
#include "ExternalFunctions.h"
#include <QMessageBox>

using namespace GlobalNameSpace;

ReportOptionsDialog::ReportOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportOptionsDialog)
{
    ui->setupUi(this);

    for (int i = 0; i < 8; i++){
        ui->listWidget->addItem(report_array[i]);
    }

    ui->listWidget->setCurrentRow(0);


}

ReportOptionsDialog::~ReportOptionsDialog()
{
    delete ui;
}

void ReportOptionsDialog::on_confirmB_clicked()
{
    const int index = ui->listWidget->currentRow();
    Report r;
    r.setDate(NowTime());
    r.setKeyProduct(Globals::KEY_PRODUCT);
    r.setReason(report_array[index]);

    Globals::REPORT_LIST.pushBack(r);

    NodeProduct* p_node =  &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    Product p_data = p_node->getData();

    p_data.setComplainNumber(p_data.getComplainNumber() + 1);
    p_node->setData(p_data);

    Globals::REPORT_LIST.writeFile();
    Globals::PRODUCT_LIST.writeFile();

    QMessageBox::information(this, "Report Sent", "Thanks for your report.\n"
                                                  "The products with more than 2 reports will be"
                                                  " removed from the main list of products.");

    close();

}

void ReportOptionsDialog::on_cancelB_clicked()
{
    close();
}
