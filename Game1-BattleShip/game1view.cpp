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

    QObject::connect(gamePage->home,SIGNAL(clicked(bool)),this,SLOT(goToHome()));
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
    hitHome();
}

void Game1View::hitHome(){
    gamePage->badAnswers=gamePage->badAnswers+1;
    if (gamePage->badAnswers==1){
        gamePage->boat1Part1Label->setStyleSheet("background-color: red");
    }
    if (gamePage->badAnswers==2){
        gamePage->boat1Part2Label->setStyleSheet("background-color: red");
    }
    if (gamePage->badAnswers==3){
        gamePage->boat1Part3Label->setStyleSheet("background-color: red");
    }
    if (gamePage->badAnswers==4){
        gamePage->boat2Label->setStyleSheet("background-color: red");
    }
    if (gamePage->badAnswers==5){
        gamePage->boat3Label->setStyleSheet("background-color: red");
    }
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

    gamePage->correctAnswerNo->setText(tr("Number of correct answers: %1").arg(numTrue));
    gamePage->incorrectAnswerNo->setText(tr("Number of incorrect answers: %1").arg(numFalse));

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
            gamePage->gameStatus->setText("YOU WON!");
            gamePage->gameStatus->setStyleSheet("QLabel { color: green}");
            gamePage->gameStatus->show();
        }
        else{
            activeUser->game1Scores.push_back(0);
            gamePage->gameStatus->setText("YOU LOST!");
            gamePage->gameStatus->setStyleSheet("QLabel { color: red}");
            gamePage->gameStatus->show();
        }
        jsonUtils->updateScores(activeUser->username,activeUser->game1Scores,activeUser->game1HighScore,0);
    }
    else{
       if(winOrLose){
           gamePage->gameStatus->setText("YOU WON!");
           gamePage->gameStatus->setStyleSheet("QLabel { color: green}");
           gamePage->gameStatus->show();
       }
       else{
           gamePage->gameStatus->setText("YOU LOST!");
           gamePage->gameStatus->setStyleSheet("QLabel { color: red}");
           gamePage->gameStatus->show();
       }
    }
    clearQuestionPage();
    currentGameScores.clear();
    gamePage->endGame=true;
//    this->setScene(welcomePage);
//    this->show();
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
    //gamePage->boat3Label->setStyleSheet("background-color: red");
}

void Game1View::goToHome(){
    this->hide();
    panel->hide();
    if(gamePage->endGame){
        //add here

        //Show all buttons
        for (int i=0; i<=3;i++) {
            for (int j=0; j<=3;j++) {
                gamePage->gridButtons.at(i).at(j)->show();
            }
        }
        

        gamePage->setupScene();
        gamePage->setupWidgets();
        //gamePage->setupBoats();
        //gamePage->setupGrids();
        //gamePage->setupButtons();
        gamePage->endGame=false;
       
    }
    appMainView->show();
}
