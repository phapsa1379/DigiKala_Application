#ifndef LISTSETTINGSPRODUCT_H
#define LISTSETTINGSPRODUCT_H

#include <QDialog>


namespace Ui {
class ListSettingsProduct;
}

class ListSettingsProduct : public QDialog
{
    Q_OBJECT

public:
    explicit ListSettingsProduct(QWidget *parent = nullptr);
    ~ListSettingsProduct();

    static QString getSortBasedOn();
    static QString getSortType();
    static QString getGroup();
    static QString getState();
    static QString getCategory();
    static double getUtmostPrice();

    static void setSortBasedOn(QString);
    static void setSortType(QString);
    static void setGroup(QString);
    static void setUtmostPrice(double);
    static void setState(QString);
    static void setCategory(QString);
    static void filterList();

public slots:
    void on_confirmB_clicked();


    void on_cancelB_clicked();

private:

    static QString sortBasedOn;
    static QString category;
    static QString sortType;
    static QString group;
    static QString state;
    static double utmostPrice;


    Ui::ListSettingsProduct *ui;
};

#endif // LISTSETTINGSPRODUCT_H
