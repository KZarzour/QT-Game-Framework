#include "game2welcomepage.h"

Game2WelcomePage::Game2WelcomePage()
{
    gameInsructions = new QLabel();
    playGame = new QPushButton("Start Game");


    setupScene();
}
void Game2WelcomePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/game1background.jpg")));

    gameInsructions->setText("The goal is to hit high number of discs.\nRed discs are worth 3 points; Green discs are worth 5 points; Blue discs are worth 7 points."
                             "\nUse Left, Right, and Down Arrows to Play.");
    gameInsructions->setWindowFlag(Qt::FramelessWindowHint);
    gameInsructions->setAttribute(Qt::WA_NoSystemBackground);
    gameInsructions->setStyleSheet("QLabel { font-size: 18px;font-family: Arial; font-weight: bold; color: white}");
    gameInsructions->setWordWrap(true);
    gameInsructions->setGeometry(250,400,400,100);

    playGame->setGeometry(250,600,100,50);
    this->addWidget(gameInsructions);
    this->addWidget(playGame);

}
