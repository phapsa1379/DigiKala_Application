#include <QApplication>
#include "login.h"
#include "ExternalFunctions.h"



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // DONT TUCH THIS CODE // DAST NAZAN BE KOD HAYE PAYEEN

    startApp();

    //cout << DEALER_LIST << endl;
    login *ww = new login();
    ww->setWindowTitle("Sign in");
    ww->setLogin(ww);
    ww->show();
    // DONT TUCH THIS CODE  // DAST NAZAN BE KOD HAYE BALA

    return app.exec();

}


