#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QWidget>
#include <QtWidgets>

class LandingPage : public QWidget
{
    Q_OBJECT
public:
    explicit LandingPage(QWidget *parent = nullptr);
    QLabel * welcomeLabel= new QLabel("Welcome");
    QLabel * userNameLabel= new QLabel("Username");
    QLabel * passwordLabel= new QLabel("Password");
    QLineEdit * userNameLineEdit = new QLineEdit;
    QLineEdit * passwordLineEdit = new QLineEdit;
    QPushButton * signInPushButton = new QPushButton("Sign In");
    QPushButton * signUpPushButton = new QPushButton("Sign Up");
    QPushButton * guestPushButton = new QPushButton("Continue as Guest");
    QGridLayout * gridLayout = new QGridLayout;
    QVBoxLayout * verticalLayout = new QVBoxLayout;
signals:

};

#endif // LANDINGPAGE_H
