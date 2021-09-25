#ifndef APPMAINVIEW_H
#define APPMAINVIEW_H

#include <QObject>
#include <QGraphicsView>
#include "Accounts_Framework/jsonutils.h"
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/signuppage.h"
#include "Accounts_Framework/mainpage.h"
#include "Accounts_Framework/landingpage.h"

class AppMainView : public QGraphicsView
{
    Q_OBJECT
public:
    AppMainView();

    JsonUtils *jsonUtils;
    SignupPage *signupPage;
    LandingPage *landingPage;
    mainPage *menuPage;

    void connectButtons();

public slots:
    void signup();
    void openMainPage();
    void playAsGuest();

};

#endif // APPMAINVIEW_H
