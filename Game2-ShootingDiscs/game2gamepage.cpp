#include "game2gamepage.h"

Game2GamePage::Game2GamePage()
{
    leftArrow = new QGraphicsPixmapItem();
    downArrow = new QGraphicsPixmapItem();
    rightArrow = new QGraphicsPixmapItem();
    gameGrid = new QGraphicsPixmapItem();

    home = new QPushButton("Home");

    currentScore = new QLabel("Current Score");
    highScore = new QLabel("High Score");
    currentScoreValue = new QLabel("0");
    highScoreValue = new QLabel();

    setupScene();
    setupWidgets();
    /*setupGrid();
    setupButtons();
    setupLabels();*/
    fillScene();
}
void Game2GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));
}
void Game2GamePage::setupWidgets(){
    currentScore->setGeometry(60,150,500,80);
    currentScore->setAttribute(Qt::WA_NoSystemBackground);
    currentScore->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: white}");

    highScore->setGeometry(550,150,500,80);
    highScore->setAttribute(Qt::WA_NoSystemBackground);
    highScore->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: white}");

    currentScoreValue->setGeometry(250,150,500,80);
    currentScoreValue->setAttribute(Qt::WA_NoSystemBackground);
    currentScoreValue->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: green}");

    highScoreValue->setGeometry(650,150,500,80);
    highScoreValue->setAttribute(Qt::WA_NoSystemBackground);
    highScoreValue->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: green}");
}

void Game2GamePage::fillScene()
{
    this->addWidget(currentScore);
    this->addWidget(highScore);
    this->addWidget(currentScoreValue);
    this->addWidget(highScoreValue);
}
