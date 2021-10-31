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

    void keyPressEvent(QKeyEvent *event);
    void connectButtons();
    void clearQuestionPage();
    void checkCurrGameScores();
    void endCurrentGame(bool winOrLose);

public slots:
    void startGame();
    void correctAnswer();
    void wrongAnswer();
};

#endif // GAME1VIEW_H
