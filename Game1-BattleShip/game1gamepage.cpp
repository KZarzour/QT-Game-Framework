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
    player2Boat4 = new QGraphicsPixmapItem();
    player2Boat5 = new QGraphicsPixmapItem();
    player2Boat6 = new QGraphicsPixmapItem();

    button00 = new QPushButton();
    button01 = new QPushButton();
    button02 = new QPushButton();
    button03 = new QPushButton();
    button10 = new QPushButton();
    button11 = new QPushButton();
    button12 = new QPushButton();
    button13 = new QPushButton();
    button20 = new QPushButton();
    button21 = new QPushButton();
    button22 = new QPushButton();
    button23 = new QPushButton();
    button30 = new QPushButton();
    button31 = new QPushButton();
    button32 = new QPushButton();
    button33 = new QPushButton();

    QVector<QPushButton*> v1;
    v1.push_back(button00);
    v1.push_back(button01);
    v1.push_back(button02);
    v1.push_back(button03);
    gridButtons.push_back(v1);
    v1.clear();
    v1.push_back(button10);
    v1.push_back(button11);
    v1.push_back(button12);
    v1.push_back(button13);
    gridButtons.push_back(v1);
    v1.clear();
    v1.push_back(button20);
    v1.push_back(button21);
    v1.push_back(button22);
    v1.push_back(button23);
    gridButtons.push_back(v1);
    v1.clear();
    v1.push_back(button30);
    v1.push_back(button31);
    v1.push_back(button32);
    v1.push_back(button33);
    gridButtons.push_back(v1);
    v1.clear();
    qDebug()<<gridButtons;

    QVector<bool> v2;
    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(false);
    userBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(false);
    userBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(false);
    userBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(true);
    userBoatPositions.push_back(v2);
    v2.clear();
    qDebug()<<userBoatPositions;

    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(true);
    enemyBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(false);
    enemyBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(false);
    v2.push_back(false);
    enemyBoatPositions.push_back(v2);
    v2.clear();
    v2.push_back(false);
    v2.push_back(true);
    v2.push_back(true);
    v2.push_back(true);
    enemyBoatPositions.push_back(v2);
    v2.clear();
    qDebug()<<enemyBoatPositions;

    lastBoxChosen="";

    setupScene();
    setupWidgets();
    setupBoats();
    setupGrids();
    setupButtons();
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
    player1Boat2->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player1Boat2->setPos(QPointF(115,405));
    player1Boat3->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player1Boat3->setPos(QPointF(318,473));

    player2Boat1->setPixmap((QPixmap(":/images/big-boat.png")).scaled(200,50));
    player2Boat1->setPos(QPointF(618,338));
    player2Boat2->setPixmap((QPixmap(":/images/big-boat.png")).scaled(200,50));
    player2Boat2->setPos(QPointF(686,471));
    player2Boat3->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player2Boat3->setPos(QPointF(821,268));
    player2Boat4->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player2Boat4->setPos(QPointF(618,268));
    player2Boat5->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player2Boat5->setPos(QPointF(618,403));
    player2Boat6->setPixmap((QPixmap(":/images/small-boat.png")).scaled(60,60));
    player2Boat6->setPos(QPointF(686,268));

}

void Game1GamePage::setupGrids()
{
    player1Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player1Grid->setPos(QPointF(100,250));

    player2Grid->setPixmap((QPixmap(":/images/grid.png")).scaled(300,300));
    player2Grid->setPos(QPointF(600,250));

}

void Game1GamePage::setupButtons(){
    button00->setGeometry(618,268,62,62);
    button01->setGeometry(686,268,62,62);
    button02->setGeometry(753,268,62,62);
    button03->setGeometry(821,268,62,62);
    button10->setGeometry(618,336,62,62);
    button11->setGeometry(686,336,62,62);
    button12->setGeometry(753,336,62,62);
    button13->setGeometry(821,336,62,62);
    button20->setGeometry(618,403,62,62);
    button21->setGeometry(686,403,62,62);
    button22->setGeometry(753,403,62,62);
    button23->setGeometry(821,403,62,62);
    button30->setGeometry(618,471,62,62);
    button31->setGeometry(686,471,62,62);
    button32->setGeometry(753,471,62,62);
    button33->setGeometry(821,471,62,62);

    button00->setEnabled(false);
    button01->setEnabled(false);
    button02->setEnabled(false);
    button03->setEnabled(false);
    button10->setEnabled(false);
    button11->setEnabled(false);
    button12->setEnabled(false);
    button13->setEnabled(false);
    button20->setEnabled(false);
    button21->setEnabled(false);
    button22->setEnabled(false);
    button23->setEnabled(false);
    button30->setEnabled(false);
    button31->setEnabled(false);
    button32->setEnabled(false);
    button33->setEnabled(false);
}

void Game1GamePage::fillScene()
{
    this->addWidget(GCPLabel);
    this->addWidget(BCPLabel);

    this->addItem(player1Boat1);
    this->addItem(player1Boat2);
    this->addItem(player1Boat3);
    this->addItem(player2Boat1);
    this->addItem(player2Boat2);
    this->addItem(player2Boat3);
    this->addItem(player2Boat4);
    this->addItem(player2Boat5);
    this->addItem(player2Boat6);

    this->addItem(player1Grid);
    this->addItem(player2Grid);

    this->addWidget(button00);
    this->addWidget(button01);
    this->addWidget(button02);
    this->addWidget(button03);
    this->addWidget(button10);
    this->addWidget(button11);
    this->addWidget(button12);
    this->addWidget(button13);
    this->addWidget(button20);
    this->addWidget(button21);
    this->addWidget(button22);
    this->addWidget(button23);
    this->addWidget(button30);
    this->addWidget(button31);
    this->addWidget(button32);
    this->addWidget(button33);
}

QVector<int> Game1GamePage::getButtonPosition(QPushButton *button){
    QVector<int> pos;
    for (int i=0;i<gridButtons.size();i++) {
        for (int j=0;j<gridButtons.at(0).size();j++) {
            if(button == gridButtons.at(i).at(j)){
                pos.push_back(i);
                pos.push_back(j);
                qDebug()<<pos;
                return pos;
            }
        }
    }
    pos.push_back(-1);
    return pos;
}

bool Game1GamePage::discoverBlock(int x ,int y){
    if(enemyBoatPositions.at(x).at(y)){
        return true;
    }
    return false;
}
