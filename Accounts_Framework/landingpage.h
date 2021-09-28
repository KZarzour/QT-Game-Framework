#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QWidget>
#include <QtWidgets>
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/jsonutils.h"

class LandingPage : public QWidget
{
    Q_OBJECT
public:
    explicit LandingPage(QWidget *parent = nullptr);

    User *activeUser = NULL;
    JsonUtils json;

    QLabel * welcomeLabel;
    QLabel * warningLabel;
    QLabel * userNameLabel;
    QLabel * passwordLabel;
    QLineEdit * userNameLineEdit;
    QLineEdit * passwordLineEdit;
    QPushButton * signInPushButton;
    QPushButton * signUpPushButton;
    QPushButton * guestPushButton;
    QGridLayout * gridLayout;
    QVBoxLayout * verticalLayout;
public slots:
    void authenticateUser();

};

#endif // LANDINGPAGE_H
