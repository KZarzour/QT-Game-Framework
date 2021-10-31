#ifndef GAME1GAMEPAGE_H
#define GAME1GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include "commandpanel.h"
#include <QtWidgets>

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
    QGraphicsPixmapItem *player2Boat4;
    QGraphicsPixmapItem *player2Boat5;
    QGraphicsPixmapItem *player2Boat6;
    commandPanel *playerCommandPanel;
    QLabel *GCPLabel;
    QLabel *BCPLabel;

    QPushButton *button00;
    QPushButton *button01;
    QPushButton *button02;
    QPushButton *button03;
    QPushButton *button10;
    QPushButton *button11;
    QPushButton *button12;
    QPushButton *button13;
    QPushButton *button20;
    QPushButton *button21;
    QPushButton *button22;
    QPushButton *button23;
    QPushButton *button30;
    QPushButton *button31;
    QPushButton *button32;
    QPushButton *button33;

    QVector<QVector<QPushButton *>> gridButtons;
    QVector<QVector<bool>> userBoatPositions;
    QVector<QVector<bool>> enemyBoatPositions;

    void setupScene();
    void setupGrids();
    void fillScene();
    void setupBoats();
    void setupWidgets();
    void setupButtons();
};

#endif // GAME1GAMEPAGE_H
