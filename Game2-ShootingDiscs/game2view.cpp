#include "game2view.h"

Game2View::Game2View()
{
    activeUser = new User();
    jsonUtils = new JsonUtils();

    welcomePage = new Game2WelcomePage();
    gamePage =new Game2GamePage();

    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    this->setScene(welcomePage);

    connectButtons();
}
void Game2View::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F1 && (this->scene()==welcomePage)){
        this->startGame();
    }
    if(event->key() == Qt::Key_Down && (this->scene()==gamePage)){
        qDebug()<<"Down Pressed";
        bool collides = false;
        QList<QGraphicsItem *> list = gamePage->greenButton->collidingItems();
        foreach (QGraphicsItem *i, list) {
            if(dynamic_cast<Disk*>(i)){
                scene()->removeItem(i);
                delete i;
                collides = true;
                //increment score
                gamePage->incrementScore(5);
                break;
            }
        }
    }
    if(event->key() == Qt::Key_Left && (this->scene()==gamePage)){
        qDebug()<<"Left Pressed";
        bool collides = false;
        QList<QGraphicsItem *> list = gamePage->redButton->collidingItems();
        foreach (QGraphicsItem *i, list) {
            if(dynamic_cast<Disk*>(i)){
                scene()->removeItem(i);
                delete i;
                collides = true;
                //increment score
                gamePage->incrementScore(3);
                break;
            }
        }
    }
    if(event->key() == Qt::Key_Right && (this->scene()==gamePage)){
        qDebug()<<"Right Pressed";
        QList<QGraphicsItem *> list = gamePage->blueButton->collidingItems();
        foreach (QGraphicsItem *i, list) {
            if(dynamic_cast<Disk*>(i)){
                scene()->removeItem(i);
                delete i;
                //increment score
                gamePage->incrementScore(7);
                break;
            }
        }
    }
}


void Game2View::connectButtons(){
    QObject::connect(welcomePage->playGame,SIGNAL(clicked(bool)),this,SLOT(startGame()));
}

void Game2View::startGame(){
    this->setScene(gamePage);
    if(activeUser){
        gamePage->activeUser = this->activeUser;
    }
    gamePage->start();
    qDebug()<<"Starting";
}
