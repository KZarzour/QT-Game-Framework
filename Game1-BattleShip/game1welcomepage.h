#ifndef GAME1WELCOMEPAGE_H
#define GAME1WELCOMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "../Accounts_Framework/user.h"

class Game1WelcomePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1WelcomePage();
    User* activeUser = NULL;

    QLabel *gameName;
    QLabel *gameInsructions;

    QPushButton *playGame;

    void setupScene();

};

#endif // GAME1WELCOMEPAGE_H
