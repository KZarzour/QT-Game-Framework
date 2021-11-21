/**
* \file mainPage.cpp
* \brief contains initialization of main menu page that is used to access and the games.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/



#include "mainpage.h"

mainPage::mainPage(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0,0,400,800);
    this->setBackgroundBrush(QBrush(QImage(":/images/main-page-background.jpg").scaled(500,1000)));

    QString userFullName = (activeUser != NULL) ? activeUser->firstName+" "+activeUser->lastName : "Guest";

    welcomeL = new QLabel("Welcome, " + userFullName+".");
    dateL = new QLabel(QDate::currentDate().toString("dd/MM/yyyy"));

    game1Logo = new QGraphicsPixmapItem();
    game2Logo = new QGraphicsPixmapItem();
    userProfilePicture = new QGraphicsPixmapItem();
    flag = new QGraphicsPixmapItem();

    game1Scores = new QLabel("");
    game2Scores = new QLabel("");

    game1B = new QPushButton("Battleship");
    game2B = new QPushButton("Shooting Discs");
    homeB = new QPushButton("Home");

    setupGameLogos();
    setupWidgetLocations();
    addProfilePicture();
    adjustLabelAppearance();
    fillScene();
}

/**
 * @brief mainPage::setupGameLogos, Sets the icons of the games in their corresponding place on the scene
 */
void mainPage::setupGameLogos(){
    game1Logo->setPixmap((QPixmap(":/images/game1-logo.png")).scaled(120,120));
    game1Logo->setPos(QPointF(30,250));

    game2Logo->setPixmap((QPixmap(":/images/game2-logo.jpg")).scaled(110,110));
    game2Logo->setPos(QPointF(260,250));
}
/**
 * @brief mainPage::setupWidgetLocations, Sets the geometry of the widgets
 */
void mainPage::setupWidgetLocations(){
    game1B->setGeometry(10,380,150,30);
    game2B->setGeometry(240,380,150,30);
    homeB->setGeometry(160,600,100,30);

    game1Scores->setGeometry(10,440,150,80);
    game1Scores->setWordWrap(true);
    game2Scores->setGeometry(240,440,150,80);
    game2Scores->setWordWrap(true);
}

/**
 * @brief mainPage::addProfilePicture, Decodes a user's profile picture from a QJsonValue into a QPixmap. Sets the Pixmap p to the corresponding profile pic location on the scene
 */
void mainPage::addProfilePicture(){
    if(activeUser && (activeUser->profilePicture).toString()!=""){
        QJsonValue val = activeUser->profilePicture;
        auto const encodedProfilePicture = val.toString().toLatin1();
        QPixmap pic;
        pic.loadFromData(QByteArray::fromBase64(encodedProfilePicture),"PNG");
        userProfilePicture->setPixmap(pic.scaled(100,100));
        userProfilePicture->setPos(QPointF(400,65));
        this->addItem(userProfilePicture);
        setFlag();

    }
}
/**
 * @brief mainPage::setFlag, sets the flag for corresponding active user
 */
void mainPage::setFlag(){
    QString iso = activeUser->findCorrespondingFlag();
    QString path= ":/images/flags/"+iso+".png";
    flag->setPixmap(QPixmap(path));
    flag->setPos(QPointF(180,40));
    this->addItem(flag);
}
/**
 * @brief mainPage::adjustLabelAppearance, Function used to fix Labels.
 */
void mainPage::adjustLabelAppearance(){
    welcomeL->setWindowFlag(Qt::FramelessWindowHint);
    welcomeL->setAttribute(Qt::WA_NoSystemBackground);
    welcomeL->setStyleSheet("QLabel { font-size: 26px;font-family: Arial; font-weight: bold; color: white}");
    welcomeL->setGeometry(0,100,400,40);
    welcomeL->setAlignment(Qt::AlignCenter);

    dateL->setAttribute(Qt::WA_NoSystemBackground);
    dateL->setWindowFlag(Qt::FramelessWindowHint);
    dateL->setStyleSheet("QLabel {font-size: 20px;font-family: Arial; color: white; font-weight: bold}");
    dateL->setGeometry(0,130,400,40);
    dateL->setAlignment(Qt::AlignCenter);

    game1Scores -> setAttribute(Qt::WA_NoSystemBackground);
    game1Scores -> setStyleSheet("QLabel { font-weight: bold; color: white}");

    game2Scores -> setAttribute(Qt::WA_NoSystemBackground);
    game2Scores -> setStyleSheet("QLabel { font-weight: bold; color: white}");
}

/**
 * @brief mainPage::fillScene, Function Used to fill the Scene
 */
void mainPage::fillScene(){
    this->addWidget(welcomeL);
    this->addWidget(dateL);

    this->addItem(game1Logo);
    this->addItem(game2Logo);

    this->addWidget(game1B);
    this->addWidget(game2B);
    this->addWidget(homeB);

    this->addWidget(game1Scores);
    this->addWidget(game2Scores);

}
/**
 * @brief mainPage::updateScores, Displays a user's scores to the scene for each corresponding game
 */
void mainPage::updateScores(){
    QString scores1 ="Game 1 Scores:\n";
    QVector<int> game1scores = activeUser->game1Scores;
    for(int i :game1scores){
         scores1 = scores1 + QString::number(i)+",";
    }

    scores1.remove(scores1.size()-1, 1);
    scores1 = scores1 + "\n\nYour highest score is " + QString::number(activeUser->game1HighScore);
    game1Scores->setText(scores1);


    QString scores2 = "Game 2 Scores:\n";
    QVector<int> game2scores = activeUser->game2Scores;
    for(int i :game2scores){
        scores2 = scores2 + QString::number(i)+",";
    }

    scores2.remove(scores2.size()-1, 1);
    scores2 = scores2+ "\n\nYour highest score is " + QString::number(activeUser->game2HighScore);
    game2Scores->setText(scores2);
}
/**
 * @brief mainPage::clearPage
 * Called when we need to go to the maingview
 * Cleans all widgets in order to prepare for another user to login/signup
 */
void mainPage:: clearPage(){
    this->activeUser = NULL;
    this->welcomeL->setText("Hello Guest!");
    this->removeItem(userProfilePicture);
    this->game1Scores->setText("Please SignUp/In to save your scores");
    this->game2Scores->setText("Please SignUp/In to save your scores");
}
