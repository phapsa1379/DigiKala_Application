#ifndef PERSONAL_page2_H
#define PERSONAL_page2_H

#include <QMainWindow>
//#include "common_questions.h"
//#include "offers.h"
#include "EditProfileUser.h"

namespace Ui {
class personal_page2;
}

class personal_page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit personal_page2(QWidget *parent = nullptr);
    ~personal_page2();

private slots:
    void on_actionSign_Out_2_triggered();

    void on_actionCommon_Questions_triggered();

    //void on_actionDiscounts_and_Offers_triggered();

    void on_actionEdit_Profile_triggered();

    void on_actionView_Account_triggered();
    void on_actionBought_Basket_triggered();

    void on_actionTotal_list_of_goods_triggered();

    void on_actionFavourites_triggered();

    void on_actionSales_List_triggered();

    void on_actionAdd_Goods_triggered();



    void on_actionDigital_triggered();

    void on_actionClothes_triggered();

    void on_actionNutrition_triggered();

    void on_actionHealth_triggered();

    void on_actionMake_up_triggered();

    void on_actionCar_triggered();

    void on_actionOffice_Equipment_triggered();

    void on_actionHouse_triggered();

    void on_actionKitchen_triggered();

    void on_actionBook_triggered();

    void on_actionArt_triggered();

    void on_actionStationary_triggered();

    void on_actionToys_triggered();

    void on_actionChildren_triggered();

    void on_actionSport_triggered();

    void on_actionTrip_triggered();

    void on_actionChats_triggered();

    void on_actionView_Report_triggered();

    void on_actionDiscounts_and_Offers_triggered();

protected:
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::personal_page2 *ui;

};

#endif // PERSONAL_page2_H
