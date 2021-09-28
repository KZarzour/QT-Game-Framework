#include "landingpage.h"
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include <Accounts_Framework/user.h>

LandingPage::LandingPage(QWidget *parent) : QWidget(parent)
{
    welcomeLabel= new QLabel("Welcome");
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
    //QObject::connect(signInPushButton,SIGNAL(clicked(bool)),this,SLOT(addUser()));

}

void LandingPage::authenticateUser(){
    QString username =userNameLineEdit->text();
    QString password=passwordLineEdit->text();
    this->activeUser=new User(json.validateUser(username,password));

};
