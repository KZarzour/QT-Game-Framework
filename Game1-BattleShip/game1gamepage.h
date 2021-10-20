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
    commandPanel *playerCommandPanel;
    QLabel *GCPLabel;
    QLabel *BCPLabel;

    void setupScene();
    void setupGrids();
    void fillScene();
    void setupWidgets();
};

#endif // GAME1GAMEPAGE_H
