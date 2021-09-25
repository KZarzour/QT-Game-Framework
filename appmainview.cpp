#include "appmainview.h"

AppMainView::AppMainView()
{
    jsonUtils = new JsonUtils();
    signupPage = new SignupPage();
    menuPage = new mainPage();
    landingPage=new LandingPage();
    landingPage->show();

    connectButtons();
}

void AppMainView::connectButtons(){


    //QObject::connect(signupPage->signInB);
    QObject::connect(signupPage->signUpB,SIGNAL(clicked(bool)),this,SLOT(openMainPage()));
    QObject::connect(signupPage->playAsGuestB,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(landingPage->guestPushButton,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(landingPage->signUpPushButton,SIGNAL(clicked(bool)),this,SLOT(signup()));


}

void AppMainView::signup(){
    this->hide();
    landingPage->hide();
    signupPage->clearPage();
    signupPage->show();
}
void AppMainView::openMainPage(){
    if(signupPage->activeUser!=NULL){
        signupPage->close();
        //loginPage->activeUser = NULL;
        menuPage->activeUser = signupPage->activeUser;
        menuPage->welcomeL->setText(QString("Welcome, "+signupPage->activeUser->firstName+" "+signupPage->activeUser->lastName+"."));
        menuPage->addProfilePicture();
        menuPage->updateScores();
        this->setScene(menuPage);
        this->show();
    }
    //implement here else statement when we come from login page
}
void AppMainView::playAsGuest(){
    signupPage->hide();
    landingPage->hide();
    menuPage->clearPage();
    this->setScene(menuPage);
    this->show();
}
