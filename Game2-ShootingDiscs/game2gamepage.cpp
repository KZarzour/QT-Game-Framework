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
    highScoreValue = new QLabel("123");

    redButton = new LowerPanelButton(nullptr, 0);
    greenButton = new LowerPanelButton(nullptr, 1);
    blueButton = new LowerPanelButton(nullptr, 2);

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(addDisk()));
    timer->start(2000);

    setupScene();
    setupWidgets();
    setupGrid();
    /*setupButtons();
    setupLabels();*/
    fillScene();
}
void Game2GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));
}
void Game2GamePage::setupWidgets(){
    currentScore->setGeometry(700,150,500,80);
    currentScore->setAttribute(Qt::WA_NoSystemBackground);
    currentScore->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: white}");

    highScore->setGeometry(700,300,500,80);
    highScore->setAttribute(Qt::WA_NoSystemBackground);
    highScore->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: white}");

    currentScoreValue->setGeometry(900,150,500,80);
    currentScoreValue->setAttribute(Qt::WA_NoSystemBackground);
    currentScoreValue->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: green}");

    highScoreValue->setGeometry(900,300,500,80);
    highScoreValue->setAttribute(Qt::WA_NoSystemBackground);
    highScoreValue->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: green}");
}

void Game2GamePage::setupGrid()
{
    gameGrid->setPixmap((QPixmap(":/images/game2-bg.jpg")).scaled(300,600));
    gameGrid->setPos(QPointF(100,200));

}

void Game2GamePage::fillScene()
{
    this->addWidget(currentScore);
    this->addWidget(highScore);
    this->addWidget(currentScoreValue);
    this->addWidget(highScoreValue);

    this->addItem(gameGrid);

    this->addItem(redButton);
    this->addItem(greenButton);
    this->addItem(blueButton);
}

void Game2GamePage::addDisk(){
    diskItem = new Disk();
    this->addItem(diskItem);
}
