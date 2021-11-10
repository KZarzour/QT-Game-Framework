#ifndef APPMAINVIEW_H
#define APPMAINVIEW_H

#include <QObject>
#include <QGraphicsView>
#include "Accounts_Framework/jsonutils.h"
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/signuppage.h"
#include "Accounts_Framework/mainpage.h"
#include "Accounts_Framework/landingpage.h"
#include "Game1-BattleShip/game1view.h"
#include "Game2-ShootingDiscs/game2view.h"

class AppMainView : public QGraphicsView
{
    Q_OBJECT
public:
    AppMainView();

    JsonUtils *jsonUtils;
    SignupPage *signupPage;
    LandingPage *landingPage;
    mainPage *menuPage;
    Game1View *game1View;
    Game2View *game2View;

    void connectButtons();

public slots:
    void signup();
    void openMainPage();
    void playAsGuest();
    void login();
    void authenticateUser();
    void logOut();
    void playGame1();
    void playGame2();

};

#endif // APPMAINVIEW_H
