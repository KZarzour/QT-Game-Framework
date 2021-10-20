#ifndef GAME1GAMEPAGE_H
#define GAME1GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>

class Game1GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1GamePage();

    void setupScene();
};

#endif // GAME1GAMEPAGE_H
