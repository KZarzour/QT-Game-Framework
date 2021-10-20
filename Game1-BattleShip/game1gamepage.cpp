#include "game1gamepage.h"

Game1GamePage::Game1GamePage()
{
    player1Grid = new QGraphicsPixmapItem();
    player2Grid = new QGraphicsPixmapItem();
    playerCommandPanel = new commandPanel();
    GCPLabel = new QLabel("Good Coding Practices");
    BCPLabel = new QLabel("Bad Coding Practices");

    player1Boat1 = new QGraphicsPixmapItem();
    player1Boat2 = new QGraphicsPixmapItem();
    player1Boat3 = new QGraphicsPixmapItem();

    player2Boat1 = new QGraphicsPixmapItem();
    player2Boat2 = new QGraphicsPixmapItem();
    player2Boat3 = new QGraphicsPixmapItem();

    setupScene();
    setupWidgets();
    setupBoats();
    setupGrids();
    fillScene();
}

void Game1GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));

}

void Game1GamePage::setupWidgets(){
    GCPLabel->setGeometry(60,200,500,80);
    GCPLabel->setAttribute(Qt::WA_NoSystemBackground);
    GCPLabel->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: white}");

    BCPLabel->setGeometry(550,200,500,80);
    BCPLabel->setAttribute(Qt::WA_NoSystemBackground);
    BCPLabel->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: white}");
}

void Game1GamePage::setupBoats()
{
    player1Boat1->setPixmap((QPixmap(":/images/big-boat.png")).scaled(200,50));
    player1Boat1->setPos(QPointF(115,270));



}

void Game1GamePage::setupGrids()
{
    player1Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player1Grid->setPos(QPointF(100,250));

    player2Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player2Grid->setPos(QPointF(600,250));

}

void Game1GamePage::fillScene()
{
    this->addItem(player1Grid);
    this->addItem(player2Grid);

    this->addWidget(GCPLabel);
    this->addWidget(BCPLabel);

    this->addItem(player1Boat1);
    this->addItem(player1Boat2);
    this->addItem(player1Boat3);
    this->addItem(player2Boat1);
    this->addItem(player2Boat2);
    this->addItem(player2Boat3);


}
