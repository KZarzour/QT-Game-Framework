/**
* \file Game1WelcomePage.cpp
* \brief contains initialization of welcome page of game 1. (Instructions + Start Button)
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

#include "game1welcomepage.h"

Game1WelcomePage::Game1WelcomePage()
{
    gameInsructions = new QLabel();
    playGame = new QPushButton("Start Game");


    setupScene();
}

/**
 * @brief Game1WelcomePage::setupScene, sets up the scene for the welcome page of game 1
 */
void Game1WelcomePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/game1background.jpg")));

    gameInsructions->setText("The goal is to find and strike\n the battleships presenting \nbad coding practices by answering questions \nabout software development.");
    gameInsructions->setWindowFlag(Qt::FramelessWindowHint);
    gameInsructions->setAttribute(Qt::WA_NoSystemBackground);
    gameInsructions->setStyleSheet("QLabel { font-size: 18px;font-family: Arial; font-weight: bold; color: white}");
    //gameInsructions->setAlignment(Qt::AlignCenter);
    gameInsructions->setWordWrap(true);
    gameInsructions->setGeometry(250,400,400,100);

    playGame->setGeometry(250,600,100,50);
    this->addWidget(gameInsructions);
    this->addWidget(playGame);

}
