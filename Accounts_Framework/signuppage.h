#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QtWidgets>
#include <QPixmap>
#include <QJsonObject>
#include <QFileDialog>
#include <QImage>
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/jsonutils.h"

class SignupPage : public QWidget
{
    Q_OBJECT
public:
    SignupPage(QWidget *parent = nullptr);

    User *activeUser = NULL;
    JsonUtils json;

    QLabel *headerL;
    QLabel *warningL;
    QLabel *SignInPromptL;
    QLineEdit *firstNameLE;
    QLineEdit *lastNameLE;
    QLineEdit *usernameLE;
    QLineEdit *passwordLE;
    QLineEdit *confirmPasswordLE;
    QLineEdit *phoneNumberLE;
    QSpinBox *daySB;
    QSpinBox *monthSB;
    QSpinBox *yearSB;
    QRadioButton *maleRB;
    QRadioButton *femaleRB;
    QPushButton *signUpB;
    QPushButton *signInB;
    QPushButton *uploadImageB;
    QPushButton *playAsGuestB;

    QGroupBox *groupBox;
    QFormLayout *formL;
    QVBoxLayout *GenderVerticalL;
    QHBoxLayout *signInL;
    QHBoxLayout *playAsGuestL;
    QHBoxLayout *dateL;
    QVBoxLayout *viewL;
    QHBoxLayout *birthdayL;

    QString fileName;


public:
    bool checkPassword(QString password);
    User* createUser();
    void clearPage();
    void setupWidgets();

public slots:
    void addUser();
    void browseImage();

};

#endif // SIGNUPPAGE_H
