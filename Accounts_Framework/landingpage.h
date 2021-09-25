#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QWidget>
#include <QtWidgets>

class LandingPage : public QWidget
{
    Q_OBJECT
public:
    explicit LandingPage(QWidget *parent = nullptr);
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
signals:

};

#endif // LANDINGPAGE_H
