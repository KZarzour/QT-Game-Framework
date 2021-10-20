#include "game1gamepage.h"

Game1GamePage::Game1GamePage()
{
    player1Grid = new QGraphicsPixmapItem();
    player2Grid = new QGraphicsPixmapItem();
    playerCommandPanel = new commandPanel();
    setupScene();
    setupGrids();
    fillScene();
}

void Game1GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));


}

void Game1GamePage::setupGrids()
{
    player1Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player1Grid->setPos(QPointF(30,250));

    player2Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player2Grid->setPos(QPointF(260,250));

}

void Game1GamePage::fillScene()
{
    this->addItem(player1Grid);
    this->addItem(player2Grid);
}
