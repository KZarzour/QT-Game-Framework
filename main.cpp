#include <QApplication>

#include "appmainview.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    AppMainView * mainView = new AppMainView();

    mainView -> setFixedSize(800, 800);
    mainView -> show();

    return app.exec();

}
