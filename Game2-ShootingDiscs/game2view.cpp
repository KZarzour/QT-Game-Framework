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
}


void Game2View::connectButtons(){
    QObject::connect(welcomePage->playGame,SIGNAL(clicked(bool)),this,SLOT(startGame()));
}

void Game2View::startGame(){
    this->setScene(gamePage);
    qDebug()<<"Starting";
}
