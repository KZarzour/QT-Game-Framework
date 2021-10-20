#ifndef GAME1GAMEPAGE_H
#define GAME1GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include "commandpanel.h"

class Game1GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game1GamePage();
    QGraphicsPixmapItem *player1Grid;
    QGraphicsPixmapItem *player2Grid;
    QGraphicsPixmapItem *player1Boat1;
    QGraphicsPixmapItem *player1Boat2;
    QGraphicsPixmapItem *player1Boat3;
    QGraphicsPixmapItem *player2Boat1;
    QGraphicsPixmapItem *player2Boat2;
    QGraphicsPixmapItem *player2Boat3;
    commandPanel *playerCommandPanel;
    QLabel *GCPLabel;
    QLabel *BCPLabel;

    void setupScene();
    void setupGrids();
    void fillScene();
    void setupBoats();
    void setupWidgets();
};

#endif // GAME1GAMEPAGE_H
