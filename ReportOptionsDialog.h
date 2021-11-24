#ifndef REPORTOPTIONSDIALOG_H
#define REPORTOPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class ReportOptionsDialog;
}

class ReportOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportOptionsDialog(QWidget *parent = nullptr);
    ~ReportOptionsDialog();

private slots:
    void on_confirmB_clicked();

    void on_cancelB_clicked();

private:
    Ui::ReportOptionsDialog *ui;
};

#endif // REPORTOPTIONSDIALOG_H
