#include "signuppage.h"

/**
* \file SignupPage.cpp
* \brief contains initialization of the Signup page.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

SignupPage::SignupPage(QWidget *parent) : QWidget(parent)
{
    headerL = new QLabel("Fill This Form To Sign Up");
    warningL = new QLabel();
    SignInPromptL = new QLabel("Already Have an Account?");

    firstNameLE = new QLineEdit();
    lastNameLE = new QLineEdit();
    usernameLE = new QLineEdit();
    passwordLE = new QLineEdit();
    confirmPasswordLE = new QLineEdit();
    phoneNumberLE = new QLineEdit();

    passwordLE->setEchoMode(QLineEdit::Password);
    confirmPasswordLE->setEchoMode(QLineEdit::Password);

    daySB = new QSpinBox();
    monthSB = new QSpinBox();
    yearSB = new QSpinBox();

    daySB->setRange(1,31);
    monthSB->setRange(1,12);
    yearSB->setRange(1900,2030);

    maleRB = new QRadioButton("Male");
    femaleRB = new QRadioButton("Female");

    signUpB = new QPushButton("Sign Up");
    signInB = new QPushButton("Sign In");
    uploadImageB = new QPushButton("Browse...");
    playAsGuestB = new QPushButton("Play As Guest");

    //Header
    QFont font = headerL->font();
    font.setBold(true);
    font.setPixelSize(18);
    headerL->setFont(font);

    //Layouts
    groupBox = new QGroupBox();
    formL=new QFormLayout();
    GenderVerticalL=new QVBoxLayout();
    signInL=new QHBoxLayout();
    dateL=new QHBoxLayout();
    viewL=new QVBoxLayout();
    birthdayL = new QHBoxLayout();
    playAsGuestL = new QHBoxLayout;
    setupWidgets();

    QObject::connect(signUpB,SIGNAL(clicked(bool)),this,SLOT(addUser()));
    QObject::connect(uploadImageB,SIGNAL(clicked(bool)),this,SLOT(browseImage()));
}
/**
 * @brief SignupPage::setupWidgets
 * Sets the geometry of the widgets
 */
void SignupPage::setupWidgets(){
    //GenderVertical Layout
    GenderVerticalL->addWidget(maleRB);
    GenderVerticalL->addWidget(femaleRB);

    groupBox->setLayout(GenderVerticalL);

    //Birthday Layout
    birthdayL->addWidget(daySB);
    birthdayL->addWidget(monthSB);
    birthdayL->addWidget(yearSB);

    //Play As A Guest Layout
    playAsGuestL->addWidget(new QLabel("Don't Want To Sign Up?"));
    playAsGuestL->addWidget(playAsGuestB);

    //SignIn Layout
    signInL->addWidget(SignInPromptL);
    signInL->addWidget(signInB);

    //Form Layout
    formL->addRow(tr("First Name "),firstNameLE);
    formL->addRow(tr("Last Name "),lastNameLE);
    formL->addRow(tr("Username "),usernameLE);
    formL->addRow(tr("Upload Profile Picture "),uploadImageB);
    formL->addRow(tr("Phone Number eg:+961-76123456 "),phoneNumberLE);
    formL->addRow(tr("Date of Birth(dd/mm/yyyy) "),birthdayL);
    formL->addRow(tr("Gender "),groupBox);
    formL->addRow(tr("Password "),passwordLE);
    formL->addRow(tr("Confirm Password"),confirmPasswordLE);
    formL->setSpacing(10);

    //Final Layout
    viewL->addWidget(headerL);
    viewL->addWidget(warningL);
    viewL->addItem(formL);
    viewL->addWidget(signUpB);
    viewL->addItem(signInL);
    viewL->addItem(playAsGuestL);

    setLayout(viewL);
//    this->setFixedSize(800,800);
}
/**
 * @brief SignupPage::checkPassword, Checks if a password is valid, of size at least 4 and have special chars
 * @param password
 * @return True if valid, false otherwise.
 */
bool SignupPage::checkPassword(QString password){
    std::string pw = password.toLocal8Bit().constData();
         bool cap = false,
         len = false,
         digit = false,
         lower=false;

         // Check length
         if (pw.length() >= 8)
             len = true;

         for (const auto &ch : pw)
         {
             if (isdigit(ch))
                 digit = true;
             if (isupper(ch))
                 cap = true;
             if (islower(ch))
                 lower = true;
         }
         return cap && len && digit && lower;
}
/**
 * @brief SignupPage::createUser, Reads the input from the widgets and attemps to create a new user
 * @return if successful, returns the new user (not yet added to users.json)
    else, returns NULL
 */
User* SignupPage::createUser(){
    if(passwordLE->text()!=confirmPasswordLE->text()){
        warningL->setStyleSheet("color : red");
        warningL->setText("Password and Confirmation DO NOT Match!");
        return NULL;
    }

    User* user = new User();
    user->firstName=firstNameLE->text();
    user->lastName=lastNameLE->text();
    user->username=usernameLE->text();
    user->password=passwordLE->text();
    user->phonenumber = phoneNumberLE->text();
    user->dob=daySB->text()+"/"+monthSB->text()+"/"+yearSB->text();
    if(maleRB->isChecked()){
        user->gender="male";
    }
    else if(femaleRB->isChecked()){
        user->gender="female";
    }
    QImage image;
    auto load = image.load(fileName);
    if(!load){
        qWarning("Image not loaded successfully!");
    }
    auto pixMap = QPixmap::fromImage(image);
    auto encodedValue = json.encodeProfilePicture(pixMap);
    user->profilePicture=encodedValue;

    if(!user->isUnique()){
        qWarning("Username Is Taken!");
        warningL->setStyleSheet("color: red");
        warningL->setText("Username Is Taken!");
        delete user;
        return NULL;
    }

    if(!user->isValid()){
        qWarning("Missing Details!");
        warningL->setStyleSheet("color: red");
        warningL->setText("Missing Details!");
        delete user;
        return NULL;
    }

    if(!checkPassword(passwordLE->text())){
        qWarning("Weak Password, Please Change!");
        warningL->setStyleSheet("color: red");
        warningL->setText("Weak Password, Please Change!");
        delete user;
        return NULL;
    }
    this->activeUser=user;
    return user;
}
/**
 * @brief SignupPage::clearPage, this methods resets all the widgets that took user input
 */
void SignupPage::clearPage(){
    firstNameLE->clear();
    lastNameLE->clear();
    usernameLE->clear();
    passwordLE->clear();
    confirmPasswordLE->clear();
    phoneNumberLE->clear();
    daySB->clear();
    monthSB->clear();
    yearSB->clear();
    maleRB->setAutoExclusive(false);
    femaleRB->setAutoExclusive(false);
    maleRB->setChecked(false);
    femaleRB->setChecked(false);
    maleRB->setAutoExclusive(true);
    femaleRB->setAutoExclusive(true);
    passwordLE->clear();
    confirmPasswordLE->clear();
}
/**
 * @brief SignupPage::addUser
 * Called whenever the signup button is pressed
 * calls createUser() in order to check all necessary conditions before adding a new user to the users.json file
 * if createUser() returned a user, setUser() appends it to users.json
 */
void SignupPage::addUser(){
    User* user = createUser();
    if(user==NULL){
        return;
    }
    QJsonObject userJson = user->userToJson();
    json.addUserToJson(userJson);
    clearPage();
}
/**
 * @brief SignupPage::browseImage
 *
 * Takes profile picture file path from user
 * updates the corresponding class member
 */
void SignupPage::browseImage(){
    this->fileName = QFileDialog::getOpenFileName(this,"Browse File","");
}

