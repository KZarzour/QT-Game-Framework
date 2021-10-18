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
//    commandPanel *panel =new commandPanel();
//    panel->show();
    page = new QuestionPage();
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

    QObject::connect(page->correctAnswerPB,SIGNAL(clicked(bool)),this,SLOT(correctAnswer()));
    QObject::connect(page->wrongAnswerPB,SIGNAL(clicked(bool)),this,SLOT(wrongAnswer()));

}

void Game1View::startGame(){
    qDebug()<<"hello";
}

void Game1View::correctAnswer(){
    page->setStyleSheet("background-color: green;");
}

void Game1View::wrongAnswer(){
    page->setStyleSheet("background-color: red;");
}

void Game1View::clearQuestionPage(){
    page->questionL->clear();
    page->correctAnswerPB->setText("");
    page->wrongAnswerPB->setText("");
    page->setStyleSheet("background-color: white;");
}
