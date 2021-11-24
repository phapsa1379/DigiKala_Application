#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QScrollArea>
#include <QDialog>

#include "personal_page1.h"
#include "personal_page2.h"


namespace Ui {
class ReportDialog;
}

class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportDialog(QWidget *parent = nullptr);
    ~ReportDialog();


    QScrollArea *scroll;

private slots:
    void on_btn_backB_clicked(bool);
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::ReportDialog *ui;



};

#endif // REPORTDIALOG_H
