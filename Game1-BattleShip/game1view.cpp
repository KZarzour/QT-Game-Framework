#include "game1view.h"

Game1View::Game1View()
{
    activeUser = new User();
    welcomePage = new Game1WelcomePage();
    jsonUtils = new JsonUtils();
    gamePage =new Game1GamePage();

    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    this->setScene(gamePage);
    //this->show();
    //this->hide();
    commandPanel *panel =new commandPanel();
    panel->show();
    page = new QuestionPage();
    //page->show();

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
    page->show();
}

void Game1View::correctAnswer(){
    page->setStyleSheet("background-color: green;");
    currentGameScores.push_back(true);
    //page->correctAnswerPB->setEnabled(false);
    //page->wrongAnswerPB->setEnabled(false);
    //qDebug()<< currentGameScores;
    checkCurrGameScores();
}

void Game1View::wrongAnswer(){
    page->setStyleSheet("background-color: red;");
    currentGameScores.push_back(false);
    //qDebug()<< currentGameScores;
    checkCurrGameScores();
    //page->correctAnswerPB->setEnabled(false);
    //page->wrongAnswerPB->setEnabled(false);
}

void Game1View::clearQuestionPage(){
    page->questionL->clear();
    page->correctAnswerPB->setText("");
    page->wrongAnswerPB->setText("");
    page->setStyleSheet("background-color: white;");
    page->correctAnswerPB->setEnabled(true);
    page->wrongAnswerPB->setEnabled(true);
}

void Game1View::checkCurrGameScores(){

    int numTrue=0;
    int numFalse=0;

    for (bool& n : currentGameScores){
        if(n){
            numTrue++;
        }
        else{
            numFalse++;
        }
    }

    if(numFalse==4){
        //qDebug()<<"Lost Game";
        endCurrentGame(false);
    }
    else if(numTrue==7){
        //qDebug()<<"Won Game";
        endCurrentGame(true);
    }
}
void Game1View::endCurrentGame(bool winOrLose){
    if(activeUser){
        if(winOrLose){
            activeUser->game1Scores.push_back(1);
            activeUser->game1HighScore++;
        }
        else{
            activeUser->game1Scores.push_back(0);
        }
        jsonUtils->updateScores(activeUser->username,activeUser->game1Scores,activeUser->game1HighScore,0);
    }

    clearQuestionPage();
    currentGameScores.clear();
    this->setScene(welcomePage);
    this->show();
}
