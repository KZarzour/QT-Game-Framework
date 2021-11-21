#include "appmainview.h"
/**
* \file AppMainView.cpp
* \brief contains initialization of main view of the application.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
AppMainView::AppMainView()
{
    jsonUtils = new JsonUtils();
    signupPage = new SignupPage();
    menuPage = new mainPage();
    landingPage=new LandingPage();
    game1View = new Game1View();
    game2View = new Game2View();
    landingPage->show();

    connectButtons();
}

/**
 * @brief AppMainView::connectButtons, connects the buttons to the functions that need to be called when they are clicked.
 */
void AppMainView::connectButtons(){

    QObject::connect(signupPage->signUpB,SIGNAL(clicked(bool)),this,SLOT(openMainPage()));
    QObject::connect(signupPage->playAsGuestB,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(signupPage->signInB,SIGNAL(clicked(bool)),this,SLOT(login()));

    QObject::connect(landingPage->guestPushButton,SIGNAL(clicked(bool)),this,SLOT(playAsGuest()));
    QObject::connect(landingPage->signUpPushButton,SIGNAL(clicked(bool)),this,SLOT(signup()));
    QObject::connect(landingPage->signInPushButton,SIGNAL(clicked(bool)),this,SLOT(authenticateUser()));

    QObject::connect(menuPage->homeB,SIGNAL(clicked(bool)),this,SLOT(logOut()));
    QObject::connect(menuPage->game1B,SIGNAL(clicked(bool)),this,SLOT(playGame1()));
    QObject::connect(menuPage->game2B,SIGNAL(clicked(bool)),this,SLOT(playGame2()));
}

/**
 * @brief AppMainView::signup, changes the page to the signup page.
 */
void AppMainView::signup(){
    this->hide();
    landingPage->hide();
    signupPage->clearPage();
    signupPage->show();
}

/**
 * @brief AppMainView::openMainPage, changes the page to the main page.
 */
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

/**
 * @brief AppMainView::playAsGuest, changes the page to  the main page and allows player to play without an account.
 */
void AppMainView::playAsGuest(){
    signupPage->hide();
    landingPage->hide();
    menuPage->clearPage();
    this->setScene(menuPage);
    this->show();
}

/**
 * @brief AppMainView::login, changes the page to the login page and clears widgets.
 */
void AppMainView::login(){
    signupPage->close();
    signupPage->clearPage();
    landingPage->userNameLineEdit->clear();
    landingPage->passwordLineEdit->clear();
    landingPage->warningLabel->clear();
    landingPage->show();
}

/**
 * @brief AppMainView::authenticateUser, on login checks if the username and password pair are correct.
 */
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

/**
 * @brief AppMainView::logOut, logs out the user from their account.
 */
void AppMainView::logOut(){
    landingPage->activeUser=NULL;
    signupPage->activeUser=NULL;

    //add code to stop games and update scores

    menuPage->clearPage();
    this->hide();
    this->login();
}

/**
 * @brief AppMainView::playGame1, changes page to game 1 welcome page.
 */
void AppMainView::playGame1(){
    game1View->activeUser = menuPage->activeUser;

    game1View->appMainView = this;

    this->hide();
    game1View->show();
}

/**
 * @brief AppMainView::playGame2, changes page to game 2 welcome page.
 */
void AppMainView::playGame2(){
    game2View->activeUser = menuPage->activeUser;

    game2View->appMainView = this;

    this->hide();
    game2View->show();
}
