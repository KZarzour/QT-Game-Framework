#ifndef GAME2WELCOMEPAGE_H
#define GAME2WELCOMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "../Accounts_Framework/user.h"

class Game2WelcomePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game2WelcomePage();
    User* activeUser = NULL;

    QLabel *gameName;
    QLabel *gameInsructions;

    QPushButton *playGame;

    void setupScene();
};

#endif // GAME2WELCOMEPAGE_H
