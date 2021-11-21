#include "game2view.h"
/**
* \file Game2View.cpp
* \brief contains initialization of game 2 view.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
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

/**
 * @brief Game2View::keyPressEvent, is called when the arrow keys are pressed to delete the disks and add to the score.
 */
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

/**
 * @brief Game2View::connectButtons, connects the buttons to the functions that need to be called when they are clicked.
 */
void Game2View::connectButtons(){
    QObject::connect(welcomePage->playGame,SIGNAL(clicked(bool)),this,SLOT(startGame()));

    QObject::connect(gamePage->home,SIGNAL(clicked(bool)),this,SLOT(goToHome()));
}

/**
 * @brief Game2View::startGame, is called to start the game.
 */
void Game2View::startGame(){
    this->setScene(gamePage);
    if(activeUser){
        gamePage->activeUser = this->activeUser;
        gamePage->highestScore= activeUser->game2HighScore;
        gamePage->highScoreValue->setText(QString::number(gamePage->highestScore));
    }
    gamePage->start();
    qDebug()<<"Starting";
}

/**
 * @brief Game2View::goToHome, is called when home button is pressed, stops the game and takes the
 * player back to the welcome page.
 */
void Game2View::goToHome(){
    gamePage->interuptGame();
    gamePage->gameResult->hide();
    this->setScene(welcomePage);
    this->hide();
    appMainView->show();
}
