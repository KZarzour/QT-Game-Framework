#include "game1view.h"

Game1View::Game1View()
{
    activeUser = new User();
    welcomePage = new Game1WelcomePage();

    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    //this->setScene(welcomePage);
    //this->show();
    //this->hide();

    QuestionPage *page = new QuestionPage();
    page->show();

    connectButtons();
}

void Game1View::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F1 && (this->scene()==welcomePage)){
       this->startGame();
    }
}


void Game1View::connectButtons(){
    QObject::connect(welcomePage->playGame,SIGNAL(clicked(bool)),this,SLOT(startGame()));
}

void Game1View::startGame(){
    qDebug()<<"hello";
}
