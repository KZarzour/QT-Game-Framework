#include "landingpage.h"
#include <QWidget>
#include <QtWidgets>
#include <QFont>

LandingPage::LandingPage(QWidget *parent) : QWidget(parent)
{
    welcomeLabel= new QLabel("Welcome");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    QFont welcomeLabelFont("Arial", 20, QFont::Bold);
    welcomeLabel->setFont(welcomeLabelFont);
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

    verticalLayout->addWidget(welcomeLabel,0);
    verticalLayout->addLayout(gridLayout,1);
    verticalLayout->addWidget(signInPushButton,2);
    verticalLayout->addWidget(signUpPushButton,2);
    verticalLayout->addWidget(guestPushButton,2);

    setLayout(verticalLayout);
}
