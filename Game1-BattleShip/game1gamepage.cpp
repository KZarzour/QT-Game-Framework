#include "game1gamepage.h"

Game1GamePage::Game1GamePage()
{
    setupScene();
}

void Game1GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));

}
