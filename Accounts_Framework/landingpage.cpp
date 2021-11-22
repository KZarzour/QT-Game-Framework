/**
* \file LandingPage.cpp
* \brief contains definition of landing page that is displayed when user accesses the app.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

#include "landingpage.h"
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include <Accounts_Framework/user.h>


/**
 * @brief LandingPage::LandingPage, sets the geometry of all widgets and labels. Adds them to the scene
 * @param parent
 */
LandingPage::LandingPage(QWidget *parent) : QWidget(parent)
{
    welcomeLabel= new QLabel("Welcome To QT Gaming Framework!");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    QFont welcomeLabelFont("Arial", 20, QFont::Bold);
    welcomeLabel->setFont(welcomeLabelFont);
    warningLabel= new QLabel();
    userNameLabel= new QLabel("Username: ");
    passwordLabel= new QLabel("Password: ");
    userNameLineEdit = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    signInPushButton = new QPushButton("Sign In");
    signUpPushButton = new QPushButton("Sign Up");
    guestPushButton = new QPushButton("Continue as Guest");

    gridLayout = new QGridLayout;
    verticalLayout = new QVBoxLayout;

    gridLayout->addWidget(userNameLabel,0,0);
    gridLayout->addWidget(passwordLabel,1,0);
    gridLayout->addWidget(userNameLineEdit,0,1);
    gridLayout->addWidget(passwordLineEdit,1,1);

    verticalLayout->addWidget(welcomeLabel);
    verticalLayout->addWidget(warningLabel);
    verticalLayout->addLayout(gridLayout);
    verticalLayout->addWidget(signInPushButton);
    verticalLayout->addWidget(signUpPushButton);
    verticalLayout->addWidget(guestPushButton);

    setLayout(verticalLayout);

}

