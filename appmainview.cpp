#include "appmainview.h"

AppMainView::AppMainView()
{
    jsonUtils = new JsonUtils();
    signupPage = new SignupPage();
    menuPage = new mainPage();
    landingPage=new LandingPage();
    game1View = new Game1View();
    landingPage->show();

    connectButtons();
}

void AppMainView::connectButtons(){

    QObject::connect(signupPage->signUpB,SIGNAL(clicked(bool)),this,SLOT(openMainPage()));
    QObject::connect(signupPage->playAsGuestB,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(signupPage->signInB,SIGNAL(clicked(bool)),this,SLOT(login()));

    QObject::connect(landingPage->guestPushButton,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(landingPage->signUpPushButton,SIGNAL(clicked(bool)),this,SLOT(signup()));
    QObject::connect(landingPage->signInPushButton,SIGNAL(clicked(bool)),this,SLOT(authenticateUser()));

    QObject::connect(menuPage->homeB,SIGNAL(clicked(bool)),this,SLOT(logOut()));
    QObject::connect(menuPage->game1B,SIGNAL(clicked(bool)),this,SLOT(playGame1()));
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
    else if (landingPage->activeUser!=NULL){
        landingPage->close();
        menuPage->activeUser = landingPage->activeUser;
        menuPage->welcomeL->setText(QString("Welcome, "+landingPage->activeUser->firstName+" "+landingPage->activeUser->lastName+"."));
        menuPage->addProfilePicture();
        menuPage->updateScores();
        this->setScene(menuPage);
        this->show();
    }
}
void AppMainView::playAsGuest(){
    signupPage->hide();
    landingPage->hide();
    menuPage->clearPage();
    this->setScene(menuPage);
    this->show();
}
void AppMainView::login(){
    signupPage->close();
    signupPage->clearPage();
    landingPage->userNameLineEdit->clear();
    landingPage->passwordLineEdit->clear();
    landingPage->warningLabel->clear();
    landingPage->show();
}

void AppMainView::authenticateUser(){
    QString username =landingPage->userNameLineEdit->text();
    QString password=landingPage->passwordLineEdit->text();
    landingPage->activeUser=new User(jsonUtils->validateUser(username,password));
    if (landingPage->activeUser->isValid()){
        openMainPage();
    }
    else {
        landingPage->warningLabel->setStyleSheet("color : red");
        landingPage->warningLabel->setText("Incorrect Username/Password pair");
    }
}

void AppMainView::logOut(){
    landingPage->activeUser=NULL;
    signupPage->activeUser=NULL;

    //add code to stop games and update scores

    menuPage->clearPage();
    this->hide();
    this->login();
}

void AppMainView::playGame1(){
    game1View->activeUser = menuPage->activeUser;

    this->hide();
    game1View->show();
}
