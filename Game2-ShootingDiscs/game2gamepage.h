#ifndef GAME2GAMEPAGE_H
#define GAME2GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QtWidgets>
#include "lowerpanelbutton.h"

class Game2GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game2GamePage();

    QGraphicsPixmapItem *leftArrow;
    QGraphicsPixmapItem *downArrow;
    QGraphicsPixmapItem *rightArrow;

    QGraphicsPixmapItem *gameGrid;

    QPushButton *home;

    QLabel *currentScore;
    QLabel *highScore;
    QLabel *currentScoreValue;
    QLabel *highScoreValue;

    LowerPanelButton *redButton;
    LowerPanelButton *greenButton;
    LowerPanelButton *blueButton;

    bool endGame = false;

    void setupScene();
    void setupWidgets();
    void setupGrid();
    void setupButtons();
    void setupLabels();
    void fillScene();

};

#endif // GAME2GAMEPAGE_H
