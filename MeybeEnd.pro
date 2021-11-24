QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddProduct1.cpp \
    ChangePassword.cpp \
    ContactListDialog.cpp \
    Dealer.cpp \
    DetailOfAllProducts.cpp \
    DetailOfBoughtProducts.cpp \
    DetailOfFavoriteProducts.cpp \
    DetailOfOnSaleProducts.cpp \
    DetailUser.cpp \
    DetailsOfOwner.cpp \
    DialogBuy.cpp \
    EditProduct.cpp \
    EditProfileUser.cpp \
    ExternalFuncions.cpp \
    Global.cpp \
    IncreaseMoney.cpp \
    KeyLinkedList.cpp \
    KeyNode.cpp \
    LinkedListMessage.cpp \
    LinkedListProduct.cpp \
    LinkedListReport.cpp \
    ListOfProducts.cpp \
    ListSettingsProduct.cpp \
    Message.cpp \
    NewMessageDialog.cpp \
    NewMessageDialogForOwner.cpp \
    NodeMessage.cpp \
    NodeProduct.cpp \
    NodeReport.cpp \
    PV.cpp \
    Product.cpp \
    ProductDelegateClass.cpp \
    RatingDialog.cpp \
    Report.cpp \
    ReportDialog.cpp \
    ReportOptionsDialog.cpp \
    StarDelegate.cpp \
    StarEditor.cpp \
    StarRating.cpp \
    TLinkedListUser.cpp \
    TNodeUser.cpp \
    Users.cpp \
    about.cpp \
    common_questions.cpp \
    forgot_password.cpp \
    help.cpp \
    login.cpp \
    main.cpp \
    MainWindow.cpp \
    offers.cpp \
    personal_page1.cpp \
    personal_page2.cpp \
    rating_product.cpp \
    signup.cpp \
    signup_dealer.cpp \
    signup_user.cpp

HEADERS += \
    AddProduct1.h \
    CategoryDatas.h \
    ChangePassword.h \
    ContactListDialog.h \
    CurrentTime.h \
    Dealer.h \
    DetailOfAllProducts.h \
    DetailOfBoughtProducts.h \
    DetailOfFavoriteProducts.h \
    DetailOfOnSaleProducts.h \
    DetailUser.h \
    DetailsOfOwner.h \
    DialogBuy.h \
    EditProduct.h \
    EditProfileUser.h \
    EnumsProduct.h \
    EnumsRecentActions.h \
    EnumsReport.h \
    ExternalFunctions.h \
    FastArrays.h \
    Global.h \
    IncreaseMoney.h \
    KeyLinkedList.h \
    KeyNode.h \
    LinkedListMessage.h \
    LinkedListProduct.h \
    LinkedListReport.h \
    ListOfProducts.h \
    ListSettingsProduct.h \
    MainWindow.h \
    Message.h \
    NewMessageDialog.h \
    NewMessageDialogForOwner.h \
    NodeMessage.h \
    NodeProduct.h \
    NodeReport.h \
    PV.h \
    Product.h \
    ProductDelegateClass.h \
    ProductDetail.cpp.autosave \
    RatingDialog.h \
    Report.h \
    ReportDialog.h \
    ReportOptionsDialog.h \
    ReportTypes.h \
    StarDelegate.h \
    StarEditor.h \
    StarRating.h \
    TLinkedListUser.h \
    TNodeUser.h \
    Users.h \
    about.h \
    common_questions.h \
    forgot_password.h \
    help.h \
    login.h \
    offers.h \
    personal_page1.h \
    personal_page2.h \
    rating_product.h \
    signup.h \
    signup_dealer.h \
    signup_user.h

FORMS += \
    AddProduct1.ui \
    ChangePassword.ui \
    ContactListDialog.ui \
    DetailOfAllProducts.ui \
    DetailOfBoughtProducts.ui \
    DetailOfFavoriteProducts.ui \
    DetailOfOnSaleProducts.ui \
    DetailUser.ui \
    DetailsOfOwner.ui \
    DialogBuy.ui \
    EditProduct.ui \
    EditProfileUser.ui \
    IncreaseMoney.ui \
    ListOfProducts.ui \
    ListSettingsProduct.ui \
    MainWindow.ui \
    NewMessageDialog.ui \
    NewMessageDialogForOwner.ui \
    PV.ui \
    RatingDialog.ui \
    ReportDialog.ui \
    ReportOptionsDialog.ui \
    about.ui \
    common_questions.ui \
    forgot_password.ui \
    help.ui \
    login.ui \
    offers.ui \
    personal_page1.ui \
    personal_page2.ui \
    rating_product.ui \
    signup.ui \
    signup_dealer.ui \
    signup_user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc \
    files.qrc

DISTFILES += \
    Divar.pro.user.be2bb85 \
    Divar.pro.user.f365116
