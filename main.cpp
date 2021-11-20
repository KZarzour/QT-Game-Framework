#include <QApplication>

#include "appmainview.h"

/**
* \mainpage EECE 435L Game Framework
* \author Karim Zarzour
* \author Maarouf Yassine
* \date 20-11-2021
*/

int main(int argc, char **argv){
    QApplication app(argc, argv);

    AppMainView * mainView = new AppMainView();

    mainView -> setFixedSize(800, 800);
//    mainView -> show();
    mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    return app.exec();

}
