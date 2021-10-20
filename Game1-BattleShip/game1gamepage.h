#ifndef GAME1GAMEPAGE_H
#define GAME1GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "commandpanel.h"

class Game1GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1GamePage();
    QGraphicsPixmapItem *player1Grid;
    QGraphicsPixmapItem *player2Grid;
    commandPanel *playerCommandPanel;

    void setupScene();
    void setupGrids();
    void fillScene();
};

#endif // GAME1GAMEPAGE_H
