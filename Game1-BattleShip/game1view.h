#ifndef GAME1VIEW_H
#define GAME1VIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <numeric>
#include "../Accounts_Framework/user.h"
#include "game1welcomepage.h"
#include "questionobj.h"
#include "questionpage.h"
#include "commandpanel.h"
#include "game1gamepage.h"
#include "../Accounts_Framework/jsonutils.h"
#include <string>

/**
* \file Game1View.h
* \brief Game1View class
*/

class Game1View : public QGraphicsView
{
    Q_OBJECT
public:
    Game1View();

    User *activeUser = NULL;

    Game1WelcomePage *welcomePage;
    Game1GamePage *gamePage;

    QuestionPage *page;

    QVector<bool> currentGameScores;

    JsonUtils *jsonUtils;

    commandPanel *panel;

    QGraphicsView *appMainView;

    void keyPressEvent(QKeyEvent *event);
    void connectButtons();
    void clearQuestionPage();
    void checkCurrGameScores();
    void endCurrentGame(bool winOrLose);
    void revealBox(int x , int y);
    void strikeBox(int x, int y);


public slots:
    void startGame();
    void correctAnswer();
    void wrongAnswer();
    void hitHome();
    void attack();
    void goToHome();
};

#endif // GAME1VIEW_H
