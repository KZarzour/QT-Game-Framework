#include "game2gamepage.h"

Game2GamePage::Game2GamePage()
{
    jsonUtils =new JsonUtils();
    leftArrow = new QGraphicsPixmapItem();
    downArrow = new QGraphicsPixmapItem();
    rightArrow = new QGraphicsPixmapItem();
    gameGrid = new QGraphicsPixmapItem();

    timer = new QTimer();
    home = new QPushButton("Home");

    gameSpeed =0;

    currentUserScore=0;
    highestScore= activeUser ? activeUser->game2HighScore : 0;
    currentMissedDisks=0;
    //qDebug()<<activeUser->game2HighScore;
    gameResult = new QLabel();
    currentScore = new QLabel("Current Score");
    highScore = new QLabel("High Score");
    currentScoreValue = new QLabel(QString::number(currentUserScore));
    highScoreValue = new QLabel(QString::number(highestScore));
    missedDisks = new QLabel("Missed Disks");
    missedDisksValue = new QLabel(QString::number(currentMissedDisks));

    redButton = new LowerPanelButton(nullptr, 0);
    greenButton = new LowerPanelButton(nullptr, 1);
    blueButton = new LowerPanelButton(nullptr, 2);
    mdz = new missedDiskZone(nullptr);

    setupScene();
    setupWidgets();
    setupGrid();
    fillScene();
}
void Game2GamePage::setupScene(){
    this->setSceneRect(0,0,1000,1000);
    this->setBackgroundBrush(QBrush(QImage(":/images/pannel-bg.jpg")));
}
void Game2GamePage::setupWidgets(){
    gameResult->setGeometry(700,600,0,0);
    gameResult->setAttribute(Qt::WA_NoSystemBackground);
    gameResult->hide();

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

    missedDisks->setGeometry(700,450,500,200);
    missedDisks->setAttribute(Qt::WA_NoSystemBackground);
    missedDisks->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: white}");

    missedDisksValue->setGeometry(900,450,500,80);
    missedDisksValue->setAttribute(Qt::WA_NoSystemBackground);
    missedDisksValue->setStyleSheet("QLabel { font-size: 18px; font-weight: bold; color: red}");

    home->setGeometry(500,700,100,50);
}

void Game2GamePage::setupGrid()
{
    gameGrid->setPixmap((QPixmap(":/images/game2-bg.jpg")).scaled(300,600));
    gameGrid->setPos(QPointF(100,200));

}

void Game2GamePage::fillScene()
{
    this->addWidget(gameResult);
    this->addWidget(currentScore);
    this->addWidget(highScore);
    this->addWidget(currentScoreValue);
    this->addWidget(highScoreValue);
    this->addWidget(missedDisks);
    this->addWidget(missedDisksValue);
    this->addItem(mdz);
    this->addWidget(home);
    this->addItem(gameGrid);

    this->addItem(redButton);
    this->addItem(greenButton);
    this->addItem(blueButton);


}
void Game2GamePage::start(){
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(addDisk()));
    timer->start(2000);
    QTimer *detectingTimer = new QTimer();
    QObject::connect(detectingTimer,SIGNAL(timeout()),this,SLOT(checkMissedDisks()));
    detectingTimer->start(100);
}

void Game2GamePage::addDisk(){
    diskItem = new Disk(nullptr,gameSpeed);
    this->addItem(diskItem);
}

void Game2GamePage::checkMissedDisks(){
    QList<QGraphicsItem *> list = mdz->collidingItems();
    foreach (QGraphicsItem *i, list) {
        delete i;
        qDebug()<<"Disk collides";
        incrementMisses();
        break;
    }
}

void Game2GamePage::incrementScore(int n){
    //int currScore = currentScoreValue->text().toInt();
    currentUserScore+=n;
    currentScoreValue->setText(QString::number(currentUserScore));
    this->gameSpeed = currentUserScore/30;
    if  (currentUserScore >=80){
        finishGame();
    }
}
void Game2GamePage::incrementMisses(){
    currentMissedDisks++;
    missedDisksValue->setText(QString::number(currentMissedDisks));
    if (currentMissedDisks>=3){
        finishGame();
    }
}

void Game2GamePage::finishGame(){
    endGame=true;
    timer->stop();
    qDebug()<<"GAME ENDED";
    int currScore = currentScoreValue->text().toInt();
    if (currScore>=5){
        gameResult->setText("You Won!");
        gameResult->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: green}");
    }
    else{
        gameResult->setText("You Lost :(");
        gameResult->setStyleSheet("QLabel { font-size: 32px; font-weight: bold; color: red}");        
    }

    QList<QGraphicsItem *> list = gameGrid->collidingItems();
    foreach (QGraphicsItem *i, list) {
        if (i->y()<750){
            delete i;
            qDebug()<<"Disk Deleted";
        }
    }

    gameResult->show();

    if (activeUser){
        qDebug()<<currentUserScore;
        activeUser->game2Scores.push_back(currentUserScore);
        if (currentUserScore>activeUser->game2HighScore){
            activeUser->game2HighScore=currentUserScore;
        }
        jsonUtils->updateScores(activeUser->username,activeUser->game2Scores,activeUser->game2HighScore,1);
    }

}



