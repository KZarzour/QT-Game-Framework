#ifndef GAME2VIEW_H
#define GAME2VIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <numeric>
#include "../Accounts_Framework/user.h"
#include "../Accounts_Framework/jsonutils.h"
#include "game2welcomepage.h"
#include <string>

class Game2View : public QGraphicsView
{
    Q_OBJECT
public:
    Game2View();

    User *activeUser = NULL;
    QGraphicsView *appMainView;
    JsonUtils *jsonUtils;

    Game2WelcomePage *welcomePage;

    void keyPressEvent(QKeyEvent *event);
    void connectButtons();

    public slots:
        void startGame();
};

#endif // GAME2VIEW_H
