#ifndef GAME1VIEW_H
#define GAME1VIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include "../Accounts_Framework/user.h"
#include "game1welcomepage.h"
#include "questionobj.h"

class Game1View : public QGraphicsView
{
    Q_OBJECT
public:
    Game1View();

    User *activeUser = NULL;

    Game1WelcomePage *welcomePage;

    void keyPressEvent(QKeyEvent *event);
    void connectButtons();

public slots:
    void startGame();
};

#endif // GAME1VIEW_H
