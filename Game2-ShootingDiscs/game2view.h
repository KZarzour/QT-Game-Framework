#ifndef GAME2VIEW_H
#define GAME2VIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <numeric>
#include "../Accounts_Framework/user.h"
#include "../Accounts_Framework/jsonutils.h"
#include "game2welcomepage.h"
#include "game2gamepage.h"
#include <string>

/**
* \file Game2View.h
* \brief Game2View class
*/

class Game2View : public QGraphicsView
{
    Q_OBJECT
public:
    Game2View();

    User *activeUser = NULL;
    QGraphicsView *appMainView;
    JsonUtils *jsonUtils;

    Game2WelcomePage *welcomePage;
    Game2GamePage *gamePage;


    void keyPressEvent(QKeyEvent *event);
    void connectButtons();

    public slots:
        void startGame();
        void goToHome();
};

#endif // GAME2VIEW_H
