#include "game1view.h"

Game1View::Game1View()
{
    activeUser = new User();
    welcomePage = new Game1WelcomePage();
    jsonUtils = new JsonUtils();
    gamePage =new Game1GamePage();
    panel =new commandPanel();
    page = new QuestionPage();

    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    this->setScene(welcomePage);
    //this->show();
    //this->hide();
    //panel->show();
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

    QObject::connect(panel->confirmPB,SIGNAL(clicked(bool)),this,SLOT(attack()));
}

void Game1View::startGame(){
    this->setScene(gamePage);
    panel->show();
    //page->show();
}

void Game1View::correctAnswer(){
    page->setStyleSheet("background-color: green;");
    currentGameScores.push_back(true);
    page->correctAnswerPB->setEnabled(false);
    page->wrongAnswerPB->setEnabled(false);
    //qDebug()<< currentGameScores;
    checkCurrGameScores();
    int i = gamePage->lastBoxChosen.toInt();

    int y = i%10;
    int x = (i/10) % 10;
    revealBox(x,y);
}

void Game1View::wrongAnswer(){
    page->setStyleSheet("background-color: red;");
    currentGameScores.push_back(false);
    //qDebug()<< currentGameScores;
    checkCurrGameScores();
    page->correctAnswerPB->setEnabled(false);
    page->wrongAnswerPB->setEnabled(false);
    int i = gamePage->lastBoxChosen.toInt();

    int y = i%10;
    int x = (i/10) % 10;
    strikeBox(x,y);
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

void Game1View::attack(){
    QString pos = panel->targetLineEdit->text();
    bool ok;
    gamePage->lastBoxChosen=pos;
    int i = pos.toInt(&ok);
    if (!ok){
        qDebug()<<"Wrong Input";
    }

    int y = i%10;
    int x = (i/10) % 10;

    bool isValidBox = gamePage->discoverBlock(x,y);

    if(isValidBox){
        page->generateQuestion();
        page->show();
        /*if(){
            revealBox(x,y);
        }
        else{
            strikeBox(x,y);
        }*/
    }
    else{
        qDebug()<<"Here";
        revealBox(x,y);
    }
}

void Game1View::revealBox(int x, int y){
    gamePage->gridButtons.at(x).at(y)->hide();
}

void Game1View::strikeBox(int x, int y){
    gamePage->gridButtons.at(x).at(y)->setStyleSheet("background-color: red");
}
